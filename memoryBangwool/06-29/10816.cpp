#include<stdio.h>
#include<algorithm>
using namespace std;

void quick(int *arr, int left, int right);
int partition(int *arr, int left, int right);
int search(int *arr, int len, int target);
int search_frst(int *arr, int left, int right, int target);
int search_last(int *arr, int left, int right, int target);

void swap(int *arr, int i, int j);

int main(){
    int arr[500000];
    int N, M;
    int result[500000];
    int i, target;
    
    scanf("%d", &N);
    for(i=0;i<N;i++)
        scanf("%d", &arr[i]);
    //quick(arr, 0, N);
    sort(arr, arr + N);
    
    scanf("%d", &M);
    for(i=0;i<M;i++){
        scanf("%d", &target);
        result[i]=search(arr, N, target);
    }
    
    for(i=0;i<M;i++)
        printf("%d ", result[i]);
   // printf("\n");
    
}


void quick(int *arr, int left, int right){
    int pivot;
    if(left<(right)){
        pivot=partition(arr, left, right);
        quick(arr,left,pivot);
        quick(arr, pivot+1, right);
    }
}
int partition(int *arr, int left, int right){
    int low=left+1;
    int high=right-1;
    int pivot=arr[left];
    
    while(low<=high){
        while(arr[low]<=pivot)
            low++;
        while(arr[high]>pivot)
            high--;
        if(low<high)
            swap(arr, low, high);
    }
    swap(arr, left, high);
    return high;
}




int search(int *arr, int len, int target){
    int mid;
    int left=0, right=(len-1);
    int low, high;
    
    while(left<=right)
    {
        mid=(left+right)/2;
        if(arr[mid]==target){
            low=search_frst(arr, 0, mid, target);
            high=search_last(arr, mid, len-1, target);
            return (high-low+1);
        }
        if(arr[mid]>target)
            right=mid-1;
        else if(arr[mid]<target)
            left=mid+1;
    }
    return 0;
}


void swap(int *arr, int i, int j){
    int tmp=arr[i];
    *(arr+i)=arr[j];
    *(arr+j)=tmp;
}


int search_frst(int *arr, int left, int right, int target){
    int mid;
    while(left<=right){
        mid=(left+right)/2;
        if(arr[mid]==target){
            if((mid==left)||(arr[mid-1]!=target))
                return mid;
            else right=mid-1;
        }
        else left=mid+1;
    }
    return -1;
}


int search_last(int *arr, int left, int right, int target){
    int mid;
    while(left<=right){
        mid=(left+right)/2;
        
        if(arr[mid]==target){
            if(mid==right||arr[mid+1]!=target)
                return mid;
            else left=mid+1;
        }
        else right=mid-1;
    }
    return -1;
}
