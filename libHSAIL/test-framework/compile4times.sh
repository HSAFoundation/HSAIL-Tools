#!/bin/bash
#FILE=inst.large
ASM=../build_linux/hsailasm
FILE=hsail_tests_p
${ASM} -assemble ${FILE}.hsail -o ${FILE}.bin1
${ASM} -disassemble ${FILE}.bin1 -o ${FILE}.s1
${ASM} -assemble ${FILE}.s1 -o ${FILE}.bin2
${ASM} -disassemble ${FILE}.bin2 -o ${FILE}.s2
