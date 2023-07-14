
#include <iostream>
using namespace std;

int main()
{
    int nums[4] = {5, 2, 1, 4};
    int *ptr = nums;
    // The name of the Array returns the address of its first element
    printf("\n`ptr = nums`   is same as   `ptr = &nums[0]`");

    // To get the address of the array itself, use `&nums`
    printf("\nAddress of the Array        (&nums)   = %d \t (type = int **)", &nums);
    // Address of the array is same as the address of its first element only their types are not the same
    printf("\nAddress of the 1st element (&nums[0]) = %d \t (type = int *)", &nums[0]);
    // In this example : address of the int array nums is of the type `int**`
    //                 : address of the its first element is of the type `int*`

    // Order of precedence
    printf("\n\n");
    printf("\n*(nums+1) = %d \t\t!=\t *nums + 1 = %d \t\t==\t (*nums)+1 = %d", *(nums + 1), *nums + 1, (*nums) + 1);
    // &(address of) and *(value at) operators are unary operators and have a greater priority than {*, /, +, -} operators
    printf("\n\n");

    // Using %d specifier to print the address in base10 int for easy understanding
    return 0;
}
