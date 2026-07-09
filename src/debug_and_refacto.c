#include "../includes/struct.h"

int debug(t_coder *coder)
{
    print_log(coder->data, coder->id, "is debugging");
    if (ft_usleep(coder->data, coder->rules->time_to_debug) != CONTINUING)
        return 0;
    return 1;
}


void refactor(t_coder *coder)
{
    print_log(coder->data, coder->id, "is refactoring");
    if (ft_usleep(coder->data, coder->rules->time_to_refactor) != CONTINUING)
        return 0;
    return 1;
}