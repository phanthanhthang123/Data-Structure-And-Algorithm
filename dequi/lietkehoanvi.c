#include<stdio.h>
#include<string.h>

int used[100];
int x[100];
int n;

void in(){
    for(int i=1;i<n;i++){
        printf("%d ",x[i]);
    }
    printf("\n");
}
void Try(int i){
    for(int j=1;j<=n;j++){
        if(used[j]==0){
            used[j]=1;
            x[i]=j;
            if( j%2 ==1 != x[i-1]%2){
                x[i]=j;
            }
            if(i==n) in();
            else{
                Try(i+1);
            }
            used[j]=0;
        }
    }

}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    memset(x,0,100);
    memset(used,0,100);
    scanf("%d",&n);
    Try(1);

    return 0;
}