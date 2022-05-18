#!/bin/sh

if [ -e "mono/${1}.cpp" ]; then
  echo "$1" is already exist.
else
  echo create mono/"$1"
  cp template/_.cpp "mono/${1}.cpp"
fi

echo opening mono/"$1"...
code . ./_tips.cpp mono/in "mono/${1}.cpp"
echo done.
