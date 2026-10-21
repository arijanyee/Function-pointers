
#include <stdio.h>
#include <stdlib.h>

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
int exit_program(int a, int b);

int main(void)
{
    int a = 6;
    int b = 3;
    char choice;

    int (*operations[5])(int, int) = {
        add,
        subtract,
        multiply,
        divide,
        exit_program
    };

    printf("Operand 'a' : %d | Operand 'b' : %d\n", a, b);
    printf("Specify the operation to perform (0 : add | 1 : subtract | 2 : Multiply | 3 : divide | 4 : exit): ");

    scanf(" %c", &choice);

    operations[choice - '0'](a, b);

    return 0;
}

int add(int a, int b)
{
    printf("Adding 'a' and 'b'\n");
    printf("x = %d\n", a + b);
    return a + b;
}

int subtract(int a, int b)
{
    printf("Subtracting 'b' from 'a'\n");
    printf("x = %d\n", a - b);
    return a - b;
}

int multiply(int a, int b)
{
    printf("Multiplying 'a' and 'b'\n");
    printf("x = %d\n", a * b);
    return a * b;
}

int divide(int a, int b)
{
    printf("Dividing 'a' by 'b'\n");
    printf("x = %d\n", a / b);
    return a / b;
}

int exit_program(int a, int b)
{
    (void)a;
    (void)b;
    return 0;
}
