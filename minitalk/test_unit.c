#include "include/minitalk.h"

int main(void)
{
    // test ft_strlen

    assert(ft_strlen("hello") == 5);
    assert(ft_strlen("     hello") == 10);
    assert(ft_strlen("") == 0);
    assert(ft_strlen(NULL) == 0);

    //ft_ft_strjoin_char

    assert(ft_strncmp(ft_strjoin_char("hello ", 'c'), "hello c", 7) == 0);
    assert(ft_strncmp(ft_strjoin_char(NULL, 'c'), "c", 7) == 0);
    assert(ft_strncmp(ft_strjoin_char("    ", 'c'), "    c", 5) == 0);
    assert(ft_strncmp(ft_strjoin_char("cb", 'c'), "cbc", 3) == 0);
    assert(ft_strncmp(ft_strjoin_char("cb", 0), "cb", 5) == 0);
    

    int i = 10;
    ft_print_bit(i);

    ft_send_int_to_pid(10, 0, 100);
    ft_printf("test realise avec succes");
    return(0);
}