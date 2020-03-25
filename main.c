#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "../laba1/func.h"

void test1(int number, int type)
{
    void* void_test1;
    void_test1 = create_array(&number, &type);
    if (void_test1 != NULL)
        printf("Test#1 completed succesfully!\n");
}

void test2_for_int_quick_sort()
{
    void* source_array;
    int type = 0;
    int number = 5;
    (int*)source_array = (int*)malloc(5 * sizeof(int));
    ((int*)source_array)[0] = 2;
    ((int*)source_array)[1] = -33;
    ((int*)source_array)[2] = 555;
    ((int*)source_array)[3] = 11;
    ((int*)source_array)[4] = -637;
    int first = 0;
    int last = 4;
    quick_sort(&source_array, &first, &last, &type);
    int expected_array[5] = { -637, -33 ,2 ,11 ,555 };
    int i;
    for (i = 0; i < 5; i++)
    {
        if (((int*)source_array)[i] != expected_array[i])
        {
            printf("Test#2 failed\n");
            break;
        }
    }
    if (i == 5)
        printf("Test#2 completed succesfully!\n");
}

void test2_for_float_quick_sort()
{
    void* source_array;
    int type = 1;
    int number = 5;
    (float*)source_array = (float*)malloc(5 * sizeof(float));
    ((float*)source_array)[0] = 2311.22;
    ((float*)source_array)[1] = -3113;
    ((float*)source_array)[2] = -33.1;
    ((float*)source_array)[3] = 8877.0;
    ((float*)source_array)[4] = 111.11111;
    int first = 0;
    int last = 4;
    quick_sort(&source_array, &first, &last, &type);
    float expected_array[5] = { -3113, -33.1 ,111.11111 ,2311.22 ,8877.0 };
    int i;
    for (i = 0; i < 5; i++)
    {
        if (((float*)source_array)[i] != expected_array[i])
        {
            printf("Test#2 failed\n");
            break;
        }
    }
    if (i == 5)
        printf("Test#2 completed succesfully!\n");
}

void test3_for_int_quick_sort()
{
    void* source_array;
    int type = 0;
    int number = 4;
    (int*)source_array = (int*)malloc(4 * sizeof(int));
    ((int*)source_array)[0] = 111;
    ((int*)source_array)[1] = 0;
    ((int*)source_array)[2] = -11;
    ((int*)source_array)[3] = -11;
    int first = 0;
    int last = 3;
    quick_sort(&source_array, &first, &last, &type);
    int expected_array[4] = { -11, -11, 0, 111 };
    int i;
    for (i = 0; i < 4; i++)
    {
        if (((int*)source_array)[i] != expected_array[i])
        {
            printf("Test#3 failed\n");
            break;
        }
    }
    if (i == 4)
        printf("Test#3 completed succesfully!\n");
}

void test3_for_float_quick_sort()
{
    void* source_array;
    int type = 1;
    int number = 4;
    (float*)source_array = (float*)malloc(4 * sizeof(float));
    ((float*)source_array)[0] = 0.133;
    ((float*)source_array)[1] = -0.335;
    ((float*)source_array)[2] = -0.332;
    ((float*)source_array)[3] = 0;
    int first = 0;
    int last = 3;
    float expected_array[4];
    expected_array[0] = ((float*)source_array)[1];
    expected_array[1] = ((float*)source_array)[2];
    expected_array[2] = ((float*)source_array)[3];
    expected_array[3] = ((float*)source_array)[0];
    quick_sort(&source_array, &first, &last, &type);
    int i;
    for (i = 0; i < 4; i++)
    {
        if (((float*)source_array)[i] != expected_array[i])
        {
            printf("Test#3 failed\n");
            break;
        }
    }
    if (i == 4)
        printf("Test#3 completed succesfully!\n");
}

void test4_concatenation(int type)
{
    int number_source = 2;
    int number_to_conc = number_source;
    void* test4_void_pointer;
    test4_void_pointer = create_array(&number_source, &type);
    test4_void_pointer = concatenation(&test4_void_pointer, &number_to_conc, &type);
    if (number_to_conc > number_source)
    {
        int i;
        for (i = number_source; i < number_to_conc; i++)
        {
            if (type == 0)
            {
                if (&((int*)test4_void_pointer)[i] == NULL)
                    break;
            }
            if (type == 1)
            {
                if (&((float*)test4_void_pointer)[i] == NULL)
                    break;
            }

        }
        if (i == number_to_conc)
            printf("Test#4 completed succesfully!\n");
        else
            printf("Test#4 failed\n");
    }
}


void test5_inc2(int type)
{
    void* test5_void_pointer = NULL;
    int exp_int = 13;
    float exp_float = 13.5;
    if (type == 0)
    {
        (int*)test5_void_pointer = (int*)malloc(1 * sizeof(int));
        (*((int*)test5_void_pointer)) = 11;
    }
    if (type == 1)
    {
        (float*)test5_void_pointer = (float*)malloc(1 * sizeof(float));
        (*((float*)test5_void_pointer)) = 11.5;
    }
    inc2(test5_void_pointer, &type);

    if (*((int*)test5_void_pointer) == exp_int || *((float*)test5_void_pointer) == exp_float)
        printf("Test#5 completed succesfully!\n");
    else
        printf("Test#5 failed\n");
}

void test6_map_int()
{
    void* test6_void_pointer;
    int type = 0;
    int number = 3;
    (int*)test6_void_pointer = (int*)malloc(number * sizeof(int));
    ((int*)test6_void_pointer)[0] = 14;
    ((int*)test6_void_pointer)[1] = -322;
    ((int*)test6_void_pointer)[2] = 3333;
    map(test6_void_pointer, &number, &type, inc2);
    int exp_array[3];
    exp_array[0] = 16;
    exp_array[1] = -320;
    exp_array[2] = 3335;
    int i;
    for (i = 0; i < 3; i++)
    {
        if (exp_array[i] != ((int*)test6_void_pointer)[i])
            break;
    }
    if (i == 3)
        printf("Test#6 completed succesfully!\n");
    else
        printf("Test#6 failed\n");
}

void test6_map_float()
{
    void* test6_void_pointer;
    int type = 1;
    int number = 3;
    (float*)test6_void_pointer = (float*)malloc(number * sizeof(float));
    ((float*)test6_void_pointer)[0] = 14.31;
    ((float*)test6_void_pointer)[1] = 344.111;
    ((float*)test6_void_pointer)[2] = 88.2;
    float exp_array[3];
    exp_array[0] = ((float*)test6_void_pointer)[0] + 2;
    exp_array[1] = ((float*)test6_void_pointer)[1] + 2;
    exp_array[2] = ((float*)test6_void_pointer)[2] + 2;
    map(test6_void_pointer, &number, &type, inc2);
    int i;
    for (i = 0; i < 3; i++)
    {
        if (exp_array[i] != ((float*)test6_void_pointer)[i])
            break;
    }
    if (i == 3)
        printf("Test#6 completed succesfully!\n");
    else
        printf("Test#6 failed\n");
}

void test_78_comparison(int type)
{
    void* test7_void_pointer;
    if (type == 0)
    {
        (int*)test7_void_pointer = (int*)malloc(1 * sizeof(int));
        *(int*)test7_void_pointer = 192;
        if (comparison(test7_void_pointer, &type))
            printf("Test#7 completed succesfully!\n");
        else
            printf("Test#7 failed\n");
        *(int*)test7_void_pointer = -3221;
        if (comparison(test7_void_pointer, &type))
            printf("Test#8 failed\n");
        else
            printf("Test#8 completed succesfully!\n");
    }
    if (type == 1)
    {
        (float*)test7_void_pointer = (float*)malloc(1 * sizeof(float));
        *(float*)test7_void_pointer = 332.111;
        if (comparison(test7_void_pointer, &type))
            printf("Test#7 completed succesfully!\n");
        else
            printf("Test#7 failed\n");
        *(float*)test7_void_pointer = -3754.13;
        if (comparison(test7_void_pointer, &type))
            printf("Test#8 failed\n");
        else
            printf("Test#8 completed succesfully!\n");
    }
}

void test9_where_int(int type)
{
    void* test9_void_pointer;
    void* test9_void_pointer_where;
    int number = 5;
    void* where(void* marker_void, int* type_marker, int* number, int (*replacement_func)(void* p, int* type));
    if (type == 0)
    {
        int exp_array[3];
        (int*)test9_void_pointer = (int*)malloc(5 * sizeof(int));
        ((int*)test9_void_pointer)[0] = 321;
        ((int*)test9_void_pointer)[1] = -332;
        ((int*)test9_void_pointer)[2] = 20;
        ((int*)test9_void_pointer)[3] = 0;
        ((int*)test9_void_pointer)[4] = 111;
        test9_void_pointer_where = where(test9_void_pointer, &type, &number, comparison);
        exp_array[0] = 321;
        exp_array[1] = 20;
        exp_array[2] = 111;
        int i;
        for (i = 0; i < 3; i++)
        {
            if (exp_array[i] != ((int*)test9_void_pointer_where)[i])
                break;
        }
        if (i == 3)
            printf("Test#9 completed succesfully!\n");
        else
            printf("Test#9 failed\n");
    }
}

void test9_where_float(int type)
{
    void* test9_void_pointer;
    void* test9_void_pointer_where;
    int number = 5;
    void* where(void* marker_void, int* type_marker, int* number, int (*replacement_func)(void* p, int* type));
    if (type == 1)
    {
        float exp_array[3];
        (float*)test9_void_pointer = (float*)malloc(5 * sizeof(float));
        ((float*)test9_void_pointer)[0] = 322.13;
        ((float*)test9_void_pointer)[1] = -753.13;
        ((float*)test9_void_pointer)[2] = 84.45;
        ((float*)test9_void_pointer)[3] = 0;
        ((float*)test9_void_pointer)[4] = 666.53;
        exp_array[0] = ((float*)test9_void_pointer)[0];
        exp_array[1] = ((float*)test9_void_pointer)[2];
        exp_array[2] = ((float*)test9_void_pointer)[4];
        test9_void_pointer_where = where(test9_void_pointer, &type, &number, comparison);
        int i;
        for (i = 0; i < 3; i++)
        {
            if (exp_array[i] != ((float*)test9_void_pointer_where)[i])
                break;
        }
        if (i == 3)
            printf("Test#9 completed succesfully!\n");
        else
            printf("Test#9 failed\n");
    }
}

void test10_where_int2(int type)
{
    void* test10_void_pointer;
    void* test10_void_pointer_where;
    int number = 4;
    void* where(void* marker_void, int* type_marker, int* number, int (*replacement_func)(void* p, int* type));
    if (type == 0)
    {
        int exp_array[3];
        (int*)test10_void_pointer = (int*)malloc(4 * sizeof(int));
        ((int*)test10_void_pointer)[0] = 3123;
        ((int*)test10_void_pointer)[1] = 1112;
        ((int*)test10_void_pointer)[2] = -44;
        ((int*)test10_void_pointer)[3] = 99;
        test10_void_pointer_where = where(test10_void_pointer, &type, &number, comparison);
        exp_array[0] = 3123;
        exp_array[1] = 1112;
        exp_array[2] = 99;
        int i;
        for (i = 0; i < 3; i++)
        {
            if (exp_array[i] != ((int*)test10_void_pointer_where)[i])
                break;
        }
        if (i == 3)
            printf("Test#10 completed succesfully!\n");
        else
            printf("Test#10 failed\n");
    }
}

void test10_where_float2(int type)
{
    void* test10_void_pointer;
    void* test10_void_pointer_where;
    int number = 4;
    void* where(void* marker_void, int* type_marker, int* number, int (*replacement_func)(void* p, int* type));
    if (type == 1)
    {
        float exp_array[3];
        (float*)test10_void_pointer = (float*)malloc(4 * sizeof(float));
        ((float*)test10_void_pointer)[0] = 444.13;
        ((float*)test10_void_pointer)[1] = -57.23;
        ((float*)test10_void_pointer)[2] = 98.56;
        ((float*)test10_void_pointer)[3] = 75.2;
        exp_array[0] = ((float*)test10_void_pointer)[0];
        exp_array[1] = ((float*)test10_void_pointer)[2];
        exp_array[2] = ((float*)test10_void_pointer)[3];
        test10_void_pointer_where = where(test10_void_pointer, &type, &number, comparison);
        int i;
        for (i = 0; i < 3; i++)
        {
            if (exp_array[i] != ((float*)test10_void_pointer_where)[i])
                break;
        }
        if (i == 3)
            printf("Test#10 completed succesfully!\n");
        else
            printf("Test#10 failed\n");
    }
}
int main()
{
    void* pointer_void;
    int number;
    int type;
    printf("enter number of array elements\n");
    while (scanf_s("%d", &number) == 0)
    {
        scanf_s("%*[^\n,\n]");
        printf("uncorrect input, enter number!\n");
    }
    while (number < 0)
    {
        scanf_s("%*[^\n,\n]");
        printf("uncorrect input, enter positive number or zero!\n");
        scanf_s("%d", &number);
    }

    printf("array of float elements press 1\narray of integer elements press 0\n");
    while ((scanf_s("%d", &type) == 0))
    {
        scanf_s("%*[^\n,\n]");
        printf("uncorrect input, enter 1 or 0\n");
    }
    while ((type != 0) && (type != 1))
    {
        scanf_s("%*[^\n,\n]");
        printf("uncorrect input, enter 1 or 0\n");
        scanf_s("%d", &type);
    }
    void* pointer_void_where;
    pointer_void = create_array(&number, &type);
    int choice = 12;
    while (choice != 0)
    {
        int first = 0;
        int last = number - 1;
        printf("\n1.to sort array\n"
            "2.to create and concatenate 2nd array\n"
            "3.to increase by 2 every array`s element\n"
            "4.to create new array from positive elements\n"
            "5.to test\n"
            "0.to exit\n");
        while ((scanf_s("%d", &choice) == 0) && (choice != 0) && (choice != 1) && (choice != 2) && (choice != 3) && (choice != 4) && (choice != 5))
        {
            scanf_s("%*[^\n,\n]");
            printf("uncorrect input, enter 0 or 1 or 2 or 3 or 4\n");
            scanf_s("%d", &choice);
        };
        if (choice == 1)
            quick_sort(&pointer_void, &first, &last, &type);
        if (choice == 2)
            pointer_void = concatenation(&pointer_void, &number, &type);
        if (choice == 3)
            map(pointer_void, &number, &type, inc2);
        if (choice == 4)
            pointer_void_where = where(pointer_void, &type, &number, comparison);
        printf("main array :");
        if (type == 0)
        {
            for (int i = 0; i < number; i++)
                printf("%d ", ((int*)pointer_void)[i]);
        }
        if (type == 1)
        {
            for (int i = 0; i < number; i++)
                printf("%f ", ((float*)pointer_void)[i]);
        }
        printf("\n");
        if (choice == 5)
        {
            printf("for 1st test enter %d elements\n", number);
            test1(number, type);
            if (type == 0)
            {
                test2_for_int_quick_sort();
                test3_for_int_quick_sort();
                printf("for 4th test enter 2 elements and 2nd array\n");
                test4_concatenation(type);
                test5_inc2(type);
                test6_map_int();
                test_78_comparison(type);
                test9_where_int(type);
                test10_where_int2(type);
            }
            if (type == 1)
            {
                test2_for_float_quick_sort();
                test3_for_float_quick_sort();
                printf("for 4th test enter 2 elements and 2nd array\n");
                test4_concatenation(type);
                test5_inc2(type);
                test6_map_float();
                test_78_comparison(type);
                test9_where_float(type);
                test10_where_float2(type);
            }
        }
    }
    return 0;
}