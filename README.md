# Text Search & Convert Tool
This C program searches through text files in a certain directory for a certain word to convert it's characters to uppercase. Then, it generates a report to show how many changes occurred and sorts them by frequency.

## Features

- Recursively processes all `.txt` files in the current directory
- Case-insensitive word search
- In-place file modification (converts matched words to uppercase)
- Sorted report showing files with the most changes first
- Memory-efficient file processing

## Building
```bash
make
```

## Usage
```bash
./textsearch <word_to_search>
```

### Example
```bash
./textsearch hello
```

This will:
1. Search all `.txt` files in the current directory for "hello" (case-insensitive)
2. Convert all occurrences to "HELLO"
3. Display a report showing which files were modified and how many changes were made

## Sample Output
```
Showing the report
Showing the files ordered/sorted by number of changes (most changes first):
15 ./document1.txt
8 ./notes.txt
3 ./readme.txt
Thanks for using this program
```

## Project Structure

- `src/main.c` - Entry point and directory traversal
- `src/traversal.c` - File opening and processing coordination
- `src/text.c` - Core text processing and word replacement
- `src/report.c` - Change tracking and report generation
- `include/` - Header files

## Requirements

- GCC compiler
- POSIX-compliant system (for dirent.h)

## Warning

⚠️ This program modifies files in-place. Make sure to backup important files before running.

## Author

Najlaa Achouhal
