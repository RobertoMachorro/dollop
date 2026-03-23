## Simple Makefile for building the Go `dollop` CLI

BINARY := dollop
PKG := .

.PHONY: all build install clean

all: build

build:
	go build -o $(BINARY) $(PKG)

install:
	go install .

clean:
	rm -f $(BINARY)
