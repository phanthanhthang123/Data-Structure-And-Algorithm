#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char datatype;

typedef struct Node{
    datatype data;
    struct Node* next;
    struct Node* previous;
}Node;

Node* head = NULL;
Node* tail = NULL;


Node* MakeNode (datatype v){
    Node* NewNode = (Node*)malloc(sizeof(Node*));
    if(NewNode==NULL){
        printf("error memory\n");
        exit(1);
    }
    NewNode->data = v;
    NewNode->next=NULL;
    NewNode->previous=NULL;

    return NewNode;
}

Node* PushBack(Node* head,datatype v){
    Node* temp = head;
    if(temp==NULL) return MakeNode(v);
    Node* NewNode = MakeNode(v);
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = NewNode;

    return head;
}

Node* RemoveBack(Node* head){
    Node* tmp = head;
    if(tmp==NULL) return NULL;
    if(tmp->next == NULL){
        return NULL;
    }

    if(tmp->next!=NULL){
        tmp=tmp->next;
    }

    Node* p = tmp;
    tmp =NULL;
    free(p);
    return head;
}

void FreeList(Node* head){
    while(head!=NULL){
        Node* tmp = head;
        head=head->next;
        free(tmp);
    }

}

int Data(){
    int x;
    scanf("%d",&x);
    return x;
}

void PrintList(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        printf("%c ",temp->data);
        temp=temp->next;
    }

    printf("\n");
}

int EmptyList(Node* head){
    if(head==NULL) return 1;
    return 0;
}

Node* chuyendoiso(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        if(temp->data=='('){
            temp->data = '1';
        }
        if(temp->data==')'){
            temp->data = '2';
        }

        temp = temp->next;
    }
    return head;
}

Node* check(Node* head){
    Node* temp = head;
    if(temp->data=='2')exit(1);
    while(temp!=NULL){
        if(temp->data=='(') temp=temp->next;
        if(temp->data==')'){
            Node* p = temp;
            temp=temp->next;
            free(p);
        }
        if(temp->data=='?'){

        }
    }
}

int main(){

    int n = Data();

    while(n--){
        int x = Data();

        switch (x) {
            case 0 :
                head = PushBack(head,'?');
                break;
            case 1 :
                head = PushBack(head,'(');
                break;
            case 2 :
                head = PushBack(head,')');
                break;

        }
    }





    head= chuyendoiso(head);
    PrintList(head);

    return 0;
}