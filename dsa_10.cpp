// 010 Linked Lists
#include <iostream>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
};

ListNode *createNode(int value = 0) // create node
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

int insAtBeg(ListNode *&head, int value, int &size) // Insert at Beginning
{
    ListNode *newnode = createNode(value);
    newnode->next = head;
    head = newnode;
    size++;
    return 0;
}

int insAtEnd(ListNode *&head, int value, int &size) // Insert at End
{
    ListNode *newnode = createNode(value);
    if (head == NULL)
    {
        head = newnode;
        size++;
    }
    else
    {
        ListNode *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        size++;
    }
    return size;
}
int insAtIndex(ListNode *&head, int value, int index, int &size) // Insert at given Index
{
    if (index < 0 || size < index)
    {
        // Invalid Index
        return -1;
    }
    else if (index == 0)
    {
        return insAtBeg(head, value, size);
    }
    else
    {
        ListNode *newnode = createNode(value);
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            ListNode *temp = head;
            while (index > 1)
            {
                temp = temp->next;
                index -= 1;
            }
            newnode->next = temp->next;
            temp->next = newnode;
            size++;
        }
        return size;
    }
}
void display(ListNode *head) // Display using List Traversal
{
    printf("\nList:");
    ListNode *temp = head;
    while (temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }
}

int delAtBeg(ListNode *&head, int &size) // Deletes the node present in the beginning of the linked list
{
    ListNode *temp = head;
    if (head == NULL)
    {
        return -1;
    }
    head = temp->next;
    size--;
    return 0;
}

int delAtEnd(ListNode *&head, int &size) // Deletes a node present at the end of the linked list
{
    if (head == NULL)
    {
        return -1;
    }
    if (head->next == NULL)
    {
        head = NULL;
        size--;
        return size;
    }
    ListNode *temp = head;
    ListNode *temp1;
    while (temp->next != NULL)
    {
        temp1 = temp;
        temp = temp->next;
    }
    temp1->next = NULL;
    size--;
    return size;
}

int delAtIndex(ListNode *&head, int index, int &size) // Deletes a node present at a given index
{
    if (head == NULL)
    {
        return -1;
    }
    else
    {
        ListNode *temp, *temp1;
        if (index < 0 || size <= index)
        {
            // Invalid Index
            return -2;
        }
        else
        {
            int val = 0;
            temp = head;
            temp1 = head;
            while (temp != NULL)
            {
                if ((index) == val)
                    break;
                temp1 = temp;
                val++;
                temp = temp->next;
            }
            if (temp == head)
            {
                head = head->next;
            }
            else
            {
                temp1->next = temp->next;
            }
            size--;
            return val;
        }
    }
}

int readValue(ListNode *head, int index, int &size)
{
    if (head == NULL)
        return -1;
    else if ((size - 1) < index || index < 0)
        return -2;
    int val = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        if (index == val)
            return temp->data;
        val++;
        temp = temp->next;
    }
}

int writeValue(ListNode *head, int index, int value, int &size)
{
    if (head == NULL)
        return -1;
    else if ((size - 1) < index || index < 0)
        return -2;
    ListNode *temp = head;
    int val = 0;
    while (temp != NULL)
    {
        if (index == val)
        {
            temp->data = value;
            return value;
        }
        temp = temp->next;
        val++;
    }
}

int searchValue(ListNode *head, int value)
{
    if (head == NULL)
        return -1;
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

int rotateLeft(ListNode *&head)
{
    if (head == NULL)
        return -1;
    ListNode *temp = head;
    int first_element = head->data;
    while (temp->next != NULL)
    {
        temp->data = temp->next->data;
        temp = temp->next;
    }
    temp->data = first_element;
    return 1;
}

int rotateRight(ListNode *head)
{
    if (head == NULL)
        return -1;
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
    return 1;
}

void printReverse(ListNode *head){

    ListNode *temp =head;
    if(temp!=NULL)
    {
       printReverse(temp->next);
       cout<<temp->data<<", ";
    }
}

int main()
{
    int choice, index, value, value1, size = 0;
    ListNode *head = NULL;
    while (1)
    {
        printf("\n\n=============MENU=============\n");

        printf("\nInsert at:\n\t01.beginning\n\t02.end\n\t03.given index\nDelete at:\n\t04.beginning\n\t05.end\n\t06.given Index\n07.Read node in given list\n08.Write node in given list\n09.Search a value in given list\n10.Rotate the linked list to the left\n11.Rotate the linked list to the right\n12.Print the reverse of the linked list\n0.Exit\n\n");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
            {
            case 1: // insert at beg
            {
                printf("Enter data value: ");
                scanf("%d", &value);
                value = insAtBeg(head, value, size);
                printf("The node is successfully inserted at index: %d", value);
                display(head);
                break;
            }
            case 2: // insert at end
            {
                printf("Enter data value: ");
                scanf("%d", &value);
                value = insAtEnd(head, value, size);
                printf("The node is successfully inserted at index: %d", value);
                display(head);
                break;
            }
            case 3: // insert at index
            {
                printf("Enter data value: ");
                scanf("%d", &value);
                printf("Enter index: ");
                scanf("%d", &index);
                value = insAtIndex(head, value, index, size);
                if (value == -1)
                    printf("You have given an invalid index as input.\n");
                else
                    printf("The node is successfully inserted at index: %d", index);
                display(head);
                break;
            }
            case 0:
            {
                printf("\n===========THE END===========\n ");
                return 0;
            }
            case 4:
            {
                printf("The node that is present at the beginning will be deleted.\n");
                value = delAtBeg(head, size);
                if (value == -1)
                    printf("The linked list is empty. \n");
                else
                    printf("The node present at the index %d is deleted. ", value);
                display(head);
                break;
            }
            case 5:
            {
                printf("The node that is present at the end will be deleted. \n");
                value = delAtEnd(head, size);
                if (value == -1)
                    printf("The linked list is empty. \n");
                else
                    printf("The node present at the index %d is deleted. ", value);
                display(head);
                break;
            }
            case 6:
            {
                printf("Enter the index at which : \n");
                scanf("%d", &index);
                value = delAtIndex(head, index, size);
                if (value == -1)
                    printf("The linked list is empty. \n");
                else if (value == -2)
                    printf("The index is invalid. \n");
                else
                    printf("The node present at the index %d is deleted. ", value);
                display(head);
                break;
            }
            case 7:
            {
                printf("Enter the index of the node you want to read : \n");
                scanf("%d", &index);
                value = readValue(head, index, size);
                if (value == -1)
                    printf("The list is empty\n");
                else if (value == -2)
                    printf("The index is invalid\n");
                else
                    printf("The data value of the %dth node is : %d\n", index, value);
                display(head);
                break;
            }
            case 8:
            {
                printf("Enter the index of the node you want to write a value at: \n");
                scanf("%d", &index);
                printf("Enter the value to be written at that index : \n");
                scanf("%d", &value);
                value = writeValue(head, index, value, size);
                if (value == -1)
                    printf("The list is empty\n");
                else if (value == -2)
                    printf("The index is invalid\n");
                else
                    printf("The new value of the %dth node is : %d \n", index, value);
                display(head);
                break;
            }
            case 9:
            {
                printf("Enter the value you want to search in the list : \n");
                scanf("%d", &value);
                value = searchValue(head, value);
                if (value == -1)
                    printf("The list is empty\n");
                else if (value == -2)
                    printf("The node is not present in the list\n");
                else
                    printf("The node is present at the index %d .", value);
                display(head);
                break;
            }
            case 10:
            {
                value = rotateLeft(head);
                if (value == -1)
                    printf("The list is empty\n");
                else
                    printf("The list has been rotated to the left\n");
                display(head);
                break;
            }
            case 11:
            {
                value = rotateRight(head);
                if (value == -1)
                    printf("The list is empty\n");
                else
                    printf("The list has been rotated to the right\n");
                display(head);
                break;
            }
            case 12:
            {
                printReverse(head);
                printf("\nThe list has been printed in reverse.");
                break;
            }
            default:
            {
                printf("Invalid choice (choose 0-12)");
            }
            }
        }
    }
}