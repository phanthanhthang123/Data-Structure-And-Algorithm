#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node{
	int value;
	struct Node *next;
}node;

node* Capphatdong(){
	node* list = (node*) malloc(sizeof(node));
	return list;
}

void printlist(node* head){
	while(head!=NULL){
		printf("%d ",head->value);
		head = head->next;
	}
}
//ham dem so phan tu trong dslk
int size(node* head){
	int cnt = 0;
	while(head!=NULL){
		head=head->next;
		cnt++;
	}
	return cnt;
}
//ham tao node moi
node* makenode(int v){
	node* newNode = Capphatdong();
	newNode->value=v;
	newNode->next=NULL;
	return newNode;
}

int data(){
	int tmp;
	scanf("%d",&tmp);
	return tmp;
}

// them phan tu o dau danh sach
node* PushFront(node* head,int x){
	node* pushfront = makenode(x);
	pushfront->next = head;
	head = pushfront;
	return pushfront;
}

// them phan tu o cuoi danh sach
node* insertlist(node* head,int v){
	node* p = head;
	if(p==NULL){
		return makenode(v);
	}
	while(p->next!=NULL){
		p=p->next;
	}
	node* newNode = makenode(v);
	p->next = newNode;
	return head;
}

int main(){
	node* head = NULL;
	for(int i=0;i<5;i++){
		// head = PushFront(head,data());
		head= insertlist(head,data());
	}

	printlist(head);
	printf("\n");
	printf("%d",size(head));

	return 0;
}