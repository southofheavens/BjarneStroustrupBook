/*
 * Напишите функцию, принимающую в качестве входных данных массив целых чисел типа int и находящую
 * наименьший и наибольший его элементы. Она также должна вычислять медиану и среднее значение.
 * Используйте в качестве возвращаемого значения структуру, хранящую результаты работы.
 * 
 * How to compile:
 * clang -std=c89 ex14.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct ResOfCalc
{
    int min;
    int max;
    double median;
    double avg;
};

int Comp(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

struct ResOfCalc Calculations(int arr[], uint16_t sz)
{
    struct ResOfCalc result;
    
    qsort(arr,sz,sizeof(int),Comp); // Сортируем массив
    
    result.min = arr[0];
    result.max = arr[sz - 1];
    
    if (sz % 2 == 1) {
        result.median = arr[sz / 2];
    }
    else {
        result.median = (arr[sz / 2] + arr[sz / 2 - 1]) / (double)2;
    }
    
    int sumOfElems = 0;
    int i;
    for (i = 0; i < sz; ++i) {
        sumOfElems+=arr[i];
    }
    result.avg = sumOfElems / (double)sz;
    
    return result;
}

int main(void)
{
    int arr[10] = {3,14,-5,7,-1,16,21,8,33,1};
    
    struct ResOfCalc result = Calculations(arr, sizeof(arr) / sizeof(int));
    
    printf("Result: %d, %d, %f, %f\n", result.min, result.max, result.median, result.avg);
    return 0;
}
