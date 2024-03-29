#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef char datatype;

typedef struct _BNode{
    datatype id;
    struct _BNode* LeftChild;
    struct _BNode* RightChild;
}BNode;

BNode* root = NULL;

BNode* MakeRoot(datatype id){
    BNode* NewNode = (BNode*)malloc(sizeof(BNode));
    if(NewNode==NULL){
        printf("Error Memory\n");
        exit(1);
    }
    NewNode->id = id;
    NewNode->LeftChild = NULL;
    NewNode->RightChild =NULL;

    return NewNode;
} 

BNode* Find(BNode* root,datatype parent_id){
    if(root==NULL) return NULL;
    if(root->id==parent_id)  return root;

    BNode* found = Find(root->LeftChild,parent_id);
    if(found!=NULL) return found;

    found = Find(root->RightChild,parent_id);
    return found;
}
 
void AddLeft(datatype parent_id,datatype child_id){
    BNode* temp = Find(root,parent_id);
    if(temp==NULL) return;
    temp->LeftChild = MakeRoot(child_id);
}

void AddRight(datatype parent_id,datatype child_id){
    BNode* temp = Find(root,parent_id);
    if(temp==NULL) return;
    temp->RightChild = MakeRoot(child_id);
}

void PreOrder(BNode* root){
    if(root==NULL) return;
    printf("%c ",root->id);
    PreOrder(root->LeftChild);
    PreOrder(root->RightChild);
}

int main(){

    root = MakeRoot('a');
    AddLeft('a','b');
    AddRight('a','c');
    AddLeft('b','d');
    AddRight('b','e');
    AddLeft('d','f');
    AddLeft('e','g');
    AddRight('e','h');
    AddLeft('c','i'); 
    AddRight('c','k');
    AddLeft('k','l');
    AddRight('k','m');

    PreOrder(root);

    BNode* tmp = Find(root,'e');

    if(tmp==NULL){
        printf("\nNULL");
    }
    return 0;
}
