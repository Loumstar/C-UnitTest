#include "unittest.h"

bool assert_int_equal(int a, int b){
    return a == b;
}

bool assert_double_equal(double a, double b){
    return fabs(a - b) < DBL_EPSILON;
}

bool assert_double_similar(double a, double b, double max_difference){
    return fabs(a - b) < max_difference;
}
