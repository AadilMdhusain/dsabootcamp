#include <iostream>
using namespace std;

struct node
{
    char x;
    node *next;
};

int main()
{
    struct node *letter1, *letter2, *letter3, *letter4, *letter5;
    letter1 = (struct node *)malloc(sizeof(struct node));
    letter2 = (struct node *)malloc(sizeof(struct node));
    letter3 = (struct node *)malloc(sizeof(struct node));
    letter4 = (struct node *)malloc(sizeof(struct node));
    letter5 = (struct node *)malloc(sizeof(struct node));

    letter1->x = 'H';
    letter2->x = 'E';
    letter3->x = 'L';
    letter4->x = 'L';
    letter5->x = 'O';

    letter1->next = letter2;
    letter2->next = letter3;
    letter3->next = letter4;
    letter4->next = letter5;
    letter5->next = NULL;
    cout << "The word represented by the Structure is " << endl;

    struct node *temp;
    temp = letter1;
    while (temp != NULL)
    {
        cout << temp->x;
        temp = temp->next;
    }

    return 0;
}
