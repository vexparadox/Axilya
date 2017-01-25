mkdir headers
mkdir lib
find . -name *.o -exec rm {} +
find ./axsrc/ -type f -name '*.hpp' -exec cp '{}' ./headers/ \;
find ./axsrc/ -type f -name '*.h' -exec cp '{}' ./headers/ \;
make lib
cp ./libaxilya.a ./lib/


