# Binary File Copy Utility in C++

## Overview

This program demonstrates a simple, efficient method for copying the exact contents of a binary file (such as an image) in C++. It reads the entire source file into memory using `std::istreambuf_iterator<char>` and writes the data to a new file using unformatted output. The use of binary mode and stream buffer iterators ensures that no character translations occur and that the copy is byte-for-byte identical to the original.

The example copies a WebP image file named `ex_img.webp` to `copy_ex_img.webp`, but the technique is applicable to any binary file.

## Features

- Opens input and output files in binary mode (`std::ios::binary`).
- Reads the entire file content directly from the underlying stream buffer, avoiding formatted input overhead.
- Stores the raw bytes in a `std::vector<char>`.
- Writes the data in a single operation using `std::ostream::write`.
- Performs basic error checking for file opening and write operations.
- Uses only standard C++ library facilities (no third-party dependencies).
