#!/bin/sh

if [ ! -e "$REPOSITORY_ROOT"/cpp/"$1" ]; then
  echo "$1" is not exist.
  return
fi

TARGET_CONTEST_FOLDER="$REPOSITORY_ROOT"/cpp/"$1"/"$2"
CPP_TEMPLATE_PATH="$REPOSITORY_ROOT"/cpp/template
CONTEST_NAME_PATH="${1}/${2}"

if [ -e "$TARGET_CONTEST_FOLDER" ]; then
  echo "$2" is already exist.
else
  echo creating "$CONTEST_NAME_PATH"...
  mkdir -p "$TARGET_CONTEST_FOLDER"
  cp "$CPP_TEMPLATE_PATH"/_.cpp "$TARGET_CONTEST_FOLDER"/a.cpp
  cp "$CPP_TEMPLATE_PATH"/_.cpp "$TARGET_CONTEST_FOLDER"/b.cpp
  cp "$CPP_TEMPLATE_PATH"/_.cpp "$TARGET_CONTEST_FOLDER"/c.cpp
  cp "$CPP_TEMPLATE_PATH"/_.cpp "$TARGET_CONTEST_FOLDER"/d.cpp
  cp "$CPP_TEMPLATE_PATH"/_.cpp "$TARGET_CONTEST_FOLDER"/e.cpp
  cp "$CPP_TEMPLATE_PATH"/_.cpp "$TARGET_CONTEST_FOLDER"/f.cpp
  cp "$CPP_TEMPLATE_PATH"/_.cpp "$TARGET_CONTEST_FOLDER"/g.cpp
  cp "$CPP_TEMPLATE_PATH"/_.cpp "$TARGET_CONTEST_FOLDER"/h.cpp
  cp "$CPP_TEMPLATE_PATH"/in "$TARGET_CONTEST_FOLDER"/in
  echo 'done'
fi

echo opening "$CONTEST_NAME_PATH" ...
code $REPOSITORY_ROOT/cpp \
  $REPOSITORY_ROOT/cpp/_tips.cpp \
  "$TARGET_CONTEST_FOLDER"/in \
  "$TARGET_CONTEST_FOLDER"/*.cpp

echo 'done'
