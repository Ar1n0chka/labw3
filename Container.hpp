#include <iostream>
class VecContainer
{
    public:
    VecContainer(int length = 10)
    {
        arr = new int [length];
    }

    VecContainer(VecContainer& copiedContainer)
    {
        arr = new int [copiedContainer.capacity];
        for(int i = 0; i< size; ++i)
        {
            arr[i] = copiedContainer.arr[i];
        }
        capacity = copiedContainer.capacity;
        size = copiedContainer.size;
    }
    
    
    ~VecContainer()
    {

        delete[] arr;
    }

    void PrintContainer()
    {

        
        for (int i = 0; i < capacity; ++i)
        {
            std::cout << arr[i] << " ";
        }
        std::cout<< std::endl;
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
    void insert (int number, int position )
    {
        
        int* arrNew = new int[capacity + 1];
        for (int i = 0; i < position; ++i) {
            arrNew[i] = arr[i];
        }
        arrNew[position] = number;
        for (int i = position; i < size; ++i) {
            arrNew[i + 1] = arr[i];
        }

        arr = arrNew;
        capacity++;

    }

    private:
    int *arr;
    int size = 10;
    int capacity = 0;
    

};
