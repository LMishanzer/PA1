#include <stdio.h>

int input(char *mode, int *num_sys, long long int *low, long long int *high)
{
    int a ;
    if((a = scanf("%s %d %lld %lld", mode, num_sys, low, high)) != 4 || *num_sys < 2 || *num_sys > 36
    || (*mode != 'c' && *mode != 'l') || *low < 0 || *high < 0 || *low > *high)
    {
        if (getchar() != EOF || a != -1)
            return 1;
        return 2;
    }
    return 0;
}

int is_symmetry(const long long int *number, const int *num_sys, int *arr, int *c)
{
    long long int tmp_whole = *number;
    long long int num_b[32], num_b_rev[32];
    for (int i = 0; i < 32; i++)
    {
        int tmp_fractional = (int)(tmp_whole % *num_sys);
        tmp_whole /= *num_sys;

        num_b[i] = tmp_fractional;
        num_b_rev[31 - i] = tmp_fractional;
        arr[31 - i] = tmp_fractional;
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

void find(const char *mode, int *num_sys, const long long int *low, const long long int *high)
{
    int arr[32];
    int tmp = 0;

    if(*mode == 'l')
    {
        for (long long int i = *low; i <= *high; i++)
        {
            if (is_symmetry(&i, num_sys, arr, &tmp) == 1)
            {
                printf("%lld = ", i);
                for (int j = tmp; j < 32; j++)
                {
                    if (arr[j] < 10)
                        printf("%d", arr[j]);
                    else
                        printf("%c", arr[j] + 87);
                }
                printf(" (%d)\n", *num_sys);
            }
        }
    }
    else if (*mode == 'c')
    {
        int counter = 0;
        for (long long int i = *low; i <= *high; i++)
        {
            if (is_symmetry(&i, num_sys, arr, &tmp) == 1)
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
        int num_sys;
        long long int low, high;
        int flag = input(&mode, &num_sys, &low, &high);

        if (flag == 2)
            return 0;

        if(flag == 1)
        {
            printf("Nespravny vstup.\n");
            int a = 0;
            while (a != '\n' && a != EOF) // костиль
                a = getchar();
            continue;
        }

        find(&mode, &num_sys, &low, &high);
    }
}
