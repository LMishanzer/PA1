#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
#define MIN_BUFFER 64
#define ACCURACY 10000

typedef struct {
    double x, y;
    char * name, *buffer;
} FLY;

int readInput(char ** buffer)
{
    size_t bufsize = MIN_BUFFER;
    *buffer = (char *)malloc(bufsize * sizeof(char));
    int current_size = 0;
    char temp;

    while (1)
    {
        temp = (char) getchar();
        if (temp == '\n')
        {
            (*buffer)[current_size] = '\0';
            return 0;
        }
        if (temp == EOF)
        {
            (*buffer)[current_size] = '\0';
            return 1;
        }
        (*buffer)[current_size] = temp;
        current_size++;
        if (current_size == (int) bufsize)
        {
            bufsize += bufsize;
            *buffer = (char *) realloc(*buffer, bufsize * sizeof(char));
        }
    }
}

int parseInput(char ** line, FLY * fly)
{
    if (sscanf(*line, " [ %lf , %lf ]", &(fly->x), &(fly->y)) != 2)
    {
        return 1;
    }

    int i;
    for (i = 0; *(*line + i) != ','; i++) {
        if (*(*line + i) == '\0'
        || !((*(*line + i) >= '0' && *(*line + i) <= '9')
        || *(*line + i) == ' ' || *(*line + i) == '\t' || *(*line + i) == '['
        || *(*line + i) == '.' || *(*line + i) == '-' || *(*line + i) == 'e'))
            return 1;
    }
    for (i++; *(*line + i) != ']'; i++) {
        if (*(*line + i) == '\0'
            || !((*(*line + i) >= '0' && *(*line + i) <= '9')
                 || *(*line + i) == ' ' || *(*line + i) == '\t' || *(*line + i) == '['
                 || *(*line + i) == '.' || *(*line + i) == '-' || *(*line + i) == 'e'))
            return 1;
    }
    i++;
    for ( ; *(*line + i) == ' ' || *(*line + i) == '\t'; i++) { }

    fly->name = *line + i;

    if ((fly->name)[0] == '\0' || (fly->name)[0] == ']')
        return 1;

    return 0;
}

double measure_distance (FLY * fly1, FLY * fly2)
{
    return sqrt(pow((fly1->x - fly2->x), 2) + pow((fly1->y - fly2->y), 2));
}

double findMinDistance(FLY * flies, const int * num_of_flies)
{
    double min_distance = DBL_MAX;
    for (int i = 0; i < *num_of_flies; i++)
    {
        for (int j = 0; j < *num_of_flies; j++)
        {
            if (i != j)
            {
                double tmp = measure_distance(&flies[i], &flies[j]);
                if (tmp < min_distance)
                {
                    min_distance = tmp;
                }
            }
        }
    }
    return min_distance;
}

void iLoveMarry (FLY * flies, int * num_of_flies)
{
    double min_distance = findMinDistance(flies, num_of_flies);
    printf("Nejmensi vzdalenost: %f\n", min_distance);
    for (int i = 0; i < *num_of_flies; i++)
    {
        for (int j = i + 1; j < *num_of_flies; j++)
        {
            if (fabs(min_distance - measure_distance(&flies[i], &flies[j])) <
            ACCURACY * (min_distance ? min_distance : 1) * DBL_EPSILON)
            {
                    printf("%s - %s\n", flies[i].name, flies[j].name);
            }
        }
    }
}

void clearing (FLY * flies, const int * num_of_flies)
{
    for (int i = 0; i < *num_of_flies + 1; i++)
    {
        free(flies[i].buffer);
    }
    free(flies);
}

int main(void) {
    FLY * flies;
    int number_of_flies = 0, max_number_of_flies = 10;
    flies = (FLY *) malloc(max_number_of_flies * sizeof(FLY));

    printf("Zadejte lety:\n");
    while (1)
    {
        flies[number_of_flies].buffer = NULL;
        if (readInput(&flies[number_of_flies].buffer))
        {
            if (number_of_flies == 0)
            {
                clearing(flies, &number_of_flies);
                printf("Nespravny vstup.\n");
                return 0;
            }
            break;
        }
        if (parseInput(&flies[number_of_flies].buffer, &flies[number_of_flies]))
        {
            printf("Nespravny vstup.\n");
            clearing(flies, &number_of_flies);
            return 1;
        }

        number_of_flies++;

        if (number_of_flies == max_number_of_flies)
        {
            max_number_of_flies += max_number_of_flies;
            flies = (FLY *) realloc(flies, max_number_of_flies * sizeof(FLY));
        }
    }
    if (number_of_flies < 2)
    {
        printf("Nespravny vstup.\n");
        clearing(flies, &number_of_flies);
        return 1;
    }
    iLoveMarry(flies, &number_of_flies);
    clearing(flies, &number_of_flies);

    return 0;
}
