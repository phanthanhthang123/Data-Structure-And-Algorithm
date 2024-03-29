#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct SinhVien{
    char name[30];
    int age;
    double gpa;
}SinhVien;

typedef struct Node{
    SinhVien sinhvien;
    struct Node* next;
}node;
//Ham tach chuoi tu ham fgets
void erasespace(char* c){
    for(int i=0;i<strlen(c);i++){
        if(c[i]=='\n') c[i] = '\0';
    }
}
//Ham tao 1 node moi
node* MakeNode(){
    node* NewNode = (node*)malloc(sizeof(node));
    fflush(stdin);
    printf("Nhap ten cho sinh vien: ");
    fgets(NewNode->sinhvien.name,30,stdin);
    erasespace(NewNode->sinhvien.name);
    printf("Nhap tuoi cho sinh vien: ");
    scanf("%d",&NewNode->sinhvien.age);fflush(stdin);
    printf("Nhap diem cho sinh vien: ");
    scanf("%lf",&NewNode->sinhvien.gpa); fflush(stdin);
    NewNode->next = NULL;
    return NewNode;
}
//Ham in ra danh sach
void printlist(node* head,int i){
    if(head==NULL) return ;
    while(head!=NULL){
        printf("Thong tin cua sinh vien thu %d\n",i);
        printf("Ten: %s\nTuoi: %d\nGpa: %.2lf\n",head->sinhvien.name,head->sinhvien.age,head->sinhvien.gpa);
        head=head->next;
        i++;
    }
}
//Ham menu
int menu(){
    system("cls");
    printf("_______________________MENU___________________\n");
    printf("1.Xem danh sach sinh vien\n");
    printf("2.Them sinh vien vao dau danh sach\n");
    printf("3.Them sinh vien vao cuoi danh sach\n");
    printf("4.Xoa sinh vien ra khoi danh sach\n");
    printf("0.Thoat chuong trinh\n");
    rest :
    int luachon;
    printf("Ban chon: ");
    scanf("%d",&luachon);
    if(luachon<0||luachon>5) {
        printf("Lua chon khong hop le vui long nhap lai\n");
        goto rest;
    }
    return luachon;
}
//Ham them 1 node vao dau danh sach
node* PushFront(node* head){
    node* newnode=MakeNode();
    newnode->next = head;
    head = newnode;
    return newnode;
}
//Ham them 1 node vao cuoi danh sach
node* PushBack(node* head){
    node* newnode = head;
    if(newnode == NULL) return PushFront(head);

    while(newnode->next!=NULL){
        newnode=newnode->next;
    }
    node* New = MakeNode();
    newnode->next = New;
    return head;
}
//Ham nhap value tu ban phim
int data(){
    int tmp;
    scanf("%d",&tmp);
    return tmp;
}
//Ham hien thi kich thuoc cua danh sach
int size(node* head){
    int cnt=0;
    while(head!=NULL){
        cnt++;
        head = head->next;
    }
    return cnt;
}
//Ham xoa 1 node o cuoi danh sach
node* PopBack(node* head){
    node* tmp = head;
    for(int i=1;i<=size(head)-2;i++){
        tmp = tmp->next;
    }
    node* q = tmp->next;
    tmp->next = NULL;
    free(q);

    return head;
}
//Ham xoa 1 node o dau danh sach
node* PopFront(node* head){
    node* tmp=head;
    head=head->next;
    free(tmp);

    return head;
}
//Ham xoa 1 node o vi tri ma nguoi dung nhap vao
node* EraseNode(node* head,int k){
    node* tmp = head;
    if(k<1 || k>size(head)) return head;
    if(k==1) return PopFront(head);
    if(k==size(head)) return PopBack(head);

    for(int i=1;i<= k -2;i++){
        tmp=tmp->next;
    }
    node* q = tmp->next;
    tmp = q->next;
    free(q);
    return head;
}

int main(){
    node* head = NULL;
    while(1){
        int n = menu();
        switch (n)
        {
        case 0:
            return 0;
        case 1: 
            printlist(head,1);
            break;
        case 2:
            head = PushFront(head);
            break;
        case 3:
            head = PushBack(head);
            break;
        case 4:
            printf("Nhap vi tri ma ban muon xoa sinh vien ra khoi danh sach: ");
            head = EraseNode(head,data());
            break;
        default:
            break;
        }
    }
    return 0;
}