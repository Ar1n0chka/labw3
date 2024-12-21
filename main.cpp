#include "lib.h"
#include "Container.hpp"
#include "OneListContainer.hpp"
#include "TwoListContainer.hpp"
#include <iostream>
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


int main () 
{
    
    VecContainer arr;
    ListOne<int> list;
    ListTwo<int> listTwo;
    
    std::cout << "Массив: " << std::endl;
    for (auto i = 0; i < 10; i++)
    {
        arr.push_back(i);
    }
    arr.PrintContainer();
    // std::cout << arr.getSize();
    std::cout << "Size: " << arr.getCapacity() << std::endl;
   

    
    arr.erase(3);
    arr.erase(4);
    arr.erase(5);
    arr.PrintContainer();
    // std::cout <<"Size of the current array: "<< arr.getCapacity() << std::endl;
    arr.insert(10, 0);
    arr.PrintContainer();
    arr.insert(20, 4);
    arr.PrintContainer();
    arr.push_back(30);
    arr.PrintContainer();
    std::cout<< std::endl;

    std::cout << "Однонаправленный список: " << std::endl;
    for(int i = 0; i<10; i++)
    {
        list.push_back(i);
    }
    list.PrintListOne();
    std::cout << "Size: " << list.GetSize() << std::endl;
    list.erase(2);
    list.erase(3);
    list.erase(4);
    list.PrintListOne();
    list.insert(1, 10);
    list.insert(4, 20);
    list.push_back(30);
    list.PrintListOne();
    std::cout<< std::endl;

    std::cout << "Двунаправленный список: " << std::endl;
    for(int i = 0; i<10; i++)
    {
        listTwo.push_back(i);
    }
    listTwo.PrintListTwo();
    std::cout << "Size: " << listTwo.GetSize() << std::endl;
    listTwo.erase(2);
    listTwo.erase(3);
    listTwo.erase(4);
    listTwo.PrintListTwo();
    listTwo.insert(0, 10);
    listTwo.insert(4, 20);
    listTwo.push_back(30);
    listTwo.PrintListTwo();
}


// #include <iostream>
// using namespace std;

// struct Node {
//     string val;
//     Node* next;

//     Node(string _val) : val(_val), next(nullptr) {}
// };

// struct list {
//     Node* first;
//     Node* last;

//     list() : first(nullptr), last(nullptr) {}

//     bool is_empty() {
//         return first == nullptr;
//     }

//     void push_back(string _val) {
//         Node* p = new Node(_val);
//         if (is_empty()) {
//             first = p;
//             last = p;
//             return;
//         }
//         last->next = p;
//         last = p;
//     }

//     void print() {
//         if (is_empty()) return;
//         Node* p = first;
//         while (p) {
//             cout << p->val << " ";
//             p = p->next;
//         }
//         cout << endl;
//     }

//     Node* find(string _val) {
//         Node* p = first;
//         while (p && p->val != _val) p = p->next;
//         return (p && p->val == _val) ? p : nullptr;
//     }

//     void remove_first() {
//         if (is_empty()) return;
//         Node* p = first;
//         first = p->next;
//         delete p;
//     }

//     void remove_last() {
//         if (is_empty()) return;
//         if (first == last) {
//             remove_first();
//             return;
//         }
//         Node* p = first;
//         while (p->next != last) p = p->next;
//         p->next = nullptr;
//         delete last;
//         last = p;
//     }

//     void remove(string _val) {
//         if (is_empty()) return;
//         if (first->val == _val) {
//             remove_first();
//             return;
//         }
//         else if (last->val == _val) {
//             remove_last();
//             return;
//         }
//         Node* slow = first;
//         Node* fast = first->next;
//         while (fast && fast->val != _val) {
//             fast = fast->next;
//             slow = slow->next;
//         }
//         if (!fast) {
//             cout << "This element does not exist" << endl;
//             return;
//         }
//         slow->next = fast->next;
//         delete fast;
//     }

//     Node* operator[] (const int index) {
//         if (is_empty()) return nullptr;
//         Node* p = first;
//         for (int i = 0; i < index; i++) {
//             p = p->next;
//             if (!p) return nullptr;
//         }
//         return p;
//     }
// };

// int main()
// {
//     list l;
//     cout << l.is_empty() << endl;
//     l.push_back("3");
//     l.push_back("123");
//     l.push_back("8");
//     l.print();
//     cout << l.is_empty() << endl;
//     l.remove("123");
//     l.print();
//     l.push_back("1234");
//     l.remove_first();
//     l.print();
//     l.remove_last();
//     l.print();
//     cout << l[0]->val << endl;
//     return 0;
// }
