#include<stdio.h>

int Glink[1001][1001]={0};
int visit[1001];
int Bque[1000];
int Bfront=-1;
int Brear=0;

void DFS(int start);
void BFS(int start);
void get_link();
void push(int n);
int pop();
void reset_visit(int n);

int main(){
    int n, m, start;
    scanf("%d %d %d", &n, &m, &start);
    
    for(int i=0;i<m;i++)
        get_link();
    
    reset_visit(n);
    DFS(start);
    printf("\n");
    reset_visit(n);
    BFS(start);
}


void DFS(int start){
    int i, j;
    
    printf("%d ", start);
    visit[start]=1;
    
    for(i=1,j=0;j<Glink[start][0]&&i<1001;i++){
        if((!Glink[start][i]&&!Glink[i][start])||visit[i]){
            if(Glink[start][i]||Glink[i][start])j++;
            continue;
        }
        DFS(i);
        j++;
        }
            
    
}
void BFS(int start){
    int tmp, i, j;
    
    printf("%d ", start);
    visit[start]=1;
    push(start);
    
    for(tmp=pop();Brear>Bfront;tmp=pop()){
    
        for(i=1, j=0;j<Glink[tmp][0]&&i<1001;i++){
            if((!Glink[tmp][i]&&!Glink[i][tmp])||visit[i]){
                if(Glink[tmp][i]||Glink[i][tmp])j++;
                continue;
            }
            
            printf("%d ", i);
            visit[i]=1;
            push(i);
            j++;
        }
    }
   
}

void get_link(){
    int x, y;
    
    scanf("%d %d", &x, &y);
    Glink[x][y]=1;
    Glink[x][0]++;
    Glink[y][0]++;
    
}

void push(int n){
    if(Brear>1000||Brear<0){
        Brear++;
        return;
    }
    Bque[Brear++]=n;
}

int pop(){
    if(Bfront>999||Bfront<-1){
        Bfront++;
        return NULL;
    }
    return Bque[++Bfront];
}

void reset_visit(int n){
    for(int i=1;i<=n;i++)
        visit[i]=0;
}


