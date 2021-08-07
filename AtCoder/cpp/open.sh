if [ ! -e ./$1 ]; then
  echo $1 is not exist.
  return
fi
 
if [ -e ./$1/$2 ]; then
  echo $2 is already exist.
else
  echo creating $1/$2...
  mkdir $1/$2
  cp ./template/_.cpp ./$1/$2/a.cpp
  cp ./template/_.cpp ./$1/$2/b.cpp
  cp ./template/_.cpp ./$1/$2/c.cpp
  cp ./template/_.cpp ./$1/$2/d.cpp
  cp ./template/_.cpp ./$1/$2/e.cpp
  cp ./template/_.cpp ./$1/$2/f.cpp
  cp ./template/_.cpp ./$1/$2/g.cpp
  cp ./template/_.cpp ./$1/$2/h.cpp
  cp ./template/in ./$1/$2/in
  echo 'done'
fi

echo opening $1/$2 ...
code . ./_tips.cpp ./$1/$2/in ./$1/$2/*.cpp
echo 'done'
