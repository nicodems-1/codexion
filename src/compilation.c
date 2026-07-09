#include "../includes/struct.h"

int compiling(t_coder *coder)
{
    get_dongles(&coder);
    print_log(coder->data, coder->id, "has taken a dongle");
    //1  Take one dongle on the left side (shortest adress memory)
    //1_bis lock the  mutex left dongle
    //2  Take one dongle on the right side (other adress memory)
    //2_bis lock the mutex right dongle
    if(ft_usleep(coder->data, coder->rules->time_to_compile) != CONTINUING)
        return 0;
    //3  Compile for the time it need compilation time the number of time required to compile
    //4  Dongle cooldown
    //5  Debbuging (just usleep for the time required)
    //6  Refactoring (just usleep for time required)
    return(check_status(coder->data));
}

void    get_dongles(t_coder *coder)
{
    pthread_mutex_lock(&coder->left_dongle->mutex);
    pthread_mutex_lock(&coder->right_dongle->mutex);
}

void    drop_dongles(t_coder *coder)
{
    coder->left_dongle->time_released = actual_time_ms();
    coder->right_dongle->time_released = actual_time_ms();
    pthread_mutex_unlock(&coder->left_dongle->mutex);
    pthread_mutex_unlock(&coder->right_dongle->mutex);
}


void    compilation(t_coder coders)
{
    //get two dongles right and left
    //compile(with time of compilation) * nb of compilations
}

int lauch_simulation();