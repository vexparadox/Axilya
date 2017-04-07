# Axilya v0.9.5

A 2D Game Engine Library written in C++ by William Meaton.

See the examples and [wiki](http://axilya.com/wiki) for a better idea of what's happening.

It's recomended you download as a zip or go to the releases page.

Docs: http://axilya.com/docs

Features: http://axilya.com/about.php

## Compiling+installing on Linux+OSX

A quick list of [dependencies](https://github.com/vexparadox/Axilya/wiki/Dependencies):

For OSX you'll need: `g++`, `make`, `libcurl`, `tar` and `SDL`(see below). These can be installed using `xcode-select --install` in your Terminal. They're also install when you install xCode.

For Linux you'll need: `g++`, `make`, `libcurl`, `tar` and `SDL`. All but SDL are available via `apt-get`, see the commands below for how to install SDL.

There are a few commands you can use to compile and install.

To install SDL2:
```Shell
	sudo make sdl
```

To build the library, install and build examples (reccomended):
```Shell
	make all
```

To just install use:

```Shell
	make install
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

## Compiling+installing on Windows

To install Axilya on please see start on this [wiki](http://axilya.com/wiki/index.php?title=Downloading) page.



## Other

To see the initial production of this project see: https://github.com/vexparadox/axInitial