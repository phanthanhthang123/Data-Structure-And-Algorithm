#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int arr[100];

typedef struct Node{
    int value;
    struct Node* next;
}Node;

Node* MakeNode(int v){
    Node* NewNode  = (Node*)malloc(sizeof(Node));
    NewNode->value = v;
    NewNode->next=NULL;
    return NewNode;
}



Node* PushStack(Node* head,int v){
    Node* temp = head;
    if(temp==NULL) return MakeNode(v);
    Node* NewNode = MakeNode(v);
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = NewNode;
    return head;

}
Node* PopStack(Node* head){
    if (head == NULL || head->next == NULL) return NULL;
    if(head->next->next ==NULL){
        free(head->next);
        head->next = NULL;
        return head;
    }
    Node* temp = head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}


void PrintArr(int* a,int n){
    for(int i=1;i<=n;i++){
        printf("%d",a[i]);
    }
    printf(" ");
}

void FreeList(Node* head){
    while (head!=NULL)
    {
        Node* tmp = head;
        head=head->next;
        free(tmp);
    }
    
}
int Check(Node* head,int arr[],int n){
    for(int i = 1;i<=n; i++){
        if(arr[i]==1) head = PushStack(head,1);
        else if(arr[i]==2 && head !=NULL) head = PopStack(head);
        else if(arr[i]==2 && head ==NULL) return 0;
    }

    if(head == NULL) return 1;
    else{
        FreeList(head);
        head = NULL;
        return 0;
    }
}
Node* head = NULL;

void TrySinh(int arr[],int k,int n){
    if (k == n + 1 ) {
        // PrintArr(arr, n);
        if(Check(head,arr,n)==1) PrintArr(arr,n);
        return;
    }
    if (arr[k] == 0) {
        for (int i = 1; i <= 2; i++) {
            arr[k] = i;
            if (k == n ) {
                // PrintArr(arr, n);
                if(Check(head,arr,n)==1) PrintArr(arr,n);
            } else {
                TrySinh(arr, k + 1, n);
            }
        }
        arr[k] = 0; // Đặt lại arr[k] = 0 không cần thiết ở đây
    } else {
        TrySinh(arr, k + 1, n);
    }
}

void PrintList(Node* head){
    Node* tmp = head;
    while(tmp!=NULL){
        printf("%d ",tmp->value);
        tmp=tmp->next;
    }
    printf("\n");
}

int Data(){
    int x;
    scanf("%d",&x);
    return x;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        scanf("%d",&arr[i]);
    }

    TrySinh(arr,1,n);


    // int n;
    // scanf("%d",&n);
    // while (n--)
    // {
    //     int x = Data();
    //     head= PushStack(head,x);
    // }
    // head = PopStack(head);

    // PrintList(head);
    
    return 0;

}