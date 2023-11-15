# cpx - C Project Boilerplate Generator

## Overview

`cpx` is a simple command-line utility that generates a basic boilerplate structure for C projects. It creates directories for source code, headers, object files, tests, documentation, and a Makefile for build automation.

## Installation
## 1. Manual
Compile the `cpx` program using a C compiler (e.g., GCC):

```bash
gcc cpx.c -o cpx
```

Move the compiled executable to a directory in your system's PATH for global access:

```bash
sudo mv cpx /usr/local/bin/
```

## 2. Using Make
To use the Makefile, simply run the following commands in the terminal:

	make          # Builds the cpx executable
	sudo make install  # Installs cpx globally
	make clean    # Removes the cpx executable

## Usage

Generate a C project boilerplate with the following command:

```bash
cpx YourProjectName
```
Replace YourProjectName with the desired name for your project.
Directory Structure

The generated project structure will include the following directories:

    src/: Source code files (.c)
    include/: Header files (.h)
    obj/: Object files (.o)
    bin/: Executable file
    tests/: Test files
    docs/: Documentation files
    Makefile: Build automation file
    README.md: Project overview and instructions

## Customization

Feel free to modify the generated structure to suit the specific needs of your project. Update the Makefile, add more source files, or include additional documentation as required.

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Author
Calvin Kimani


## Acknowledgments

Inspired by npx and the need for a simple C project boilerplate generator.
