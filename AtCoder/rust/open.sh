if [ -e ./$1 ]; then
  echo $1 is already exist.
else
  echo create $1
  cargo compete new $1
fi

echo opening $1 ...
code _tips.rs $1 $1/src/bin/*.rs
