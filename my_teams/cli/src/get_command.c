/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../includes/client.h"

static void free_parser(char **array, char *array_str)
{
    for (int i = 0; array[i] != NULL; ++i) {
        free(array[i]);
    }
    free(array);
    free(array_str);
}

static void get_the_command(connect_t *con, char *input)
{
    int len = 0;
    char *out;
    for (; input[len] && input[len] != ' '; ++len);
    out = malloc(sizeof(char) * len + 1);
    for (int i = 0; input[i] && input[i] != ' '; ++i) {
        out[i] = input[i];
    }
    out[len] = 0;
    if (out[len - 1] == '\n')
        out[len - 1] = 0;
    con->command = cjson_push(NULL, 1, "command", out);
    free(out);
}

static char *get_quoted(char *input, int *index)
{
    int len = *index;
    for (; input[len] && input[len] != '"'; ++len);
    char *out = malloc(sizeof(char) * len + 1);
    int index_out = 0;
    for (;input[*index] && input[*index] != '"'; *index += 1, ++index_out)
        out[index_out] = input[*index];
    out[index_out] = 0;
    char *coded_out = encode_str(out);
    free(out);

    return coded_out;
}

static void parse_args(connect_t *con, char *input)
{
    if (strlen(input) <= 2)
        return;
    get_the_command(con ,input);
    int len = 0;
    for (int i = 0; input[i]; ++i)
        (input[i] == '"') ? (++len) : 0;
    len /= 2;
    char **array = malloc(sizeof(char *) * (len + 1));
    int index_out = 0;
    for (int i = 0; input[i]; ++i) {
        if (input[i] == '"') {
            ++i;
            array[index_out] = get_quoted(input, &i);
            ++i; ++index_out;
        }
    }
    array[index_out] = NULL;
    char *array_str = cjson_stringify_array(array);
    cjson_push(con->command, 1, "args", array_str);
    free_parser(array, array_str);
}

void get_command(connect_t *con)
{
    if (FD_ISSET(0, &con->user_input)) {
        int len;
        int nb_quote = 0;
        char buf[4096];
        len = read(0, buf, 4095);
        buf[len] = 0;
        for (int i = 0; buf[i]; ++i)
            (buf[i] == '"') ? (++nb_quote) : 0;
        if (buf[0] == '/' && nb_quote % 2 == 0) {
            parse_args(con, buf + 1);
        } else {
            printf("bad syntax\n");
        }
    }
}
