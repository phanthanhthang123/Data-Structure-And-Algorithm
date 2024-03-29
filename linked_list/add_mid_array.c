#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LEN 100
const int ll = 10000;

typedef struct Node{
    int value;
    struct Node* next;
}node;

int data(){
    int tmp;
    scanf("%d",&tmp);
    return tmp;
}

void printlist(node* head){
    while(head!=NULL){
        printf("%d ",head->value);
        head=head->next;
    }
    printf("\n");
}

int size(node* head){
    int cnt = 0;
    while(head!=NULL){
        cnt++;
        head=head->next;
    }
    return cnt;
}

node* MakeNode(int v){
    node* NewNode = (node*) malloc(sizeof(node));
    NewNode->value = v;
    NewNode->next = NULL;
    return NewNode;
}

node* Pushfront(node* head){
    node* p = head;
    p = MakeNode(data());
    p->next = head;
    head = p;
    return p;
}
node* PushBack(node* head){
    node* p = head;
    if(head==NULL){
        return MakeNode(data());
    }

    while(p->next !=NULL){
        p = p -> next;
    }

    node* NewNode = MakeNode(data());
    p->next = NewNode;

    return head;
}
node* insertNode(node* head, int k){ // k : vi tri muon chen phan tu
    int n = size(head);
    if(k<1 || k > n+1) return head;
    if(k==1) return Pushfront(head);

    node* tmp = head;
    for(int i=1;i<=k-2;i++){
        tmp=tmp->next;
    }
    node* NewNode = MakeNode(data());
    NewNode->next = tmp->next;
    tmp->next = NewNode;
    return head;
}
//Ham xoa node o dau danh sach
node* PopFront(node* head){
    node* tmp = head;
    head = head->next;
    tmp->next =NULL;
    free(tmp);
    return head;
}
//Ham xoa nodde o cuoi danh sach
node* PopBack(node* head){
    node* tmp = head;
    // int n = size(head);
    // for(int i=1;i<= n-2;i++){
    //     tmp = tmp->next;
    // }
    if(tmp->next == NULL){
        head = NULL;
        free(tmp);
        return head;
    }
    while(tmp->next->next!=NULL){
        tmp= tmp->next;
    }
    node* p = tmp;
    p = p->next;
    tmp->next = NULL;
    free(p);

    return head;
}

//Ham xoa 1 node co value la v;
node* RemoveNode(node* head, int v){
    node* tmp = head;
    if(tmp == NULL) return head;
    //TH phan tu dau co value = v
    if(tmp->value==v) return PopFront(head);
    //TH thong thuong
    while(tmp->next!=NULL){
        if(tmp->next->value==v) break;
        tmp=tmp->next;
    }
    if(tmp->next !=NULL){
        node* q = tmp->next;
        tmp->next = q->next;
        free(q);
    }
    return head;
}

node* RemoveAllInv(node* head,int v){
    if(head==NULL) return head;

    if(head->value==v){
        node* tmp = head;
        head = head->next;
        free(tmp);
        head = RemoveAllInv(head,v);
        return head;
    }

    head->next = RemoveAllInv(head->next,v);

    return head;
}
//Them 1 node o vi tri bat tri
node* AddNode(node* head,int k){ // them 1 node o vi tri thu k
    if(k<1 || k> size(head)){
        return head;
    }
    if(k==1){
        return Pushfront(head);
    }
    node* tmp=head;
    for(int i=1;i<=k-2;i++){
        tmp=tmp->next;
    }
    node* newnode = MakeNode(data());
    newnode->next = tmp->next;
    tmp->next = newnode;

    return head;
}
int main(){
    node* head = NULL;
    // while(1){
    //     printf("__________________MENU__________________\n");
    //     printf("1.Them phan tu vao dau\n");
    //     printf("2.Them phan tu vao cuoi\n");
    //     printf("3.Them phan tu vao giua vi tri ban muon\n");
    //     printf("4.Xem danh sach cac phan tu\n");
    //     printf("0.Thoat\n");
    //     rest :
    //     int luachon;
    //     printf("Ban chon: ");
    //     scanf("%d",&luachon);
    //     if (luachon ==1 ){
    //         head = Pushfront(head);
    //     }
    //     else if(luachon==2){
    //         head = PushBack(head);
    //     }
    //     else if(luachon==3){
    //         int k;
    //         printf("vi tri ban can them phan tu la : ");
    //         scanf("%d",&k);
    //         head = insertNode(head,k);
    //     }
    //     else if(luachon==4){
    //         printlist(head);
    //     }
    //     else if(luachon ==0 ) return 0;
    //     else{
    //         printf("Lua chon khong hop le\n");
    //         printf("Vui long nhap lai: "); goto rest;
    //     }
    // }
    for(int i=0;i<5;i++){
        head = PushBack(head);
    }
    // head = PopFront(head);
    // head = PopBack(head);
    // printf("Can Xoa Phan tu : ");
    // head = RemoveNode(head,data());
    // printf("Chon phan tu ma ban muon xoa ra khoi DSLK: ");
    // head = RemoveAllInv(head,data());
    

    printf("ban muon them 1 node vao node thu : ");
    head = AddNode(head,data());
    printlist(head);
    printf("%d",size(head));

    while(head!=NULL){
        node* tmp = head;
        head=head->next;
        free(tmp);
    }


    return 0;
}