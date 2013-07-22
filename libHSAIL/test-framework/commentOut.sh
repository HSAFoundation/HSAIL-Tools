#!/bin/bash
FILENAME=../tests/hsail_tests_p
ASM=../build_linux/hsailasm
string=`${ASM} -assemble ${FILENAME}.hsail 2>&1`
n=0
while [ -n "$string" ]
do
  line=`echo $string | awk -F"^" '{ print $2 }' | awk -F"(" '{ print $2 }' | awk -F"," '{ print $1 }'`
  echo $line
  sed -i "${line} s/^/\/\//" ${FILENAME}.hsail
#  cat -n ${FILENAME}.hsail | grep $line
  string=`${ASM} -assemble ${FILENAME}.hsail 2>&1`
  n=`expr $n + 1`
done

${ASM} -assemble ${FILENAME}.hsail -o ${FILENAME}.bin1 2>/dev/null >/dev/null
${ASM} -disassemble ${FILENAME}.bin1 -o ${FILENAME}.s1 2>/dev/null >/dev/null
string=`${ASM} -assemble ${FILENAME}.s1 2>&1`
echo $string

while [ -n "$string" ]
do
  echo $string
  p1=`echo $string | awk -F";" '{ print $1 }' | awk -F">" '{ print $2}'| awk -F"/*" '{ print $1}'`
  p2=`echo $string | awk -F";" '{ print $1 }' | awk -F"*/" '{ print $2}'| awk -F" " '{ print $1}'`
  if [ -z "$p2"]
  then
    p1=`echo $string | awk -F";" '{ print $1 }' | awk -F"> " '{ print $2}'| awk -F"_" '{ print $1}'`
    p2=`echo $string | awk -F";" '{ print $1 }' | awk -F" " '{ print $2}'\
      | awk -F"_" '{ print $NF}'`
#    p2=`echo $string | awk -F";" '{ print $1 }' | awk -F"> " '{ print $2}'\
#      | awk -F"_" '{ print $NF}'`
  fi

  p3=`echo $string | awk -F"," '{ print $1 }' | awk -F"> " '{ print $2}'| awk -F" " '{ print $2}'`
  p3=${p3#*-}
  echo "p1=$p1"
  echo "p2=$p2"
  echo "p3=$p3"
  line=`grep -n $p1 ${FILENAME}.hsail | grep ${p2}  | grep $p3 | grep -v "//" `
  echo $line
  if [ -z "$line" ]
  then
    continue
  fi
  num=`echo $line | awk -F":" '{print $1}'`
  echo $num
  sed -i "${num} s/^/\/\//" ${FILENAME}.hsail
  cat -n ${FILENAME}.hsail | grep $num
  n=`expr $n + 1`
  ${ASM} -assemble ${FILENAME}.hsail -o ${FILENAME}.bin1 2>/dev/null >/dev/null
  ${ASM} -disassemble ${FILENAME}.bin1 -o ${FILENAME}.s1 2>/dev/null >/dev/null
  string=`${ASM} -assemble ${FILENAME}.s1 2>&1`
done
echo "Totally commented out $n lines"
