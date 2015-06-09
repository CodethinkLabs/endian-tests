#!/usr/bin/python
# random-function-generator.py

# This is designed to test calls to functions with mismatched arguments; calling
# a function with int arguments and passing short ints, or passing ints to floats.
# There are potential issues with variable promotion in big-endian mode mentioned in
# the ICC manual.

import random

types = ["int", "float", "double"];

sizePrefixes = { "int":    ["s", "n", "l"],
                 "float":  ["n"],
                 "double": ["n", "l"] }

printfFormatSpecifiers = { "int": "%d",
                          "float": "%f",
                          "double": "%g" }

sizeKeywords = { "s": "short ",
                 "n": "",
                 "l": "long " }

initializer = 0

print "#include <stdio.h>"
print "#pragma warning disable 181" # This is the ICC warning number for printf mismatches
print "#pragma warning disable 161" # This is the ICC warning number for unknown pragmas!
print "#pragma GCC diagnostic ignored \"-Wformat\""
print "/* Please see tools/random-function-generator.py for documentation */"

returnTypes = []

for i in range(0,20):
    funcName = "function"+str(i)
    returnType = random.choice(types)
    args = []
    typedArgs = []
    returnTypes.append(returnType)
    for i in range(0,10):
        args.append(chr(97+i))
        typeName = random.choice(types)
        sizedTypeName = sizeKeywords[random.choice(sizePrefixes[typeName])] + typeName
        typedArgs.append("%s %s"%(sizedTypeName, args[i]))
    argSpec = ", ".join(typedArgs)
    print "%s %s(%s)"%(returnType, funcName, argSpec)
    print "{\n    return a+b+c+d+e+f+g+h+i+j;\n}"

print "int main()"
print "{"

for i in range(0,20):
    typeName = random.choice(types)

    if typeName == "int": initializer = random.randint(0,65535)
    else: initializer = random.random()

    print "    %s%s %s = %s;"%( sizeKeywords[random.choice(sizePrefixes[typeName])], typeName, chr(65+i), str(initializer))


for l in range(0,100):
    funcNo = random.randint(0,19)
    funcName = "function"+str(funcNo)
    args = []
    for i in range(0,10):
        args.append(chr(random.randint(65,84)))

    print "    printf(\"%s \", %s(%s));"%(printfFormatSpecifiers[returnTypes[funcNo]], funcName, ", ".join(args))
print "    printf(\"\\n\");"
print "    return 0;\n}"
