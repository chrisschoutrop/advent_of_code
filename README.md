C++ implementations for [Advent of Code 2022](https://adventofcode.com/)

To compile on Linux:

1. Clone the repository:

```bash
   git clone git@github.com:chrisschoutrop/advent_of_code.git
```

2. Make a build folder, and build

```bash
   mkdir build
   cd build
   cmake ..
   make -j
```

The samples can be run by changing directory, inside build, to that specific puzzle. This is needed because the file paths are relative. So to run puzzle 1:

```bash
   cd 1
   ./1
```

Tests can be run with
```bash
   ctest
```
