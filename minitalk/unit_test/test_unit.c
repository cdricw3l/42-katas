#include "minitalk_test.h"
#include <limits.h>

int main(void)
{
    // test ft_strlen

    assert(ft_strlen("hello") == 5);
    assert(ft_strlen("     hello") == 10);
    assert(ft_strlen("") == 0);
    assert(ft_strlen(NULL) == 0);
    
    // //test strjoint_char
    assert(ft_strncmp(ft_joint_char("hello ", 'c'), "hello c", 7) == 0);
    assert(ft_strncmp(ft_joint_char(NULL, 'c'), "c", 7) == 0);
    assert(ft_strncmp(ft_joint_char("    ", 'c'), "    c", 5) == 0);
    assert(ft_strncmp(ft_joint_char("cb", 'c'), "cbc", 3) == 0);
    assert(ft_strncmp(ft_joint_char("cb", 0), "cb", 5) == 0);

    int i, j;

    i = 26;
    j = 0;
    char *txt = "abcdefghijklmnopqrstuvwxyz";
    char *str = malloc(i);
    if(!str)
        return (1);
    str = NULL;
    while (txt[j])
    {
        printf("Ancienne adresse %p\n", str);
        str = ft_clean_alloc(str, txt[j]);
        char *sub = ft_substr(txt,0,j + 1);
        printf("Nouvelle adresse %p\n", str);
        printf("Str1: %s, Str2 %s\n", str, sub);
        //assertion
        assert(ft_strncmp(sub,str,i) == 0);
        j++;
    }

    //array of bytes int (SIGUSR1,SIGUSR2, 2, 97,65)
    int arr[6] = {SIGUSR1, SIGUSR2, 2, 97,65, 4095};
    char *bit[7] = {"0000000000011110", "0000000000011111", "0000000000000010","0000000001100001", "0000000001000001","0000111111111111", NULL};
    i = 0;
    while (bit[i])
    {
        char *bit_to_pid = ft_send_int_to_pid_test(arr[i], 20);
        ft_printf("string 1 : %s, string 2 : %s\n", bit_to_pid, bit[i]);
        assert(ft_strncmp(bit[i],ft_send_int_to_pid_test(arr[i], 20), 8) == 0);
        i++;
    }
    return(0);
}