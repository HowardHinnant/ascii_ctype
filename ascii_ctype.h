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

#ifndef ASCII_CTYPE_H
#define ASCII_CTYPE_H

#include <cstdint>

namespace ascii
{

// 0x0000'0001'0000'0100  0x0000'0000'0000'0000
constexpr
inline
bool
isblank(char c) noexcept
{
    return c == ' ' || c == '\t';
}

// 0x0000'03FF'0000'0000  0x0000'0000'0000'0000
constexpr
inline
bool
isdigit(char c) noexcept
{
    return '0' <= c && c <= '9';
}

// 0x03FF'0000'0000'0000  0x0000'007E'0000'007E
constexpr
inline
bool
isxdigit(char c) noexcept
{
//  return isdigit(c) || ('A' <= c && c <= 'F') || ('a' <= c && c <= 'f');
    std::uint64_t const ctype[4] = {0x03FF'0000'0000'0000, 0x0000'007E'0000'007E};
    std::uint8_t uc(c);
    return ctype[uc >> 6] & (std::uint64_t{1} << (uc & 0x3F));
}

// 0x0000'0000'0000'0000  0x07FF'FFFE'0000'0000
constexpr
inline
bool
islower(char c) noexcept
{
    return 'a' <= c && c <= 'z';
}

// 0x0000'0000'0000'0000  0x0000'0000'07FF'FFFE
constexpr
inline
bool
isupper(char c) noexcept
{
    return 'A' <= c && c <= 'Z';
}

// 0x0000'0001'0000'1F00  0x0000'0000'0000'0000
constexpr
inline
bool
isspace(char c) noexcept
{
    return c == ' ' || (0x09 <= c && c <= 0x0D);
}

// 0xFC00'FFFE'0000'0000  0x7800'0001'F800'0001
constexpr
inline
bool
ispunct(char c) noexcept
{
//  return ('!' <= c && c <= '/') || (':' <= c && c <= '@') || ('[' <= c && c <= '`') ||
//         ('{' <= c && c <= '~');
    std::uint64_t const ctype[4] = {0xFC00'FFFE'0000'0000, 0x7800'0001'F800'0001};
    std::uint8_t uc(c);
    return ctype[uc >> 6] & (std::uint64_t{1} << (uc & 0x3F));
}

// 0x0000'0000'0000'0000  0x07FF'FFFE'07FF'FFFE
constexpr
inline
bool
isalpha(char c) noexcept
{
    return isupper(c) || islower(c);
}

// 0x03FF'0000'0000'0000  0x07FF'FFFE'07FF'FFFE
constexpr
inline
bool
isalnum(char c) noexcept
{
//  return isalpha(c) || isdigit(c);
    std::uint64_t const ctype[4] = {0x03FF'0000'0000'0000, 0x07FF'FFFE'07FF'FFFE};
    std::uint8_t uc(c);
    return ctype[uc >> 6] & (std::uint64_t{1} << (uc & 0x3F));
}

// 0xFFFF'FFFE'0000'0000  0x7FFF'FFFF'FFFF'FFFF
constexpr
inline
bool
isgraph(char c) noexcept
{
//  return isalnum(c) || ispunct(c);
    return '!' <= c && c <= '~';
}

// 0xFFFF'FFFF'0000'0000  0x7FFF'FFFF'FFFF'FFFF
constexpr
inline
bool
isprint(char c) noexcept
{
//  return isgraph(c) || c == ' ';
    return ' ' <= c && c <= '~';
}

// 0x0000'0000'FFFF'FFFF  0x8000'0000'0000'0000
constexpr
inline
bool
iscntrl(char c) noexcept
{
//  return !(c & 0x80) && !isprint(c);
    std::uint64_t const ctype[4] = {0x0000'0000'FFFF'FFFF, 0x8000'0000'0000'0000};
    std::uint8_t uc(c);
    return ctype[uc >> 6] & (std::uint64_t{1} << (uc & 0x3F));
}

constexpr
inline
char
tolower(char c) noexcept
{
    if (isupper(c))
        return static_cast<char>(c + ('a' - 'A'));
    return c;
}

constexpr
inline
char
toupper(char c) noexcept
{
    if (islower(c))
        return static_cast<char>(c - ('a' - 'A'));
    return c;
}

}  // namespace ascii

#endif  // ASCII_CTYPE_H
