#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

int a[30];
long long c[1000][1000];
int k,n;
bool visited[30];

int check_binary(int i,int n){
    return 1;
}

void print_binary(){
    for(int i=1;i<=n;i++){
        printf("%d",a[i]);
    }
    printf("\n");
}

void Try_Binary(int k){
    for(int i=0;i<=1;i++){
        if(check_binary(k,i)){ // a[k]=i;
            a[k]=i;
            if(k==n) print_binary();
            else{
                Try_Binary(k+1);
            }
        }
    }
}
int check_hoanvi(int k,int i){
    if(visited[i]==false){
        visited[i] = true;
        return 1;
    }
    return 0;
}
void print_hoanvi(){
    for(int i=1;i<=n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

void Hoan_Vi(int k){
    for(int i=1;i<=n;i++){
        if(check_hoanvi(k,i)){ //a[k]=i;
            a[k]=i;
            if(k==n) print_hoanvi();
            else{
                Hoan_Vi(k+1);
            }
            visited[i]= false;
        }
    }
}
long long To_Hop(int k,int n,int m){
    if(k==0||k==n){
        c[k][n]= 1 ;
    }
    else{
        if(c[k][n]<0){
            c[k][n] = (To_Hop(k-1,n-1,m) % m + To_Hop(k,n-1,m) % m)%m;
        }
    }
    return c[k][n] % m;
}

void contet1(){
    memset(a,0,sizeof(a));
    scanf("%d",&n);
    Try_Binary(1);
}
void contest2(){
    memset(a,0,sizeof(a));
    memset(visited,false,sizeof(visited));
    scanf("%d",&n);
    Hoan_Vi(1);
}
void contest3(){
    double modul = pow(10,9) + 7;
    scanf("%d %d",&k,&n);
    for(int i=0;i<=999;i++){
        for(int j=0;j<=999;j++){
            c[i][j]=-1;
        }
    }
    printf("%lld",To_Hop(k,n,(int)modul ));
}
int main(){
    // contet1();
    // contest2();
    contest3();

    return 0;
}