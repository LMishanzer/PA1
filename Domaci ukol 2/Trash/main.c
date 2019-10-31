#include <stdio.h>

int input(char *mode, int *low, int *high)
{
    int a ;
    if((a = scanf("%s %d %d", mode, low, high)) != 3
    || (*mode != 'c' && *mode != 'l') || *low < 0 || *high < 0 || *low > *high)
    {
        if (getchar() != EOF || a != -1)
            return 1;
        return 2;
    }
    return 0;
}

int is_symmetry(const int *number, int *arr, int *c)
{
    int num = *number;
    int num_b[32], num_b_rev[32];
    for (int i = 0; i < 32; i++)
    {
        int tmp = num >> i;
        if (tmp & 1)
        {
            num_b[i] = 1;
            num_b_rev[31 - i] = 1;
            arr[31 - i] = 1;
        }
        else
        {
            num_b[i] = 0;
            num_b_rev[31 - i] = 0;
            arr[31 - i] = 0;
        }
    }

    int counter = 0;
    while (num_b_rev[counter] == 0 && counter != 31)
    {
        counter++;
    }
    *c = counter;

    int flag = 1;
    for (int i = 0; i + counter < 32; i++)
    {
        num_b_rev[i] = num_b_rev[i + counter];
        num_b_rev[i + counter] = 0;
        if (num_b[i] != num_b_rev[i])
            flag = 0;
    }

    return flag;
}

void find(const char *mode, const int *low, const int *high)
{
    int arr[32];
    int tmp = 0;

    if(*mode == 'l')
    {
        for (int i = *low; i <= *high; i++)
        {
            if (is_symmetry(&i, arr, &tmp) == 1)
            {
                printf("%d = ", i);
                for (int j = tmp; j < 32; j++)
                {
                    printf("%d", arr[j]);
                }
                printf("b\n");
            }
        }
    }
    else if (*mode == 'c')
    {
        int counter = 0;
        for (int i = *low; i <= *high; i++)
        {
            if (is_symmetry(&i, arr, &tmp) == 1)
            {
                counter++;
            }
        }
        printf("Celkem: %d\n", counter);
    }
}

int main ()
{
    printf("Vstupni intervaly:\n");
    while (1)
    {
        char mode;
        int low, high;
        int flag = input(&mode, &low, &high);

        if (flag == 2)
            return 0;

        if(flag == 1)
        {
            printf("Nespravny vstup.\n");
            int a = 0;
            while (a != '\n' && a != EOF)
                a = getchar();
            continue;
        }

        find(&mode, &low, &high);
    }
}
