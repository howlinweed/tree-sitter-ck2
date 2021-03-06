#!/bin/bash

set -e

# cd "$(dirname "$0")/.."
#
#
# # Clone npm/npm and check out a known sha
# repo=examples/npm
#
# if [ ! -d "$repo" ]; then
#   git clone https://github.com/npm/npm "$repo"
# fi
#
# pushd "$repo" && git fetch
# git reset --hard ee147fbbca6f2707d3b16f4fa78f4c4606b2d9b1
# popd

tree-sitter parse tests/*.ck2 -q

# # TODO: Fix known issues in known_failures.txt
# known_failures=$(cat script/known_failures.txt)
# examples_to_parse=$(
#   for example in $(find "$repo" -name '*.js'); do
#     if [[ ! $known_failures == *$example* ]]; then
#       echo $example
#     fi
#   done
# )
#
# echo $examples_to_parse | xargs -n 5000 tree-sitter parse -q
#
# skipped=$( echo $known_failures | wc -w )
# parsed=$( echo $examples_to_parse | wc -w )
# total=$((parsed+skipped))
# percent=$(bc -l <<< "100*$parsed/$total")
#
# printf "Successfully parsed %.2f%% of $repo (%d of %d files)\n" $percent $parsed $total
