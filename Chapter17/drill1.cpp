/*
    Задание
    Это задание состоит из двух частей. Первая часть упражнений должна дать вам представление о динамических
    массивах и их отличии от класса vector.
 
    1. Разместите в динамической памяти массив, состоящий из десяти чисел типа int, используя оператор new.
    2. Выведите в поток cout значения этих десяти чисел типа int.
    3. Освободите память, занятую массивом (используя оператор delete[]).
    4. Напишите функцию print_array10(ostream& os, int* a), выводящую в поток os значения из массива a
    (содержащего десять элементов).
    5. Разместите в динамической памяти массив, состоящий из десяти чисел типа int; инициализируйте его
    значениями 100, 101, 102 и т.д.; выведите эти значения на печать.
    6. Разместите в динамической памяти массив, состоящий из одиннадцати чисел типа int; инициализируйте его
    значениями 100, 101, 102 и т.д.; выведите эти значения на печать.
    7. Напишите функцию print_array(ostream& os, int* a, int n), выводящую в поток os значения массива a
    (содержащего n элементов).
    8. Разместите в динамической памяти массив, состоящий из двадцати чисел типа int; инициализируйте его
    значениями 100, 101, 102 и т.д.; выведите эти значения на экран.
    9. Вы не забыли удалить массивы? (Если забыли, сделайте это сейчас.)
    10. Выполните задания 5, 6 и 8, используя класс vector, а не массив, и функцию print_vector() вместо
    функции print_array().
*/

#include <iostream>
#include <vector>

std::ostream& PrintArray10(std::ostream& os, int* a)
{
    for (int i = 0; i < 10; ++i){
        os << a[i];
        i != 9 ? os << ' ' : os << '\n';
    }
    return os;
}

std::ostream& PrintArray(std::ostream& os, int* a, int n)
{
    for (int i = 0; i < n; ++i)
    {
        os << a[i];
        i != n - 1 ? os << ' ' : os << '\n';
    }
    return os;
}

std::ostream& PrintVector(std::ostream& os, const std::vector<int>& vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        os << vec[i];
        i != vec.size() - 1 ? os << ' ' : os << '\n';
    }
    return os;
}

int main()
{
    int* arr = new int[10];
    
    for (int i = 0; i < 10; ++i)
    {
        std::cout << arr[i];
        i != 9 ? std::cout << ' ' : std::cout << '\n';
    }
        
    int* arr2 = new int[10] {100,101,102,103,104,105,106,107,108,109};
    
    PrintArray10(std::cout, arr2);
    
    int* arr3 = new int[11] {100,101,102,103,104,105,106,107,108,109,110};
    
    for (int i = 0; i < 11; ++i)
    {
        std::cout << arr3[i];
        i != 10 ? std::cout << ' ' : std::cout << '\n';
    }
    
    int* arr4 = new int[20];
    for (int i = 0; i < 20; ++i)
    {
        arr4[i] = 100+i;
    }
    PrintArray(std::cout, arr4, 20);
    
    delete[] arr4;
    delete[] arr3;
    delete[] arr2;
    delete[] arr;
    
    std::cout << "----------\n";
    
    // 10.
    std::vector<int> vec{100,101,102,103,104,105,106,107,108,109};
    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i];
        i != vec.size() - 1 ? std::cout << ' ' : std::cout << '\n';
    }
    
    std::vector<int> vec2{100,101,102,103,104,105,106,107,108,109,110};
    for (int i = 0; i < vec2.size(); ++i)
    {
        std::cout << vec2[i];
        i != vec2.size() - 1 ? std::cout << ' ' : std::cout << '\n';
    }
    
    std::vector<int> vec3(20);
    for (int i = 0; i < vec3.size(); ++i)
    {
        vec3[i] = 100+i;
    }
    PrintVector(std::cout, vec3);
    
    return 0;
}
