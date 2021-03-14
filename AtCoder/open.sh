if [ ! -e ./$1 ]; then
  echo $1 is not exist.
  return
fi
 
if [ -e ./$1/$2 ]; then
  echo $2 is already exist.
else
  echo create $1/$2
  cp -r ./template ./$1/$2
fi

echo opening $1/$2 ...
code . ./_tips.cpp ./$1/$2/in ./$1/$2/*.cpp
