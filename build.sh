cppfiles=$(find . -name *.cpp -exec echo {} +)
objects=""
for c in $cppfiles 
do
	$objects=$objects${c/".cpp"/".o"}
done
echo $objects

directories=$(find ./gamesrc -type d -exec echo {} +)
directoriesInclude=""
for d in $directories
do
	directoriesInclude=$directoriesInclude"-I"$d" "
done

g++ $cppfiles -framework SDL2 -o -c axilya -std=c++11 -g $directoriesInclude