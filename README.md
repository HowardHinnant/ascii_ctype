# ASCII ctype library

## Overview

This header-only C++14 library provides an alternate implementation of the C
header `<ctype.h>`.  The API has been modernized to C++ in that each function
is `constexpr` and `noexcept`.  And each function takes a `char` argument and
returns a `bool` or `char`.  Furthermore, everything is in `namespace ascii`.  These functions
only implement the "C" locale equivalent, which is what enables them to be `constexpr`.

```c++
namespace ascii
{

constexpr bool isblank(char c) noexcept;
constexpr bool isdigit(char c) noexcept;
constexpr bool isxdigit(char c) noexcept;
constexpr bool islower(char c) noexcept;
constexpr bool isupper(char c) noexcept;
constexpr bool isspace(char c) noexcept;
constexpr bool ispunct(char c) noexcept;
constexpr bool isalpha(char c) noexcept;
constexpr bool isalnum(char c) noexcept;
constexpr bool isgraph(char c) noexcept;
constexpr bool isprint(char c) noexcept;
constexpr bool iscntrl(char c) noexcept;

constexpr char tolower(char c) noexcept;
constexpr char toupper(char c) noexcept;

}  // namespace ascii
```

To use, `#include "ascii_ctype.h"`.

License: MIT.

An attempt has been made to make these functions reasonably fast.  Though no
claim is made that they are the fastest.  Merely that they are not unreasonably
slow when compiled with optimizations enabled.

Use cases include:

* One needs the functionality to be either `constexpr`, `noexcept` or both.
* One needs the "C" locale version even if the global locale has been set to something else.
