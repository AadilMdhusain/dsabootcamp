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

int insAtBeg(ListNode *&head, ListNode *&tail, int value, int &size)
{
    ListNode *newnode = createNode(value);
    newnode->next = head;
    if (head == NULL)
        tail = newnode;
    head = newnode;
    size++;
    return 0;
}

int insAtEnd(ListNode *&head, ListNode *&tail, int value, int &size)
{
    ListNode *newnode = createNode(value);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        tail->next = newnode;
        tail = newnode;
    }
    size++;
    return size - 1;
}

int insAtIndex(ListNode *&head, ListNode *&tail, int value, int index, int &size)
{
    if (index < 0 || size < index)
    {
        // Invalid Index
        return -2;
    }
    else if (index == 0)
    {
        return insAtBeg(head, tail, value, size);
    }
    else if (index == size)
    {
        return insAtEnd(head, tail, value, size);
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

int delAtBeg(ListNode *&head, ListNode *&tail, int &size)
{
    if (head == NULL)
    {
        return -1;
    }
    else
    {
        ListNode *temp = head;
        head = temp->next;
        if (size == 1)
            tail = NULL;
        size--;
        return 0;
    }
}

int delAtEnd(ListNode *&head, ListNode *&tail, int &size)
{
    if (head == NULL)
    {
        return -1;
    }
    else if (head->next == NULL)
    {
        head = NULL;
        tail = NULL;
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
        tail = temp1;
    }
    size--;
    return size;
}

int delAtIndex(ListNode *&head, ListNode *&tail, int index, int &size)
{
    if (head == NULL)
    {
        return -1;
    }
    else if (index < 0 || size <= index)
    {
        return -2;
    }
    else if (index == 0)
    {
        return delAtBeg(head, tail, size);
    }
    else
    {
        ListNode *temp = head;
        for (int t = 1; t < index; t++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        if (index == size - 1)
            tail = temp;
        size--;
        return index;
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

int main()
{
    int choice, index, value, size = 0;
    ListNode *head = NULL, *tail = NULL;
    while (1)
    {
        printf("\n\n=============MENU=============\n");
        printf("\nInsert at:\n\t01.beginning\n\t02.end\n\t03.given index\nDelete at:\n\t04.beginning\n\t05.end\n\t06.given Index\n0.Exit");
        printf("\n");
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            printf("Enter data value: ");
            scanf("%d", &value);
            index = insAtBeg(head, tail, value, size);
            printf("\nA node is inserted at index: %d", index);
            display(head);
            break;
        }
        case 2:
        {
            printf("Enter data value: ");
            scanf("%d", &value);
            index = insAtEnd(head, tail, value, size);
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
            index = insAtIndex(head, tail, value, index, size);
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
            index = delAtBeg(head, tail, size);
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
            index = delAtEnd(head, tail, size);
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
            index = delAtIndex(head, tail, index, size);
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
        case 0:
        {
            printf("\n===========THE END===========\n ");
            return 0;
        }
        default:
        {
            printf("Invalid Choice : choose [0-6]");
        }
        }
    }
}
