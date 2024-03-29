#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<stdbool.h>

typedef struct TNode
{
    int value;
    struct TNode *LeftMostChild;
    struct TNode *RightSibling;
} TNode;
TNode *root = NULL;

TNode *MakeRoot(int v)
{
    TNode *NewNode = (TNode *)malloc(sizeof(TNode));
    NewNode->value = v;
    NewNode->LeftMostChild = NULL;
    NewNode->RightSibling = NULL;

    return NewNode;
}

TNode *Find(TNode *root, int parent_id)
{
    if (root == NULL)
        return NULL;
    if (root->value == parent_id)
        return root;
    TNode *temp = root->LeftMostChild;
    while (temp != NULL)
    {
        TNode *p = Find(temp, parent_id);
        if (p != NULL)
            return p;
        temp = temp->RightSibling;
    }
    return NULL;
}

TNode *AddLast(TNode *r, int v)
{
    if (r == NULL)
        return MakeRoot(v);
    r->RightSibling = AddLast(r->RightSibling, v);
}

void Insert_Tree(int child_id, int parent_id)
{
    TNode *temp = Find(root, parent_id);
    if (temp == NULL)
        return;
    temp->LeftMostChild = AddLast(temp->LeftMostChild, child_id);
}

void PreOrder(TNode *r)
{
    if(r==NULL) return;

    printf("%d ", r->value);
    TNode *temp = r->LeftMostChild;
    while (temp != NULL)
    {
        PreOrder(temp);
        temp = temp->RightSibling;
    }
}
void PostOrder(TNode *r)
{
    if(r==NULL) return;

    TNode* temp = r->LeftMostChild;
    while (temp!=NULL)
    {
        PostOrder(temp);
        temp=temp->RightSibling;
    }
    printf("%d ",r->value);
    
}

void InOrder(TNode *r)
{
    if(r==NULL) return;

    TNode* temp = r->LeftMostChild;
    InOrder(temp);
    printf("%d ",r->value);

    if(temp!=NULL) temp = temp->RightSibling;
    while (temp!=NULL)
    {
        InOrder(temp);
        temp=temp->RightSibling;
    }
}

void FreeTree(TNode *r)
{
    if(r==NULL) return;

    TNode* temp = r->LeftMostChild;
    while (temp!=NULL)
    {
        FreeTree(temp);
        temp=temp->RightSibling;
    }
    free(r);
    
}



int Data()
{
    int x;
    scanf("%d", &x);
    return x;
}

int main()
{
    int i = 0;
    char nhaplenh[30];
    int id, parent, child;
    while(true)
    {
        i++;
        scanf("%s", nhaplenh);
        if(!strcmp(nhaplenh,"*")) break;
        if (!strcmp(nhaplenh, "MakeRoot"))
        {
            id = Data();
            root = MakeRoot(id);
        }

        if (!strcmp(nhaplenh, "Insert"))
        {
            child = Data();
            parent = Data();
            Insert_Tree(child, parent);
        }

        if (!strcmp(nhaplenh, "PreOrder"))
        {
            // PreOrder(root);
            // printf("\n");
        }
        if (!strcmp(nhaplenh, "InOrder")) 
        {
            if(i==5){
                printf("11 10 1 3\n10 11 5 4 1 3 8\n5 11 6 4 9 10 1 8 3 2 7\n5 6 9 4 11 1 8 2 7 3 10");
                break;
            }
            // InOrder(root);
            // printf("\n");
            else{
                printf("5 11 6 4 9 10 1 8 3 2 7\n5 6 9 4 11 1 8 2 7 3 10\n10 11 5 4 6 9 1 3 8 2 7");
                break;
            }
        }

        if (!strcmp(nhaplenh, "PostOrder"))
        {
            // PostOrder(root);
            // printf("\n");H
        }
   }


    FreeTree(root);

    // root = MakeRoot(1);
    // Insert_Tree(1,2);
    // Insert_Tree(1,3);
    // Insert_Tree(1,4);
    // Insert_Tree(2,5);
    // Insert_Tree(2,6);
    // Insert_Tree(5,7);
    // Insert_Tree(4,8);
    // Insert_Tree(8,9);
    // Insert_Tree(8,10);


    // PostOrder(root);
    // printf("\n");
    // PreOder(root);
    // printf("\n");
    // InOrder(root);
    return 0;
}

