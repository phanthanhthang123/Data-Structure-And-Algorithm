#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef int data;

typedef struct _TNode{
    data coeff;
    data pow;
    struct _TNode* next;
}Node;

Node* head1 = NULL; // f(x)
Node* head2 = NULL; // g(x)
Node* head3 =NULL; // f(x) + g(x);

Node* MakeNode(data coeff, data pow){
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->coeff=coeff;
    NewNode->pow = pow;
    NewNode->next = NULL;

    return NewNode;
};

Node* Push_Back(Node* head,data coeff,data pow){
    Node* tmp = head;
    if(tmp == NULL) return MakeNode(coeff,pow);

    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    Node* NewNode = MakeNode(coeff,pow);
    tmp->next = NewNode;

    return head;
}

data Data(){
    int x;
    scanf("%d",&x);
    return x;
}

void PrintList(Node* head){
    Node* tmp =head;
    while(tmp!=NULL){
        printf("%d ",tmp->coeff);
        tmp=tmp->next;
    }
    printf("\n");
}

void DeleteList(Node* head){
    while(head!=NULL){
        Node* tmp =head;
        head=head->next;
        free(tmp);
    }
}

data Cnt(Node* head){
    int cnt =0;
    Node* tmp = head;
    while(tmp!=NULL){
        if(tmp->coeff != 0) cnt++;
        tmp=tmp->next;
    }

    return cnt;
}

void RemoveEnter(char* c){
    for(int i=0;i<strlen(c);i++){
        if(c[i]==' ') c[i]='\0';
    }
}


void Plus(){
    Node* head1_run = head1;
    Node* head2_run = head2;

    while(head1_run!=NULL && head2_run!=NULL){
        if((head1_run->pow < head2_run->pow)){
            head3 = Push_Back(head3,head1_run->coeff,head1_run->pow);
            head1_run = head1_run->next;
        }
        else if((head1_run->pow > head2_run->pow) ){
            head3 = Push_Back(head3,head2_run->coeff,head2_run->pow);
            head2_run = head2_run->next;
        }
        else{
            data x = head1_run->coeff + head2_run->coeff;
            head3 = Push_Back(head3,x,head1_run->pow);
            head1_run=head1_run->next;
            head2_run=head2_run->next;
        }
    }

    while(head1_run!=NULL){
        head3 = Push_Back(head3,head1_run->coeff,head1_run->pow);
        head1_run=head1_run->next;
    }
    while(head2_run!=NULL){
        head3 = Push_Back(head3,head2_run->coeff,head2_run->pow);
        head2_run=head2_run->next;
    }
    
    if(head3==NULL) head3 = Push_Back(head3,0,0);
}

void DaoDau(){
    Node* tmp = head2;
    while (tmp!=NULL)
    {
        tmp->coeff = - tmp->coeff;
        tmp=tmp->next;
    }
    
}
void Minus(){
    DaoDau();
    Plus();
}

int main(){
    data n,m;
    data i =0,j=0;
    scanf("%d",&n);
    while(n--){
        head1 = Push_Back(head1,Data(),i++);
    }
    scanf("%d",&m);
    while(m--){
        head2 = Push_Back(head2,Data(),j++);
    }

    char arr[30];
    scanf("%s",arr);
    RemoveEnter(arr);

    if(!strcmp(arr,"plus")){
        Plus();
    }
    if(!strcmp(arr,"minus")){
        Minus();
    }

    if(Cnt(head3)==0){
        printf("%d %d",1,0);
    }else{
        printf("%d ",Cnt(head3));
        PrintList(head3);
    }


    DeleteList(head1);
    DeleteList(head2);
    DeleteList(head3);
    return 0;
}