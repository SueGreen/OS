#include <stdio.h>
#include <zconf.h>
#include <limits.h>
#include <float.h>
int main() {
    int a;
    float b;
    double c;
    a = INT_MAX;
    b = FLT_MAX;
    c = DBL_MAX;
    printf("Size of a is %i, a = %g\n", sizeof(a), a);
    printf("Size of b is %i, b = %g\n", sizeof(b), b);
    printf("Size of c is %i, c = %g\n", sizeof(c), c);
    return 0;
}