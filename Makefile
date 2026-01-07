## Simple Makefile for building the Go `dollop` CLI

BINARY := dollop
PKG := .

.PHONY: all build install clean

all: build

build:
	go build -o $(BINARY) $(PKG)

install: build
	install -m 0755 $(BINARY) $(GOBIN)/$(BINARY)

clean:
	rm -f $(BINARY)
