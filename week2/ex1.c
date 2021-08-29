#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int int_;
    float float_;
    double double_;

    int_ = INT_MAX;
    float_ = FLT_MAX;
    double_ = DBL_MAX;

    printf("INT_MAX size = %ld\n", sizeof(int_));
    printf("INT_MAX value = %d\n", int_);
    printf("FLT_MAX size = %ld\n", sizeof(float_));
    printf("FLT_MAX value = %lf\n", float_);
    printf("DBL_MAX size = %ld\n", sizeof(double_));
    printf("DBL_MAX value = %lf\n", double_);

    return 0;
}

