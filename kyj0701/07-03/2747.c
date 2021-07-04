#include <stdio.h>

int fibonacciList[50];

int fibonacci(int n);

int main(void)
{
    int n;

    fibonacciList[0] = 0;
    fibonacciList[1] = 1;

    scanf("%d", &n);

    printf("%d\n", fibonacci(n));

    return 0;
}

int fibonacci(int n)
{
    if (n > 1)
    {
        for (int i = 2; i <= n; i++)
        {
            fibonacciList[i] = fibonacciList[i-1] + fibonacciList[i-2];
        }
    }
    return fibonacciList[n];
}