<!-- Copilot / AI agent instructions for the `dollop` repo -->
# Dollop — AI contributor quick guide

Purpose: help an automated coding agent be immediately productive in this small C/autotools project.

- **Project type:** C command-line utility using GNU Autotools (see `configure.ac` and `Makefile.am`).
- **Build:** use Autotools to generate `configure`, then build.
  - Typical sequence from git: `aclocal && autoconf && automake --add-missing && ./configure && make` (see `README.md`).
  - Tarball builds have `./configure && make`.

- **Entry point:** `main.c` — arg parsing lives here using the bundled `argtable3` sources. See [main.c](main.c).
- **Core logic / API:** `dollout.c`/`dollout.h` implement the output/random-data helpers used by `main.c`. See [dollout.c](dollout.c) and [dollout.h](dollout.h).

- **Binary target:** `dollop` (defined in `Makefile.am` via `bin_PROGRAMS`). See [Makefile.am](Makefile.am).

- **Conventions and idioms to follow (observable in code):**
  - CLI parsing uses `argtable3.c`/`argtable3.h` bundled in the tree — modify carefully and maintain API compatibility with existing `main.c` usage.
  - Small, single-file utilities: prefer small, focused changes (adds in `main.c` or `dollout.c`) rather than large refactors.
  - Error handling uses return codes (0 success / non-zero error). New helpers should follow this pattern.
  - Output helpers are centralized in `dollout_*` functions — reuse them for file/stdout writing.

- **Build/test/debug workflow:**
  - Recreate the `configure` script when modifying build files: `aclocal && autoconf && automake --add-missing`.
  - Build: `./configure && make`.
  - Install locally: `sudo make install` (or use a local `--prefix` during `./configure`).
  - Debugging: build with `CFLAGS='-g -O0'` passed to `./configure` to enable `gdb` debugging.

- **Integration points & external deps:**
  - No external package dependencies; `argtable3` is included. The project expects POSIX stdio and srand/rand.

- **Safe change guidance for PRs:**
  - Keep CLI behavior backward compatible: `main.c` exposes `--length`, `--buffer-size`, `--output`, `--help`, `--version`.
  - If extending CLI, add options via `argtable3` in `main.c` and document usage in `README.md`.
  - When touching build infra (`configure.ac`, `Makefile.am`) regenerate `configure` and ensure `make dist-gzip` still works.

- **Files to inspect first for any change:**
  - [main.c](main.c) — argument parsing and program flow
  - [dollout.c](dollout.c), [dollout.h](dollout.h) — output helpers
  - [argtable3.c](argtable3.c), [argtable3.h](argtable3.h) — argument library (bundled)
  - [README.md](README.md) — build and usage notes

If anything here is unclear or you want more detailed patterns (naming rules, style, or tests), tell me which area to expand. 
