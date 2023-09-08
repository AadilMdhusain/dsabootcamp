#include <iostream>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
};

ListNode *createNode(int value = 0)
{
    // Using malloc to create/allocate a node in C
    // struct ListNode* newnode = (struct ListNode *)malloc(sizeof(struct ListNode *));

    // Using malloc to create/allocate a node in C++
    // ListNode* newnode = (ListNode *)malloc(sizeof(ListNode *));

    // Using new to create/allocate a node in C++
    ListNode *newnode = new ListNode;

    newnode->data = value;
    newnode->next = NULL;

    return newnode;
}

int insAtBeg(ListNode *&head, int value, int &size)
{
    ListNode *newnode = createNode(value);
    newnode->next = head;
    head = newnode;
    size++;
    return 0;
}

int insAtEnd(ListNode *&head, int value, int &size)
{
    ListNode *newnode = createNode(value);
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        ListNode *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    size++;
    return size - 1;
}

int insAtIndex(ListNode *&head, int value, int index, int &size)
{
    if (index < 0 || size < index)
    {
        // Invalid Index
        return -2;
    }
    else if (index == 0)
    {
        return insAtBeg(head, value, size);
    }
    else
    {
        ListNode *newnode = createNode(value);
        ListNode *temp = head;
        for (int i = index; i > 1; i--)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        size++;
        return index;
    }
}

int delAtBeg(ListNode *&head, int &size)
{
    if (head == NULL)
    {
        return -1;
    }
    else
    {
        ListNode *temp = head;
        head = temp->next;
        size--;
        return 0;
    }
}

int delAtEnd(ListNode *&head, int &size)
{
    if (head == NULL)
    {
        return -1;
    }
    else if (head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        ListNode *temp = head;
        ListNode *temp1;
        while (temp->next != NULL)
        {
            temp1 = temp;
            temp = temp->next;
        }
        temp1->next = NULL;
    }
    size--;
    return size;
}

int delAtIndex(ListNode *&head, int index, int &size)
{
    if (head == NULL)
    {
        return -1;
    }
    else if (index < 0 || size <= index)
    {
        // Invalid Index
        return -2;
    }
    else if (index == 0)
    {
        return delAtBeg(head, size);
    }
    else
    {
        ListNode *temp = head;
        for (int t = 1; t < index; t++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        size--;
        return index;
    }
}

int readValue(ListNode *head, int index, int &size)
{
    if (head == NULL)
    {
        return -1;
    }
    else
    {
        ListNode *temp = head;
        for (int i = 0; temp != NULL; i++)
        {
            if (i == index)
            {
                return temp->data;
            }
            temp = temp->next;
        }
    }
    return -2;
}

int writeValue(ListNode *head, int index, int value, int &size)
{
    if (head == NULL)
    {
        return -1;
    }
    else
    {
        ListNode *temp = head;
        for (int i = 0; temp != NULL; i++)
        {
            if (i == index)
            {
                temp->data = value;
                return value;
            }
            temp = temp->next;
        }
    }
    return -2;
}

int searchValue(ListNode *head, int value)
{
    if (head == NULL)
    {
        return -1;
    }
    ListNode *temp = head;
    int val = 0;
    while (temp != NULL)
    {
        if (temp->data == value)
            return val;
        temp = temp->next;
        val++;
    }
    return -2;
}

void rotateLeft(ListNode *&head)
{
    if (head != NULL && head->next != NULL)
    {
        ListNode *temp = head;
        int first_element = head->data;
        while (temp->next != NULL)
        {
            temp->data = temp->next->data;
            temp = temp->next;
        }
        temp->data = first_element;
    }
}

void rotateRight(ListNode *head)
{
    if (head != NULL && head->next != NULL)
    {
        ListNode *temp = head;
        int prev_value = head->data, saved_value;
        while (temp != NULL)
        {
            saved_value = temp->data;
            temp->data = prev_value;
            prev_value = saved_value;
            temp = temp->next;
        }
        head->data = prev_value;
    }
}

void display(ListNode *head)
{
    printf("\nList:");
    ListNode *temp = head;
    while (temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }
}

void printReverse(ListNode *head)
{

    ListNode *temp = head;
    if (temp != NULL)
    {
        printReverse(temp->next);
        cout << temp->data << " ";
    }
}

int main()
{
    int choice, index, value, size = 0;
    ListNode *head = NULL;
    while (1)
    {
        printf("\n\n=============MENU=============\n");

        printf("\nInsert at:\n\t01.beginning\n\t02.end\n\t03.given index\nDelete at:\n\t04.beginning\n\t05.end\n\t06.given Index\n07.Read node in given list\n08.Write node in given list\n09.Search a value in given list\n10.Rotate the linked list to the left\n11.Rotate the linked list to the right\n12.Print the reverse of the linked list\n0.Exit\n\n");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
        {
            printf("Enter data value: ");
            scanf("%d", &value);
            index = insAtBeg(head, value, size);
            printf("\nA node is inserted at index: %d", index);
            display(head);
            break;
        }
        case 2:
        {
            printf("Enter data value: ");
            scanf("%d", &value);
            index = insAtEnd(head, value, size);
            printf("\nA node is inserted at index: %d", index);
            display(head);
            break;
        }
        case 3:
        {
            printf("Enter data value: ");
            scanf("%d", &value);
            printf("Enter index: ");
            scanf("%d", &index);
            index = insAtIndex(head, value, index, size);
            if (index == -2)
            {
                printf("\nInvalid index");
            }
            else
            {
                printf("\nA node is inserted at index: %d", index);
                display(head);
            }
            break;
        }
        case 4:
        {
            index = delAtBeg(head, size);
            if (index == -1)
            {
                printf("\nThe linked list is empty");
            }
            else
            {
                printf("\nA node is deleted at index: %d", index);
                display(head);
            }
            break;
        }
        case 5:
        {
            index = delAtEnd(head, size);
            if (index == -1)
            {
                printf("\nThe linked list is empty");
            }
            else
            {
                printf("\nA node is deleted at index: %d", index);
                display(head);
            }
            break;
        }
        case 6:
        {
            printf("Enter the index at which : ");
            scanf("%d", &index);
            index = delAtIndex(head, index, size);
            if (index == -1)
            {
                printf("\nThe linked list is empty");
            }
            else if (index == -2)
            {
                printf("\nInvalid index");
            }
            else
            {
                printf("\nA node is deleted at index: %d", index);
                display(head);
            }
            break;
        }
        case 7:
        {
            printf("Enter the index of the node you want to read : ");
            scanf("%d", &index);
            value = readValue(head, index, size);
            if (value == -1)
            {
                printf("\nThe list is empty");
            }
            else if (value == -2)
            {
                printf("\nThe index is invalid");
            }
            else
            {
                printf("\nThe data value of the %dth node is : %d", index, value);
                display(head);
            }
            break;
        }
        case 8:
        {
            printf("Enter the index of the node you want to write a value at: ");
            scanf("%d", &index);
            printf("Enter the value to be written at that index : ");
            scanf("%d", &value);
            value = writeValue(head, index, value, size);
            if (value == -1)
            {
                printf("\nThe list is empty");
            }
            else if (value == -2)
            {
                printf("\nThe index is invalid");
            }
            else
            {
                printf("\nThe new value of the %dth node is : %d", index, value);
                display(head);
            }
            break;
        }
        case 9:
        {
            printf("Enter the value you want to search in the list : \n");
            scanf("%d", &value);
            value = searchValue(head, value);
            if (value == -1)
            {
                printf("\nThe list is empty");
            }
            else if (value == -2)
            {
                printf("\nThe node is not present in the list");
            }
            else
            {
                printf("\nThe node is present at the index %d", value);
                display(head);
            }
            break;
        }
        case 10:
        {
            rotateLeft(head);
            printf("The list has been rotated to the left\n");
            display(head);
            break;
        }
        case 11:
        {
            rotateRight(head);
            printf("The list has been rotated to the right\n");
            display(head);
            break;
        }
        case 12:
        {
            printf("\n");
            printReverse(head);
            printf("\nThe list has been printed in reverse.");
            break;
        }
        case 0:
        {
            printf("\n===========THE END===========\n ");
            return 0;
        }
        default:
        {
            printf("Invalid Choice : choose [0-12]");
        }
        }
    }
}