# Axilya v0.9.7

A 2D Game Engine Library written in C++ by [William Meaton](http://willmeaton.com).

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

See the examples and [wiki](http://axilya.com/wiki) for a better idea of what's happening.

It's recomended you download as a zip or go to the releases page.

Docs: http://axilya.com/docs

Features: http://axilya.com/about.php

## Linux+macOS Quick Install

Open your terminal and type:

```Shell
	curl http://axilya.com/install.sh | sh
```

Note that macOS developers may have to install development tools first.

## Linux+macOS Manual Install

For macOS you'll need: `g++`, `make`, `libcurl`, `tar`. These can be installed using `xcode-select --install` in your Terminal. They're also install when you install xCode. Axilya comes with a script to install SDL2.

For Linux you'll need: `g++`, `make`, `libcurl`, `tar` and `SDL`. Axilya comes with a Shell script to install all of these and SDL2.

There are a few commands you can use to compile and install.

If you get stuck, see the [wiki](http://axilya.com/wiki/index.php?title=Installing) for help.

To install SDL2:
```Shell
	sudo make depends
```

To build the library, install and build examples (reccomended):
```Shell
	make all
```

To just install use:

```Shell
	sudo make install
```

To just make the examples:
```Shell
	make examples
```

To just build the library use:
```Shell
	make lib
```

To remove the install use:

```Shell
	make cleaninstall
```
If you get issues with permissions it might just be that your /usr/local/lib or /usr/local/include folders haven't been initialised, you can either run these commands in `sudo` mode or create the folders and try again.

## Windows Manual Install

To install Axilya on please see start on this [wiki](http://axilya.com/wiki/index.php?title=Downloading) page.

## Other

To see the initial production of this project see: https://github.com/vexparadox/axInitial