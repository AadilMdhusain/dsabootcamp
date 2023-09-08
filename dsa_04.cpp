#include <iostream>
using namespace std;

int main()
{
    int arr[5][5], i, j;
    cout << "The address of the array variable \"arr\" " << &arr << endl;
    cout << endl;
    for (i = 0; i < 5; i++)
    {
        cout << "The address of the array elements present in the first row  " << &arr[i] << endl;
    }
    cout << endl;
    cout << endl;
    cout << "The address of all the elements of the array row-wise" << endl
         << endl;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            cout << "The address of the array elements " << &arr[i][j] << endl;
        }
        cout << endl;
    }

    return 0;
}