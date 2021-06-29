#include <stdio.h>

void Swap(int arr[], int a, int b);
int Partition(int arr[], int left, int right);
void QuickSort(int arr[], int left, int right);
int BinarySearch(int *arr, int len, int target);

int main(void)
{
    int N;
    int A[100050];
    
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    QuickSort(A, 0, N-1);

    // Search
    int M;
    int B[100050];

    scanf("%d", &M);

    for (int i = 0; i < M; i++)
    {
        scanf("%d", &B[i]);
    }

    for (int i = 0; i < M; i++)
    {
        printf("%d\n",BinarySearch(A, N, B[i]));
    }

    return 0;
}

void Swap(int *arr, int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int Partition(int *arr, int left, int right)
{
    int pivot = arr[left];
    int low = left + 1;
    int high = right;
 
    while (low <= high)
    {
        while (low <= right && pivot >= arr[low])
        {
            low++;
        }
        while (high >= (left+1) && pivot <= arr[high])
        {
            high--;
        }
        if (low <= high)
        {
            Swap(arr, low, high);
        }
    }
    Swap(arr, left, high); 
    return high; 
 
}
 
void QuickSort(int *arr, int left, int right)
{
    if (left <= right)
    {
        int pivot = Partition(arr, left, right);
        QuickSort(arr, left, pivot - 1);
        QuickSort(arr, pivot + 1, right);
    }
}

int BinarySearch(int *arr, int len, int target)
{
    int left = 0;
    int right = len - 1;
    int mid;

    while (left <= right)
    {
        mid = (left + right) / 2;
        if (target == arr[mid]) return 1;
        else if (target > arr[mid])
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return 0;
}