#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

typedef struct Node{
    int value;
    struct Node* next;
}Node;

Node* head = NULL;
char str[30];
int u,v,k;

Node* MakeNode(int value){
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->value = value;
    NewNode->next =NULL;
    return NewNode;
}

Node* AddLast(int v){
    Node* tmp = head;
    if(tmp==NULL) return MakeNode(v);
    while(tmp->next!=NULL){
        if(tmp->value==v) return head;
        tmp=tmp->next;
    }
    if(tmp->value !=v){
        Node* NewNode = MakeNode(v);
        tmp->next=NewNode;
    }
    return head;
}
Node* AddFirst(int v){
    Node* tmp = head;
    if(head==NULL) return MakeNode(v);
    while(tmp!=NULL){
        if(tmp->value==v) return head;
        tmp=tmp->next;
    }
    //Neu k co phan tu nao trung =>> tmp = NULL
    Node* NewNode = MakeNode(v);
    NewNode->next = head;
    return NewNode;
}

void AddAfter(int u,int v){ // thêm ptu u vào sau ptu v(nếu v đã tồn tại trên danh sách và u chưa tồn tại)
    //Ktra u da nam trong danh sach hay chua
    Node* p = head;
    while(p!=NULL){
        if(p->value==u) return;
        p=p->next;
    }

    Node* tmp = head;
    while(tmp!=NULL){
        if(tmp->value==v) break;
        tmp=tmp->next;
    }
    if(tmp==NULL) return;
    if(tmp->next==NULL){
        Node* NewNode = MakeNode(u);
        tmp->next = NewNode;
        return;
    }
    Node* NewNode = MakeNode(u);
    NewNode->next = tmp->next;
    tmp->next=NewNode;
}

void AddBefore(int u,int v){//them ptu u vao truoc ptu v ( neu v ton tai va u chua ton tai)
    Node* p = head;
    while (p!=NULL){
        if(p->value==u) return;
        p=p->next;
    }

    Node* tmp = head;
    if(tmp->value==v){
        head = AddFirst(u);
        return;
    }

    while(tmp!=NULL){
        if(tmp->next->value==v) break;
        tmp=tmp->next;
    }
    if(tmp==NULL) return;

    Node* NewNode = MakeNode(u);
    NewNode->next = tmp->next;
    tmp->next=NewNode;
}
void ReMove(int k){
    Node* tmp = head;
    if(tmp==NULL) return;
    if(tmp->value==k){
        head=head->next;
        free(tmp);
        return;
    }
    Node* p = head;
    while(p!=NULL){
        if(p->value==k) break;
        p=p->next;
    }
    if(p==NULL) return;

    while(tmp->next!=NULL){
        if(tmp->next->value==k) break;
        tmp=tmp->next;
    }
    Node* x = tmp->next;
    tmp->next = tmp->next->next;
    free(x);
}

Node* Reverse(){
    if(head==NULL || head->next==NULL) return head;
    Node* p1 = NULL;
    Node* p2 = head;
    Node* p3 = head->next;
    while(p2!=NULL){
        p2->next = p1;
        p1=p2;
        p2=p3;
        if(p3!=NULL) p3 = p3->next;
    }
    return p1;
}
void Print_List(Node* head){
    Node* tmp = head;
    while(tmp!=NULL){
        printf("%d ",tmp->value);
        tmp=tmp->next;
    }
    printf("\n");
}

int data(){
    int x;
    scanf("%d",&x);
    return x;
}
void free_list(){
    while(head!=NULL){
        Node* tmp = head;
        head=head->next;
        free(tmp);
    }
}

void EraseEnter(char* c){
    for(int i=0;i<strlen(c);i++){
        if(c[i]==' ')c[i]='\0';
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        head = AddLast(data());
    }
    fflush(stdin);
    while(true){
        scanf("%s",&str);

        if(!strcmp(str,"#")){
            break;
        }

        if(!strcmp(str,"addlast")){
            scanf(" %d",&k);
            head = AddLast(k);
        }
        if(!strcmp(str,"addfirst")){
            scanf(" %d",&k);
            head=AddFirst(k);
        }
        if(!strcmp(str,"addafter")){
            scanf(" %d %d",&u,&v);
            AddAfter(u,v);
        }
        if(!strcmp(str,"addbefore")){
            scanf(" %d %d",&u,&v);
            AddBefore(u,v);
        }
        if(!strcmp(str,"remove")){
            scanf(" %d",&k);
            ReMove(k);
        }
        if(!strcmp(str,"reverse")){
            head = Reverse();
        }
    }

    Print_List(head);
    free_list();



    return 0;
}