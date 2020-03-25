#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>



void quick_sort(void** p, int* first_sort, int* last_sort, int* type)
{
    int left = *first_sort;
    int right = *last_sort;
    if (*type == 0)
    {
        int mid = ((int*)(*p))[(left + right) / 2];
        int swap_left_and_right;
        while (left <= right)
        {
            while (((int*)(*p))[left] < mid)
                left++;
            while (((int*)(*p))[right] > mid)
                right--;
            if (left <= right)
            {
                swap_left_and_right = ((int*)(*p))[left];
                ((int*)(*p))[left] = ((int*)(*p))[right];
                ((int*)(*p))[right] = swap_left_and_right;
                left++;
                right--;
            }
        }
        if (*first_sort < right)
            quick_sort(p, first_sort, &right, type);
        if (*last_sort > left)
            quick_sort(p, &left, last_sort, type);
    }
    if (*type == 1)
    {
        float mid = ((float*)(*p))[(left + right) / 2];
        float swap_left_and_right;
        while (left <= right)
        {
            while (((float*)(*p))[left] < mid)
                left++;
            while (((float*)(*p))[right] > mid)
                right--;
            if (left <= right)
            {
                swap_left_and_right = ((float*)(*p))[left];
                ((float*)(*p))[left] = ((float*)(*p))[right];
                ((float*)(*p))[right] = swap_left_and_right;
                left++;
                right--;
            }
        }
        if (*first_sort < right)
            quick_sort(p, first_sort, &right, type);
        if (*last_sort > left)
            quick_sort(p, &left, last_sort, type);
    }
}


void* create_array(int* number, int* type)
{
    if (*type == 0)
    {
        int* p = (int*)malloc((*number) * sizeof(int));
        if (NULL == p)
        {
            printf("OS didn`t gave memory. Exit...\n");
            exit(1);
        }
        printf("enter array`s elements\n");
        for (int i = 0; i < *number; i++)
            while (scanf_s("%d", &p[i]) == 0)
            {
                scanf_s("%*[^\n,\n]");
                printf("uncorrect input, enter integer element\n");
            }
        void* point = p;
        return(point);
    }
    if (*type == 1)
    {
        float* p = (float*)malloc((*number) * sizeof(float));
        if (NULL == p)
        {
            printf("OS didn`t gave memory. Exit...\n");
            exit(1);
        }
        printf("enter array`s elements\n");
        for (int i = 0; i < *number; i++)
            while (scanf_s("%f", &p[i]) == 0)
            {
                scanf_s("%*[^\n,\n]");
                printf("uncorrect input, enter float element\n");
            }
        void* point = p;
        return(point);
    }
}


void* concatenation(void** p1, int* number, int* type)
{
    printf("enter number of 2nd array elements\n");
    int number2;
    while (scanf_s("%d", &number2) == 0)
    {
        scanf_s("%*[^\n,\n]");
        printf("uncorrect input, enter number!\n");
    }
    while (number2 <= 0)
    {
        scanf_s("%*[^\n,\n]");
        printf("uncorrect input, enter natural number!\n");
        scanf_s("%d", &number2);
    }
    void* p2;
    p2 = create_array(&number2, type);

    if (*type == 0)
    {
        *p1 = (int*)realloc(*p1, (*number + number2) * sizeof(int));
        for (int i = *number; i < (*number + number2); i++)
        {
            ((int*)(*p1))[i] = ((int*)p2)[i - *number];
        }
    }

    if (*type == 1)
    {

        *p1 = (float*)realloc(*p1, (*number + number2) * sizeof(float));
        for (int i = *number; i < (*number + number2); i++)
        {
            ((float*)(*p1))[i] = ((float*)p2)[i - *number];
        }
    }


    if (*type == 0)
    {
        for (int i = 0; i < (*number + number2); i++)
            printf("%d\n", ((int*)(*p1))[i]);
    }

    if (*type == 1)
    {
        for (int i = 0; i < (*number + number2); i++)
            printf("%f\n", ((float*)(*p1))[i]);
    }

    *number = *number + number2;
    return(*p1);
}

void inc2(void* void_inc, int* type)
{
    if (*type == 0)
        *((int*)void_inc) = *((int*)void_inc) + 2;
    if (*type == 1)
        *((float*)void_inc) = *((float*)void_inc) + 2;
}

void map(void* p, int* number, int* type, void (*replacement_func)(void* p, int* type))
{
    for (int i = 0; i < *number; i++)
    {
        if (*type == 0)
        {
            replacement_func(&(((int*)p)[i]), type);
        }
        if (*type == 1)
        {
            replacement_func(&(((float*)p)[i]), type);
        }
    }

}

int comparison(void* p, int* type)
{
    if (*type == 0)
    {
        if (*((int*)p) > 0)
            return 1;
        else
            return 0;
    }
    if (*type == 1)
    {
        if (*((float*)p) > 0)
            return 1;
        else
            return 0;
    }
}

void* where(void* marker_void, int* type_marker, int* number, int (*replacement_func)(void* p, int* type))
{
    if (*type_marker == 0)
    {
        int j = 0;
        int* p = (int*)malloc((*number) * sizeof(int));
        for (int i = 0; i < *number; i++)
        {
            if (comparison(&((int*)marker_void)[i], type_marker))
            {
                ((int*)p)[j] = ((int*)marker_void)[i];
                j = j + 1;
            }
        }
        if (j == 0)
        {
            printf("elements hasn`t been found");
            p = NULL;
        }
        else
            p = (int*)realloc(p, j * sizeof(int));
        for (int ik = 0; ik < j; ik++)
            printf("%d\n", p[ik]);
        return(p);
    }
    if (*type_marker == 1)
    {
        int j = 0;
        float* p = (float*)malloc((*number) * sizeof(float));
        for (int i = 0; i < *number; i++)
        {
            if (comparison(&((float*)marker_void)[i], type_marker))
            {
                ((float*)p)[j] = ((float*)marker_void)[i];
                j = j + 1;
            }
        }
        if (j == 0)
        {
            printf("elements hasn`t been found");
            p = NULL;
        }
        else
            p = (float*)realloc(p, j * sizeof(float));
        for (int ik = 0; ik < j; ik++)
            printf("%f\n", p[ik]);
        return(p);
    }
}