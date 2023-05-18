/*
** EPITECH PROJECT, 2021
** mylib
** File description:
** mylib
*/

#ifndef CJSON_H_
    #define CJSON_H_

    #define JSON_STRING_CHAR "\"'"
    #define OPEN_VALUE_CHAR "\"'{["
    #define CLOSE_VALUE_CHAR "\"'}]"
    #define KEY_CHAR "\"'"
    #define OPEN_CHAR "{"
    #define CLOSE_CHAR "}"
    #define VALUE_CHAR ":"
    #define SPLIT_CHAR ","
    #define NULL_CHAR " \n\t"


    #include "utils.h"
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>



typedef struct data_s {
    char *key;
    char *value;
    struct data_s *next;
}data;

typedef struct {
    data *data;
    int lenght;
}cjson;


/**
 * @brief Free a cjson object
 * @param obj Pointer to the cjson object to free
 */
void cjson_free(cjson *obj);

/**
 * @brief Append data at the beginning of the object
 * @param obj Pointer to the cjson object to append data to
 * @param nb Number of pair following `nb` parameter
 * @param ... Key-value pairs, alternating keys and values
 * @return cjson* Pointer to the modified cjson object
 */
cjson *cjson_push(cjson *obj, int nb, ...);

/**
 * @brief Get the value of a key from a cjson object
 * The returned string needs to be freed after use.
 * @param obj Pointer to the cjson object to search for the key
 * @param key The key to search for
 * @return const char* Pointer to the value of the key, or NULL if not found
 */
char *cjson_get_by_key(const cjson *obj, const char *key);

/**
 * @brief Get the value at an index from a cjson object.
 * The returned string needs to be freed after use.
 * @param obj Pointer to the cjson object to get the value from
 * @param index The index of the value to retrieve
 * @return const char* Pointer to the value at the index, or NULL if not found
 */
char *cjson_get_by_index(const cjson *obj, const int index);

/**
 * @brief Get the cjson object as a string.
 * The returned string needs to be freed after use.
 * @param obj Pointer to the cjson object to convert to string
 * @param pretty Whether or not to pretty-print the resulting string
 * @return char* Pointer to the resulting string
 */
char *cjson_get_obj_str(const cjson *obj, bool pretty);

/**
 * @brief Initialize a new cjson object
 * @return cjson* Pointer to the newly created cjson object
 */
cjson *cjson_init(void);

/**
 * @brief Get the cjson object as a char*** array.
 * The returned array needs to be freed after use.
 * @param obj Pointer to the cjson object to convert to array
 * @return char*** Pointer to the resulting array
 */
char ***cjson_get_obj_array(const cjson *obj);

/**
 * @brief Free an array created by `cjson_get_obj_array`
 * @param obj_array Pointer to the array to free
 */
void cjson_free_obj_array(char ***obj_array);

/**
 * @brief Delete a value from a cjson object using a key
 * @param obj Pointer to the cjson object to delete the value from
 * @param key The key of the value to delete
 */
void cjson_delete_by_key(cjson *obj, const char *key);

/**
 * @brief Delete a value from a cjson object using an index
 * @param obj Pointer to the cjson object to delete the value from
 * @param index The index of the value to delete
 */
void cjson_delete_by_index(cjson *obj, const int index);

/**
 * @brief Set a value in a cjson object using a key
 * @param obj Pointer to the cjson object to set the value in
 * @param key The key to set the value of
 * @param value The value to set
 */
void cjson_set_by_key(cjson *obj, const char *key, const char *value);

/**
 * @brief Set the value at a given index in a cjson object.
 * @param obj The cjson object to modify.
 * @param index The index at which to set the value.
 * @param value The value to set.
 */
void cjson_set_by_index(cjson *obj, const int index, const char *value);

/**
 * @brief Parse a JSON string and return a cjson object.
 * @param src The JSON string to parse.
 * @return A cjson object representing the parsed JSON string.
 */
cjson *cjson_parse_obj_str(const char *src);

/**
 * @brief Write a cjson object to a file.
 * @param path The path to the file to write.
 * @param flags Flags to use when opening the file.
 * @param obj The cjson object to write to the file.
 * @return true if the file was written successfully, false otherwise.
 */
bool cjson_write_file(char *path, int flags, const cjson *obj);

/**
 * @brief Read a JSON file and return a cjson object.
 * @param path The path to the JSON file to read.
 * @param buf A buffer to use when reading the file.
 * @return A cjson object representing the JSON data in the file.
 */
cjson *cjson_read_file(const char *path, int buf);


/**
 * @brief Parse a string array into a two-dimensional array.
 * This function takes a string array and parses it into a two-dimensional
 * array. The resulting array is terminated with a NULL pointer.
 * The resulting array is dynamically allocated and must be freed with
 * `cjson_free_array()` when no longer needed.
 * @param array The string to be parsed.
 * @return char** A pointer to the resulting two-dimensional array.
 */
char **cjson_parse_array(char *array);

/**
 * @brief Convert a two-dimensional array into a string.
 * This function takes a two-dimensional array and converts it into a string.
 * The input array must be terminated with a NULL pointer.
 * The resulting string is dynamically allocated and must be freed with
 * `free()` when no longer needed.
 * @param array The two-dimensional array to be converted.
 * @return char* A pointer to the resulting string.
 */
char *cjson_stringify_array(char **array);

/**
 * @brief Free a two-dimensional array.
 * This function frees the memory allocated for a two-dimensional array.
 * The array must be terminated with a NULL pointer.
 * @param array The two-dimensional array to be freed.
 */
void cjson_free_array(char **array);

/**
 * @brief Creates a JSON-formatted string containing the specified key-value
 * pairs.
 * The resulting string will have the format: {"key1":value1, "key2":value2,
 *  ...}
 * @param nb The number of key-value pairs to include in the string.
 * @param ... Key-value pairs in the form of alternating keys and values.
 * @return A dynamically-allocated string containing the JSON-formatted
 * key-value pairs. The caller is responsible for freeing the memory
 * allocated by this function.
 */
char *cjson_do_string(int nb, ...);

/**
 * @brief Do not use. This function is for internal use only.
 */
char get_the_char(const char *src, int *i);

/**
 * @brief Do not use. This function is for internal use only.
 */
bool get_next(const char *src, int *index, char *good, bool m_index);

/**
 * @brief Do not use. This function is for internal use only.
 */
bool is_char_in(char c, const char *ex);

/**
 * @brief Do not use. This function is for internal use only.
 */
void add_node(char *key, char *value, data **obj, bool encode);





#endif // !CJSON_H_
