// 010 Linked Lists Insertion
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
int sizeOf(ListNode *&head)
{
    int size = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        size = size + 1;
    }
    return size;
}
void insAtBeg(ListNode *&head, int value) // Insert at Beginning
{
    ListNode *newnode = createNode(value);
    newnode->next = head;
    head = newnode;
}
void insAtEnd(ListNode *&head, int value) // Insert at End
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
}
void insAtIndex(ListNode *&head, int value, int index) // Insert at given Index
{
    if (index < 0 || (int)sizeof(head) < index)
    {
        printf("This is an Invalid Index. \n");
        // Invalid Index
        return;
    }
    else if (index == 0)
    {
        insAtBeg(head, value);
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
        }
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

void delAtBeg(ListNode *&head) // Deletes the node present in the beginning of the linked list
{
    ListNode *temp=head;
    if(head==NULL)
    {
        printf("The Linked List is empty. \n");
        return;
    }
    head=temp->next;
    printf("The node is successfully deleted \n");

}

void delAtEnd(ListNode *&head) //Deletes a node present at the end of the linked list
{
    if(head==NULL)
    {
        printf("The Linked List is empty. \n");
        return;
    }
    if(head->next==NULL)
    {
        head=NULL;
        printf("The node is successfully deleted. \n");
        return;
    }
    ListNode *temp= head;
    ListNode *temp1;
    while(temp->next!=NULL)
    {
      temp1=temp;
      temp=temp->next;
    }
    temp1->next=NULL;
    printf("The node is successfully deleted. \n");
}

void delAtIndex(ListNode *&head, int index) //Deletes a node present at a given index
{
    int val=0;
    if(head==NULL)
    {
        printf("The Linked List is empty. \n");
        return;
    }
    else{
        ListNode *temp,*temp1;
        if (index < 0 || (int)sizeof(head) < index)
    {
        printf("This is an Invalid Index. \n");
        // Invalid Index
        return;
    }
        else{
            val=0;
            temp=head;
            temp1=head;
            while(temp!=NULL)
            {
                if((index-1)==val)
                    break;
                temp1=temp;
                val++;
                temp=temp->next;

            }
            if(temp==head)
            {
                head=head->next;
            }
            else{
                temp1->next=temp->next;
            }
        }

    }
}

int main()
{
    int choice, index, value;
    ListNode *head = NULL;
    while (1)
    {
        printf("\n\n=============MENU=============\n");

        printf("\nInsert at:\n\t01.beginning\n\t02.end\n\t03.given index\n\t04.Delete a Node at Beginning\n\t05.Delete a Node at End\n\t06.Delete a Node at given Index\n\t0.Exit\n\n");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
            {
            case 1: // insert at beg
            {
                printf("Enter data value: ");
                scanf("%d", &value);
                insAtBeg(head, value);
                display(head);
                break;
            }
            case 2: // insert at end
            {
                printf("Enter data value: ");
                scanf("%d", &value);
                insAtEnd(head, value);
                display(head);
                break;
            }
            case 3: // insert at index
            {
                printf("Enter data value: ");
                scanf("%d", &value);
                printf("Enter index: ");
                scanf("%d", &index);
                insAtIndex(head, value, index);
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
                delAtBeg(head);
                display(head);
                break;
            }
            case 5:
            {
                printf("The node that is present at the end will be deleted. \n");
                delAtEnd(head);
                display(head);
                break;

            }
            case 6:
            {
                printf("Enter the index at which : \n");
                scanf("%d", &index);
                delAtIndex(head, index);
                display(head);
                break;
            }
            default:
            {
                printf("Invalid choice (choose 0-3)");
            }
            }
        }
    }
}
