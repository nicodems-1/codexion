#include "../includes/struct.h"

void debug(t_param p)
{
    int time_to_debug;
    time_to_debug = convert_ms_to_micros(p.time_to_debug);
    usleep(time_to_debug);
}


void refactor(t_param p)
{
    int time_to_refactor;
    time_to_refactor = convert_ms_to_micros(p.time_to_refactor);
    usleep(time_to_refactor);
}