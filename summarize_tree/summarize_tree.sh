#!/usr/bin/env bash
HOME=$(pwd)
PATH="$1"
cd "$PATH" || exit

FILE_NUM=$( /usr/bin/find . -type f | /usr/bin/wc -l) 
DIR_NUM=$( /usr/bin/find . -type d | /usr/bin/wc -l) 

echo "There were" "$DIR_NUM" "directories."
echo "There were" "$FILE_NUM" "regular files."

cd "$HOME" || exit 
