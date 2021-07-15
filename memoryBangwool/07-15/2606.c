#include<stdio.h>


int network[100][100]={0};
int visit[100]={0};

int DFS(int start, int c_num);
void get_network();
int count=0;

int main(){
    int c_num, n_num;
    
    scanf("%d", &c_num);
    scanf("%d", &n_num);
    
    for(int i=0;i<n_num;i++)
        get_network();
    
    DFS(1, c_num);
    
    printf("%d",count-1);
}


int DFS(int start, int c_num){
    int j=0;
    
    visit[start-1]=1;
    count++;
    
    for(int i=0;i<100&&j<c_num;i++){
        if(network[start-1][i])
            if(!visit[i]){
                DFS(i+1, c_num);
                j++;
            }
    }
        
    
    return count;
}

void get_network(){
    int x, y;
    scanf("%d %d", &x, &y);
    network[x-1][y-1]=1;
    network[y-1][x-1]=1;
    
}
