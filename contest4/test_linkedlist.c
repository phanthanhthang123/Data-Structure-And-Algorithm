#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node{
    int value;
    struct Node* next;
}Node;

Node* head_1 = NULL;
Node* head_2 = NULL;
Node* head_3 = NULL;

Node* MakeNode(int value){
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->next=NULL;
    NewNode->value=value;
    return NewNode;
}

Node* Push_Back(Node* head,int value){
    Node* tmp = head;
    if(tmp==NULL)return MakeNode(value);
    while(tmp->next !=NULL){
        tmp=tmp->next;
    }
    Node* NewNode = MakeNode(value);
    tmp ->next = NewNode;
    return head;
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
void ISort(){ //trộn hai danh sách này thành danh sách mới với thứ tự các khóa không giảm
    Node* i = head_1;
    Node* j = head_2;
    while(i!=NULL && j!=NULL){
        if(i->value<=j->value){
            head_3 = Push_Back(head_3,i->value);
            i = i->next;
        }
        else{
            head_3 = Push_Back(head_3,j->value);
            j=j->next;
        }
    }
    // if(i==NULL){
    //     while(j!=NULL){
    //         head_3 = Push_Back(head_3,j->value);
    //         j=j->next;
    //     }
    // }
    // else{
    //     while(i!=NULL){
    //         head_3 = Push_Back(head_3,i->value);
    //         j=j->next;
    //     }
    // }
        while(i!=NULL){
        head_3 = Push_Back(head_3,i->value);
        i=i->next;
    }
    while(j!=NULL){
        head_3 = Push_Back(head_3,j->value);
        j=j->next;
    }
}

void DSort(){ //trộn hai danh sách này thành danh sách mới với thứ tự các khóa không tăng
    Node* i = head_1;
    Node* j = head_2;
    while(i!=NULL && j!=NULL){
        if(i->value >= j->value){
            head_3 = Push_Back(head_3,i->value);
            i = i->next;
        }
        else{
            head_3 = Push_Back(head_3,j->value);
            j=j->next;
        }
    }

    // if(i==NULL){
    //     while(j!=NULL){
    //         head_3 = Push_Back(head_3,j->value);
    //         j=j->next;
    //     }
    // }
    // else{
    //     while(i!=NULL){
    //         head_3 = Push_Back(head_3,i->value);
    //         j=j->next;
    //     }
    // }
    
    while(i!=NULL){
        head_3 = Push_Back(head_3,i->value);
        i=i->next;
    }
    while(j!=NULL){
        head_3 = Push_Back(head_3,j->value);
        j=j->next;
    }
}

void RemoveEnter(char* c){
    for(int i=0;i<strlen(c);i++){
        if(c[i]==' ') c[i] = '\0';
    }
}

Node* HoanDay(Node* head){
    Node* tmp = head;
    Node* p1 = NULL;
    Node* p2 = tmp;
    Node* p3 = tmp->next;
    while(p2!=NULL){
        p2->next = p1;
        p1 = p2;
        p2 = p3;
        if(p3!=NULL) p3 = p3->next;
    }
    return p1;
}


void Delete_List(Node* head){
    while(head!=NULL){
        Node* tmp = head;
        head=head->next;
        free(tmp);
    }
}
int main(){
    int n,m;
    scanf("%d",&n);
    while(n--){
        head_1 = Push_Back(head_1,data());
    }
    scanf("%d",&m);
    while(m--){
       head_2 = Push_Back(head_2,data());
    }

    char c[30];
    scanf("%s",&c);
    RemoveEnter(c);
    if(!strcmp(c,"dSort")){
        Node* x = head_1;
        Node* y = head_2;
        while(x!=NULL){
            if(x->next==NULL) break;
            if(x->value < x->next->value){
                head_1= HoanDay(head_1);
                break;
            }
            x=x->next;
        }
        while(y!=NULL){
            if(y->next==NULL) break;
            if(y->value < y->next->value){
                head_2= HoanDay(head_2);
                break;
            }
            y=y->next;
        }
        DSort();
    }
    if(!strcmp(c,"iSort")){
        Node* x = head_1;
        Node* y = head_2;
        while(x!=NULL){
            if(x->next==NULL) break;
            if(x->value > x->next->value){
                head_1 = HoanDay(head_1);
                break;
            }
            x= x->next;
        }
        while(y!=NULL){
            if(y->next==NULL) break;
            if(y->value > y->next->value){
                head_2= HoanDay(head_2);
                break;
            }
            y=y->next;
        }
        ISort();
    }

    Print_List(head_3);

    Delete_List(head_1);
    Delete_List(head_2);
    Delete_List(head_3);
    return 0;
}