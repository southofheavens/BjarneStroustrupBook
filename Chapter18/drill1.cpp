/*
    Задание
    В этой главе мы ставим два задания: одно необходимо выполнить с помощью массивов, а второе - с помощью
    векторов. Выполните оба задания и сравните количество усилий, которые вы при этом затратили.

    Задание с массивами
    1. Определите глобальный массив ga типа int, состоящий из десяти целых чисел и инициализированный 
    числами 1, 2, 4, 8, 16 и т.д.
    2. Определите функцию f(), принимающую в качестве аргументов массив типа int и значение типа int, 
    задающее количество элементов в массиве.
    3. В функции f() выполните следующее.
        - Определите локальный массив la типа int, состоящий из десяти элементов.
        - Скопируйте значения из массива ga в массив la.
        - Выведите на печать элементы массива la
        - Определите указатель p на тип int и инициализируйте его адресом массива, расположенного в
        динамической памяти и хранящего такое же количество элементов, как и массив, являющийся 
        аргументом функции.
        - Скопируйте значения из массива, являющегося аргументом функции, в массив в динамической памяти.
        - Выведите на печать элементы массива, расположенного в динамической памяти.
        - Освободите память, выделенную для массива.
    4. В функции main() сделайте следующее.
        - Вызовите функцию f() с аргументом ga.
        - Определите массив aa, содержащий десять элементов, и инициализируйте его первыми десятью 
        значениями факториала (т.е. 1, 2*1, 3*2*1, 4*3*2*1 и т.д.).
        - Вызовите функцию f() с аргументом aa.
*/

#include <iostream>

int ga[10] {1,2,4,8,16,32,64,128,256,512};

void F(int arr[], int c)
{
    int la[10];
    for (int i = 0; i < 10; ++i)
    {
        la[i] = ga[i];
    }
    for (int i = 0; i < 10; ++i)
    {
        std::cout << la[i];
        i != 9 ? std::cout << ' ' : std::cout << '\n';
    }
    int* arr1 = new int[c];
    int* p = arr1;
    for (int i = 0; i < c; ++i)
    {
        p[i] = arr[i];
    }
    for (int i = 0; i < c; ++i)
    {
        std::cout << p[i];
        i != c - 1 ? std::cout << ' ' : std::cout << '\n';
    }
    delete[] arr1;
}

int Factorial(int n)
{
    return n > 1 ? n * Factorial(n - 1) : 1;
}

int main()
{
    F(ga,10);
    int aa[10];
    for (int i = 0; i < 10; ++i){
        aa[i] = Factorial(i + 1);
    }
    F(aa,10);
    return 0;
}
