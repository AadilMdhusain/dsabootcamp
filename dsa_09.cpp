#include <iostream>

using namespace std;

int insertatbeg(int arr[], int &size, int value)
{
    if (size == 50)
        return -1;
    else
    {
        for (int i = size; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = value;
    }
    size++;
    return size;
}

int insertatend(int arr[], int &size, int value)
{
    if (size == 50)
        return -1;
    else
        arr[size] = value;
    size++;
    return size;
}

int insertatindex(int arr[], int &size, int value, int index)
{
    if (size == 50)
        return -1;
    else if (index < 0 || index > size)
        return -2;
    else
    {
        for (int i = size; i > index; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
        size++;
        return index;
    }
}

int delatbeg(int arr[], int &size)
{
    if (size == 0)
        return -1;
    else
    {
        for (int i = 0; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
        return size;
    }
}

int delatend(int arr[], int &size)
{
    if (size == 0)
        return -1;
    else
    {
        size--;
        return size;
    }
}

int delatgivenindex(int arr[], int &size, int index)
{
    if (size == 0)
        return -1;
    else if (index < 0 || index >= size)
        return -2;
    else
    {
        for (int i = index; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
        return size;
    }
}

void display(int arr[], int size)
{
    cout << "Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int choice, size, arr[50], output, input, index;
    while (1)
    {
        printf("\n\n=============MENU=============\n");

        printf("\nInsert at:\n\t01.beginning\n\t02.end\n\t03.given index\nDelete at:\n\t04.beginning\n\t05.end\n\t06.given Index\n0.Exit\n\n");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            cout << "Enter the value to entered as the input\n";
            cin >> input;
            output = insertatbeg(arr, size, input);
            if (output == -1)
                cout << "The array is full, no more data values can be entered in it";
            else
                cout << "The data value have been successfully entered at the beginning of the array \n";
            display(arr, size);
            break;
        case 2:
            cout << "Enter the value to entered as the input\n";
            cin >> input;
            output = insertatend(arr, size, input);
            if (output == -1)
                cout << "The array is full, no more data values can be entered in it";
            else
                cout << "The data value have been successfully entered at the end of the array \n";
            display(arr, size);
            break;
        case 3:
            cout << "Enter the value to entered as the input\n";
            cin >> input;
            cout << "Enter the index in which the value is to be placed\n";
            cin >> index;
            output = insertatindex(arr, size, input, index);
            if (output == -1)
                cout << "The array is full, no more data values can be entered in it\n";
            else if (output == -2)
                cout << "The given index is invalid\n";
            else
                cout << "The data value have been successfully entered at the end of the array \n";
            display(arr, size);
            break;
        case 4:
            output = delatbeg(arr, size);
            if (output == -1)
                cout << "The array is empty\n";
            else
                cout << "The given element has been deleted\n";
            display(arr, size);
            break;
        case 5:
            output = delatend(arr, size);
            if (output == -1)
                cout << "The array is empty\n";
            else
                cout << "The given element has been deleted\n";
            display(arr, size);
            break;
        case 6:
            cout << "Enter the index at which has to be deleted\n";
            cin >> index;
            output = delatgivenindex(arr, size, index);
            if (output == -1)
                cout << "The array is empty\n";
            else if (output == -2)
                cout << "The given index is invalid\n";
            else
                cout << "The given element has been deleted\n";
            display(arr, size);
            break;
        case 0:
            return 0;

        default:
            cout << "You have inserted an invalid choice, please enter a choice between (0-6) \n";
            break;
        }
    }

    return 0;
}