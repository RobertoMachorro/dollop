package main

import (
	"flag"
	"fmt"
	"io"
	"math/rand"
	"os"
	"strconv"
	"time"
)

const version = "1.0"

func usage() {
	fmt.Fprintf(os.Stdout, "Usage: dollop [options]\n")
	flag.PrintDefaults()
	fmt.Fprintln(os.Stdout, "\nCreates files with pseudo-random content (dollop). Generated content is sent to standard output, unless an output file is given. Invalid lengths will be treated as 0.")
}

func main() {
	var lengthStr string
	var bufsize int
	var outname string
	var showHelp bool
	var showVersion bool

	flag.StringVar(&lengthStr, "l", "", "final file length in bytes, default 1k")
	flag.StringVar(&lengthStr, "length", "", "final file length in bytes, default 1k")
	flag.IntVar(&bufsize, "b", 4096, "write buffer size in bytes, default 4k")
	flag.IntVar(&bufsize, "buffer-size", 4096, "write buffer size in bytes, default 4k")
	flag.StringVar(&outname, "o", "", "output file, defaults to console")
	flag.StringVar(&outname, "output", "", "output file, defaults to console")
	flag.BoolVar(&showHelp, "h", false, "display this help and exit")
	flag.BoolVar(&showHelp, "help", false, "display this help and exit")
	flag.BoolVar(&showVersion, "V", false, "display version info and exit")
	flag.BoolVar(&showVersion, "version", false, "display version info and exit")

	flag.Usage = usage
	flag.Parse()

	if showHelp {
		usage()
		os.Exit(0)
	}
	if showVersion {
		fmt.Printf("Dollop %s\nCopyright (C) 2018 Roberto Machorro.\n", version)
		os.Exit(0)
	}

	var length int64 = 1024
	if lengthStr != "" {
		v, err := strconv.ParseInt(lengthStr, 10, 64)
		if err != nil {
			fmt.Fprintf(os.Stderr, "Invalid length: %v\n", err)
			os.Exit(1)
		}
		length = v
	}

	rand.Seed(time.Now().UnixNano())

	var out io.Writer
	var f *os.File
	if outname != "" {
		var err error
		f, err = os.Create(outname)
		if err != nil {
			fmt.Fprintf(os.Stderr, "Unable to create output file named %s.\n\n", outname)
			os.Exit(1)
		}
		defer f.Close()
		out = f
	} else {
		out = os.Stdout
	}

	if err := writeRandom(out, length, bufsize); err != nil {
		fmt.Fprintf(os.Stderr, "%v\n", err)
		os.Exit(1)
	}
}

func writeRandom(w io.Writer, length int64, bufsize int) error {
	if length <= 0 {
		return nil
	}
	if bufsize <= 0 {
		bufsize = 4096
	}

	buf := make([]byte, bufsize)
	var written int64
	for written < length {
		towrite := bufsize
		rem := int(length - written)
		if rem < towrite {
			towrite = rem
		}
		for i := 0; i < towrite; i++ {
			buf[i] = byte(rand.Intn(94) + 32)
		}
		n, err := w.Write(buf[:towrite])
		if err != nil {
			return err
		}
		if n != towrite {
			return fmt.Errorf("short write: %d of %d", n, towrite)
		}
		written += int64(n)
	}
	return nil
}
