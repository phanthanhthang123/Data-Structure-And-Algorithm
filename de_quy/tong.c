#include<stdio.h>

int tong(int n){
    printf("%d\n",n);

    return n + tong(n-1);
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d",tong(n));

    return 0;
}