#include "array.h"
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