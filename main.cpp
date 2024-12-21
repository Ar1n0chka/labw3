#include "lib.h"
#include "Container.hpp"
#include "OneListContainer.hpp"
#include "TwoListContainer.hpp"
#include <iostream>



int main () 
{
    
    VecContainer arr;
    ListOne<int> list;
    ListOne<int> list2;
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
    std::cout << "Copy of list:\t" ;
    list2 = list;
    list2.PrintListOne();
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

