/*
    Попробуйте запрограммировать пример с Джеком и Джилл из раздела 20.1.2. Для тестирования используйте
    несколько небольших файлов.

    jack.txt: 55.7 60.2 100.24 21.3 15.1 76.20
    jill.txt: 90.0 70.0 65.5 21.5 45.7 30.42

    Результат работы программы: 
    Максимум Джека: 100.24, Максимум Джилл: 90
*/

#include <iostream>
#include <fstream>
#include <vector>

double* GetFromJack(int* count)
{
    std::ifstream jackData;
    jackData.open("jack.txt");
    
    for (double speed; jackData >> speed;) {
        (*count)++;
    }
    
    jackData.close();
    jackData.open("jack.txt");
    
    double* data = new double[(int64_t)*count];
    for (int i = 0; i < *count; ++i)
    {
        double speed;
        jackData >> speed;
        data[i] = speed;
    }
    
    jackData.close();
    return data;
}

std::vector<double>* GetFromJill()
{
    std::ifstream jillData;
    jillData.open("jill.txt");
    
    std::vector<double>* data = new std::vector<double>;
    for (double speed; jillData >> speed;){
        data->push_back(speed);
    }
    
    jillData.close();
    return data;
}

double* High(double* first, double* last)
{
    double* high = first;
    for (double* p = first; p != last; ++p)
    {
        if (*high < *p)
        {
            high = p;
        }
    }
    return high;
}

int main()
{
    int jackCount = 0;
    double* jackData = GetFromJack(&jackCount);
    std::vector<double>* jillData = GetFromJill();
    std::vector<double>& v = *jillData;

    double* jackHigh = High(jackData,jackData+jackCount);
    double* jillHigh = High(&v[0],&v[0]+v.size());
    
    std::cout << "Максимум Джека: " << *jackHigh;
    std::cout << ", Максимум Джилл: " << *jillHigh << '\n';
    
    delete[] jackData;
    delete jillData;
    return 0;
}
