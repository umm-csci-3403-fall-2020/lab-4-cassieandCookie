#!/usr/bin/env bash
HOME=$(pwd)
PATH="$1"
cd "$PATH" || exit

FILE=$(find . -type f | wc) 
DIR=$(find . -type d | wc) 

echo "There were" $DIR "directories."
echo "There were" $FILE "regular files."

cd "$HOME" || exit 
