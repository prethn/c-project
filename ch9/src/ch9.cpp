#include"custom_ch9.hpp"

void (*fun)();

int main()
{
    fun = do_refun;
    fun();
    return 0;
}
