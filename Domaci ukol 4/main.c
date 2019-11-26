#include <stdio.h>
#include <stdlib.h>

#define MAX_COUNT 200000

typedef struct
{
    int width, height, length, alt, is_working;
}TANK;

int compareAlt(const void * p, const void * q)
{
    TANK tank1 = *(const TANK *)p;
    TANK tank2 = *(const TANK *)q;
    if (tank1.alt < tank2.alt)
        return -1;
    else if (tank1.alt > tank2.alt)
        return 1;
    return 0;
}

int readInput(TANK * tanks, int * count)
{
   printf("Zadejte pocet nadrzi:\n");
   if (scanf("%d", count) != 1 || *count <= 0 || *count > MAX_COUNT)
   {
       *count = 0;
       return 1;
   }
   printf("Zadejte parametry nadrzi:\n");

   for (int i = 0; i < *count; i++)
   {
       if (scanf("%d %d %d %d", &tanks[i].alt, &tanks[i].height, &tanks[i].width, &tanks[i].length) != 4
       || tanks[i].height <= 0 || tanks[i].width <= 0 || tanks[i].length <= 0)
       {
           return 1;
       }
       tanks[i].is_working = 0;
   }
   return 0;
}

int byIncrementing(TANK * tanks, const int * count, const long int * volume, double * h)
{
    double tmp_volume = 0;
    double whole_area = 0;
    *h = tanks[0].alt;

    if (*volume == 0)
        return -1;

    do
    {
        whole_area = 0;
        int flag = 0;
        for (int i = 0; i < *count; i++)
        {
            if (tanks[i].alt <= *h && tanks[i].alt + tanks[i].height > *h)
            {
                whole_area += tanks[i].width * tanks[i].length;
                flag = 1;
            }
            if (tanks[i].alt > *h)
                flag = 1;
        }
        if (!flag)
            return 1;

        tmp_volume += whole_area;
        (*h)++;
    } while (tmp_volume < (double) *volume);

    *h -= (tmp_volume - (double)*volume) / whole_area;
    return 0;
}

int main()
{
    TANK tanks[MAX_COUNT];
    int count = 0;

    if(readInput(tanks, &count))
    {
        printf("Nespravny vstup.\n");
        return 1;
    }
    printf("Zadejte objem vody:\n");

    while (1)
    {
        long int volume;
        double h;

        if (scanf("%ld", &volume) != 1 || volume < 0)
        {
            if (getchar() == EOF)
                return 0;

            printf("Nespravny vstup.\n");
            return 1;
        }

        qsort(tanks, count, sizeof(*tanks), compareAlt);

        switch (byIncrementing(tanks, &count, &volume, &h))
        {
            case 1:
                printf("Pretece.\n");
                break;
            case 0:
                printf("h = %f\n", h);
                break;
            case -1:
                printf("Prazdne.\n");
                break;
        }
    }
}