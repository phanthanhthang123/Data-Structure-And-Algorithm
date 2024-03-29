#include<stdio.h>
#include<string.h>

int n,cot[100],d1[100],d2[100],x[100];

void in(){
    for(int i=1;i<=n;i++){
        printf("%d ",x[i]);
    }
    printf("\n");
}

void Try(int i){
    //duyet cac kha nang cua x[i] co the dat
    for(int j=1;j<=n;j++){
        if(cot[j]==1 && d1[i-j+n]==1 && d2[i+j-1]==1){
            x[i]=j;
            cot[j]=d1[i-j+n]=d2[i+j-1]=0;
            if(i==n) in();
            else{
                Try(i+1);
            }
            //backtrack
            cot[j]=d1[i-j+n]=d2[i+j-1]=1;
        }

    }
}

int main()
{
    for(int i=1;i<=99;i++){
        cot[i]=d1[i]=d2[i]=1;
    }
    memset(x,0,100);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d",&n);
    Try(1);

    return 0;

}