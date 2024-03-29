#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node{
    int value;
    struct Node* next;
}node;

node* head = NULL;

node* MakeNode(int v){
    node* NewNode = (node*)malloc(sizeof(node));
    NewNode->value = v;
    NewNode->next = NULL;
    return NewNode;
}

node* PushFront(node* head,int v){
    if(head==NULL) return MakeNode(v);
    node* NewNode = MakeNode(v);
    NewNode->next = head;
    return NewNode;
}

int PopStack(node** head){
    node* tmp = *head;
    if(tmp==NULL) return -1;
    int v = (*head)->value;
    *head=(*head)->next;
    free(tmp);
    return v;
}

void ReverseArr(char* c,int l,int r){
    if(l>r) return;
    char tmp = c[l];
    c[l]=c[r];
    c[r]=tmp;
    ReverseArr(c,l+1,r-1);
}
void EraseEnter(char* c){
    for(int i=0;i<strlen(c);i++){
        if(c[i]=='\n') c[i]='\0'; 
    }
}
void printarr(char* c){
    for(int i=0;i<strlen(c);i++){
        printf("%c",c[i]);
    }
    printf("\n");
}

int main(){
//    char a[30],b[30];
//    // fgets(a,sizeof(a),stdin);
//    // fgets(b,sizeof(b),stdin);
//    // EraseEnter(a);
//    // EraseEnter(b);
//
//    scanf("%s %s",&a,&b);
//    ReverseArr(a,0,strlen(a)-1);
//    ReverseArr(b,0,strlen(b)-1);
//    int du =0;
//    int len_min = (strlen(a) > strlen(b)) ? strlen(b) : strlen(a);
//    int len_max = (strlen(a)> strlen(b))? strlen(a) : strlen(b);
//
//    for(int i = 0;i<len_min;i++){
//        if(a[i]-'0'+b[i]-'0'+ du > 10){
//            head=PushFront(head,(a[i]-'0'+b[i]-'0'+ du) % 10 );
//            du = 1;   
//        }
//        else{
//            head=PushFront(head,(a[i]-'0'+b[i]-'0'+ du));
//            du =0;
//        }
//    }
//
//    if(strlen(a)==len_max){
//        for(int i = len_min;i<len_max;i++){
//            if(a[i]-'0' + du > 10){
//                head=PushFront(head,(a[i]-'0'+ du ) % 10 );
//                du = 1;
//            }
//            else{
//                head=PushFront(head,(a[i]-'0'+ du));
//                du =0;
//            }
//        }
//    }
//    else{
//        for(int i = len_min;i<len_max;i++){
//            if(b[i]-'0' + du > 10){
//                head=PushFront(head,(b[i]-'0'+ du ) % 10 );
//                du = 1;
//            }
//            else{
//                head=PushFront(head,(b[i]-'0'+ du));
//                du =0;
//            }
//        }
//
//    }
//
//    if(du==1){
//        head=PushFront(head,1);
//    }
//
//    // printarr(a);
//    // printarr(b);
//    while(head!=NULL){
//        printf("%d",PopStack(&head));
//    }

	printf("%5.2f",426,1576);

    return 0;
}
