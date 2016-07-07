#!/bin/bash

set -e

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

  for profile in full base; do
    for model in large small; do
      generate ${name}-${profile}-${model} $iset $profile $model
    done
  done
}

generate_all CORE CORE
generate_all IMAGE IMAGE
generate_all amd_gcn amd:gcn
generate_all amd_mipmap amd:mipmap
