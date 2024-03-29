#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

void Merge(int a[],int l,int m,int  r){
    int arr[r-l+1];
    int i = l, j=m+1;
    int k=0;

    while (i<=m && j<=r){
        if(a[i] <= a[j]){
            arr[k]=a[i];
            i++;
        }
        else{
            arr[k]=a[j];
            j++;
        }
        k++;
    }

    while(i<=m){
        arr[k]=a[i];
        i++;
        k++;
    }
    while(j<=r){
        arr[k]=a[j];
        j++;
        k++;
    }

    for(int i=0;i< k;i++){
        a[i+l]=arr[i];
    }
    
}

void MergeSort(int a[],int l,int r){
    if(l>=r) return;
    int m =(l+r)/2;
    MergeSort(a,l,m);
    MergeSort(a,m+1,r);
    Merge(a,l,m,r);
}

int main(){
    int a[100];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        a[i] = rand() % 100;
    }

    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    printf("\n");

    MergeSort(a,0,n-1);

    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}