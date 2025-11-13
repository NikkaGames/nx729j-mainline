#!/usr/bin/env bash
set -euo pipefail

EXP="$1"
ACT="$2"

# Normalize config: convert "# CONFIG_X is not set" -> "CONFIG_X=n"
normalize_config() {
  local file="$1"
  while IFS= read -r line || [ -n "$line" ]; do
    line="${line%%$'\r'}"  # remove CR if any
    line="${line%"${line##*[![:space:]]}"}"  # trim trailing spaces
    if [[ "$line" =~ ^#\ CONFIG_([A-Z0-9_]+)\ is\ not\ set$ ]]; then
      echo "CONFIG_${BASH_REMATCH[1]}=n"
    elif [[ "$line" =~ ^CONFIG_[A-Z0-9_]+= ]]; then
      echo "$line"
    fi
  done < "$file"
}

# Read expected config
declare -A exp_map
while IFS== read -r key val; do
  exp_map["$key"]="$val"
done < <(normalize_config "$EXP")

# Read actual config
declare -A act_map
while IFS== read -r key val; do
  act_map["$key"]="$val"
done < <(normalize_config "$ACT")

# Compare
for key in "${!exp_map[@]}"; do
  if [[ -z "${act_map[$key]+_}" ]]; then
    echo "Missing:   $key (expected=${exp_map[$key]})"
  elif [[ "${exp_map[$key]}" != "${act_map[$key]}" ]]; then
    echo "Different: $key expected=${exp_map[$key]} actual=${act_map[$key]}"
  fi
done
