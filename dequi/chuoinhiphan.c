#include<stdio.h>
#include<string.h>
int n;
int a[100];
int check(int k, int i){
    a[k] =i;
    if(a[k-1]==i) return 0;

    return 1;
}
void printff(){
    for(int i=1;i<=n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
void Try(int k){
    for(int i=0;i<=1;i++){
        if(check(k,i)){
            a[k] = i;
            if(k==n) printff();
            else{
                Try(k+1);
            }
        }
    }
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    scanf("%d",&n);
    memset(a,-1,100);
    Try(1);
    return 0;
}