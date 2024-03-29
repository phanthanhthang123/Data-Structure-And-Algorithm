#include<stdio.h>

void Swap(int* a,int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void Heapify(int* a,int n,int i){
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int max = i;

    if(l < n && a[l] > a[max] ){
        max = l;
    }
    if(r < n && a[r] > a[max]){
        max = r;
    }

    if(max != i){
        Swap(&a[i],&a[max]);
        Heapify(a,n,max);
    }
}

void HeapSort(int* a,int n){
    for(int i = n/2 -1;i>=0;i--){
        Heapify(a,n,i);
    }

    for(int i=n-1;i>=0;i--){
        Swap(&a[i],&a[0]);
        Heapify(a,i,0);
    }
}

int main(){
    int n;
    int a[1000];
    scanf("%d",&n);
    // srand(time(NULL));
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    HeapSort(a,n);

    for(int i=0;i< n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}