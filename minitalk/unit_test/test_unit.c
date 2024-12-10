#include "../include/minitalk.h"

int main(void)
{
    // test ft_strlen

    assert(ft_strlen("hello") == 5);
    assert(ft_strlen("     hello") == 10);
    assert(ft_strlen("") == 0);
    assert(ft_strlen(NULL) == 0);


    assert(ft_strncmp(ft_joint_char("hello ", 'c'), "hello c", 7) == 0);
    assert(ft_strncmp(ft_joint_char(NULL, 'c'), "c", 7) == 0);
    assert(ft_strncmp(ft_joint_char("    ", 'c'), "    c", 5) == 0);
    assert(ft_strncmp(ft_joint_char("cb", 'c'), "cbc", 3) == 0);
    assert(ft_strncmp(ft_joint_char("cb", 0), "cb", 5) == 0);

    // //test liberation memoire

    char *str = malloc(5);
    if(!str)
        return (1);
    str = ft_strdup("hello");
    ft_printf("voici l'adresse de la premier string %p\n", str);

    char *new_str = ft_joint_char(str, 'x');
    ft_printf("voici l'adresse de la premier string %p\n",  new_str);
    
    ft_printf("La prochaine action devrai creer uneffet de bord\n");
    free(str);
    str = NULL;
    ft_printf("%s\n",(char *)0x602000000110);
    str = ft_strdup("worl");    
    return(0);
}