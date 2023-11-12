#include <stdio.h>
#include <stdlib.h>

/* Function pointer type for binary operations */
typedef int (*BinaryOperation)(int, int);

/* Function prototypes for operations */
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

int main(void)
{
    int a = 6, b = 3;
    int x;

    /* Array of function pointers for operations */
    BinaryOperation operations[] = {add, subtract, multiply, divide};

    while (1)
    {
        printf("Operand 'a' : %d | Operand 'b' : %d\n", a, b);
        printf("Specify the operation to perform (0: add | 1: subtract | 2: Multiply | 3: divide | 4: exit): ");

        int choice;
        scanf("%d", &choice);

        if (choice >= 0 && choice <= 3)
        {
            /* Use the function pointer to call the selected operation */
            x = operations[choice](a, b);
            printf("x = %d\n", x);
        }
        else if (choice == 4)
        {
            printf("Exiting program.\n");
            break;
        }
        else
        {
            printf("Invalid choice. Please enter a number between 0 and 4.\n");
        }
    }

    return 0;
}

/* Operation functions */
int add(int a, int b)
{
    printf("Adding 'a' and 'b'\n");
    return a + b;
}

int subtract(int a, int b)
{
    printf("Subtracting 'b' from 'a'\n");
    return a - b;
}

int multiply(int a, int b)
{
    printf("Multiplying 'a' and 'b'\n");
    return a * b;
}

int divide(int a, int b)
{
    if (b != 0)
    {
        printf("Dividing 'a' by 'b'\n");
        return a / b;
    }
    else
    {
        printf("Error: Cannot divide by zero.\n");
        return 0;
    }
}
