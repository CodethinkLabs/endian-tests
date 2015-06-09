#!/bin/bash

GREEN=$'\033[32m'
RED=$'\033[31m'
RESET=$'\033[0m'

MODE=$1

if [[ $MODE == "BE" || $MODE == "LE" ]]; then
    echo "Mode is $MODE"
else
    echo "Please specify LE or BE as the first parameter."
    exit 1
fi

export CFLAGS=""
export CC=""

PLATFORM=`uname -m`

if [[ $PLATFORM == "x86_64" && $MODE == "BE" ]]; then
    export CC="" # Replace with the name of a big-endian capable compiler
    export CFLAGS="--big-endian" # Replace with the flag necessary to build for a big-endian data model
elif [[ $PLATFORM == "armv7b" && $MODE == "BE" ]]; then
    export CC="gcc"
elif [[ $PLATFORM == "x86_64" && $MODE == "LE" ]]; then
    export CC="gcc"
fi

if [[ $CC == "" ]]; then
    echo "No suitable compiler found for this combination ($PLATFORM, $MODE)"
    exit 0
fi

rm -f test-bin/*
make || exit 1
mkdir -p output
rm -f output/*

for i in test-src/*;  do
FAIL=""
TESTNAME=`basename $i`
timeout 300 /usr/bin/time -f "%U %E" -o output/$TESTNAME.$MODE.time test-bin/`basename $i .c` >output/$TESTNAME.$MODE.out 2>output/$TESTNAME.$MODE.err || FAIL="exit"
if [[ $? == 124 ]]; then FAIL="timeout"; fi
diff -q output/$TESTNAME.$MODE.out expected-output/$TESTNAME.$MODE.out >/dev/null || FAIL="$FAIL stdout"
diff -q output/$TESTNAME.$MODE.err expected-output/$TESTNAME.$MODE.err >/dev/null || FAIL="$FAIL stderr"
if [[ $FAIL == "" ]]; then
    printf "%40.40s %s[PASS]%s " $TESTNAME $GREEN $RESET
else
    printf "%40.40s %s[FAIL]%s %s " $TESTNAME $RED $RESET $FAIL
fi
cat output/$TESTNAME.$MODE.time
done
