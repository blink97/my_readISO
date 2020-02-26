#!/bin/sh

if [ $# -ne 2 ]; then
  echo Usage: ./testsuite.sh MY_READ_ISO ARGS
  exit 1
fi

$("$1" "$2"  < "commands.txt" > "output.txt")
diff "expected.txt" "output.txt"
