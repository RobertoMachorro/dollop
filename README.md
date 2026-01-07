![GitHub release (latest by date)](https://img.shields.io/github/v/release/RobertoMachorro/dollop)
![build](https://github.com/RobertoMachorro/dollop/workflows/build/badge.svg)

## Download

Please be aware that Git sources are based of the master branch and require GNU automake.

* [Download Git Source](https://github.com/RobertoMachorro/dollop/archive/v1.0.tar.gz)

* [Download v1.0](https://github.com/RobertoMachorro/dollop/releases/download/v1.0/dollop-1.0.tar.gz)

## Usage

Generating a dolloped file requires the size and name. Parameters can be given in GNU style or short style.
Invalid lengths will be treated as 0.

```
$ dollop --length=23000 --output=testfile.txt
$ dollop -l 23000 -o testfile.txt
```

If no output file is specified, the dollop is thrown to the standard output. This in turn can be piped or redirected.

```
$ dollop --length=23000 > testfile.txt
$ dollop --length=23000 | wc -c
```

Parameter reference is always available with the `--help` option.

```
$ dollop --help
```

## License

This software is licensed under [GNU GPLv3 or later](https://www.gnu.org/licenses/gpl-3.0.en.html). Please see the [LICENSE](https://raw.githubusercontent.com/RobertoMachorro/Moped/master/LICENSE) file for details.

![GNU GPLv3 Logo](https://www.gnu.org/graphics/gplv3-127x51.png)

## Building from Git

```
$ aclocal
$ autoconf
$ automake --add-missing
$ ./configure
$ make
$ sudo make install
```

## Building with Go (alternative)

This repository now includes a Go re-implementation of the `dollop` CLI.

Build with a Go toolchain (Go 1.18+ recommended):

```sh
 $ go build -o dollop ./cmd/dollop
 $ ./dollop --help
```

The Go binary (`./cmd/dollop`) is a drop-in CLI replacement for most use-cases; flags are the same (`-l/--length`, `-b/--buffer-size`, `-o/--output`, `-h/--help`, `-V/--version`).


## Building from Tarball

```
$ ./configure
$ make
$ sudo make install
```

## Build Distribution

```
$ make dist-gzip
```

## Build Cleanup

```
$ make distclean-am
```

## Dependencies

Dollop builds on any standard Posix environment. It has been tested under Linux and MacOS.
`GNU automake and autoconf` where used to make configure and Makefile files.
It contains the argtable3 library in source, including license file.

```
Argtable is Copyright (C) 1998-2001,2003-2011 Stewart Heitmann.
Parts are Copyright (C) 1989-1994, 1996-1999, 2001, 2003
  Free Software Foundation, Inc.

Argtable was written by Stewart Heitmann <sheitmann@users.sourceforge.net>

Argtable is now maintained by Tom G. Huang <tomghuang@gmail.com>
The project homepage of argtable 3.x is http://www.argtable.org
The project homepage of argtable 2.x is http://argtable.sourceforge.net/
```
