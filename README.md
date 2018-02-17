# Dollop

Creates files with pseudo-random content (dollop).

## Usage

**PENDING:** Instructions and sample command line code.

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
