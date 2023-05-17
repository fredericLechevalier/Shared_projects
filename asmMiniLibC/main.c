/*
** EPITECH PROJECT, 2022
** Epitech_project
** File description:
** main
*/

#include <stdio.h>
#include <string.h>
// ONLY PUSH THE CONTENT IN lib/my/ (the content of /my/)
extern size_t _strlen(const char *param);
extern char *_strchr(const char *str, int c);
extern char *_strrchr(const char *str, int c);
extern int _strcmp(const char *str, const char *str2);
extern int _strncmp(const char *str, const char *str2, size_t nbr);
extern void *_memset(void *s, int c, size_t size);
extern void *_memcpy(void *s, void *c, size_t size);
extern void *_memmove(void *s, void *c, size_t size);
extern int _strcasecmp(const char *str, const char *str2);

int main()
{
    printf("Launching test battery for x86-64 Assembly library into C code.\n\n");
    printf("_strlen     Got = %ld\n",_strlen("I am 18char long!\n"));
    printf("strlen Expected = %ld\n\n", strlen("I am 18char long!\n"));
    printf("_strlen     Got = %ld\n",_strlen(""));
    printf("strlen Expected = %ld\n\n", strlen(""));
    printf("_strlen     Got = %ld\n",_strlen("I am 18char long!"));
    printf("strlen Expected = %ld\n\n", strlen("I am 18char long!"));
    printf("_strlen     Got = %ld\n",_strlen("I am 18char\0 long!"));
    printf("strlen Expected = %ld\n", strlen("I am 18char\0 long!"));
    printf("-----------------------------------------------\n");
    printf("_strchr     Got = %s\n",_strchr("I am 18char long!", 'a'));
    printf("strchr Expected = %s\n\n", strchr("I am 18char long!", 'a'));
    printf("_strchr     Got = %s\n",_strchr("", 'a'));
    printf("strchr Expected = %s\n\n", strchr("", 'a'));
    printf("_strchr     Got = %s\n",_strchr("I am \0 18char long!", '\0'));
    printf("strchr Expected = %s\n\n", strchr("I am \0 18char long!", '\0'));
    printf("_strchr     Got = %s\n",_strchr("I am 18char long!", 'Z'));
    printf("strchr Expected = %s\n\n", strchr("I am 18char long!", 'Z'));
    printf("_strchr     Got = %s\n",_strchr("I am 18char long!", 'c'));
    printf("strchr Expected = %s\n", strchr("I am 18char long!", 'c'));
    printf("-----------------------------------------------\n");
    printf("_strrchr     Got = %s\n",_strrchr("I am 18char long!", 'a'));
    printf("strrchr Expected = %s\n\n", strrchr("I am 18char long!", 'a'));
    printf("_strrchr     Got = %s\n",_strrchr("\0", 'a'));
    printf("strrchr Expected = %s\n\n", strrchr("\0", 'a'));
    printf("_strrchr     Got = %s\n",_strrchr("I am \0 18char long!", '\0'));
    printf("strrchr Expected = %s\n\n", strrchr("I am \0 18char long!", '\0'));
    printf("_strrchr     Got = %s\n",_strrchr("I am 18char long!", 'Z'));
    printf("strrchr Expected = %s\n\n", strrchr("I am 18char long!", 'Z'));
    printf("_strrchr     Got = %s\n",_strrchr("I am 18char long!", ' '));
    printf("strrchr Expected = %s\n", strrchr("I am 18char long!", ' '));
    printf("-----------------------------------------------\n");
    printf("_strcmp     Got = %i\n",_strcmp("123456", "1234567"));
    printf("strcmp Expected = %i\n\n", strcmp("123456", "1234567"));
    printf("_strcmp     Got = %i\n",_strcmp("12345", "12345"));
    printf("strcmp Expected = %i\n\n", strcmp("12345", "12345"));
    printf("_strcmp     Got = %i\n",_strcmp("12", "1234567"));
    printf("strcmp Expected = %i\n\n", strcmp("12", "1234567"));
    printf("_strcmp     Got = %i\n",_strcmp("123456", "123"));
    printf("strcmp Expected = %i\n\n", strcmp("123456", "123"));
    printf("_strcmp     Got = %i\n",_strcmp("123456", "12349"));
    printf("strcmp Expected = %i\n\n", strcmp("123456", "12349"));
    printf("_strcmp     Got = %i\n",_strcmp("", ""));
    printf("strcmp Expected = %i\n\n", strcmp("", ""));
    printf("_strcmp     Got = %i\n",_strcmp("123z56", "123467"));
    printf("strcmp Expected = %i\n", strcmp("123z56", "123467"));
    printf("-----------------------------------------------\n");
    printf("_strncmp     Got = %i\n",_strncmp("123456", "1234567", 7));
    printf("strncmp Expected = %i\n\n", strncmp("123456", "1234567", 7));
    printf("_strncmp     Got = %i\n",_strncmp("12345", "12345", 2));
    printf("strncmp Expected = %i\n\n", strncmp("12345", "12345", 2));
    printf("_strncmp     Got = %i\n",_strncmp("12", "1234567", 44));
    printf("strncmp Expected = %i\n\n", strncmp("12", "1234567", 44));
    printf("_strncmp     Got = %i\n",_strncmp("123456", "123", 55));
    printf("strncmp Expected = %i\n\n", strncmp("123456", "123", 55));
    printf("_strncmp     Got = %i\n",_strncmp("123456", "12349", 8));
    printf("strncmp Expected = %i\n\n", strncmp("123456", "12349", 8));
    printf("_strncmp     Got = %i\n",_strncmp("", "", 1));
    printf("strncmp Expected = %i\n\n", strncmp("", "", 1));
    printf("_strncmp     Got = %i\n",_strncmp("123z56", "123467", 5));
    printf("strncmp Expected = %i\n\n", strncmp("123z56", "123467", 5));
    printf("_strncmp     Got = %i\n",_strncmp("123z56", "123467", 0));
    printf("strncmp Expected = %i\n", strncmp("123z56", "123467", 0));
    printf("-----------------------------------------------\n");
    char string1[13] = "Hello World!";
    char string2[13] = "Hello World!";
    _memset(string1, '.', 0);
    memset(string2, '.', 0);
    printf("_memset     Got = %s\n",string1);
    printf("memset Expected = %s\n\n",string2);
    _memset(string1, '.', 2);
    memset(string2, '.', 2);
    printf("_memset     Got = %s\n",string1);
    printf("memset Expected = %s\n\n",string2);
    _memset(string1, '!', 10);
    memset(string2, '!', 10);
    printf("_memset     Got = %s\n",string1);
    printf("memset Expected = %s\n\n",string2);
    _memset(string1, '\0', 8);
    memset(string2, '\0', 8);
    printf("_memset     Got = %s\n",string1);
    printf("memset Expected = %s\n\n",string2);
    _memset(string1, 'A', 12);
    memset(string2, 'A', 12);
    printf("_memset     Got = %s\n",string1);
    printf("memset Expected = %s\n\n",string2);
    _memset(string1, ' ', 5);
    memset(string2, ' ', 5);
    printf("_memset     Got = %s\n",string1);
    printf("memset Expected = %s\n\n",string2);
    _memset(string1, 'O', 18);
    memset(string2, 'O', 18);
    printf("_memset     Got = %s\n",string1);
    printf("memset Expected = %s\n\n",string2);
    _memset(string1, 'C', 20);
    memset(string2, 'C', 20);
    printf("_memset     Got = %s\n",string1);
    printf("memset Expected = %s\n\n",string2);
    _memset(string1, '\0', 30);
    memset(string2, '\0', 30);
    printf("_memset     Got = %s\n",string1);
    printf("memset Expected = %s\n",string2);
    printf("------------------------------------------\n");
    char string3[13] = "Hello_World!";
    char string4[13] = "Hello_World!";
    _memcpy(string3, "aaaaa", 5);
    memcpy(string4, "aaaaa", 5);
    printf("_memcpy     Got = %s\n",string3);
    printf("memcpy Expected = %s\n\n",string4);
    _memcpy(string3, "bbb", 0);
    memcpy(string4, "bbb", 0);
    printf("_memcpy     Got = %s\n",string3);
    printf("memcpy Expected = %s\n\n",string4);
    _memcpy(string3, "ccccc", 2);
    memcpy(string4, "ccccc", 2);
    printf("_memcpy     Got = %s\n",string3);
    printf("memcpy Expected = %s\n\n",string4);
    _memcpy(string3, "ddddddddddd", 11);
    memcpy(string4, "ddddddddddd", 11);
    printf("_memcpy     Got = %s\n",string3);
    printf("memcpy Expected = %s\n\n",string4);
    _memcpy(string3, "eeeee", 8);
    memcpy(string4, "eeeee", 8);
    printf("_memcpy     Got = %s\n",string3);
    printf("memcpy Expected = %s\n\n",string4);
    _memcpy(string3, "ffffffffffff", 12);
    memcpy(string4, "ffffffffffff", 12);
    printf("_memcpy     Got = %s\n",string3);
    printf("memcpy Expected = %s\n",string4);
    printf("-----------------------------------------------\n");
    char string5[13] = "Hello_World!";
    char string6[13] = "Hello_World!";
    _memmove(string5, "aaaaa", 5);
    memmove(string6, "aaaaa", 5);
    printf("_memmove     Got = %s\n",string5);
    printf("memmove Expected = %s\n\n",string6);
    _memmove(string5, "bbb", 0);
    memmove(string6, "bbb", 0);
    printf("_memmove     Got = %s\n",string5);
    printf("memmove Expected = %s\n\n",string6);
    _memmove(string5, "ccccc", 2);
    memmove(string6, "ccccc", 2);
    printf("_memmove     Got = %s\n",string5);
    printf("memmove Expected = %s\n\n",string6);
    _memmove(string5, "ddddddddddd", 11);
    memmove(string6, "ddddddddddd", 11);
    printf("_memmove     Got = %s\n",string5);
    printf("memmove Expected = %s\n\n",string6);
    _memmove(string5, "eeeee", 8);
    memmove(string6, "eeeee", 8);
    printf("_memmove     Got = %s\n",string5);
    printf("memmove Expected = %s\n\n",string6);
    _memmove(string5, "ffffffffffff", 12);
    memmove(string6, "ffffffffffff", 12);
    printf("_memmove     Got = %s\n",string5);
    printf("memmove Expected = %s\n",string6);
    printf("-----------------------------------------------\n");
    printf("_strcasecmp     Got = %i\n",_strcasecmp("123456", "1234567"));
    printf("strcasecmp Expected = %i\n\n", strcasecmp("123456", "1234567"));
    printf("_strcasecmp     Got = %i\n",_strcasecmp("12345", "12345"));
    printf("strcasecmp Expected = %i\n\n", strcasecmp("12345", "12345"));
    printf("_strcasecmp     Got = %i\n",_strcasecmp("12", "1234567"));
    printf("strcasecmp Expected = %i\n\n", strcasecmp("12", "1234567"));
    printf("_strcasecmp     Got = %i\n",_strcasecmp("123456", "123"));
    printf("strcasecmp Expected = %i\n\n", strcasecmp("123456", "123"));
    printf("_strcasecmp     Got = %i\n",_strcasecmp("123456", "12349"));
    printf("strcasecmp Expected = %i\n\n", strcasecmp("123456", "12349"));
    printf("_strcasecmp     Got = %i\n",_strcasecmp("", ""));
    printf("strcasecmp Expected = %i\n\n", strcasecmp("", ""));
    printf("_strcasecmp     Got = %i\n",_strcasecmp("123z56", "123467"));
    printf("strcasecmp Expected = %i\n", strcasecmp("123z56", "123467"));
    printf("-----------------------------------------------\n");
}
