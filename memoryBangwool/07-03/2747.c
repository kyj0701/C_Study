#include <stdio.h>

int fib[45]={0,1};
int fib_ind=2;

int fibonach(int n);


int main(){
    int n, fibarr[45]={0,1}, i;

    scanf("%d", &n);
    /*if(fibarr[n]==0){
    for(i=2;i<=n;i++)
        fibarr[i]=fibarr[i-1]+fibarr[i-2];
    }
    printf("%d", fibarr[n]);*/
    printf("%d", fibonach(n));
}


int fibonach(int n){
    int result=0;
    if(n<fib_ind)
        return fib[n];
    
    result=fibonach(n-1)+fibonach(n-2);
    fib[n]=result;
    fib_ind=(n+1);
    return result;
    
}
