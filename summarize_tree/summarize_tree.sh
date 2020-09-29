#!/usr/bin/env bash
HOME=$(pwd)
TREE_PATH="$1"
cd "$TREE_PATH" || exit

FILE_NUM=$( find . -type f | wc -l) 
DIR_NUM=$( find . -type d | wc -l) 

echo "There were" "$DIR_NUM" "directories."
echo "There were" "$FILE_NUM" "regular files."

cd "$HOME" || exit 
