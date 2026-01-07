![GitHub release (latest by date)](https://img.shields.io/github/v/release/RobertoMachorro/dollop)
![build](https://github.com/RobertoMachorro/dollop/workflows/build/badge.svg)

## Download

Please be aware that earlier versions used GNU Autotools; this repository
now provides a Go implementation of the CLI (see `main.go`).

* [Download Release Source](https://github.com/RobertoMachorro/dollop/releases)

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

## Building, Installing and Running

The project is implemented in Go. Build with a Go toolchain (Go 1.18+ recommended):

```sh
go build -o dollop
go install
dollop --help
```

Or use the included `Makefile`:

```sh
make build
./dollop --help
```

## Dependencies

Dollop is implemented in Go and requires a Go toolchain to build. It has
been tested on Linux and macOS. The legacy Argtable3 C sources were removed
when the CLI was migrated to Go; original sources remain in repository
history if you need them.
