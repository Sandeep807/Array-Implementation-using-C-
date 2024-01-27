#include "array.h"

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

