/**
 * @file encrypt.c
 * @author  Lior Paz <lior.paz1@mail.huji.ac.il>
 * @version 1.0
 * @date 7 Aug 2018
 *
 * @brief Program to encrypt text by Ceaser's cypher.
 *
 * @section DESCRIPTION
 * Program to encrypt text by Caser's cypher.
 * Input  : Text to encrypt and Ceaser's encryption key.
 * Process: Changing the letters one by one according to the input and the key.
 * Output : Encrypted text.
 */

// ------------------------------ includes ------------------------------
#include <stdio.h>
#include <stdlib.h>

// -------------------------- const definitions -------------------------
/**
 * @brief Number of letters in the english language
 */
#define LETTERS_NUM 26

/**
 * @brief Range of encryption keys
 */
#define LETTERS_RANGE 25

/**
 * @brief Size of the buffer we read in every iteration
 */
#define BUFFER_SIZE 128

/**
 * @brief Buffer size as string
 */
#define BUFFER_SIZE_S "128"

#define UPPER_CASE_LOWER_BOUND ('a' -1)
#define UPPER_CASE_UPPER_BOUND ('z' + 1)
#define LOWER_CASE_LOWER_BOUND ('A' -1)
#define LOWER_CASE_UPPER_BOUND ('Z' + 1)

/**
 * @brief False
 */
#define FALSE 0

/**
 * @brief sign of empty cell
 */
#define NULL_CHAR '0'

/**
 * @brief Error message
 */
#define INVALID_INPUT "Not a valid encrypt constant!"

/**
 * @brief Encryption function
 */
#define ENCRYPT(lower) ((char) (((input - (lower) + key) % LETTERS_NUM ) + (lower) ))


// ------------------------------ functions -----------------------------
/**
 * @brief Encrypt a single Char according to an encryption key using Ceaser's Cypher
 * @param key Encryption key between 0 to 25
 * @param input Char to encrypt
 * @return Encrypted Char
 */
char encrypt(int key, char input)
{
    if (UPPER_CASE_LOWER_BOUND < input && input < UPPER_CASE_UPPER_BOUND)
    {
        return ENCRYPT((UPPER_CASE_LOWER_BOUND + 1));
    }
    else if (LOWER_CASE_LOWER_BOUND < input && input < LOWER_CASE_UPPER_BOUND)
    {
        return ENCRYPT((LOWER_CASE_LOWER_BOUND + 1));
    }
    else
    {
        return input;
    }
}

/**
 * @brief Prints an Encrypted Array of Chars
 * @param input Array of Chars to encrypt
 * @param encryptionKey Encryption key
 * @param size Num of Chars to print
 */
void printOutput(char input[], int encryptionKey, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        input[i] = encrypt(encryptionKey, input[i]);
        printf("%c", input[i]);
        input[i] = NULL_CHAR;
    }
}

/**
 * @brief The main Function.
 * @return 0, to tell the system the execution ended without errors, or 1 if an error has occurred.
 */
int main()
{
    char buffer[BUFFER_SIZE + 1] = {NULL_CHAR};
    int encryptionKey;
    int size;
    if (scanf("%d ", &encryptionKey) == FALSE)
    {
        fprintf(stderr, INVALID_INPUT);
        return EXIT_FAILURE;
    }
    if (LETTERS_RANGE < encryptionKey || encryptionKey < -LETTERS_RANGE)
    {
        fprintf(stderr, INVALID_INPUT);
        return EXIT_FAILURE;
    }
    if (encryptionKey < 0)
    {
        encryptionKey += LETTERS_NUM;
    }
    while (scanf("%"BUFFER_SIZE_S"c%n", buffer, &size) != EOF)
    {
        printOutput(buffer, encryptionKey, size);
    }
    return EXIT_SUCCESS;
}