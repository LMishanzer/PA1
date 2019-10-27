#include <stdio.h>
#include <math.h>
#include <string.h>
#include <float.h>

const char SSS[4] = "SSS";
const char SUS[4] = "SUS";
const char USU[4] = "USU";
const double pi = 3.14159265359;
const double half_circle = 180;
const double accuracy_sides = 10000;
const double accuracy_angles = 1000000;

int input(double *s, double *a, char *ch)
{
    double tmp[3];
    if (scanf("%3s %lf %lf %lf", ch, &tmp[0], &tmp[1], &tmp[2]) != 4 || tmp[0] <= 0 || tmp[1] <= 0 || tmp[2] <= 0)
    {
        return 1;
    }

    if (!strcmp(ch, SSS))
    {
        for (int i = 0; i < 3; i++){
            s[i] = tmp[i];
            a[i] = acos((tmp[(i + 1) % 3] * tmp[(i + 1) % 3] + tmp[(i + 2) % 3] * tmp[(i + 2) % 3] - tmp[i] * tmp[i]) /
                        (2 * tmp[(i + 1) % 3] * tmp[(i + 2) % 3])) * half_circle / pi;
        }
        return 0;
    }
    else if (!strcmp(ch, SUS))
    {
        a[1] = tmp[1] / half_circle * pi;
        s[0] = tmp[0];
        s[2] = tmp[2];
        s[1] = sqrt(s[0] * s[0] + s[2] * s[2] - 2 * s[0] * s[2] * cos(a[1]));
        a[0] = asin((s[0] * sin(a[1])) / s[1]) * half_circle / pi;
        a[1] = a[1] * half_circle / pi;
        a[2] = (180 - a[0] - a[1]);
        if (a[1] >= 180)
            return 1;
        return 0;
    }
    else if (!strcmp(ch, USU))
    {
        s[1] = tmp[1];
        a[0] = tmp[0] / half_circle * pi;
        a[2] = tmp[2] / half_circle * pi;
        a[1] = pi - a[0] - a[2];
        s[0] = s[1] * sin(a[0]) / sin(a[1]);
        s[2] = s[1] * sin(a[2]) / sin(a[1]);
        a[0] = a[0] / pi * half_circle;
        a[1] = a[1] / pi * half_circle;
        a[2] = a[2] / pi * half_circle;
        if (a[0] >= 180 || a[2] >= 180)
            return 1;
        return 0;
    }
    else
        return 1;
}

int check(const double *sides, const double *angles)
{
    for(int i = 0; i < 3; i++){
        if (sides[i] - sides[(i + 1) % 3] - sides[(i + 2) % 3] >= accuracy_sides * DBL_EPSILON * sides[i] ||
                sides[i] == sides[(i + 1) % 3] + sides[(i + 2) % 3])
            return 1;
    }
    if (fabs(180 - angles[0] - angles[1] - angles[2]) > accuracy_angles * DBL_EPSILON)
        return 1;
    return 0;
}

int comparison(const double *first_sides, const double *first_angles,
               const double *second_sides, const double *second_angles)
{
    int is_equal = 0;
    int is_similar = 0;
    for (int i = 0; i < 3; i++){
        is_equal = 0;
        for (int j = 0; j < 3; j++){
            if (fabs(first_sides[i] - second_sides[j]) < accuracy_sides * DBL_EPSILON * first_sides[i]) {
                is_equal = 1;
                break;
            }
        }
        if (is_equal == 0)
            break;
    }
    if (is_equal == 1)
        return 2;
    else
    {
        for (int i = 0; i < 3; i++){
            is_similar = 0;
            for (int j = 0; j < 3; j++){
                if (fabs(first_angles[i] - second_angles[j]) < accuracy_angles * DBL_EPSILON) {
                    is_similar = 1;
                    break;
                }
            }
            if (is_similar == 0)
                break;
        }
        if (is_similar == 1)
            return 1;
        else
            return 0;
    }
}

int main() {
    char ch[2][4];
    double sides[2][3];
    double angles[2][3];

    for (int i = 0; i < 2; i++) {
        printf("Trojuhelnik #%d:\n", i + 1);
        if (input(sides[i], angles[i], ch[i]) == 1) {
            printf("Nespravny vstup.\n");
            return 1;
        }
//        for (int j = 0; j < 3; j++) {
//            sides[i][j] = round(sides[i][j] * 100000000) / 100000000;
//            angles[i][j] = round(angles[i][j] * 100000) / 100000;
//        }
        if(check(sides[i], angles[i]) == 1) {
            printf("Vstup netvori trojuhelnik.\n");
            return 0;
        }
    }

    switch (comparison(sides[0], angles[0], sides[1], angles[1])){
        case 0:
            printf("Trojuhelniky nejsou shodne ani podobne.\n");
            return 0;
        case 1:
            printf("Trojuhelniky nejsou shodne, ale jsou podobne.\n");
            return 0;
        case 2:
            printf("Trojuhelniky jsou shodne.\n");
            return 0;
    }

    return 0;
}