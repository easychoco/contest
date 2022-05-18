#!/bin/sh

if [ ! -e ./"$1" ]; then
  echo "$1" is not exist.
  return
fi
 
if [ -e ./"$1"/"$2" ]; then
  echo "$2" is already exist.
else
  echo creating "$1"/"$2"...
  mkdir "$1"/"$2"
  cp ./template/_.py ./"$1"/"$2"/a.py
  cp ./template/_.py ./"$1"/"$2"/b.py
  cp ./template/_.py ./"$1"/"$2"/c.py
  cp ./template/_.py ./"$1"/"$2"/d.py
  cp ./template/_.py ./"$1"/"$2"/e.py
  cp ./template/_.py ./"$1"/"$2"/f.py
  cp ./template/_.py ./"$1"/"$2"/g.py
  cp ./template/_.py ./"$1"/"$2"/h.py
  cp ./template/in ./"$1"/"$2"/in
  echo 'done'
fi

echo opening "$1"/"$2" ...
code . ./_tips.py ./"$1"/"$2"/in ./"$1"/"$2"/*.py
echo 'done'
