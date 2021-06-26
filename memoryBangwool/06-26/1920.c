#include <stdio.h>
#include <stdlib.h>


void sort(int a[], int s, int e, int mid){
    int i,j,k=0;
    int b[e-s+1];
    for(i=s, j=mid+1;i<(mid+1)&&j<(e+1);){
       b[k++]=*(a+j)<*(a+i)?*(a+(j++)):*(a+(i++));
    }
    while(j<(e+1))
        b[k++]=*(a+(j++));
    while(i<(mid+1))
        b[k++]=*(a+(i++));
    for(i=s,k=0;i<e+1;i++,k++)
        *(a+i)=b[k];
    
}

int* merge(int a[], int s, int e){
    int mid;
//    for(int i=s;i<e+1;i++)
   //     printf("%d", *(a+i));
    //for(int i=s;i<e+1;i++)
      //  printf("%d\n", a[i]);
    if((e-s)<1)
        return a;
    mid=(s+e)/2;
  
    merge(a, s, mid);
    merge(a, mid+1, e);
    sort(a, s, e, mid);
    return a;
}

void quick(int a[], int s, int e){
    int i=s+1,j=e-1,pivot=a[s];
    int tmp;
    if(s>=e)
        return;
    while(i<j){
        while(a[i]<pivot)
            i++;
        while(a[j]>pivot)
            j--;
        if(i<j){
            tmp=*(a+i);
            *(a+i)=*(a+j);
            *(a+j)=tmp;
        }
    }
    tmp=*(a+j);
    *(a+j)=*(a+s);
    *(a+s)=tmp;
    
    quick(a, s, j);
    quick(a, j+1, e);
    
}

void search(int a[], int b[], int N, int M){
    int i,key, mid, found;
    int left=0, right=N;
    for(i=0;i<M;i++){
        key=b[i];
        left=0;
        right=N;
        found=0;
        
        while(left<=right){
            mid=(left+right)/2;
        if(a[mid]>key)
            right=mid-1;
        else if(a[mid]<key)
            left=mid+1;
        else{found=1;
             break;}
          
        }
        *(b+i)=(found==1)?1:0;
        
    }
}

int main(){
    int N, M;
    int *a, *b;
    
    scanf("%d", &N);
    a=(int*)malloc(sizeof(int)*N);
    for(int i=0;i<N;i++)
        scanf("%d", &a[i]);
    scanf("%d", &M);
    b=(int*)malloc(sizeof(int)*M);
    for(int i=0;i<M;i++)
        scanf("%d", &b[i]);
    
   // merge(a, 0, N-1);
    quick(a, 0, N);
    search(a, b, N, M);
    
    for(int i=0;i<M;i++)
        printf("%d\n",b[i]);
    
    //printf("\n");
    return 0;
}


