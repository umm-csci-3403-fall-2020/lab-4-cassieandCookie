#!/usr/bin/env bash
HOME=$(pwd)
TREE_PATH="$1"
cd "$TREE_PATH" || exit

FILE_NUM=$( find . -type f | wc -l) #find . means finding within the current directory, -type f searches for files, this is piped into wc -l which counts the number of files
DIR_NUM=$( find . -type d | wc -l) #find . means finding within the current directory, -type f searches for directories, this is piped into wc -l which counts the number of directories 

echo "There were" "$DIR_NUM" "directories."
echo "There were" "$FILE_NUM" "regular files."

cd "$HOME" || exit 
