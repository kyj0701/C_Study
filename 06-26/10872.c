#include <stdio.h>


int fact(int a){
    if(a==0)
        return 1;
    else return a*fact(a-1);
}

int main(){
    int i;
    scanf("%d", &i);
    
    printf("%d", fact(i));
    
    return 0;
}


