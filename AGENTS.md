# Agent Guidelines

## Project Overview
- **dollop** is a Go command-line utility that generates pseudo-random content to stdout or a file.
- Migrated from a legacy C/autotools implementation; no C code remains.
- No external Go module dependencies — standard library only.

## Stack
- Language: Go
- Module: `github.com/RobertoMachorro/dollop` (see `go.mod`)

## Project Rules
- Prefer standard library where possible.
- Keep CLI flags backward compatible: `-l/--length`, `-b/--buffer-size`, `-o/--output`, `-h/--help`, `-V/--version`.
- Error handling: print to `stderr` and exit non-zero via `os.Exit(n)`.

## Project Structure
- Root docs live in `README.md` and `AGENTS.md`. `CLAUDE.md` refers to `AGENTS.md`.
- Source code is expected to be Go.
- Tests should live next to the code they cover using `_test.go` filenames (e.g., `main_test.go`).
- No unit tests currently exist — add `_test.go` files and use `go test ./...` when adding tests.

## Key Files
- `main.go` — CLI entry point and random content generator (`flag`, `math/rand`, `io`, `os`)
- `go.mod` — module definition
- `Makefile` — convenience build targets
- `README.md` — user-facing build and usage notes
- `.github/workflows/build.yml` — CI build

## Build & Run
- Build: `go build -o dollop .` or `make build`
- Install: `go install .` (preferred over `make install`; see Makefile note below)
- Debug build: `go build -gcflags "all=-N -l" -o dollop .`; step-through with Delve (`dlv`)

> **Makefile note:** the `install` target uses `$(GOBIN)/$(BINARY)` — if `GOBIN` is unset this
> silently installs to `/dollop`. Prefer `go install .` which handles `GOBIN`/`GOPATH` correctly.

## Coding Style
- Use tabs for all code formatting and indentation.
- Use `gofmt` formatting and standard Go style.
- Prefer small, testable functions and explicit error handling.
- Use `camelCase` for variables, `PascalCase` for exported identifiers, and `SNAKE_CASE` only for env vars.
- Keep edits minimal and avoid adding new dependencies without discussion.

## Agentic Commands Allowed
- go mod tidy
- gofmt -w .
- go test ./...
- go test -race ./...
- go vet ./...
- golangci-lint run

## Testing
- Use Go's `testing` package for unit tests.
- Name tests `TestXxx` and table-driven tests with clear case names.
- Run `go test ./...` before opening a PR.

## CI & Release
- GitHub Actions workflows: `build.yml` (build).
- If changing the build, update workflow files accordingly.
- Run CI locally with `act` or by pushing a branch.

## Git Guidelines
- Commit messages in history are short, descriptive, and start with a capital letter (e.g., "Adding standard gitignore.").
- PRs should describe the change, reference any related issue, and include steps to verify.
- Do not auto-commit, only when prompted.
