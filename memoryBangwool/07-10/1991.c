#include<stdio.h>
#include <stdlib.h>

typedef struct tree *link_ptr;
struct tree{
    int data;
    link_ptr llink;
    link_ptr rlink;
};
link_ptr tree_top;

void make_tree(int n);
link_ptr find_node(int data,link_ptr tree);
int check_node(int data, link_ptr tree);

link_ptr new_node(int data, link_ptr llink, link_ptr rlink);

void In_order(link_ptr tree);
void Pre_order(link_ptr tree);
void Post_order(link_ptr tree);


int main(){
    int n;
    scanf("%d", &n);
    
    tree_top=(link_ptr)malloc(sizeof(struct tree));
    tree_top->data='A';
    tree_top->llink=NULL;
    tree_top->rlink=NULL;

    
    make_tree(n);
    Pre_order(tree_top);
    printf("\n");
    In_order(tree_top);
    printf("\n");
    Post_order(tree_top);
    printf("\n");
    
    
}

void make_tree(int n){
    int mother, child1, child2, trash;
    link_ptr moth_node=NULL;
    link_ptr tmp;
    
    for(int i=0;i<n;i++){
        scanf("\n%c %c %c",&mother, &child1, &child2);
        //if(child1!='.'&&child2=='.')continue;
        moth_node=find_node(mother, tree_top);
        
            
        if(child1!='.'){
            tmp=(link_ptr)malloc(sizeof(struct tree));
           // printf("%d", (*moth_node)->data);
            tmp->llink=NULL;
            tmp->rlink=NULL;
            tmp->data=child1;
            (moth_node)->llink=tmp;
        }
        if(child2!='.'){
            tmp=(link_ptr)malloc(sizeof(struct tree));
            tmp->data=child2;
            tmp->llink=NULL;
            tmp->rlink=NULL;
        (moth_node)->rlink=tmp;
        }
        
    }
}

link_ptr find_node(int data, link_ptr tree){
    link_ptr tmp;
    
    if(!tree)return NULL;
    
    if(check_node(data, tree))
        return tree;
    
    if(tmp=find_node(data, tree->llink)) return tmp;
    if(tmp=find_node(data, tree->rlink)) return tmp;
    
    return NULL;
}


int check_node(int data, link_ptr tree){
    if(tree->data==data)
        return 1;
    return 0;
}


link_ptr new_node(int data, link_ptr llink, link_ptr rlink){
    link_ptr tmp;
    tmp=(link_ptr)malloc(sizeof(struct tree));
    tmp->data=data;
    tmp->llink=llink;
    tmp->rlink=rlink;
    
    
}


void In_order(link_ptr tree){
    if(!tree)return;
    In_order(tree->llink);
    printf("%c", tree->data);
    In_order(tree->rlink);
    
}
void Pre_order(link_ptr tree){
    if(!tree)return;
    printf("%c", tree->data);
    Pre_order(tree->llink);
    Pre_order(tree->rlink);
    
}
void Post_order(link_ptr tree){
    if(!tree)return;
    Post_order(tree->llink);
    Post_order(tree->rlink);
    printf("%c", tree->data);
    
}
