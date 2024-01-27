#include <iostream>
using namespace std;

class Array
{
private:
    int capacity;
    int lastIndex;
    int *ptr;

public:
    Array() = default;

    Array(int size)
    {
        if(size>0){
        capacity=size;
        lastIndex=-1;
        ptr=new int[capacity];
    }
    else
        ptr=NULL;
    }

    void append(int);
    bool isEmpty();
    bool isFull();
    void insert(int, int);
    int count();
    void edit(int, int);
    void del(int);
    int getItem(int);
    ~Array();
    int find(int);
    Array(const Array &);
    Array& operator=(const Array &);
};