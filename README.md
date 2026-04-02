# 🖨️ _printf — Custom Implementation of printf in C

A custom reimplementation of the C standard library `printf` function, built from scratch as part of the **Holberton School** curriculum. This project covers variadic arguments, format string parsing, and output formatting without relying on `printf` itself.

---

## 📚 Table of Contents

- [Description](#-description)
- [Requirements](#-requirements)
- [Files](#-files)
- [Compilation](#-compilation)
- [Usage](#-usage)
- [Supported Specifiers](#-supported-specifiers)
- [Examples](#-examples)
- [Known Limitations](#-known-limitations)
- [Authors](#-authors)

---

## 📝 Description

`_printf` produces formatted output to **stdout**, mimicking the behavior of the standard `printf(3)` function. It parses a format string character by character, handles conversion specifiers, and returns the total number of characters printed.

The implementation uses a **dispatch table** (an array of structs) to map each specifier to its handler function — making the code clean, modular, and easy to extend.

---

## ✅ Requirements

- Ubuntu **20.04 LTS**
- GCC with flags: `-Wall -Werror -Wextra -pedantic -std=gnu89`
- **Betty** coding style compliant
- No global variables
- No more than 5 functions per file
- Only these standard functions are used:
  - `write` · `malloc` · `free`
  - `va_start` · `va_end` · `va_copy` · `va_arg`

---

## 📁 Files

| File | Description |
|------|-------------|
| `main.h` | Header file — include guard, `fmt_t` struct, all prototypes |
| `_printf.c` | Entry point — format parser and specifier dispatcher |
| `handlers.c` | Handler functions — one per supported conversion specifier |
| `README.md` | This file |

---

## ⚙️ Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c -o printf
```

> ⚠️ Do **not** include any file containing a `main` function at the root of the repository. Place your test files in a `test/` subdirectory.

---

## 🚀 Usage

Include the header in your source file:

```c
#include "main.h"
```

Then call `_printf` exactly like `printf`:

```c
int len = _printf("Hello, %s! You are %d years old.\n", "Alice", 30);
```

`_printf` returns the **number of characters printed**, excluding the null terminator.

---

## 🔣 Supported Specifiers

| Specifier | Description | Example output |
|-----------|-------------|----------------|
| `%c` | Single character | `H` |
| `%s` | Null-terminated string | `Hello` |
| `%%` | Literal percent sign | `%` |
| `%d` | Signed decimal integer | `-42` |
| `%i` | Signed decimal integer | `1337` |

> 📌 Flag characters, field width, precision, and length modifiers are **not supported** in this version.

---

## 💡 Examples

```c
_printf("Character: [%c]\n", 'Z');
// → Character: [Z]

_printf("String: [%s]\n", "Holberton");
// → String: [Holberton]

_printf("Percent: [%%]\n");
// → Percent: [%]

_printf("Integer: [%d]\n", -762534);
// → Integer: [-762534]

_printf("Same specifier: [%i]\n", 42);
// → Same specifier: [42]

_printf("Multiple args: %d + %d = %d\n", 3, 4, 7);
// → Multiple args: 3 + 4 = 7

_printf("Null string: [%s]\n", (char *)NULL);
// → Null string: [(null)]

_printf("INT_MIN: [%d]\n", -2147483648);
// → INT_MIN: [-2147483648]
```

---

## ⚠️ Known Limitations

- Non-numeric input for `%d`/`%i` (e.g. floats, pointers) produces undefined behavior, consistent with the standard `printf`.
- Unknown specifiers (e.g. `%z`) are printed literally as-is (`%z`).
- A lone `%` at the very end of the format string is silently ignored.
- No support for: flags (`-`, `+`, `0`, ` `, `#`), field width, precision, or length modifiers (`l`, `h`, etc.).
- No internal buffer — characters are written one at a time via `write`.

---

## 👥 Authors

- **Thelyaan Dufrenoy** — [GitHub](https://github.com/)
- **Steven Reize Mountsambote** — [GitHub](https://github.com/)

---

*Built with 💙 at [Holberton School](https://www.holbertonschool.com/)*
