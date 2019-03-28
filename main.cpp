#include "const_string.h"

int main()
{
    constexpr auto str1 = create_const_string("Hello ");
    constexpr auto str2 = create_const_string("world");
    constexpr auto str3 = concat_const_string(str1, str2);

    str3.print();

    return  0;
}

