find . -type f -name '*.o' -exec rm {} +
find . -type f -name '*.cpp' -exec rm {} +

find . -type f -name '*.hpp' -exec cp '{}' ./headers/ \;