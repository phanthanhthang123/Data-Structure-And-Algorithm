#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Sinhvien{
    char name[30];
    int age;
    double gpa;
};

typedef struct Node{
    struct Sinhvien sinhvien;
    struct Node* next;
}node;

void printlist(node* head,int i){
    while(head!=NULL){
        printf("Thong tin cua sinh vien thu %d la : \n",i);
        printf("name: %s\nTuoi: %d\ndiem: %.2lf\n",head->sinhvien.name,head->sinhvien.age,head->sinhvien.gpa);
        head=head->next;
        i++;
    }
}

int size(node* head){
    int cnt = 0;
    node* p = head;
    while(p!=NULL){
        p = p->next;
        cnt++;
    }
    return cnt;
}

node* CapPhatdong(){
    node* newNode = (node*)malloc(sizeof(node));
    return newNode;
}

void loaibospace(char* c){
    for(int i=0;i<strlen(c);i++){
        if(c[i]=='\n') c[i] = '\0';
    }
}

//Ham tao node moi
node* MakeNode(int i){
    node* NewNode = CapPhatdong();
    printf("NHAP THONG TIN CHO SINH VIEN THU %d : \n",i);
    printf("Nhap ten : ");
    fflush(stdin);
    fgets(NewNode->sinhvien.name,30*sizeof(char),stdin); fflush(stdin);
    loaibospace(NewNode->sinhvien.name);
    printf("Nhap tuoi: ");
    scanf("%d",&NewNode->sinhvien.age); fflush(stdin);
    printf("Nhap diem : ");
    scanf("%lf",&NewNode->sinhvien.gpa);
    NewNode->next = NULL;
    return NewNode;
}

//Ham them phan tu o cuoi danh sach
node* pushBack(node* head,int i){
    node* p=head;
    if(p==NULL) return MakeNode(i);
    while(p!=NULL){
        p=p->next;
    }
    node* NewNode = MakeNode(i);
    p->next = NewNode;
    return head;
}
//Ham them phan tu o dau danh sach
node* pushFront(node* head , int i){
    node* newNode = MakeNode(i);
    newNode->next = head;
    head = newNode;
    return newNode;
}

int main(){
    node* head = NULL;
    int n;
    printf("can bao nhieu sinh vien: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        head = pushBack(head,i+1);
        // head = pushFront(head,i+1);
    }
    printlist(head,1);
    printf("n= size = %d",size(head));

     // Giải phóng bộ nhớ
    while (head != NULL) {
        node* tmp = head;
        head = head->next;
        free(tmp);
    }

    return 0;
}