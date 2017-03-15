# Axilya v0.9.0

A 2D Game Engine Library written in C++ by William Meaton.

See the examples and wiki for a better idea of what's happening.

Note that the repo is a fair sight larger than the final install because of example projects and SDL source files included.

Docs: http://axilya.com/docs

## Compiling

You'll need: g++, make, libcurl(comes with all OSX and most Linux) and unzip

You can either run the make script, this will install SDL2.0.5, build the library and all examples.

```Shell
	sudo make all
```

To just install SDL2:
```Shell
	sudo make sdl
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
	sudo make lib
```

To remove the install use:

```Shell
	sudo make cleaninstall
```


You can also build just the library using xCode using the project file included.


## Other

To see the initial production of this project see: https://github.com/vexparadox/axInitial