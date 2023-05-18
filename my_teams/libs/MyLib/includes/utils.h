/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#ifndef UTLIS_H_
    #define UTLIS_H_


    #define NO_FLAGS 0
    #define DEFAULT_MOD S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH

    #define PRINT_BUF_SIZE 1024
    #define FPRINT_BUF_SIZE 1024

    #define DIGITS "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"

    #include <stdbool.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>

    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>

    #include <stdarg.h>

    #define BASE64 "azertyuiopqsdfghjklmwxcvbn1234567890AZERTYUIOPQSDFGHJKLMW\
XCVBN?="

    #define ENCODE_CHARS "{}[]\"':,"

/**
 * @brief Calculate the length of a string.
 * @param str The string to measure.
 * @return int The length of the string.
 */
int my_strlen(const char *str);

/**
 * @brief Create a duplicate of a string.
 * @param src The original string.
 * @return char* A pointer to the newly-allocated string.
 */
char *my_strdup(const char *src);

/**
 * @brief Copy a source string into a destination string.
 * @param out The destination string.
 * @param src The source string.
 */
void my_strcopy(char *out, const char *src);

/**
 * @brief Compare two strings for equality.
 * @param str_a The first string to compare.
 * @param str_b The second string to compare.
 * @return true If the strings are equal.
 * @return false If the strings are not equal.
 */
bool my_strcomp(const char *str_a, const char *str_b);

/**
 * @brief Read the contents of a file into a string.
 * @param path The path to the file.
 * @param buf_size The size of the buffer to use.
 * @return char* A pointer to the newly-allocated string containing the file
 * contents.
 */
char *read_file(const char *path, int buf_size);

/**
 * @brief Write a string to a file.
 * @param path The path to the file.
 * @param str The string to write.
 * @param flags The flags to use when opening the file.
 * @return int The number of characters written, or -1 on error.
 */
int write_file(char *path, char *str, int flags);

/**
 * @brief Concatenate two strings.
 * @param out The output string.
 * @param in The string to concatenate.
 * @return char* A pointer to the output string.
 */
char *my_strcat(char *out, char *in);

/**
 * @brief Convert an integer to a string.
 * @param i The integer to convert.
 * @return char* A pointer to the newly-allocated string.
 */
char *my_itoa(int i);

/**
 * @brief Reverse a string.
 * @param str The string to reverse.
 * @return char* A pointer to the reversed string.
 */
char *my_revstr(char *str);


/**
 * @brief Convert a string to an integer
 * @param str The string to be converted to an integer
 * @return int The converted integer value
 */
int my_atoi(char *str);

/**
 * @brief Print a formatted string to stdout
 * @param str The string to be printed
 * @param ... Optional parameters to be inserted into the string
 */
void my_print(char *str, ...);

/**
 * @brief Write an integer to stdout
 * @param i The integer value to be written
 */
void write_int(int i);

/**
 * @brief Write a string to stdout
 * @param str The string to be written
 */
void write_str(char *str);

/**
 * @brief Write an integer to a file
 * @param i The integer value to be written
 * @param fd The file descriptor to write to
 */
void fwrite_int(int i, int fd);

/**
 * @brief Write a string to a file
 * @param str The string to be written
 * @param fd The file descriptor to write to
 */
void fwrite_str(char *str, int fd);

/**
 * @brief Print a formatted string to a file
 * @param path The path of the file to be written to
 * @param flags The flags to be used when opening the file
 * @param str The string to be printed
 * @param ... Optional parameters to be inserted into the string
 */
void my_fprint(char *path, int flags, char *str, ...);

/**
 * @brief Print a formatted string to stderr
 * @param str The string to be printed
 * @param ... Optional parameters to be inserted into the string
 */
void my_errprint(char *str, ...);

/**
 * @brief Get the index of the first occurrence of a character in a string.
 * @param str The input string.
 * @param c The character to find in the string.
 * @return int The index of the first occurrence of the character, or -1 if
 * not found.
 */
int my_index_of_char(char *str, char c);

/**
 * @brief Get the index of the first occurrence of a substring in a string.
 * @param str The input string.
 * @param tofind The substring to find in the string.
 * @return int The index of the first occurrence of the substring, or -1 if
 * not found.
 */
int my_index_of_str(char *str, char *tofind);

/**
 * @brief Compute the power of a number.
 * @param nb The base number.
 * @param p The exponent.
 * @return int The result of the computation.
 */
int my_power(int nb, int p);

/**
 * @brief Convert a number from one base to another.
 * @param in The input number as a string.
 * @param in_base The base of the input number.
 * @param out_base The base to convert the number to.
 * @return char* The converted number as a string in the new base.
 */
char *my_base_changer(char *in, int in_base, int out_base);

/**
 * @brief Sort an array of integers in ascending order.
 * @param array The input array of integers.
 * @param size The number of integers in the array.
 * @return int* The sorted array of integers.
 */
int *my_sort(int *array, int size);

/**
 * @brief Do not use. This function is for internal use only.
 */
void sort_one(int *out, int **infos, int *array, int size);

/**
 * @brief Do not use. This function is for internal use only.
 */
void sort_inner_clock(int *array, int **infos, int size);

/**
 * @brief Encode a given string in base64.
 * @param str A string to be encoded.
 * @return A dynamically allocated tring containing the base64 encoding of the
 * input string.
 * The caller is responsible for freeing the memory allocated for the
 * returned string.
 */
char *encode_str(const char *str);

/**
 * @brief Decode a given base64 encoded string into plain text.
 * @param base A string containing the base64 encoded data to be decoded.
 * @return A dynamically allocated string containing the decoded plain text.
 * The caller is responsible for freeing the memory allocated for the
 * returned string.
 */
char *decode_str(const char *base);


#endif // !UTLIS_H_
