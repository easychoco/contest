if [ -e ./$1 ]; then
  echo $1 is already exist.
else
  echo create $
  cargo compete new $1
fi

echo opening $1 ...
cd $1
code . ./src/bin/*.rs
