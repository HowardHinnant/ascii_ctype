// The MIT License (MIT)
//
// Copyright (c) 2025 Howard Hinnant
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "ascii_ctype.h"
#include <cctype>
#include <exception>
#include <iostream>


void
display(char c)
{
    auto hexdigit = [](char c)
    {
        if (c < 10)
            return char(c + '0');
        return char(c - 10 + 'A');
    };
    auto hexout = [&hexdigit](char c)
    {
        std::cout << "0x" << hexdigit(unsigned(c) >> 4) << hexdigit(c & 0xF);
    };
    if (isgraph(c))
        std::cout << c;
    else if (c == ' ')
        std::cout << "' '";
    else
        hexout(c);
    std::cout << '\n';
}

int
main()
{
    for (int i = 0; i <= 255; ++i)
    {
        char c(i);
        if (ascii::isblank(c) != std::isblank(c))
        {
            std::cout << "isblank: ";
            display(c);
            std::terminate();
        }
    }

    for (int i = 0; i <= 255; ++i)
    {
        char c(i);
        if (ascii::isdigit(c) != std::isdigit(c))
        {
            std::cout << "isdigit: ";
            display(c);
            std::terminate();
        }
    }

    for (int i = 0; i <= 255; ++i)
    {
        char c(i);
        if (ascii::isxdigit(c) != std::isxdigit(c))
        {
            std::cout << "isxdigit: ";
            display(c);
            std::terminate();
        }
    }

    for (int i = 0; i <= 255; ++i)
    {
        char c(i);
        if (ascii::islower(c) != std::islower(c))
        {
            std::cout << "islower: ";
            display(c);
            std::terminate();
        }
    }

    for (int i = 0; i <= 255; ++i)
    {
        char c(i);
        if (ascii::isupper(c) != std::isupper(c))
        {
            std::cout << "isupper: ";
            display(c);
            std::terminate();
        }
    }

    for (int i = 0; i <= 255; ++i)
    {
        char c(i);
        if (ascii::isspace(c) != std::isspace(c))
        {
            std::cout << "isspace: ";
            display(c);
            std::terminate();
        }
    }

    for (int i = 0; i <= 255; ++i)
    {
        char c(i);
        if (ascii::ispunct(c) != std::ispunct(c))
        {
            std::cout << "ispunct: ";
            display(c);
            std::terminate();
        }
    }

    for (int i = 0; i <= 255; ++i)
    {
        char c(i);
        if (ascii::iscntrl(c) != std::iscntrl(c))
        {
            std::cout << "iscntrl: ";
            display(c);
            std::terminate();
        }
    }

    for (int i = 0; i <= 255; ++i)
    {
        char c(i);
        if (ascii::isalpha(c) != std::isalpha(c))
        {
            std::cout << "isalpha: ";
            display(c);
            std::terminate();
        }
    }

    for (int i = 0; i <= 255; ++i)
    {
        char c(i);
        if (ascii::isalnum(c) != std::isalnum(c))
        {
            std::cout << "isalnum: ";
            display(c);
            std::terminate();
        }
    }

    for (int i = 0; i <= 255; ++i)
    {
        char c(i);
        if (ascii::isgraph(c) != std::isgraph(c))
        {
            std::cout << "isgraph: ";
            display(c);
            std::terminate();
        }
    }

    for (int i = 0; i <= 255; ++i)
    {
        char c(i);
        if (ascii::isprint(c) != std::isprint(c))
        {
            std::cout << "isprint: ";
            display(c);
            std::terminate();
        }
    }

    for (int i = 0; i <= 255; ++i)
    {
        char c(i);
        if (ascii::tolower(c) != std::tolower(c))
        {
            std::cout << "tolower: ";
            display(c);
            std::terminate();
        }
    }

    for (int i = 0; i <= 255; ++i)
    {
        char c(i);
        if (ascii::toupper(c) != std::toupper(c))
        {
            std::cout << "toupper: ";
            display(c);
            std::terminate();
        }
    }
    std::cout << "Passed\n";
}

static_assert(ascii::isblank(' '), "");
static_assert(ascii::isdigit('0'), "");
static_assert(ascii::isxdigit('0'), "");
static_assert(ascii::islower('a'), "");
static_assert(ascii::isupper('A'), "");
static_assert(ascii::ispunct('.'), "");
static_assert(ascii::isalpha('c'), "");
static_assert(ascii::isalnum('c'), "");
static_assert(ascii::isgraph('c'), "");
static_assert(ascii::isprint('c'), "");
static_assert(ascii::iscntrl('\n'), "");
static_assert(ascii::tolower('A') == 'a', "");
static_assert(ascii::toupper('a') == 'A', "");
