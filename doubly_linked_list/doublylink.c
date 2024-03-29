#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_LEN 100

typedef struct Node{
    int value;
    struct Node* previous;
    struct Node* next;
}node;

node* MakeNode(int v){
    node* NewNode = (node*)malloc(sizeof(node));
    NewNode->value = v;
    NewNode->next = NULL;
    NewNode->previous=NULL;

    return NewNode;
}

node* head = NULL;
node* tail = NULL;
//Ham khoi tao danh sach 

void initlist(){
    head = NULL;
    tail = NULL;
}
//Ham kiem tra danh sach rong
int listEmpty() {
    return (head==NULL && tail==NULL);
}

//Ham chen 1 node vao cuoi danh sach
void PushBack(int v){
    node* NewNode = MakeNode(v);

    if(listEmpty()){
        head = NewNode;
        tail = NewNode;
    }
    else{
        NewNode->previous = tail;
        tail->next = NewNode;
        tail = NewNode;
    }
}
int data(){
    int tmp;
    scanf("%d",&tmp);
    return tmp;
}

//Ham hien thi danh sach tu head den tail
void printlistLeft2Right(){
    for(node* x = head;x!=NULL;x=x->next){
        printf("%d ",x->value);
    }
    printf("\n");
}

void printlistRight2Left(){
    for(node* x =tail;x!=NULL;x=x->previous){
        printf("%d ",x->value);
    }
    printf("\n");
}
//Ham giai phong bo nho
void finalize() {
    node* current = head;
    while (current != NULL) {
        node* temp = current;
        current = current->next;
        free(temp);
    }

    head = NULL;
    tail = NULL;
}

int main(){
    char buff[MAX_LEN];
    
    // Đọc dãy số vào bộ đệm
    fgets(buff, MAX_LEN, stdin);

    // Sử dụng strtok() để tách xâu bằng dấu khoảng cách
    char *token = strtok(buff, " ");

    // Tạo list
    while (token != NULL) {
        PushBack(atoi(token)); // Lấy số hiện tại
        token = strtok(NULL, " "); // Lấy số tiếp theo
    }
    printlistLeft2Right();
    printlistRight2Left();
    finalize();

    return 0;
}