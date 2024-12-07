#include "lib.h"
#include <iostream>
#include <array>
#include <vector>
// 1. Создание объекта контейнера для хранения объектов типа int. 
// 2. Добавление в контейнер десяти элементов (0, 1 … 9). 
// 3. Вывод содержимого контейнера на экран. 
// Ожидаемый результат: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9. 
// 4. Вывод размера контейнера на экран. 
// Ожидаемый результат: 10. 
// 5. Удаление третьего (по счёту), пятого и седьмого элементов. 
// 6. Вывод содержимого контейнера на экран. 
// Ожидаемый результат: 0, 1, 3, 5, 7, 8, 9. 
// 7. Добавление элемента 10 в начало контейнера. 
// 8. Вывод содержимого контейнера на экран. 
// 1 
// Ожидаемый результат: 10, 0, 1, 3, 5, 7, 8, 9. 
// 9. Добавление элемента 20 в середину контейнера. 
// 10.  Вывод содержимого контейнера на экран. 
// Ожидаемый результат: 10, 0, 1, 3, 20, 5, 7, 8, 9. 
// 11.  Добавление элемента 30 в конец контейнера. 
// 12.  Вывод содержимого контейнера на экран. 
// Ожидаемый результат: 10, 0, 1, 3, 20, 5, 7, 8, 9, 30. 
// Требования к минимальному интерфейсу: 
// • Метод/ы (может быть несколько) добавления элементов в конец 
// контейнера ( push_back ). 
// • Метод/ы вставки элементов в произвольную позицию ( insert ). 
// • Метод/ы удаления элементов из контейнера ( erase ). 
// • Метод получения текущего размера контейнера ( size ). 
// • Метод/ы получения доступа по индексу ( operator[] ).
// template <typename T>
// void printContainer(const T& container) {
//     for (const auto& elem : container) {
//         std::cout << elem << " ";
//     }
//     std::cout << std::endl;
// }

class Container
{
    public:
    Container(int length = 10)
    {
        arr = new int [length];
    }

    ~Container()
    {
        delete[] arr;
    }
    void PrintContainer()
    {

        for (int i = 0; i < capacity; ++i)
        {
            std::cout << arr[i] << " ";
        }
    }
    void push_back(int value)
    {
        arr[capacity] = value;
        capacity++; 
    }
    int getSize() const
    {
        return size;
    }
    int getCapacity() const
    {
        return capacity;
    }
    void erase(int index)
    {
        int *arrNew = new int[size - 1];
        for(int i = 0; i < size; ++i){
            
            if (i < index-1)
            { 
                arrNew[i] = arr[i];                
                continue;
            }
            if (i == index-1)
            {
                continue;
            }
            arrNew[i-1] = arr[i];
            
        }
        arr = arrNew;
        capacity--;
    }
    private:
    int *arr;
    int size = 10;
    int capacity = 0;
    

};


int main () 
{
    int i;
    std::cin >> i;
    Container arr;
    std::cout << "Array: ";
    for (auto i = 0; i < 10; i++)
    {
        arr.push_back(i);
    }
    arr.PrintContainer();
    // std::cout << arr.getSize();
    std::cout << std::endl << "Size: " << arr.getSize() << std::endl;
    std::cout << arr.getCapacity() << std::endl;

    arr.erase(i);
    arr.PrintContainer();

}
