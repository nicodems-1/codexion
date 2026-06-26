#include "../includes/struct.h"

void create_coders(t_param p)
{
    int thread_count;
    int i = 0;
    thread_count = p.numbers_of_coders;
    while(i < thread_count)
    {
        pthread_create();
        i++;
    }
}