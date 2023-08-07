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
        int place;
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
    if(head==NULL)
    {
        return -1;
    }
    if(head->next==NULL)
    {
        head=NULL;
        return 1;
    }
    int val;
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
            int val=0;
            temp=head;
            temp1=head;
            while(temp!=NULL)
            {
                if((index)==val)
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
            return val;
        }

    }
}

int readValue(ListNode *head, int size, int index)
{
    if(head==NULL)
        return 0;
    else if(size<index || index<0)
        return -1;
        int val=0;
    ListNode *temp=head;
    while(temp!=NULL)
    {
        if(index==val)
            return temp->data;
        val++;
        temp=temp->next;
    }

}

int writeValue(ListNode *head,int size, int index, int value)
{
    if(head==NULL)
        return -2;
    else if(size<index || index<0)
        return -1;
    ListNode *temp=head;
    int val=0;
    while(temp!=NULL)
    {
        if(index==val)
        {
            temp->data=value;
            return value;
        }
        temp=temp->next;
        val++;
    }

}

int searchValue(ListNode *head,int size, int value)
{
    if(head==NULL)
        return -1;
    ListNode *temp=head;
    int val=0;
    while(temp!=NULL)
    {
        if(temp->data==value)
            return val;
        temp=temp->next;
        val++;
    }
    return -1;
}


int main()
{
    int choice, index, value,value1,sizeoflist;
    ListNode *head = NULL;
    while (1)
    {
        printf("\n\n=============MENU=============\n");

        printf("\nInsert at:\n\t01.beginning\n\t02.end\n\t03.given index\nDelete at:\n\t04.beginning\n\t05.end\n\t06.given Index\n07.Read node in given list\n08.Write node in given list\n09.Search a value in given list\n0.Exit\n\n");
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
            case 7:
            {
                printf("Enter the index of the node you want to read : \n");
                scanf("%d", &index);
                sizeoflist=sizeOf(head);
                value=readValue(head,sizeoflist,index);
                if(value==0)
                    printf("The list is empty\n");
                else if(value==-1)
                    printf("The index is invalid\n");
                else
                    printf("The data value of the %dth node is : %d\n",index,value);
                    display(head);
                break;
            }
            case 8:
            {
                printf("Enter the index of the node you want to write a value at: \n");
                scanf("%d", &index);
                sizeoflist=sizeOf(head);
                printf("Enter the value to be written at that index : \n");
                scanf("%d", &value);
                value=writeValue(head,sizeoflist,index,value);
                if(value==-2)
                    printf("The list is empty\n");
                else if(value==-1)
                    printf("The index is invalid\n");
                else
                    printf("The new value of the %dth node is : %d \n",index,value);
                display(head);
                break;

            }
            case 9:
            {
                printf("Enter the value you want to search in the list : \n");
                scanf("%d", &value);
                sizeoflist=sizeOf(head);
                value=searchValue(head,sizeoflist,value);
                if(value==-1)
                    printf("The list is empty\n");
                else
                    printf("The node is present at the index %d .",value);
                display(head);
                break;
            }
            default:
            {
                printf("Invalid choice (choose 0-9)");
            }
            }
        }
    }
}
