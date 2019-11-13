#include <stdio.h>

#include "../unittest.h"

int main(void){
    int a, b;
    double c, d;

    double max_difference;

    bool is_true;
    
    printf("Test assert_int_equal().\n");
    printf("    Should assert 2 and 2 are equal:\n");

    a = 2;
    b = 2;

    is_true = assert_int_equal(a, b);

    printf("        %d == %d: %s\n", a, b, is_true ? "true" : "false");
    if(!is_true) return 1;

    printf("    Should assert 2 and -1 are not equal:\n");

    a = 2;
    b = -1;

    is_true = assert_int_equal(a, b);

    printf("        %d == %d: %s\n", a, b, is_true ? "true" : "false");
    if(is_true) return 1;

    printf("\nTest assert_double_equal()\n");
    printf("    Should assert 4.0 / 2.0 and 1.0 + 1.0 are equal:\n");

    c = 4 / 2;
    d = 1;

    d++;

    is_true = assert_double_equal(c, d);

    printf("        %f == %f: %s\n", c, d, is_true ? "true" : "false");
    if(!is_true) return 1;

    printf("    Should assert 5.000000001 and 5.000000000 are not equal:\n");

    c = 5.000000001;
    d = 5.000000000;

    is_true = assert_double_equal(c, d);

    printf("        %f == %f: %s\n", c, d, is_true ? "true" : "false");
    if(is_true) return 1;

    printf("\nTest assert_double_similar()\n");
    printf("    Should assert 7.6 and 7.2 are within 0.5 of each other:\n");

    c = 7.6;
    d = 7.2;

    max_difference = 0.5;

    is_true = assert_double_similar(c, d, max_difference);

    printf("        %f - %f < %f: %s\n", c, d, max_difference, is_true ? "true" : "false");
    if(!is_true) return 1;

    printf("    Should assert 14.437 and 1.234 are not within 4.6 of each other:\n");

    c = 14.437;
    d = 1.234;

    max_difference = 4.6;

    is_true = assert_double_similar(c, d, max_difference);

    printf("        %f - %f < %f: %s\n", c, d, max_difference, is_true ? "true" : "false");
    if(is_true) return 1;

    printf("\nTest Passed.\n");

    return 0;
}

