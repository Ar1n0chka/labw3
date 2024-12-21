#include <iostream>

template <typename T>
class Node 
{
public:
    T data;
    Node<T> *next;
    
    Node(T _data, Node<T> *_next = nullptr)
    { 
        data = _data;
        next = _next;
    }
};


template<typename T>
class ListOne
{
public:

    Node<T> *first;
    Node<T> *last;

    ListOne()
    {
        first = last = nullptr;
    }

    ~ListOne()
    {

        Node<T> *current = first;
        Node<T> *to_delete = current;
        while (current != nullptr)
        {
            current = current->next;
            delete to_delete;
            to_delete = current;
        }
        delete current;
    }

    bool is_empty() 
    {
        return first == nullptr;
    }

    void push_back(T data) 
    {
        Node<T> *p = new Node<T>(data);
        if (is_empty()) 
        {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
    }

    void PrintListOne() 
    {    
        Node<T> *p = first;
        while (p) {
            std::cout << p->data << " ";
            p = p->next;
        }
        std::cout << std::endl;
    }


    void insert(int index, T value)
    {
        Node<T>* newNode = new Node<T>(value); 
        int counter = 0;
        Node<T> *p = first;
    
        if (index == 1)
        {
            newNode->next = first;
            first = newNode;
            return;
        }
        while (counter != index-1)
        {
            p = p->next;
            counter++;
        }
        newNode->next = p->next;
        p->next = newNode;

    }

    void erase(int index)
    {
        Node<T> *current = first;
        Node<T> *prev = nullptr;

        for (int i = 0; current != nullptr && i < index; ++i) {
            prev = current;
            current = current->next;
        }

        
        if (prev == nullptr) {
            first = current->next;
        } else {
            prev->next = current->next;
        }

        if (current == last) {
            last = prev;
        }



    }

    int GetSize()
    {
            int count = 0;
        Node<T> *current = first;
        while (current != nullptr)
        {
            count++;
            current = current->next;
        }
        return count;
    }
};