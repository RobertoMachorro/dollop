# Dollop

Creates files with pseudo-random content (dollop).

[![CircleCI](https://circleci.com/gh/RobertoMachorro/dollop.svg?&style=shield&circle-token=84396ee427dea0650309f102a42c4a25a2889a07)][circleci]

[circleci]: https://circleci.com/gh/RobertoMachorro/dollop

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

Copyright (C) 2018 Roberto Machorro.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

## Building from Git

```
$ aclocal
$ autoconf
$ automake --add-missing
$ ./configure
$ make
$ sudo make install
```

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
