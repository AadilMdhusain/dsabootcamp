#include <iostream>
#include <climits>

using namespace std;

struct ListNode
{
    int data;
    ListNode *next;

    ListNode(int data, ListNode *next = NULL)
    {
        this->data=data;
        this->next=next;
    }
};

class Queue
{
    ListNode *head;
    ListNode *tail;
    int size;

public:

    Queue()
    {
        this->head=NULL;
        this->tail=NULL;
        size=0;
    }
    int push(int value);
    int pop();
    int front();
    int back();
    int isEmpty();
    void display();
};

ListNode *createNode(int value)
{
    ListNode *node= new ListNode(value);
    return node;
}

int Queue::push(int value)
{
    ListNode *newnode= createNode(value);
    if(this->size==0)
    {
        this->tail=newnode;
        this->head=newnode;
    }
    else
    {
        this->tail->next=newnode;
        this->tail=newnode;
    }
    this->size+=1;
    return 0;
}

int Queue::pop()
{
    if(this->size==0)
    {
        return -1;
    }
    ListNode *dead=this->head;
    this->head=dead->next;
    delete dead;
    this->size=this->size-1;
    if(this->size==0)
    {
        tail=NULL;
    }
    return 0;
}

int Queue::front()
{
    if(this->size==0)
    {
        return INT_MIN;
    }
    return this->tail->data;
}

int Queue::back()
{
    if(this->size==0)
    {
        return INT_MIN;
    }
    return this->head->data;

}

int Queue::isEmpty()
{
    return this->size;
}

void Queue::display()
{
    ListNode *temp=this->head;
    cout<<"Queue :";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}


int main()
{
    int choice,item;
    Queue s1;
    while(1)
    {
        cout<<"\nChoose from the following options:\n";
        cout<<"1.Push\n";
        cout<<"2.Pop\n";
        cout<<"3.Check the front of the Queue\n";
        cout<<"4.Check the back of the Queue\n";
        cout<<"5.Check if Queue is Empty\n";
        cout<<"6.Display the Queue\n";
        cout<<"7.Exit\n";
        cin>>choice;
        switch(choice)
        {
            case 1:cout<<"Enter the item to be pushed into the Queue\n";
                   cin>>item;
                   s1.push(item);
                   s1.display();
                   break;
            case 2:item=s1.pop();
                   if(item==0)
                   cout<<"Item was successfully removed.\n";
                   else
                   cout<<"The Queue is empty.\n";
                   s1.display();
                   break;
            case 3:item=s1.front();
                   if(item==INT_MIN)
                   cout<<"The Queue is empty.\n";
                   else
                   cout<<"The element at the front of the Queue is "<<item<<endl;
                   break;
            case 4:item=s1.back();
                   if(item==INT_MIN)
                    cout<<"The Queue is empty.\n";
                   else
                    cout<<"The element at at the back of the Queue is "<<item<<endl;
                   break;
            case 5:item=s1.isEmpty();
                   if(item==0)
                    cout<<"The Queue is empty\n";
                   else
                    cout<<"The Queue is not empty\n";
                    break;
            case 6:s1.display();
                    break;
            case 7:exit(0);
            default:cout<<"You have chosen a wrong option. Choose from (1-7)\n";
                    break;


        }
    }
    return 0;
}