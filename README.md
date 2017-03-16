# Axilya v0.9.5

A 2D Game Engine Library written in C++ by William Meaton.

See the examples and wiki for a better idea of what's happening.

Note that the repo is a fair sight larger than the final install because of example projects and SDL source files included.

Docs: http://axilya.com/docs

Features: http://axilya.com/about.php

## Compiling+installing on Linux+OSX

A quick list of [dependencies](https://github.com/vexparadox/Axilya/wiki/Dependencies):

For OSX you'll need: `g++`, `make`, `libcurl`, `unzip` and `SDL`(see below). These can be installed using `xcode-select --install` in your Terminal. They're also install when you install xCode.

For Linux you'll need: `g++`, `make`, `libcurl`, `unzip` and `SDL`. All but SDL are available via `apt-get`, see the [dependencies](https://github.com/vexparadox/Axilya/wiki/Dependencies) page for how to install SDL.

There are a few commands you can use to compile and install.

To install SDL2 (OSX only):
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


## Other

To see the initial production of this project see: https://github.com/vexparadox/axInitial