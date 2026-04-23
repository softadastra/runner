# Softadastra Runner

Simple command runner built with Vix.cpp.

Softadastra Runner is a small console application from Softadastra that executes system commands through `vix::process`.

It is designed to stay simple, readable, and extensible.

## What it does

Softadastra Runner lets you:

- read a command from the terminal
- parse the program name and arguments
- execute the command with `vix::process`
- capture `stdout`
- capture `stderr`
- display the final exit code

## Why this project exists

Softadastra Runner is a practical example of how to build a clean console application on top of Vix.cpp.

It shows how to structure a small CLI project with:

- clear separation of responsibilities
- a small core layer
- an infrastructure layer built on Vix
- a simple interactive loop

## Project structure

```text
runner/
├── CMakeLists.txt
├── LICENSE
├── README.md
├── .gitignore
├── include/
│   └── softadastra/
│       └── runner/
│           ├── app/
│           │   └── RunnerApp.hpp
│           ├── cli/
│           │   ├── Console.hpp
│           │   ├── InputParser.hpp
│           │   └── Prompt.hpp
│           ├── core/
│           │   ├── CommandRequest.hpp
│           │   ├── CommandResult.hpp
│           │   └── RunnerService.hpp
│           ├── infrastructure/
│           │   └── VixProcessExecutor.hpp
│           └── utils/
│               └── StringUtils.hpp
├── src/
│   ├── main.cpp
│   ├── app/
│   │   └── RunnerApp.cpp
│   ├── cli/
│   │   ├── Console.cpp
│   │   ├── InputParser.cpp
│   │   └── Prompt.cpp
│   ├── core/
│   │   └── RunnerService.cpp
│   ├── infrastructure/
│   │   └── VixProcessExecutor.cpp
│   └── utils/
│       └── StringUtils.cpp
├── tests/
│   ├── test_basic.cpp
│   └── test_cli.cpp
└── examples/
    └── demo.txt
```

## Design

Softadastra Runner uses a simple layered design:

| Layer | Responsibility |
|-------|---------------|
| `app` | application orchestration |
| `cli` | prompt, input, and output |
| `core` | command request, result, and service logic |
| `infrastructure` | execution through `vix::process` |
| `utils` | small reusable helpers |

This keeps `main()` minimal and makes the code easier to extend later.

## Requirements

- C++20
- CMake 3.20+
- Vix.cpp installed and available through CMake

## Build

```bash
vix build
```

## Run

```bash
vix run
```

## Example

```
> echo hello
hello
[exit code: 0]

> pwd
/home/user/runner
[exit code: 0]

> ls
build-ninja
include
src
tests
[exit code: 0]

> exit
```

## Notes

- The first token is treated as the program name.
- The remaining tokens are treated as arguments.
- Runner does not implement full shell parsing.
- Runner does not interpret pipes, redirects, or shell operators by itself.
- If you type a command that does not exist, execution fails with an error from the process layer.

Example:

```
> hi
exec failed: No such file or directory
[exit code: 1]
```

## Tests

Build the project, then run tests with CTest:

```bash
ctest --test-dir build-ninja --output-on-failure
```

## Purpose

Runner is intentionally small. It is meant to be:

- a learning project
- a clean Vix.cpp example
- a base for future Softadastra console tools

## License

MIT
