#include <stdio.h>
int coeff(int *C, int N, int K);
void make_coef(int *upper, int *lower, int n);

int main(){
    int C[11][10]={{1}};
    int N, K;
    int i,j;
    
    scanf("%d %d", &N, &K);
    for(i=1;i<=N;i++)
        make_coef(C[i-1],C[i], i);
    
    
   /* for(i=0;i<=N;i++){
        for(j=0;j<=i;j++)
        printf("%d ", C[i][j]);
    printf("\n");
    }*/
    
    printf("%d", C[N][K]);
    
}

void make_coef(int *upper, int *lower, int n){
    int i;
    
        
    lower[0]=1;
    lower[n]=1;
    for(i=1;i<n;i++)
        lower[i]=upper[i-1]+upper[i];
    
}
