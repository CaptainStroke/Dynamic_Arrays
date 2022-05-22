//написать 2 функции для работы с одномерным динамическим массивом.
//первая функция будет добавлять новое значение в конец массива интов.
//вторая функция будет удалять элемент из массива интов по любому переданному индексу.
//примеры вызова функций есть в отрезке кода ниже, необходимо реализовать тела.

#include <iostream>
#include <ctime>
using namespace std;

void print_array(int* ar, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << ar[i] << ", ";
    }
    cout << "\n\n";
}

void add(int*& ar, int& size, int number)
{
    int* temp = new int[size + 1];
    for (int i = 0; i < size; i++)
    {
        temp[i] = ar[i];
    }
    temp[size] = number;
    delete[] ar;
    ar = temp;
    size++;
}
void remove(int*& ar, int& size,  int number)
{
    int* temp = new int[size - 1];
    for (int i = 0; i < size - 1; i++)
    {
        if (i < number) temp[i] = ar[i];
        else if (i >= number) temp[i] = ar[i+1];
    }
    delete[] ar;
    ar = temp;
    size--;  
}

int main()
{
    int size;
    size = 5;
    int* ar = new int[size] {1, 2, 3, 4, 5};
    
    add(ar, size, 10);
    print_array(ar, size);
    
    remove(ar, size, 3);
    print_array(ar, size);

    delete[] ar;
}