#include "../includes/struct.h"

int main(int ac, char **av)
{
    t_param p;
    t_param value;
    parsing(ac, av, &p);
    create_coders(&p);
}