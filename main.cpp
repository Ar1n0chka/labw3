// #include "lib.h"
// #include <iostream>
// // 1. Создание объекта контейнера для хранения объектов типа int. 
// // 2. Добавление в контейнер десяти элементов (0, 1 … 9). 
// // 3. Вывод содержимого контейнера на экран. 
// // Ожидаемый результат: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9. 
// // 4. Вывод размера контейнера на экран. 
// // Ожидаемый результат: 10. 
// // 5. Удаление третьего (по счёту), пятого и седьмого элементов. 
// // 6. Вывод содержимого контейнера на экран. 
// // Ожидаемый результат: 0, 1, 3, 5, 7, 8, 9. 
// // 7. Добавление элемента 10 в начало контейнера. 
// // 8. Вывод содержимого контейнера на экран. 
// // 1 
// // Ожидаемый результат: 10, 0, 1, 3, 5, 7, 8, 9. 
// // 9. Добавление элемента 20 в середину контейнера. 
// // 10.  Вывод содержимого контейнера на экран. 
// // Ожидаемый результат: 10, 0, 1, 3, 20, 5, 7, 8, 9. 
// // 11.  Добавление элемента 30 в конец контейнера. 
// // 12.  Вывод содержимого контейнера на экран. 
// // Ожидаемый результат: 10, 0, 1, 3, 20, 5, 7, 8, 9, 30. 
// // Требования к минимальному интерфейсу: 
// // • Метод/ы (может быть несколько) добавления элементов в конец 
// // контейнера ( push_back ). 
// // • Метод/ы вставки элементов в произвольную позицию ( insert ). 
// // • Метод/ы удаления элементов из контейнера ( erase ). 
// // • Метод получения текущего размера контейнера ( size ). 
// // • Метод/ы получения доступа по индексу ( operator[] ).
// // template <typename T>
// // void printContainer(const T& container) {
// //     for (const auto& elem : container) {
// //         std::cout << elem << " ";
// //     }
// //     std::cout << std::endl;
// // }

// class Container
// {
//     public:
//     Container(int length = 10)
//     {
//         arr = new int [length];
//     }

//     ~Container()
//     {
//         delete[] arr;
//     }

//     void PrintContainer()
//     {

//         std::cout  << "Array: ";
//         for (int i = 0; i < capacity; ++i)
//         {
//             std::cout << arr[i] << " ";
//         }
//         std::cout<< std::endl;
//     }

//     void push_back(int value)
//     {
//         arr[capacity] = value;
//         capacity++; 
//     }

//     int getSize() const
//     {
//         return size;
//     }
//     int getCapacity() const
//     {
//         return capacity;
//     }
    
//     void erase(int index)
//     { 
//         int *arrNew = new int[size - 1];
//         for(int i = 0; i < size; ++i){
            
//             if (i < index-1)
//             { 
//                 arrNew[i] = arr[i];                
//                 continue;
//             }
//             if (i == index-1)
//             {
//                 continue;
//             }
//             arrNew[i-1] = arr[i];
            
//         }
//         arr = arrNew;
//         capacity--;
//     }
//     void insert (int number, int position )
//     {
        
//         int* arrNew = new int[capacity + 1];
//         for (int i = 0; i < position; ++i) {
//             arrNew[i] = arr[i];
//         }
//         arrNew[position] = number;
//         for (int i = position; i < size; ++i) {
//             arrNew[i + 1] = arr[i];
//         }

//         arr = arrNew;
//         capacity++;

//     }

//     private:
//     int *arr;
//     int size = 10;
//     int capacity = 0;
    

// };


// int main () 
// {
    
//     Container arr;

//     for (auto i = 0; i < 10; i++)
//     {
//         arr.push_back(i);
//     }
//     arr.PrintContainer();
//     // std::cout << arr.getSize();
//     std::cout << "Size: " << arr.getCapacity() << std::endl;
   
    
//     arr.erase(3);
//     arr.erase(4);
//     arr.erase(5);
//     arr.PrintContainer();
//     // std::cout <<"Size of the current array: "<< arr.getCapacity() << std::endl;
//     arr.insert(10, 0);
//     arr.PrintContainer();
//     arr.insert(20, 4);
//     arr.PrintContainer();
//     arr.push_back(30);
//     arr.PrintContainer();

// }


#include <iostream>
using namespace std;

struct Node {
    string val;
    Node* next;

    Node(string _val) : val(_val), next(nullptr) {}
};

struct list {
    Node* first;
    Node* last;

    list() : first(nullptr), last(nullptr) {}

    bool is_empty() {
        return first == nullptr;
    }

    void push_back(string _val) {
        Node* p = new Node(_val);
        if (is_empty()) {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
    }

    void print() {
        if (is_empty()) return;
        Node* p = first;
        while (p) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }

    Node* find(string _val) {
        Node* p = first;
        while (p && p->val != _val) p = p->next;
        return (p && p->val == _val) ? p : nullptr;
    }

    void remove_first() {
        if (is_empty()) return;
        Node* p = first;
        first = p->next;
        delete p;
    }

    void remove_last() {
        if (is_empty()) return;
        if (first == last) {
            remove_first();
            return;
        }
        Node* p = first;
        while (p->next != last) p = p->next;
        p->next = nullptr;
        delete last;
        last = p;
    }

    void remove(string _val) {
        if (is_empty()) return;
        if (first->val == _val) {
            remove_first();
            return;
        }
        else if (last->val == _val) {
            remove_last();
            return;
        }
        Node* slow = first;
        Node* fast = first->next;
        while (fast && fast->val != _val) {
            fast = fast->next;
            slow = slow->next;
        }
        if (!fast) {
            cout << "This element does not exist" << endl;
            return;
        }
        slow->next = fast->next;
        delete fast;
    }

    Node* operator[] (const int index) {
        if (is_empty()) return nullptr;
        Node* p = first;
        for (int i = 0; i < index; i++) {
            p = p->next;
            if (!p) return nullptr;
        }
        return p;
    }
};

int main()
{
    list l;
    cout << l.is_empty() << endl;
    l.push_back("3");
    l.push_back("123");
    l.push_back("8");
    l.print();
    cout << l.is_empty() << endl;
    l.remove("123");
    l.print();
    l.push_back("1234");
    l.remove_first();
    l.print();
    l.remove_last();
    l.print();
    cout << l[0]->val << endl;
    return 0;
}
