#include "../includes/struct.h"

int ft_usleep(t_data *data, long long time_to_sleep)
{
    long long start;
    long long actual;
    start = actual_time_ms();
    while(1)
    {
        usleep(500);
        actual = actual_time_ms;
        if ((actual - start) >= time_to_sleep)
            return CONTINUING;
        pthread_mutex_lock(&data->status_mutex);
        if (&data->simulation_status == BURNOUT)
            return BURNOUT;
        pthread_mutex_unlock(&data->status_mutex);
    }   
}

int check_status(t_data *data)
{
    int status;
    pthread_mutex_lock(&data->status_mutex);
    status = &data->simulation_status;
    pthread_mutex_unlock(&data->status_mutex);
    return status;
}

void    print_log(t_data *data, int id, char *action)
{
    long long time;
    int status;

    pthread_mutex_lock(&data->print_mutex);
    status = check_status(data);
    if (status == CONTINUING && ft_strncmp(action, "burned out", 10) == 0)
    {
        time = actual_time_ms() - data->start_time;
        printf("%lld %d %s\n", time, id, action);
    }
    pthread_mutex_unlock(&data->print_mutex);
}

ft_strncmp(char *str1, char *str2, int len)
{
    int i;
    i = 0;
    while(i != len-1 && str1[i] != 0 && str2[i] != 0)
    {
        if(str1[i] != str2[i])
            return(1);
        i++;
    }
    return(0);
}