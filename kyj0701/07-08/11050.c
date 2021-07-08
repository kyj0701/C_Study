#include <stdio.h>

int Binomial_Coefficient(int n, int k);

int binomial[10][10];

int main(void)
{
    int n, k;

    scanf("%d %d", &n, &k);


    printf("%d\n", Binomial_Coefficient(n,k));

    return 0;
}

int Binomial_Coefficient(int n, int k)
{
    int min;

    for (int i = 0; i <= n; i++)
    {
        min = (i <= k) ? i : k;
        for (int j = 0; j <= min; j++)
        {
            if (i == 0 || i == j) binomial[i][j] = 1;
            else binomial[i][j] = binomial[i-1][j-1] + binomial[i-1][j];
        }
    }

    return binomial[n][k];
}