#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct BNode{
    int value;
    struct BNode* leftchild;
    struct BNode* rightchild;
}BNode;

BNode* root = NULL;

BNode* MakeNode(int id){
    BNode* NewNode = (BNode*)malloc(sizeof(BNode));
    if(NewNode==NULL){
        printf("Error Memory\n");
        exit(1);
    }
    NewNode->value = id;
    NewNode->leftchild=NULL;
    NewNode->rightchild = NULL;

    return NewNode;
}

BNode* Find(BNode* root,int id){
    if(root==NULL) return NULL;
    if(root->value==id) return root;

    BNode* temp = Find(root->leftchild,id);
    if(temp!=NULL) return temp;

    BNode* temp1 = Find(root->rightchild,id);
    if(temp1!=NULL) return temp1;

    return NULL;
}

void AddLeft(int child,int parent){
    BNode* temp = Find(root,parent);
    BNode* temp1 = Find(root,child);
    if(temp==NULL) return;
    if(temp !=NULL && temp1 ==NULL && temp->leftchild ==NULL){
        temp->leftchild = MakeNode(child);
    }
}

void AddRight(int child,int parent){
    BNode* temp = Find(root,parent);
    BNode* temp1 = Find(root,child);
    if(temp==NULL) return;
    if(temp !=NULL && temp1 == NULL && temp->rightchild ==NULL){
        temp->rightchild = MakeNode(child);
    }
}

void PreOrder(BNode* root){
    if(root==NULL) return;
    printf("%d ",root->value);
    PreOrder(root->leftchild);
    PreOrder(root->rightchild);
}

void InOrder(BNode* root){
    if(root==NULL) return;
    InOrder(root->leftchild);
    printf("%d ",root->value);
    InOrder(root->rightchild);
}

void PostOrder(BNode* root){
    if(root==NULL) return;
    PostOrder(root->leftchild);
    PostOrder(root->rightchild);
    printf("%d ",root->value);
}

int Data(){
    int x;
    scanf("%d",&x);
    return x;
}
int main(){
    char caulenh[30];
    int id;
    int u,v;
    while(1){
        scanf("%s",caulenh);
        if(!strcmp(caulenh,"MakeRoot")){
            id = Data();
            root = MakeNode(id);
        }
        if(!strcmp(caulenh,"AddLeft")){
            u = Data();
            v= Data();
            AddLeft(u,v);
        }
        if(!strcmp(caulenh,"AddRight")){
            u = Data();
            v= Data();
            AddRight(u,v);
        }
        if(!strcmp(caulenh,"PreOrder")){
            PreOrder(root);
            printf("\n");
        }
        if(!strcmp(caulenh,"InOrder")){
            InOrder(root);
            printf("\n");
        }
        if(!strcmp(caulenh,"PostOrder")){
            PostOrder(root);
            printf("\n");
        }
        if(!strcmp(caulenh,"*")) break;
    }
}