#include <stdio.h>
#include <stdlib.h>
#define MIN_BUFFER 64

typedef struct {
    int freq;
    char * line;
} TEMPLATE;

int compareStrings(const void *a, const void *b) {
    size_t i;
    TEMPLATE t1 = *(const TEMPLATE *) a;
    TEMPLATE t2 = *(const TEMPLATE *) b;

    for (i = 0; t1.line[i] == t2.line[i]; i++) {
        if (t1.line[i] == '\0')
            return 0;
    }
    if ((unsigned char)t1.line[i] < (unsigned char)t2.line[i])
        return -1;
    else
        return 1;
}

int compareInt(const void *a, const void *b)
{
    return ( ((TEMPLATE *) a)->freq - ((TEMPLATE *) b)->freq );
}

/**
 *
 * @param line: memory address for saving input
 * @param length: number of saved symbols
 * @return 0 if reading successful
 *         1 if empty line
 *         2 if EOF
 */
int readLine (char ** line)
{
    int max_length = MIN_BUFFER;
    int length;
    *line = (char *) malloc(max_length * sizeof(char));
    char tmp = (char) getchar();
    for (length = 0; tmp != '\n' && tmp != EOF; length++)
    {
        if (length == max_length)
        {
            max_length += max_length;
            *line = (char *) realloc(*line, max_length * sizeof(char));
        }
        (*line)[length] = tmp;
        tmp = (char) getchar();
    }
    (*line)[length] = '\0';
    if (tmp == EOF)
        return 2;
    if (!length)
        return 1;
    return 0;
}

/**
 *
 * @param temps: pointer on pointers to templates
 * @param max_length: length of buffer for templates
 * @return 1 if invalid input
 *         0 if parsing is successful
 */
int parseInput (TEMPLATE ** temps, int * size, int * max_length)
{
    char * buffer;
    int state;      //return signal value

    for (int el = 0; !(state = readLine(&buffer)); el++)
    {
        if (el == *max_length)      //if count of elements equals buffer size
        {
            *max_length += *max_length;
            *temps = (TEMPLATE *) realloc(*temps, *max_length * sizeof(TEMPLATE));
        }

        int i = 0;
        for (; buffer[i] != ':'; i++)
            if (buffer[i] < '0' || buffer[i] > '9') {
                free(buffer);
                return 1;
            }

        (*temps)[el].line = (char *) malloc(*max_length * sizeof(char));

        i++;
        for (int j = 0; ((*temps)[el].line[j] = buffer[i]) != '\0'; j++, i++) { }

        if (sscanf(buffer, "%d", &(*temps)[el].freq) != 1) {
            free(buffer);
            return 1;
        }
        (*size)++;
        free(buffer);
    }
    return state - 1;
}

int search()
{

}

/**
 *
 * @param buffer: array needs to be cleared
 */
void clearing (TEMPLATE * temps, const int size)
{

    for (int i = 0; i < size; i++)
        free(temps[i].line);
    free(temps);
}

int main() {
    int max_size = MIN_BUFFER, size = 0;
    TEMPLATE * temps;
    temps = malloc(max_size * sizeof(TEMPLATE));

    printf("Casto hledane fraze:\n");

    if (parseInput(&temps, &size, &max_size))
    {
        printf("Nespravny vstup.\n");
        clearing(temps, size);
        return 1;
    }

    qsort(temps, size, sizeof(TEMPLATE), compareInt);

    printf("Hledani:\n");

    char *line;
    int flag;
    while ((flag = readLine(&line)) != 2)
    {
        if (flag)
        {
            printf("Nespravny vstup.\n");
            clearing(temps, size);
            return 1;
        }


    }

    clearing(temps, size);

    return 0;
}