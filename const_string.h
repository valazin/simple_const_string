#ifndef CONST_STRING_H
#define CONST_STRING_H

#include <cstddef>
#include <utility>
#include <iostream>

template <std::size_t N>
class const_string
{
public:

    template <typename... Characters>
    constexpr const_string(Characters... characters) :
        _value{characters...}
    {
    }

    void print() const
    {
        std::cout << _value << std::endl;
    }

public:
    const char _value[N];
};

template <std::size_t N, std::size_t... indexes>
constexpr const_string<N>
create_const_string(const char (&str)[N], std::index_sequence<indexes...>)
{
    return const_string<N>(str[indexes]...);
}

template <std::size_t N>
constexpr const_string<N>
create_const_string(const char (&str)[N])
{
    return create_const_string(str, std::make_index_sequence<N>());
}

template <std::size_t N1,
          std::size_t N2,
          std::size_t... indexes1,
          std::size_t... indexes2>
constexpr const_string<N1 + N2>
concat_const_string(
        const const_string<N1>& str1,
        const const_string<N2>& str2,
        std::index_sequence<indexes1...>,
        std::index_sequence<indexes2...>)
{
    return const_string<N1 + N2>(str1._value[indexes1]...,
                                 str2._value[indexes2]...);
}

template<std::size_t N1, std::size_t N2>
constexpr const_string<N1+N2>
concat_const_string(const const_string<N1>& str1, const const_string<N2>& str2)
{
    return concat_const_string(str1,
                               str2,
                               std::make_index_sequence<N1-1>(),
                               std::make_index_sequence<N2-1>());
}

#endif // CONST_STRING_H
