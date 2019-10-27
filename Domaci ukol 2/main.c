#include <stdio.h>
#include <math.h>
#include <string.h>

int input(char *mode, unsigned int *min, unsigned int *max){
    if (scanf("%s %u %u", mode, min, max) != 3 || (*mode != 'c' && *mode != 'l') || *min > *max)
    {
        if (getchar() == EOF)
            return 2;
        return 1;
    }
    return 0;
}

int symmetry(const unsigned int *num, char res1[33], char res2[33]){
    printf("1\n");
    for (int i = 0; i < 32; i++)
    {
        int tmp = *num >> i;
        if (tmp & 1)
        {
            res1[31 - i] = '1';
            res2[31 - i] = '1';
        }
        else{
            res1[31 - i] = '0';
            res2[31 - i] = '0';
        }
    }
    printf("2\n");
    printf("%s , %s\n", res1, res2);
    for (int i = 0; i < 32; i++)
    {
        char tmp = res1[i];
        res1[i] = res1[31 - i];
        res1[31 - i] = tmp;
    }
    printf("%s , %s\n", res1, res2);
    if (strcmp(res1, res2) == 0) {
        return 1;
    }
    return 0;
}

int main() {
    char mode = ' ';
    unsigned int min, max;
    int flag = 1;

    printf("Vstupni intervaly:\n");
    while(flag) {
        int a = input(&mode, &min, &max);
        if(a == 1)
        {
            printf("Nespravny vstup.\n");
            continue;
        }
        if(a == 2)
        {
            return 0;
        }
        if (mode == 'l') {
            for (unsigned int i = min; i <= max; i++) {
                char *res1[33], *res2[33];
                *res1 = "";
                *res2 = "";
                int res = symmetry(&i, res1, res2);
                if (res == 1){
                    printf("%d = %sb\n", i, res1);
                }
            }
        }
        else if (mode == 'c'){
            int counter = 0;
            for (unsigned int i = min; i <= max; i++) {
                char *res1 = "", *res2 = "";
                if (symmetry(&i, res1, res2) == 1){
                    counter++;
                }
            }
            printf("Celkem: %d\n", counter);
        }
    }
}