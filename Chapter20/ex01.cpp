/*
    Если вы еще не выполнили задания из врезок Попробуйте, то сделайте это сейчас.

    ПОПРОБУЙТЕ
    Напишите функцию void copy(int*f1, int*e1, int*f2), копирующую элементы массива типа int, определенного
    последовательностью [f1,e1) в другую последовательность [f2,f2+(e1-f1)). Используйте только упомянутые
    выше операции с итераторами (а не индексирование).
*/  

#include <iostream>

void Copy(int* f1, int* e1, int* f2)
{
    while (f1 != e1)
    {
        *f2 = *f1;
        ++f1;
        ++f2;
    }
}

int main()
{
    int arr1[]{1,2,3,4,5,6,7,8,9,10};
    constexpr int ARR_SIZE = 10;
    int arr2[ARR_SIZE];
    
    Copy(arr1,arr1+ARR_SIZE,arr2);
    
    for (int i = 0; i < ARR_SIZE; ++i) {
        i != ARR_SIZE - 1 ? std::cout << arr2[i] << ' ' : std::cout << arr2[i] << '\n';
    }
    
    return 0;
}
