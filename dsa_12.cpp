#include <iostream>

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

class Stack
{
    ListNode *head;
    ListNode *tail;
    int size;

public:

    Stack()
    {
        this->head=NULL;
        this->tail=NULL;
        size=0;
    }
    int push(int value);
    int pop();
    int top();
    int isEmpty();
    void display();
};

ListNode *createNode(int value)
{
    ListNode *node= new ListNode(value);
    return node;
}

int Stack::push(int value)
{
    ListNode *newnode= createNode(value);
    newnode->next= this->head;
    this->head=newnode;
    if(this->size==0)
    {
        this->tail=newnode;
    }
    this->size+=1;
    return 0;
}

int Stack::pop()
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

int Stack::top()
{
    if(this->size==0)
    {
        return -1;
    }
    return this->head->data;
}

int Stack::isEmpty()
{
    return this->size;
}

void Stack::display()
{
    ListNode *temp=this->head;
    cout<<"STACK :";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}


int main()
{
    int choice,item;
    Stack s1;
    while(1)
    {
        cout<<"\nChoose from the following options:\n";
        cout<<"1.Push\n";
        cout<<"2.Pop\n";
        cout<<"3.Check top of the stack\n";
        cout<<"4.Check if Stack is Empty\n";
        cout<<"5.Display the Stack\n";
        cout<<"6.Exit\n";
        cin>>choice;
        switch(choice)
        {
            case 1:cout<<"Enter the item to be pushed into the stack\n";
                   cin>>item;
                   s1.push(item);
                   s1.display();
                   break;
            case 2:item=s1.pop();
                   if(item==0)
                   cout<<"Item was successfully removed.\n";
                   else
                   cout<<"The stack is empty.\n";
                   s1.display();
                   break;
            case 3:item=s1.top();
                   if(item==-1)
                   cout<<"The stack is empty.\n";
                   else
                   cout<<"The element at the top of the stack is "<<item<<endl;
                   break;
            case 4:item=s1.isEmpty();
                   if(item==0)
                    cout<<"The stack is empty\n";
                   else
                    cout<<"The stack is not empty\n";
                    break;
            case 5:s1.display();
                    break;
            case 6:exit(0);
            default:cout<<"You have chosen a wrong option. Choose from (1-6)\n";
                    break;


        }
    }
    return 0;
}