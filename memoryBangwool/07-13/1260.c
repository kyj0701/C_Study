#include <stdio.h>
#include <stdlib.h>


typedef struct graph *g_ptr;
struct graph{
    int data;
    g_ptr link;
};

g_ptr g_link[1001];
int visit[1001];
int BFSQ[1000]={0};
int Qrear=0;
int Qfront=-1;
void make_node();
void DFS(int start);
void BFS(int start);
void print_node();
void reset_visit(int num);
void push(int n);
int pop();


int main(){
    int n, m, start;
    scanf("%d %d %d", &n, &m, &start);
    for(int i=1;i<=n;i++){
        g_link[i]=(g_ptr)malloc(sizeof(struct graph));
        g_link[i]->data=i;
        g_link[i]->link=NULL;
    }
    
    for(int i=0;i<m;i++)
        make_node();
    reset_visit(n);
    DFS(start);
    printf("\n");
    reset_visit(n);
    BFS(start);
    
}


void make_node(){
    int data[2];
    /*g_ptr tmp1, tmp2, nod1,nod2;
    g_ptr head1, head2;*/
    g_ptr tmp, head, node;
    int data_, num;
    
    scanf("%d %d", &data[0], &data[1]);
    
    for(int i=0;i<2;i++){
        for(head=g_link[data[i]];head->link;head=head->link)
            if(head->link->data>data[(i+1)%2])
                break;
        node=(g_ptr)malloc(sizeof(struct graph));
        node->data=data[(i+1)%2];
        tmp=head->link;
        head->link=node;
        node->link=tmp;
        }
}


void DFS(int start){
    g_ptr tmp;
    int next;
    
    visit[start]=1;
    printf("%d ",start);
    for(tmp=g_link[start]->link;tmp;tmp=tmp->link){
        next=tmp->data;
        if(visit[next])
            continue;
        DFS(next);
    }
}


void BFS(int start){
    g_ptr tmp;
    
    printf("%d ", start);
    visit[start]=1;
    push(start);
    
    for(tmp=g_link[pop()];Qrear>Qfront;tmp=tmp->link){
        if(!tmp){
            int j=pop();
            if(j==0||!(tmp=g_link[j]->link)){
                if(Qrear<=Qfront)
                    break;
                continue;
            }
        }
        if(visit[tmp->data])
            continue;
        
        printf("%d ", tmp->data);
        push(tmp->data);
        visit[tmp->data]=1;
    }
    
}

void reset_visit(int num){
    for(int i=1;i<=num;i++)
        visit[i]=0;
}

void push(int n){
    if(Qrear>999){
        Qrear++;
        return;
    }
    BFSQ[Qrear++]=n;
}

int pop(){
    if(Qfront<-1||Qfront>999||Qfront>=Qrear-1){
        Qfront++;
        return 0;
    }
    return BFSQ[++Qfront];
}
