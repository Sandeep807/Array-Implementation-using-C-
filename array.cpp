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

bool Array ::isEmpty()
{
    return lastIndex == -1;
}

bool Array ::isFull()
{
    return lastIndex == capacity - 1;
}
void Array ::append(int data)
{
    if (isFull())
    {
        cout << "Array full" << endl;
    }
    else
    {
        ptr[++lastIndex] = data;
    }
}

void Array ::insert(int index, int data)
{
    if (index < 0 || index > lastIndex + 1)
    {
        cout << "Index invalid" << endl;
    }
    else if (isFull())
    {
        cout << "Array full" << endl;
    }
    else
    {
        for (int i = lastIndex; i >= index; i--)
        {
            ptr[i + 1] = ptr[i];
        }
        ptr[index] = data;
        lastIndex++;
    }
}

void Array ::edit(int index, int data)
{
    if (index < 0 || index > lastIndex)
    {
        cout << "Invalid index" << endl;
    }
    else
    {
        ptr[index] = data;
    }
}

void Array ::del(int index)
{
    if (index < 0 || index > lastIndex)
    {
        cout << "Invalid index" << endl;
    }
    else
    {
        for (int i = index; i < lastIndex; i++)
            ptr[i] = ptr[i + 1];
        lastIndex--;
    }
}

int Array ::getItem(int index)
{
    if (index < 0 || index > lastIndex)
    {
        cout << "Invalid index" << endl;
        throw new exception();
    }
    else
    {
        return ptr[index];
    }
}

int Array ::count()
{
    return lastIndex + 1;
}

Array ::~Array()
{
    delete[] ptr;
}

int Array ::find(int data)
{
    for (int i = 0; i <= lastIndex; i++)
    {
        if (ptr[i] == data)
        {
            return i;
        }
    }
    return -1;
}

Array ::Array(const Array &obj)
{

    capacity = obj.capacity;
    lastIndex = obj.lastIndex;
    ptr = new int[capacity];

    for (int i = 0; i <= lastIndex; i++)
    {
        ptr[i] = obj.ptr[i];
    }
}

Array& Array :: operator =(const Array &obj)
{
     if(this != &obj){
        if(ptr!=NULL)
        delete []ptr;
        capacity=obj.capacity;
        lastIndex=obj.lastIndex;
        ptr=new int[capacity];
        for(int i=0;i<=lastIndex;i++)
            ptr[i]=obj.ptr[i];
    }
    return *this;
}

int main()
{
    Array arr(5);
    arr.append(10);
    arr.append(10);
    arr.append(10);
    arr.append(10);
    // arr.append(10);
    // arr.append(10);
    arr.insert(2, 15);
    cout << "Total element : " << arr.count() << endl;
    return 0;
}