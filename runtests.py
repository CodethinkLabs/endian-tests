#!/usr/bin/python3

import difflib
import glob
import os
import platform
import shutil
import subprocess
import sys
import time


GREEN='\033[32m'
RED='\033[31m'
RESET='\033[0m'


def diff_files(f1_name, f2_name):
    if not os.path.exists(f1_name) and os.path.exists(f2_name):
        result = ['%s missing' % f1_name]
    elif os.path.exists(f1_name) and not os.path.exists(f2_name):
        result = ['%s missing' % f2_name]
    elif not os.path.exists(f1_name) and not os.path.exists(f2_name):
        result = []
    else:
        with open(f1_name) as f1:
            with open(f2_name) as f2:
                result = list(
                    difflib.unified_diff(
                        f1.read().splitlines(),
                        f2.read().splitlines(),
                        fromfile=f1_name, tofile=f2_name))
    return result


def main():
    if len(sys.argv) != 2:
        raise RuntimeError(
             "Please specify LE or BE as the first parameter.")

    mode = sys.argv[1]

    if mode in ['BE', 'LE']:
        print("Mode is: %s" % mode)
    else:
        raise RuntimeError(
             "Please specify LE or BE as the first parameter.")

    machine = platform.machine()

    cc = ""
    cflags = ""

    if machine == "x86_64" and mode == "BE":
        cc="" # Replace with the name of a big-endian capable compiler
        cflags="--big-endian" # Replace with the flag necessary to build for a big-endian data model
    elif machine == "armv7b" and mode == "BE":
        cc="gcc"
    elif machine == "sun4v" and mode == "BE":
        cc="g++"  # gcc fails to link c++ code on Solaris
        cflags="-lsocket"
    elif machine == "x86_64" and mode == "LE":
        cc="gcc"
    elif machine == "ppc64" and mode == "BE":
        cc="gcc"
    elif platform.system() == "AIX" and platform.processor() == "powerpc" and mode == "BE":
        cc="gcc"

    if len(cc) == 0:
        raise RuntimeError(
            "No suitable compiler found for this combination (%s, %s)" %
            (machine, mode))

    if os.path.exists('test-bin/'):
        shutil.rmtree('test-bin/')

    build_env = os.environ.copy()
    build_env['CC'] = cc
    build_env['CFLAGS'] = cflags

    make_path = shutil.which('gmake')
    if not make_path:
        make_path = shutil.which('make')
    if not make_path:
        raise RuntimeError("Neither 'make' nor 'gmake' found")

    subprocess.check_call([make_path], env=build_env)

    if os.path.exists('output/'):
        shutil.rmtree('output')
    os.mkdir('output')

    for test in glob.glob('test-src/*'):
        start_time = time.time()
        test_name = os.path.basename(test)
        test_binary = os.path.join('test-bin',
                                   os.path.splitext(test_name)[0])

        failures = []

        stdout_name = 'output/%s.%s.out' % (test_name, mode)
        stderr_name = 'output/%s.%s.err' % (test_name, mode)
        expected_stdout_name = 'expected-output/%s.%s.out' % (test_name, mode)
        expected_stderr_name = 'expected-output/%s.%s.err' % (test_name, mode)

        try:
            with open(stdout_name, 'w') as f_stdout:
                with open(stderr_name, 'w') as f_stderr:
                    returncode = subprocess.call(
                        [test_binary],
                        timeout=300, stdout=f_stdout, stderr=f_stderr)

            if returncode != 0:
                failures.append("exit code")

        except FileNotFoundError:
            failures.append('compile error')

        end_time = time.time()

        stdout_diff = diff_files(stdout_name, expected_stdout_name)
        if len(stdout_diff) > 0:
            failures.append('stdout')

        stderr_diff = diff_files(stderr_name, expected_stderr_name)
        if len(stderr_diff) > 0:
            failures.append('stderr')

        if len(failures) > 0:
            print("%40.40s %s[FAIL]%s %s " %
                  (test_name, RED, RESET, ' '.join(failures)))
        else:
            print("%40.40s %s[PASS]%s" %
                  (test_name, GREEN, RESET))

        time_delta = end_time - start_time
        time_str = time.strftime('%M:%S', time.localtime(time_delta))
        with open('output/%s.%s.time' % (test_name, mode), 'w') as f:
            f.write(time_str + '\n')
        print(time_str)

        if stdout_diff:
            print(''.join(stdout_diff))

        if stderr_diff:
            print(''.join(stderr_diff))


try:
    main()
except RuntimeError as e:
    sys.stderr.write('%s\n' % e)
    sys.exit(1)
