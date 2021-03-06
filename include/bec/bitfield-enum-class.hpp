// (C) Copyright 2015 Just Software Solutions Ltd
//
// Distributed under the Boost Software License, Version 1.0.
//
// Boost Software License - Version 1.0 - August 17th, 2003
//
// Permission is hereby granted, free of charge, to any person or
// organization obtaining a copy of the software and accompanying
// documentation covered by this license (the "Software") to use,
// reproduce, display, distribute, execute, and transmit the
// Software, and to prepare derivative works of the Software, and
// to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
//
// The copyright notices in the Software and this entire
// statement, including the above license grant, this restriction
// and the following disclaimer, must be included in all copies
// of the Software, in whole or in part, and all derivative works
// of the Software, unless such copies or derivative works are
// solely in the form of machine-executable object code generated
// by a source language processor.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY
// KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
// PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
// COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE
// LIABLE FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN
// CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

// Code presented here is derived from:
//  https://www.justsoftwaresolutions.co.uk/cplusplus/using-enum-classes-as-bitfields.html
//  by Anthony Williams
// More information available here:
//  http://blog.bitwigglers.org/using-enum-classes-as-type-safe-bitmasks/
//  by Andre Haupt

#pragma once

#include <type_traits>

namespace bec
{

template<typename Enum>
struct EnableBitMaskOperators
{
    static const bool Enable = false;
};

template<typename Enum>
typename std::enable_if<EnableBitMaskOperators<Enum>::Enable, Enum>::type
operator|(Enum lhs, Enum rhs)
{
    static_assert(
        std::is_enum<Enum>::value, "template parameter is not an enum type");

    return static_cast<Enum>(
        static_cast<std::underlying_type_t<Enum>>(lhs) |
        static_cast<std::underlying_type_t<Enum>>(rhs));
}

template<typename Enum>
typename std::enable_if<EnableBitMaskOperators<Enum>::Enable, Enum>::type
operator&(Enum lhs, Enum rhs)
{
    static_assert(
        std::is_enum<Enum>::value, "template parameter is not an enum type");

    return static_cast<Enum>(
        static_cast<std::underlying_type_t<Enum>>(lhs) &
        static_cast<std::underlying_type_t<Enum>>(rhs));
}

template<typename Enum>
typename std::enable_if<EnableBitMaskOperators<Enum>::Enable, Enum>::type
operator^(Enum lhs, Enum rhs)
{
    static_assert(
        std::is_enum<Enum>::value, "template parameter is not an enum type");

    return static_cast<Enum>(
        static_cast<std::underlying_type_t<Enum>>(lhs) ^
        static_cast<std::underlying_type_t<Enum>>(rhs));
}

template<typename Enum>
typename std::enable_if<EnableBitMaskOperators<Enum>::Enable, Enum>::type
operator~(Enum rhs)
{
    static_assert(
        std::is_enum<Enum>::value, "template parameter is not an enum type");

    return static_cast<Enum>(~static_cast<std::underlying_type_t<Enum>>(rhs));
}

template<typename Enum>
typename std::enable_if<EnableBitMaskOperators<Enum>::Enable, Enum>::type&
operator|=(Enum& lhs, Enum rhs)
{
    static_assert(
        std::is_enum<Enum>::value, "template parameter is not an enum type");

    lhs = static_cast<Enum>(
        static_cast<std::underlying_type_t<Enum>>(lhs) |
        static_cast<std::underlying_type_t<Enum>>(rhs));

    return lhs;
}

template<typename Enum>
typename std::enable_if<EnableBitMaskOperators<Enum>::Enable, Enum>::type&
operator&=(Enum& lhs, Enum rhs)
{
    static_assert(
        std::is_enum<Enum>::value, "template parameter is not an enum type");

    lhs = static_cast<Enum>(
        static_cast<std::underlying_type_t<Enum>>(lhs) &
        static_cast<std::underlying_type_t<Enum>>(rhs));

    return lhs;
}

template<typename Enum>
typename std::enable_if<EnableBitMaskOperators<Enum>::Enable, Enum>::type&
operator^=(Enum& lhs, Enum rhs)
{
    static_assert(
        std::is_enum<Enum>::value, "template parameter is not an enum type");

    lhs = static_cast<Enum>(
        static_cast<std::underlying_type_t<Enum>>(lhs) ^
        static_cast<std::underlying_type_t<Enum>>(rhs));

    return lhs;
}

} // namespace bec
