#include <iostream>

using namespace std;

int insertAtBeg(int arr[], int &size, int value)
{
    if (size == 50)
    {
        return -1;
    }
    else
    {
        for (int i = size; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = value;
        size++;
        return 0;
    }
}

int insertAtEnd(int arr[], int &size, int value)
{
    if (size == 50)
    {
        return -1;
    }
    else
    {
        arr[size] = value;
        size++;
        return size - 1;
    }
}

int insertAtIndex(int arr[], int &size, int value, int index)
{
    if (size == 50)
    {
        return -1;
    }
    else if (index < 0 || size < index)
    {
        return -2;
    }
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

int deleteAtBeg(int arr[], int &size)
{
    if (size == 0)
    {
        return -1;
    }
    else
    {
        for (int i = 1; i < size; i++)
        {
            arr[i - 1] = arr[i];
        }
        size--;
        return 0;
    }
}

int deleteAtEnd(int arr[], int &size)
{
    if (size == 0)
    {
        return -1;
    }
    else
    {
        size--;
        return size;
    }
}

int deleteAtIndex(int arr[], int &size, int index)
{
    if (size == 0)
    {
        return -1;
    }
    else if (index < 0 || size <= index)
    {
        return -2;
    }
    else
    {
        for (int i = index + 1; i < size; i++)
        {
            arr[i - 1] = arr[i];
        }
        size--;
        return index;
    }
}

int linearSearch(int arr[], int &size, int value)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

void rotateLeft(int arr[], int size)
{
    if (size > 1)
    {
        int first_element = arr[0];
        for (int i = 0; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[size - 1] = first_element;
    }
}

void rotateRight(int arr[], int size)
{
    if (size > 1)
    {
        int end_element = arr[size - 1];
        for (int i = size - 1; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = end_element;
    }
}

void display(int arr[], int size)
{
    cout << "\nArray: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void reverseDisplay(int arr[], int size)
{
    cout << "\n";
    for (int i = size; i > 0; i--)
    {
        cout << " " << arr[i - 1];
    }
    cout << " : Array";
}

int main()
{
    int choice, size = 0, arr[50], output, input, index;
    while (1)
    {
        printf("\n\n=============MENU=============\n");

        printf("\nInsert at:\n\t01.beginning\n\t02.end\n\t03.given index\nDelete at:\n\t04.beginning\n\t05.end\n\t06.given index");
        printf("\n07.Linear search\n08.Left rotate\n09.Right rotate\n10.Reverse display\n00.Exit\n\n");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
        {
            cout << "Enter the value : ";
            cin >> input;
            output = insertAtBeg(arr, size, input);
            if (output == -1)
                cout << "\nOverflow : cannot add more elements";
            else
                cout << "\nElement added at index = " << index;
            display(arr, size);
            break;
        }
        case 2:
        {
            cout << "Enter the value : ";
            cin >> input;
            output = insertAtEnd(arr, size, input);
            if (output == -1)
                cout << "\nOverflow : cannot add more elements";
            else
                cout << "\nElement added at index = " << index;
            display(arr, size);
            break;
        }
        case 3:
        {
            cout << "Enter the value : ";
            cin >> input;
            cout << "Enter the index : ";
            cin >> index;
            output = insertAtIndex(arr, size, input, index);
            if (output == -1)
                cout << "\nOverflow : cannot add more elements\n";
            else if (output == -2)
                cout << "\nInvalid Index : valid index to insert [0-" << size << "]";
            else
                cout << "\nElement added at index = " << index;
            display(arr, size);
            break;
        }
        case 4:
        {
            output = deleteAtBeg(arr, size);
            if (output == -1)
                cout << "\nUnderflow : no elements to delete";
            else
                cout << "\nElement deleted at index = " << index;
            display(arr, size);
            break;
        }
        case 5:
        {
            output = deleteAtEnd(arr, size);
            if (output == -1)
                cout << "\nUnderflow : no elements to delete";
            else
                cout << "\nElement deleted at index = " << index;
            display(arr, size);
            break;
        }
        case 6:
        {
            cout << "Enter the index at which has to be deleted\n";
            cin >> index;
            output = deleteAtIndex(arr, size, index);
            if (output == -1)
                cout << "\nUnderflow : no elements to delete";
            else if (output == -2)
                cout << "\nInvalid Index : valid index to delete [0-" << size - 1 << "]";
            else
                cout << "\nElement deleted at index = " << index;
            display(arr, size);
            break;
        }
        case 7:
        {
            cout << "Enter the value to be searched : ";
            cin >> input;
            output = linearSearch(arr, size, input);
            if (output == -1)
                cout << "\nValue not found";
            else
                cout << "\nValue found at index = " << output;
            display(arr, size);
            break;
        }
        case 8:
        {
            rotateLeft(arr, size);
            cout << "\nArray rotated left";
            display(arr, size);
            break;
        }
        case 9:
        {
            rotateRight(arr, size);
            cout << "\nArray rotated right";
            display(arr, size);
            break;
        }
        case 10:
        {
            cout << "\nArray reverse display";
            reverseDisplay(arr, size);
            break;
        }
        case 0:
        {
            cout << "\n===========THE END===========\n ";
            return 0;
        }
        default:
        {
            cout << "\nInvalid Choice : choose [0-10]";
            break;
        }
        }
    }
}