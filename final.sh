#!/bin/bash

PATH_TO_TEST=${1}
TEST_NAME="$(basename "${PATH_TO_TEST}" .c)"
TEST_PATH="$(dirname "${PATH_TO_TEST}")"
DRIVER="${TEST_PATH}/${TEST_NAME}_driver.c"


if [[ ! -d "out" ]] ; then
  mkdir out
fi

make clean
make

echo "Compiling ${TEST_NAME}"
bin/c_compiler -S "${PATH_TO_TEST}" -o "out/${TEST_NAME}.s"
echo "Assembling"
mips-linux-gnu-gcc -mfp32 -o "out/${TEST_NAME}.o" -c out/"${TEST_NAME}.s"
echo "Linking to driver"
mips-linux-gnu-gcc -mfp32 -static -o "out/${TEST_NAME}" "out/${TEST_NAME}.o" "${DRIVER}"
echo "Running qemu-mips"
qemu-mips "out/${TEST_NAME}"
RESULT=${?}

if [[ ${RESULT} -eq 0 ]] ; then
  >&2 echo "Testcase ${TEST_NAME} passed successfully"
else
  >&2 echo "Testcase ${TEST_NAME} failed"
  exit 1
fi