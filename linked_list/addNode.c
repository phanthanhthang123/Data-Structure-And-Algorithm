#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

typedef struct point{
    Node* first;
}TList;

bool isEmpty(TList* list){
    return list->first;  
}

TList* createList(){
    TList* list = (TList*)malloc(sizeof(TList));
    list->first = NULL;
    return list;
}
Node* allocateNode(){
    Node* pNode = (Node*)malloc(sizeof(Node));
    return pNode;
}
Node* creatNode(int value){
    Node* pNode = allocateNode();
    pNode ->data = value;
    pNode ->next = NULL;
    return pNode;
}
int input(){
    int tmp;
    scanf("%d",&tmp);
    return tmp;
}
// them node dau tien
void addFirstNode(TList* list, Node* pNode){
    pNode->next = NULL;
    list->first = pNode;
}
void addNodeAtFront(TList* list, Node* pNode){
    if(isEmpty(list)){
        addFirstNode(list,pNode);
    }
    else{
        pNode->next = list->first;
        list->first = pNode;
    }
}
//IN toan bo danh sach 

void print(TList* list){
    for(Node* i = list->first; i!= NULL; i = i->next){
        printf("%d ",i->data);
    }
}

int main(){
    TList* list = createList();
    for(int i=0;i<3;i++){
        addNodeAtFront(list,creatNode(input()));
    }
    print(list);

    return 0;
}