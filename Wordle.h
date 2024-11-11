#include <iostream>
#include <string>
#include <list>
#include "Node.h"
using namespace std;

class Wordle
{
private:
    //Node* head;
    //char* L;
    //static string hashGroups = 10;
    //list<pair<string, string> table[hahGroups];

    char *array;
    static int capacity; 
    int size;
    char *arr;

public:

    Wordle(){
        capacity = 4;
        size = 0;
        array = new char[capacity];
        arr = new char [capacity];
    }

    Wordle( const Wordle& other)
    {
        array = new char (*other.array);
        arr = new char (*other.arr);
    }

        Wordle& operator=(const Wordle& other)
    {
        if (this != &other)
        {
            delete array;
            delete arr;
            array = new char(*other.array);
            arr = new char(*other.arr);
        }

        return *this;
    }
    
    Wordle(Wordle&& other)
    {
        array= other.array;
        other.array = nullptr;

        arr = other.arr;
        other.arr = nullptr;
    }

    Wordle& operator=(Wordle&& other)
    {
        if (this != &other)
        {
            delete array;
            delete arr;
            arr = other.arr;
            array = other.array;
            other.arr = nullptr;
            other.array = nullptr;
        }
  
        return *this;
    }

    ~Wordle(){
        delete[] array;
        for (int i = 0; i <= capacity; i++)
        {
            delete[] arr;
        }
        delete[] arr;
    }

    int getSize(){
        return size;
    }

    int getCapacity(){
        return capacity;
    }

    void insertChar(){
        for (int i = 0; i <= capacity; i++)
        {
            cin >> array[i];
        }
    }

    void printArray()
    {
        cout << "Element of array: ";
        for (int i = 0; i <= capacity; i++)
        {
            cout << array[i];
            cout << " ";
            size++;
        }

        cout << endl;
        cout << "Size: " << size << endl;
        cout << "Capacity: " << capacity << endl;
    }

    bool isEmpty() const;
    int hashfunction (string key);
    void insertItem()
    {
        for (int i = 0; i <= capacity; i++)
        {
            arr[i] = new char[capacity];
            for (int j = 1; j < 5; j++)
            {
                cin >> arr[j];
                if(i == capacity /2 && j == capacity / 2)
                {
                    growArray();
                }
            }
        }
    }
    void growArray()
    {
        char *temp = new char[capacity];
        capacity *= 2;
        for (int i = 0; i <= size; i++)
        {
            temp[i] = array[i];
        }
        delete array;
        array = temp;

        for (int i = 0; i<= size; i++)
        {
            temp[i] = arr[i];
        }
        delete arr;
        arr = temp;
    }
    void removeItem(string key);
    string searchTable(string key);
    void printTable()
    {
        for (int i = 0; i <= capacity; i++)
        {
            cout << array[i];
            for (int j = 0; j < 5; j++)
            {
                cout << arr[j];
            }
        }
    }
/*
    bool getWords();
    void getPoint();
    void getDescription();
    void clear();
    void savePoint();
    ~Wordle()
    {
        delete L;
        cout << "Destructor called\n";
    }
*/
};