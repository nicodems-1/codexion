#include "../includes/struct.h"

void create_coders(t_param p, t_coder coder)
{
    int i;
    int thread_count;
    int *thread_array;
    int *coder_array;

    i = 0;
    thread_count = p.numbers_of_coders;
    //allocating enough room to store coders struct in an array, each struct contains threads init
    coder_array = malloc(sizeof(t_coder)*thread_count);

    while(i != thread_count)
    {
        coder.thread_id = i;
        i++;
    }
}