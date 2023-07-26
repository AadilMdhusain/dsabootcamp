#include <iostream>
using namespace std;



struct type1{
    char x;
    char y;
    int  i;
    double d;
};
struct type2{
    char x;
    double d;
    char y;
    int i;
};
struct type3{
    char x;
    int  i;
    char y;
    double d;
};


int main()
{
    struct type1 test1, *ptr1;
    type2 test2, *ptr2;
    type3 test3, *ptr3;

    test1.x='A';
    test1.y='B';
    test1.i=10;
    test1.d=10000;

    test2.x='C';
    test2.y='D';
    test2.i=20;
    test2.d=20000;

    test3.x='E';
    test3.y='F';
    test3.i=30;
    test3.d=30000;

    ptr1=&test1;
    ptr2=&test2;
    ptr3=&test3;

    cout<<"The size of variable of 'type1' structure is "<<sizeof(test1);
    cout<<"\nThe size of variable of 'type2' structure is "<<sizeof(test2);
    cout<<"\nThe size of variable of 'type3' structure is "<<sizeof(test3); 

    cout<<"\n\nThe starting address of all the variables are "<<endl;

    cout<<"Starting address of 'test1' "<<(long long)ptr1;
    cout<<"\nStarting address of 'test2' "<<(long long)ptr2;
    cout<<"\nStarting address of 'test3' "<<(long long)ptr3;

    cout<<"\n\nGetting the address of the members of the struct type1\n\n";
    cout<<"Address of test1.x "<<(long long)&ptr1->x;
    cout<<"\nAddress of test1.y "<<(long long)&ptr1->y;
    cout<<"\nAddress of test1.i "<<(long long)&ptr1->i;
    cout<<"\nAddress of test1.d "<<(long long)&ptr1->d;
    cout<<"\nNext Address "<<(long long)(ptr1+1);

    cout<<"\n\nGetting the address of the members of the struct type2\n\n";
    cout<<"Address of test2.x "<<(long long)&ptr2->x;
    cout<<"\nAddress of test2.y "<<(long long)&ptr2->y;
    cout<<"\nAddress of test2.i "<<(long long)&ptr2->i;
    cout<<"\nAddress of test2.d "<<(long long)&ptr2->d;

    cout<<"\n\nGetting the address of the members of the struct type3\n\n";
    cout<<"Address of test3.x "<<(long long)&ptr3->x;
    cout<<"\nAddress of test3.y "<<(long long)&ptr3->y;
    cout<<"\nAddress of test3.i "<<(long long)&ptr3->i;
    cout<<"\nAddress of test3.d "<<(long long)&ptr3->d;




    return 0;
}