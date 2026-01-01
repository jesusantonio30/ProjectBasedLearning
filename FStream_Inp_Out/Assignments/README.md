# Text Encoder/Decoder (ASCII Conversion Tool)

## Overview

This C++ program implements a simple text encoding and decoding utility that demonstrates basic file I/O operations and character-to-integer conversion.

The program performs the following steps:

1. Prompts the user to enter multiple lines of text from standard input.
2. Reads input lines until the user enters an empty line (by pressing Enter on a blank line).
3. Writes the ASCII integer value of each character to a file named `secret_file.txt`, with values separated by spaces.
4. Immediately reads the numeric values back from the file.
5. Converts the integers back to characters and prints the reconstructed original text to the console.

This serves as a round-trip demonstration: text → ASCII numbers → file → numbers → original text.

## Features

- Multi-line text input with empty-line termination (no reliance on Ctrl+D).
- Efficient string handling using `std::move`.
- Proper use of `std::ofstream` and `std::ifstream` with RAII-scoped blocks.
- Comprehensive error checking for file opening and I/O operations.
- Preservation of original text (including spaces and punctuation) through ASCII encoding.

## Requirements

- C++11 or later compiler (uses standard library features such as `std::string`, `std::vector`, and range-based for loops).
- Standard C++ library (no external dependencies).

## Compilation

Compile the program with any compliant C++ compiler:

```bash
g++ -std=c++11 encoder.cpp -o text_encoder && ./text_encoder
