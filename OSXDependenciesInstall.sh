#!/bin/bash
mkdir temp
cd temp
echo "This script will download and install SDL2, SDL2 TTF and SDL2 Mixer"
echo "Your password is required because we're installing to the system directory."
#download files
sudo echo "Downloading SDL2"
curl https://www.libsdl.org/release/SDL2-2.0.5.dmg -o SDL2-2.0.5.dmg
echo "Downloading SDL2 TTF"
curl https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-2.0.14.dmg -o SDL2_ttf-2.0.14.dmg
echo "Downloading SDL2 Mixer"
curl https://www.libsdl.org/projects/SDL_mixer/release/SDL2_mixer-2.0.1.dmg -o SDL2_mixer-2.0.1.dmg

#install sdl2
echo "Copying SDL2"
hdiutil attach -quiet -noverify SDL2-2.0.5.dmg
sudo cp -r /Volumes/SDL2/SDL2.framework /Library/Frameworks
echo "Copy complete"
diskutil eject /Volumes/SDL2
#install sdl2 TTF
echo "Copying SDL2 ttf"
hdiutil attach -quiet -noverify SDL2_ttf-2.0.14.dmg
sudo cp -r /Volumes/SDL2_ttf/SDL2_ttf.framework /Library/Frameworks
echo "Copy complete"
diskutil eject /Volumes/SDL2_ttf
#install sdl2 mixer
echo "Copying SDL2 mixer"
hdiutil attach -quiet -noverify SDL2_mixer-2.0.1.dmg
sudo cp -r /Volumes/SDL2_mixer/SDL2_mixer.framework /Library/Frameworks
echo "Copy complete"
diskutil eject /Volumes/SDL2_mixer
cd ../
rm -rf temp
echo "Install complete."