package main

import (
	"bytes"
	"testing"
)

func TestWriteRandom(t *testing.T) {
	cases := []struct {
		name    string
		length  int64
		bufsize int
		wantLen int64
	}{
		{"zero length", 0, 4096, 0},
		{"negative length", -1, 4096, 0},
		{"small write", 16, 4096, 16},
		{"exact buffer", 4096, 4096, 4096},
		{"multi-buffer", 9000, 4096, 9000},
		{"small buffer", 100, 7, 100},
		{"zero bufsize uses default", 64, 0, 64},
	}

	for _, tc := range cases {
		t.Run(tc.name, func(t *testing.T) {
			var buf bytes.Buffer
			err := writeRandom(&buf, tc.length, tc.bufsize)
			if err != nil {
				t.Fatalf("unexpected error: %v", err)
			}
			if got := int64(buf.Len()); got != tc.wantLen {
				t.Errorf("wrote %d bytes, want %d", got, tc.wantLen)
			}
		})
	}
}

func TestWriteRandomPrintable(t *testing.T) {
	var buf bytes.Buffer
	if err := writeRandom(&buf, 1024, 256); err != nil {
		t.Fatalf("unexpected error: %v", err)
	}
	for i, b := range buf.Bytes() {
		if b < 32 || b > 125 {
			t.Errorf("byte %d = %d, want printable ASCII (32–125)", i, b)
		}
	}
}
