#include <stdio.h>
#include <algorithm>

using namespace std;

int LowerBound(int *arr, int len, int target);
int UpperBound(int *arr, int len, int target);

int main(void)
{
    int N;
    int A[500050];
    
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    sort(A, A + N);

    // Search
    int M, res;
    int B[500050];

    scanf("%d", &M);

    for (int i = 0; i < M; i++)
    {
        scanf("%d", &B[i]);
    }

    for (int i = 0; i < M; i++)
    {
        res = UpperBound(A, N, B[i]);
        if (res == -1) printf("0 ");
        else printf("%d ",res - LowerBound(A, N, B[i]) + 1);
    }

    return 0;
}

int LowerBound(int *arr, int len, int target)
{
    int left = 0;
    int right = len - 1;
    int mid;

    while (1)
    {
        mid = (left + right) / 2;

        if (left > right)
        {
            if (target == arr[left]) return left;
            else return -1;
        }

        if (target <= arr[mid]) right = mid - 1;
        else left = mid + 1;
    }
}

int UpperBound(int *arr, int len, int target)
{
    int left = 0;
    int right = len - 1;
    int mid;

    while (1)
    {
        mid = (left + right) / 2;

        if (left > right)
        {
            if (target == arr[right]) return right;
            else return -1;
        }

        if (target >= arr[mid]) left = mid + 1;
        else right = mid - 1;
    }
}