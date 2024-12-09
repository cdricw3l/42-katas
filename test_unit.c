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
    

  


    static int j = 0;

    j = j| (1 << 3);

    ft_print_bit(j);
    j = j| (1 << 2);
    ft_print_bit(j);
    ft_printf("test realise avec succes");

    char *s = "hello";
    char *c = NULL;
    int i = 0;
    while (i < 5)
    {
        c = ft_strjoin_char(c,s[i]);
        i++;
    }

    printf("voici la tring %s\n", c);
    
    return(0);
}