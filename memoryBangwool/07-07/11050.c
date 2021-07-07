#include<stdio.h>

unsigned long calC(int N, int K);
unsigned long fact(int low, int high);

int main(){
    int N,K;
    scanf("%d %d",&N, &K);
   
    printf("%u", calC(N,K));
    
}

unsigned long calC(int N, int K){
    int low;
    unsigned long up, down;

    
    if(K<N/2)
        low=N-K;
        
    else{low=K;
        K=N-K;}
    
    up=fact(low+1, N);
    down=fact(1,K);
    
    return up/down;
        
}

unsigned long fact(int low, int high){
    int i=low;
    unsigned long result=1;
   /* unsigned long result[high];
    result[low-1]=1;
    for(i=low;i<=high;i++)
        result[i]=result[i-1]*(i);
        return result[high];*/
    for(i=low;i<=high;i++)
        result*=i;
    return result;
    
}
