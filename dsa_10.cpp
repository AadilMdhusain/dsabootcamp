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
int insAtBeg(ListNode *&head, int value) // Insert at Beginning
{
    ListNode *newnode = createNode(value);
    newnode->next = head;
    head = newnode;
    return 1;
}

int insAtEnd(ListNode *&head, int value) // Insert at End
{
    int index;
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
    index=sizeOf(head);
    return index;
}
int insAtIndex(ListNode *&head, int value, int index) // Insert at given Index
{
    int place;
    if (index < 0 || sizeOf(head) < index)
    {
        // Invalid Index
        return -1;
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
        place=sizeOf(head);
        return place;
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

int delAtBeg(ListNode *&head) // Deletes the node present in the beginning of the linked list
{
    ListNode *temp=head;
    if(head==NULL)
    {
        return -1;
    }
    head=temp->next;
    return 0;

}

int delAtEnd(ListNode *&head) //Deletes a node present at the end of the linked list
{
    int val;
    if(head==NULL)
    {
        return -1;
    }
    if(head->next==NULL)
    {
        head=NULL;
        return 1;
    }
    val=sizeOf(head);
    ListNode *temp= head;
    ListNode *temp1;
    while(temp->next!=NULL)
    {
      temp1=temp;
      temp=temp->next;
    }
    temp1->next=NULL;
    return val;
}

int delAtIndex(ListNode *&head, int index) //Deletes a node present at a given index
{
    int val=0;
    if(head==NULL)
    {
        return -1;
    }
    else{
        ListNode *temp,*temp1;
        if (index < 0 || sizeOf(head) < index)
    {
        // Invalid Index
        return 0;
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
            return 1;
        }

    }
}

int main()
{
    int choice, index, value,value1;
    ListNode *head = NULL;
    while (1)
    {
        printf("\n\n=============MENU=============\n");

        printf("\nInsert at:\n\t01.beginning\n\t02.end\n\t03.given index\nDelete at:\n\t04.Delete a Node at Beginning\n\t05.Delete a Node at End\n\t06.Delete a Node at given Index\n\t0.Exit\n\n");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
            {
            case 1: // insert at beg
            {
                printf("Enter data value: ");
                scanf("%d", &value);
                value=insAtBeg(head, value);
                printf("The node is successfully inserted at index: %d", value);
                display(head);
                break;
            }
            case 2: // insert at end
            {
                printf("Enter data value: ");
                scanf("%d", &value);
                value=insAtEnd(head, value);
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
                value=insAtIndex(head, value, index);
                if(value==-1)
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
                value=delAtBeg(head);
                if(value==-1)
                    printf("The linked list is empty. \n");
                else
                    printf("The node present at the index %d is deleted. ", value);
                display(head);
                break;
            }
            case 5:
            {
                printf("The node that is present at the end will be deleted. \n");
                value=delAtEnd(head);
                if(value==-1)
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
                value=delAtIndex(head, index);
                if(value==-1)
                    printf("The linked list is empty. \n");
                else if(value==0)
                    printf("The index is invalid. \n");
                else
                    printf("The node present at the index %d is deleted. ",value);
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
