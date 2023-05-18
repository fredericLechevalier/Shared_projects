/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#include "../../includes/utils.h"

void sort_one(int *out, int **infos, int *array, int size)
{
    for (int i = 0; i < size; ++i) {
        if (array[i] != infos[0][0]) {
            out[infos[2][0]] = array[i];
            break;
        }
    }
}

void sort_inner_clock(int *array, int **infos, int size)
{
    for (int i = 0; i < size; ++i) {
        if (array[i] < infos[1][0] && array[i] != infos[0][0]) {
            infos[1][0] = array[i];
            infos[3][0] = i;
        }
        if (array[i] > infos[1][1]) {
            infos[1][1] = array[i];
            infos[3][1] = i;
        }
    }
}
