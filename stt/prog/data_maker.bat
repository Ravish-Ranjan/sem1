#!/bin/bash

mkdir -p data

for i in {1..10}; do
  lines=$((RANDOM % 6 + 10))  # 10–15 lines
  {
    for ((j=1; j<=lines; j++)); do
      words=$((RANDOM % 3 + 8))  # 8–10 words
      line=""
      for ((k=1; k<=words; k++)); do
        # random word 3–6 letters
        word=$(tr -dc 'a-z' < /dev/urandom | head -c $((RANDOM % 4 + 3)))
        line+="$word "
      done
      echo "${line:0:30}"   # trim line to ~30 chars
    done
  } > "data/data${i}.txt"
done
