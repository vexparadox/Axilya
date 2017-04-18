#!/bin/bash
mkdir temp
cd temp
echo "This script will download and install g++, libGL, SDL2, FreeType, libCurl, SDL2_ttf and SDL2_mixer"
echo "It may require your password to login or a response to confirm downloads."
#apts
echo "Updating repos..."
sudo apt-get -qq update
echo "Checking for g++..."
sudo apt-get -qq -y install g++
echo "Checking for libgl-dev..."
sudo apt-get -qq -y install libgl-dev
#Download all the files
echo "Downloading freetype"
curl -Ls http://download.savannah.gnu.org/releases/freetype/freetype-2.7.tar.gz -o freetype-2.7.tar.gz
echo "Downloading libcurl"
curl -s https://curl.haxx.se/download/curl-7.53.1.tar.gz -o curl-7.53.1.tar.gz
echo "Downloading SDL2.0.5"
curl -s https://libsdl.org/release/SDL2-2.0.5.tar.gz -o SDL2-2.0.5.tar.gz
echo "Downloading SDL2 ttf"
curl -s https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-2.0.14.tar.gz -o SDL2_ttf-2.0.14.tar.gz
echo "Downloading SDL2 mixer"
curl -s https://www.libsdl.org/projects/SDL_mixer/release/SDL2_mixer-2.0.1.tar.gz -o SDL2_mixer-2.0.1.tar.gz

#install free type
echo "Installing FreeType"
tar -xzf freetype-2.7.tar.gz
cd freetype-2.7
./configure --quiet
make --quiet && sudo make install
cd ../
#install libcurl
echo "Installing libCurl"
tar -xzf curl-7.53.1.tar.gz
cd curl-7.53.1
./configure --quiet
make --quiet && sudo make install
cd ../
#install SDL2
echo "Installing SDL2"
tar -xzf SDL2-2.0.5.tar.gz
cd SDL2-2.0.5
./configure --quiet
make --quiet && sudo make install
cd ../
#install SDL2 ttf
echo "Installing SDL2_ttf"
tar -xzf SDL2_ttf-2.0.14.tar.gz
cd SDL2_ttf-2.0.14
./configure --quiet
make --quiet && sudo make install
cd ../
#install SDL2 mixer
echo "Installing SDL2_mixer"
tar -xzf SDL2_mixer-2.0.1.tar.gz
cd SDL2_mixer-2.0.1
./configure --quiet
make --quiet && sudo make install
cd ../../
echo "Complete, cleaning up"
rm -rf temp