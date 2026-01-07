<!-- Copilot / AI agent instructions for the `dollop` repo -->
# Dollop — AI contributor quick guide (Go)

Purpose: help an automated coding agent be immediately productive in the current Go-based `dollop` CLI.

- **Project type:** Go command-line utility. The code was migrated from a C/autotools implementation to Go; legacy C files were removed.
- **Build:** use the Go toolchain. Primary entry: `main.go` at repository root (module root `go.mod`). A simple `Makefile` is included for convenience.
  - Typical build: `go build -o dollop .` or `make build`.

- **Entry point:** `main.go` — CLI parsing is implemented with the standard `flag` package. See [main.go](main.go).
- **Core logic:** the CLI and output generator are implemented in Go (random content generation uses `math/rand`). No separate helper C library remains.

- **Binary target:** `dollop` (built from `.`). See the `Makefile` at repository root for targets.

- **Conventions and idioms to follow (observable in code):**
  - Use the standard library (`flag`, `io`, `os`, `math/rand`) for CLI and I/O.
  - Preserve existing flag names and short forms (`-l/--length`, `-b/--buffer-size`, `-o/--output`, `-h/--help`, `-V/--version`) for backward compatibility.
  - Error handling: print to `stderr` and exit with non-zero code using `os.Exit(n)`.
  - Keep changes small and focused: this is a tiny utility; prefer adding helpers in `main.go` or a new package rather than large refactors.

- **Build/test/debug workflow:**
  - Build locally: `go build -o dollop .` or `make build`.
  - Install: `go install .` or `make install` (Makefile uses `$(GOBIN)` if set).
  - Debugging: build with `-gcflags "all=-N -l"` or use Delve (`dlv`) for step-through debugging.
  - No unit tests currently included; add `_test.go` files and use `go test ./...` if adding tests.

- **CI & release:**
  - GitHub Actions workflows were updated to use `actions/setup-go` and `go build`. See `.github/workflows/build.yml` and `.github/workflows/codeql-analysis.yml`.
  - If changing the build, update workflows accordingly and run CI locally with `act` or by pushing a branch.

- **Integration points & external deps:**
  - No external Go module dependencies currently declared beyond the standard library; check `go.mod` if you add modules.
  - The binary is self-contained; packaging or release automation is handled via CI if added.

- **Safe change guidance for PRs:**
  - Keep CLI flags compatible. Update `README.md` when changing user-facing behavior.
  - If adding packages, update `go.mod` and run `go mod tidy`.
  - Run `go vet` and `golangci-lint` (if enabled in CI) before opening PRs.

- **Files to inspect first for any change:**
  - [main.go](main.go) — CLI entry and generator
  - [go.mod](go.mod) — module definition
  - [Makefile](Makefile) — convenience build targets
  - [README.md](README.md) — user-facing build and usage notes
  - [.github/workflows/build.yml](.github/workflows/build.yml) and [.github/workflows/codeql-analysis.yml](.github/workflows/codeql-analysis.yml) — CI behavior

If anything here is unclear or you want more detailed patterns (naming rules, style, test strategy, or release automation), tell me which area to expand.
