#include <iostream>

template <typename T>
class NodeTwo
{
public:
    T data;
    NodeTwo<T> *next;
    NodeTwo<T> *prev;

    NodeTwo(T _data, NodeTwo<T> *_next = nullptr, NodeTwo<T> *_prev = nullptr)
    {
        data = _data;
        next = _next;
        prev = _prev;
    }
};

template<typename T>
class ListTwo
{
public:
    NodeTwo<T> *first;
    NodeTwo<T> *last;

    ListTwo()
    {
        first = last = nullptr;
    }

    ~ListTwo()
    {
        NodeTwo<T> *current = first;
        while (current != nullptr)
        {
            NodeTwo<T> *to_delete = current;
            current = current->next;
            delete to_delete;
        }
    }

    bool is_empty()
    {
        return first == nullptr;
    }

    void push_back(T data)
    {
        NodeTwo<T> *p = new NodeTwo<T>(data);
        if (is_empty())
        {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        p->prev = last;
        last = p;
    }

    void PrintListTwo() 
    {
        
        NodeTwo<T> *p = first;
        while (p) 
        {
            std::cout << p->data << " ";
            p = p->next;
        }
        std::cout << std::endl;
    }

    void insert(int index, T value)
    {
        NodeTwo<T>* newNode = new NodeTwo<T>(value);
        int counter = 0;
        NodeTwo<T> *p = first;

        if (index == 0)
        {
            newNode->next = first;
            if (first != nullptr) 
            {
                first->prev = newNode;
            }
            if (last == nullptr) 
            {
                last = newNode;
            }
            first = newNode;
            return;
        }

        while (counter != index - 1 && p != nullptr)
        {
            p = p->next;
            counter++;
        }

        newNode->next = p->next;
        newNode->prev = p;
        if (p->next != nullptr) 
        {
            p->next->prev = newNode;
        } 
        else 
        {
            last = newNode;
        }
        p->next = newNode;
    }

    void erase(int index)
    {
       

        NodeTwo<T> *current = first;

        for (int i = 0; current != nullptr && i < index; ++i) 
        {
            current = current->next;
        }

    
        if (current == first) 
        {
            first = current->next;
            if (first != nullptr) 
            {
                first->prev = nullptr;
            }
        } 
        else 
        {
            current->prev->next = current->next;
        }

       
        if (current == last) 
        {
            last = current->prev;
            if (last != nullptr) 
            {
                last->next = nullptr;
            }
        } 
        else 
        {
            current->next->prev = current->prev;
        }

        delete current;
    }

    int GetSize() const
    {
        int count = 0;
        NodeTwo<T> *current = first;
        while (current != nullptr)
        {
            count++;
            current = current->next;
        }
        return count;
    }
};