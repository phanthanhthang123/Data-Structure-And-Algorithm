#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const char c = 18;

typedef struct Node{
    char id;
    struct Node* LeftMostChild;
    struct Node* RightSibling;
}Node;

Node* root = NULL;

Node* MakeNode(char c){
    Node* NewNode = (Node*)malloc(sizeof(Node));
    if(NewNode==NULL){
        printf("error memory\n");
        exit(1);
    }
    NewNode->id = c;
    NewNode->LeftMostChild = NULL;
    NewNode->RightSibling = NULL;

    return NewNode;
}

Node* Find(Node* root,char id){
    if(root==NULL) return NULL;
    if(root ->id == id) return root;

    Node* tmp = root->LeftMostChild;
    while(tmp!=NULL){
        Node* newnode = Find(tmp,id);
        if(newnode!=NULL) return newnode;
        tmp = tmp->RightSibling;
    }

    return NULL;

}

Node* AddLast(Node* left,char id){ // con tro left o trong phan tu cha (con tro left cua phan tu cha)
    if(left==NULL) return MakeNode(id);
    Node* NewNode = MakeNode(id);
    left->RightSibling = AddLast(left->RightSibling,id);
}

void AddChild(char parent_id,char child_id){
    Node* tmp = Find(root,parent_id);
    if(tmp==NULL) return;
    tmp->LeftMostChild = AddLast(tmp->LeftMostChild,child_id);
}

void PreOder(Node* root){ //duyet cay theo thu tu truoc N_LR
    if(root==NULL) return;
    printf("%c ",root->id);
    Node* tmp = root->LeftMostChild;

    while(tmp!=NULL){
        PreOder(tmp);
        tmp=tmp->RightSibling;
    }
    
}

void PostOrder(Node* root){ //Duyet cay theo thu tu sau LR_N
    if(root==NULL) return;
    
    Node* tmp = root->LeftMostChild;
    while(tmp!=NULL){
        PostOrder(tmp);
        tmp=tmp->RightSibling;
    }
    printf("%c ",root->id);

}

void InOrder(Node* root){ //Duyet cay theo thu tu giua L_N_R
    if(root==NULL) return;
    
    Node* tmp = root->LeftMostChild;
    InOrder(tmp);
    printf("%c ",root->id);

    if(tmp!=NULL) tmp = tmp->RightSibling;
    while(tmp!=NULL){
        InOrder(tmp);
        tmp = tmp->RightSibling;
    }

}

int main(){
    root = MakeNode('a');
    AddChild('a','b');
    AddChild('a','c');
    AddChild('a','d');
    AddChild('b','e');
    AddChild('b','f');
    AddChild('c','g');
    AddChild('d','h');
    AddChild('d','k');

    // PreOder(root);
    // printf("\n");
    // PostOrder(root);
    // printf("\n");
    // InOrder(root);

    	printf("%5.2f",426.1576);
        if('a'<'e'){
            printf("hehe");
        }
        int x =8;
        x++;
        printf("%d",++x);

        // float x =9;
    
    return 0;
}