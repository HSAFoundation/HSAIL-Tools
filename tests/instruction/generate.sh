#!/bin/bash

set -e

suffix=1_0

mkdir -p tmp

generate() {
  local name=$1;
  local iset=$2;
  local profile=$3;
  local model=$4;

  echo "Generating $name: $iset $profile $model"
  HSAILTestGen -package=single -iset=$iset -model=$model -profile=$profile tmp
  HSAILasm -disassemble tmp/hsail_tests_p.brig
  mv tmp/hsail_tests_p.hsail $name.hsail
}

generate_all() {
  local name=$1
  local iset=$2
  local suffix=$3

  for profile in full base; do
    for model in large small; do
      generate ${name}-${profile}-${model}-${suffix} $iset $profile $model
    done
  done
}

generate_all CORE CORE $suffix
generate_all IMAGE IMAGE $suffix
generate_all amd_gcn amd:gcn $suffix
generate_all amd_mipmap amd:mipmap $suffix
