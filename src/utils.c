#include "../includes/struct.h"

int is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int is_number(char *str)
{
    int i;
    i = 0;
    while(str[i])
    {
        if (is_digit(str[i]) == 0)
            return(0);
        i++;
    }
    return(1);
}