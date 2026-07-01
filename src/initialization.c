#include "../includes/struct.h"

pthread_mutex_t locking_coder; //need to update the struct later so it will not be a global variable

void* routine()
{
    // pthread_mutex_lock(&locking_coder);
    printf("COOKING PIZZA\n");
    usleep(3);
    printf("PIZZA COOKED\n");
    // pthread_mutex_unlock(&locking_coder);
    return NULL;
}

void create_coders(const t_param *p)
{
    pthread_mutex_init(&locking_coder, NULL);
    t_coder c;
    int i;
    int thread_count;
    int *thread_array;
    int *coder_array;

    i = 0;
    thread_count = p->numbers_of_coders;
    //allocating enough room to store coders struct in an array, each struct contains threads init
    coder_array = malloc(sizeof(t_coder)*thread_count);
    printf("\n");
    printf("********************************\n");
    printf("NUMBER OF CODER = %d\n", p->numbers_of_coders);
    printf("Time to burnout = %d\n", p->time_to_burnout);
    printf("Time to compile = %d\n", p->time_to_compile);
    printf("Time_to_debug= %d\n", p->time_to_debug);
    printf("number_of_compiles_required = %d\n", p->numbers_of_compiles_required);
    printf("dongle_cooldown = %d\n", p->dongle_cooldown);
    printf("Time_to_refactor=%d\n", p->time_to_refactor);
    printf("scheduler = %d\n", p->scheduler);
    printf("********************************\n\n");
    while(i < thread_count)
    {
        pthread_cond_init()
        pthread_create(&c.thread_id, NULL, &routine, NULL);
        pthread_join(c.thread_id, NULL);
        i++;
    }
}

