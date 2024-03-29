#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int* CapPhatMang(int *n){
    int* pa = (int*)malloc((*n)*sizeof(int));
    return pa;
}
int* NhapMang(int* arr,int n){
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    return arr;
}
void InMang(int* arr,int n){
    for(int i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
    printf("\n");
}
bool DaTonTai(int* arr,int n,int value){
    for(int i=0;i<n;i++){
        if(arr[i]==value) return true;
    }
    return false;
}
int* ThemPhanTu(int* arr,int* n,int value){
    if(DaTonTai(arr,*n,value)) return arr;
    (*n)+=1;
    arr = (int*)realloc(arr,(*n)*sizeof(int));
    arr[(*n)-1]=value;
    return arr;
}
int* XoaPhanTu(int* arr,int *n,int index){
    for(int i=index;i<(*n)-1;i++){
        arr[i]=arr[i+1];
    }
    *n -=1;
    arr=(int*)realloc(arr,(*n)*sizeof(int));
    return arr;
}
int DemSoLanXuatHien(int* arr,int n,int value){
    int count =0;
    for(int i=0;i<n;i++){
        if(arr[i]==value){
            ++count;
        }
    }
    return count;
}
int* XoaPhanTuTRungLap(int* arr,int* n){
    for(int i=0;i<(*n);i++){
        while(DemSoLanXuatHien(arr,*n,arr[i]) >1){
            arr=XoaPhanTu(arr,n,i);
        }
    }
    return arr;
}
int NhapData(){
    int n;scanf("%d",&n);

    return n;
}
int main(){
    int n;
    scanf("%d",&n);
    int* arr = CapPhatMang(&n);
    arr = NhapMang(arr,n);
    InMang(arr,n);

    arr = ThemPhanTu(arr,&n,NhapData());
    InMang(arr,n);
    arr=ThemPhanTu(arr,&n,NhapData());
    InMang(arr,n);
    arr=ThemPhanTu(arr,&n,NhapData());
    InMang(arr,n);

    arr = XoaPhanTuTRungLap(arr,&n);
    InMang(arr,n);

    return 0;
}

#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node{
    char time[50];
    char plate[50];
    struct Node* next;
}Node;
Node* root = NULL;

Node* MakeNode(char time[],char plate[]){
    Node* NewNode = (Node*)malloc(sizeof(Node));
    strcpy(NewNode->plate,plate);
    strcpy(NewNode->time,time);
    NewNode->next=NULL;
    return NewNode;
}

//Ham tim kiem xe, neu thay tra ve vi tri , neu khong tim thay tra ve -1
int find(Node* root,char plate[]){
    if(root==NULL) return -1;
    int cnt = 0;
    Node* temp = root;
    while(temp!=NULL){
        if(!strcmp(temp->plate,plate)) return cnt;
        cnt++;
        temp=temp->next;
    }

    return -1;
}
//Ham tra ve 1 neu add xe thanh cong, tra ve 0 neu loi
int in(Node** root,char time[],char plate[]){
    Node* temp = *root;
    if(find(temp,plate) == -1){
        if((*root)==NULL){
            *root = MakeNode(time,plate);
        }else{
            while(temp->next!=NULL) temp=temp->next;
            temp->next = MakeNode(time,plate);
        }
        return 1;
    }
    return 0;
}

//tra ve 1 neu la xe may, tra ve 0 neu la xe dap
int check_moto(char plate[]){
    int cnt=0;
    for(int i=0;i<=3;i++){
        if(plate[i]=='x')cnt++;
    }
    if(cnt==4) return 0;

    return 1;
}

//dem so luong xe moto co trong bai
int cnt_moto(Node* root){
    if(root==NULL) return 0;
    int count = 0;
    Node* temp = root;
    while(temp!=NULL){
        if(check_moto(temp->plate)) count++;
        temp=temp->next;
    }
    return count;
}

//luc time cho xe plate ra , neu khong co tra ve 0, neu thanh cong tra ve 1
int out(Node** root,char time[],char plate[]){
    if(*root==NULL) return 0;
    if(find(*root,plate)==-1) return 0;
    if(!strcmp((*root)->plate,plate)){
        Node* temp = *root;
        *root=(*root)->next;
        free(temp);
        return 1;
    }else{
        Node* temp= *root;
        while(temp->next!=NULL){
            if(!strcmp(temp->next->plate,plate)){
                Node* xoa = temp->next;
                if(temp->next->next!=NULL) temp->next=temp->next->next;
                else temp->next=NULL;
                free(xoa);
                return 1;
            }
            temp=temp->next;
        }
        if(!strcmp(temp->plate,plate)){
            free(temp);
            temp=NULL;
            return 1;
        }
    }
    return 0;
}

int bill(Node* root,char time[],char plate[]){
    int k = find(root,plate);
    if(k== -1) return -1;
    int hh,mm,ss;
    int hh_n,mm_n,ss_n;
    Node* temp = root;
    for(int i=0;i<k;i++) temp=temp->next;
    sscanf(temp->plate,"%d:%d:%d",&hh,&mm,&ss);
    sscanf(time,"%d:%d:%d",&hh_n,&mm_n,&ss_n);

    //Ngay - ngay
    if( (hh>=6 && hh < 18) && ( hh_n >=6 && hh_n < 18) ){
        if(check_moto(plate)==1) return 3;
        else return 1;
    }
    //ngay - dem
    else if( (hh >=6 && hh < 18) &&  (hh_n < 6 || hh_n >= 18) ){
        if(check_moto(plate)==1) return 5;
        else return 2;
    }
    //dem - ngay
    else if( (hh>=18 || hh <6) && ( hh_n >=6 && hh_n < 18) ){
        if(check_moto(plate)==1) return 8;
        else return 3;
    }
    //dem - ngay - dem
    else if( (hh>=18 || hh <6)  &&   (hh_n >=18 && hh_n < 6) ){
        if(check_moto(plate)==1) return 13;
        else return 5;
    }
    return -1;
}
void list(Node* root){
    Node* temp = root;
    while(temp!=NULL){
        printf("%s\n",temp->plate);
        temp=temp->next;
    }
}

int main(){
    char time[50],plate[50];
    int billall=0;
    while(scanf("%s",time)){
            if(!strcmp(time,"*")) break;
            scanf("%s ",plate);
            in(&root,time,plate);
    }

    char command[50];
    char time1[50],plate1[50];
    while(scanf("%s",command)){
        if(!strcmp(command,"***")) break;
        if(!strcmp(command,"list")) list(root);
        if(!strcmp(command,"in")){
            scanf("%s",time1);
            scanf("%s",plate1);
            printf("%d\n",in(&root,time1,plate1));
        }
        if(!strcmp(command,"cnt-moto")){
            printf("%d\n",cnt_moto(root));
        }
        if(!strcmp(command,"find")){
            scanf("%s",plate1);
            printf("%d\n",find(root,plate1));
        }
        if(!strcmp(command,"out")){
            scanf("%s",time1);
            scanf("%s",plate1);
            if(bill(root,time1,plate1)!=-1) billall = billall + bill(root,time1,plate1);
            printf("%d\n",out(&root,time1,plate1));
        }
        if(!strcmp(command,"bill")){
            scanf("%s",time1);
            scanf("%s",plate1);
            int tien = bill(root,time1,plate1);
            printf("%d\n",tien);
        }
        if(!strcmp(command,"billall")){
            printf("%d\n",billall);
        }
    }

    return 0;
}
