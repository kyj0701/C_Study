#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *left;
    struct Node *right;
}Tree;


Tree* New_Node(char data);
void Make_Tree(Tree* tree, char parent, char left, char right);
void PreOrder(Tree* tree);
void InOrder(Tree* tree);
void PostOrder(Tree* tree);

int main()
{
    int n;
    char parent, left, right;
    Tree *root = New_Node('A');

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {

        scanf(" %c %c %c", &parent, &left, &right);

        Make_Tree(root, parent, left, right);
    }

    PreOrder(root);
    printf("\n");
    InOrder(root);
    printf("\n");
    PostOrder(root);
    printf("\n");

	return 0;
}

Tree* New_Node(char data)
{
    Tree* node = (Tree*)malloc(sizeof(Tree));

    node -> data = data;

    node -> left = NULL;
    node -> right = NULL;

    return node;
}

void Make_Tree(Tree* tree, char parent, char left, char right)
{
    if (!tree) return;
    if (tree -> data == parent)
    {
        if (left != '.') tree -> left = New_Node(left);
        if (right != '.') tree -> right = New_Node(right);
        return;
    }
    else
    {
        Make_Tree(tree -> left, parent, left, right);
        Make_Tree(tree -> right, parent, left, right);
    }
}

void PreOrder(Tree* tree)
{
    if (!tree) return;
    printf("%c", tree -> data);
    PreOrder(tree -> left);
    PreOrder(tree -> right);
}

void InOrder(Tree* tree)
{
    if (!tree) return;
    InOrder(tree -> left);
    printf("%c", tree -> data);
    InOrder(tree -> right);
}

void PostOrder(Tree* tree)
{
    if (!tree) return;
    PostOrder(tree -> left);
    PostOrder(tree -> right);
    printf("%c", tree -> data);
}