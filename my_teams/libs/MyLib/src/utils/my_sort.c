/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/utils.h"

static int *find_lowest(int *array, int size)
{
    int lowest = array[0];
    int nb = 0;
    int *out = malloc(sizeof(int) * 2);

    for (int i = 0; i < size; ++i) {
        if (array[i] == lowest)
            ++nb;
        if (array[i] < lowest) {
            lowest = array[i];
            nb = 1;
        }
    }
    out[0] = lowest;
    out[1] = nb;
    return out;
}

static int **init(int *out, int *array, int size)
{
    int **infos = malloc(sizeof(int *) * 4);

    infos[0] = find_lowest(array, size);
    for (int i = 1; i < 4; ++i)
        infos[i] = malloc(sizeof(int) * 2);
    for (int i = 0; i < size; ++i)
        out[i] = 0;
    for (int i = 0; i < infos[0][1]; ++i)
        out[i] = infos[0][0];
    return infos;

}

static void refresh_data(int **infos, int *out, int *array, int *remain)
{
    out[infos[2][0]] = infos[1][0];
    out[infos[2][1]] = infos[1][1];
    array[infos[3][0]] = infos[0][0];
    array[infos[3][1]] = infos[0][0];
    ++infos[2][0];
    --infos[2][1];
    *remain -= 2;
}

static int sort(int size, int **infos, int *out, int *array)
{
    int remain = size;

    infos[2][0] = infos[0][1];
    infos[2][1] = size -1;
    while (remain > 2) {
        infos[1][0] = 2147483647;
        infos[1][1] = infos[0][0];
        sort_inner_clock(array, infos, size);
        refresh_data(infos, out, array, &remain);
    }
    return remain;
}

int *my_sort(int *array, int size)
{
    int *out = malloc(sizeof(int) * size);
    int **infos = init(out, array, size);
    int remain = sort(size, infos, out, array);

    if (remain == 1)
        sort_one(out, infos, array, size);
    for (int i = 0; i < 4; ++i)
        free(infos[i]);
    free(infos);
    free(array);
    return out;
}
