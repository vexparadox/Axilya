
find . -name *.o -exec rm {} +
find ./axsrc/ -type f -name '*.hpp' -exec cp -v '{}' ./AxilyaRelease/axsrc/ \;
find ./axsrc/ -type f -name '*.h' -exec cp -v '{}' ./AxilyaRelease/axsrc/ \;
cp ./gamesrc/CoreMain.h ./AxilyaRelease/axsrc/
echo "Copied headers"
echo "Building library..."
make lib
echo "Copying library..."
cp ./libaxilya.a ./AxilyaRelease/axsrc/
rm ./libaxilya.a
echo "Release build complete in AxilyaRelease"