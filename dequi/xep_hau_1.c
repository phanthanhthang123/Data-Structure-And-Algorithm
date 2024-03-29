#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>

int n,a[100];

int abs(int x){
	if(x<0) return -x;
	return n;
}

void in(){
	for(int i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}

bool check(int i,int ucv){
	for(int x=1;x<=ucv-1;x++){
		if(a[x]==ucv) return false;
		if(a[x]-x == ucv-i) return false;
		if(a[x]+x == ucv+i) return false;
	}

	return true;
}
void Try(int i){
	//duyet cac kha nang cua a[i]
	for(int j=1;j<=n;j++){
		if(check(i,j)){//check a[i] =j co thoa man k
			a[i]=j;
			if(i==n){
				in();
			}
			else{
				Try(i+1);
			}
		}
	}

}
int main(){
	memset(a,-1,sizeof(a));
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);

	scanf("%d",&n);
	Try(1);

	return 0;
}