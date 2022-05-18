#!/bin/sh

if [ -e "mono/${1}.py" ]; then
  echo "$1" is already exist.
else
  echo create mono/"$1"
  cp template/_.py "mono/${1}.py"
fi

echo opening mono/"$1".py...
code . ./_tips.py mono/in "mono/${1}.py"
echo done.
