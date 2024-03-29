#include<stdio.h>
#include<time.h>
#include<stdlib.h>


//Lomuto
//Hoare
//pivot : chot
//Partition: phan hoach

void Swap(int* a,int* b){
    int tmp = *a;
    *a = *b;
    *b=tmp;
}
//Lomuto

// int Partition(int* a,int l,int r){
//     int pivot = a[r];
//     int i = l-1;
//     for(int j=l;j<r;j++){
//         if(a[j] <= pivot){
//             i++;
//             Swap(&a[i],&a[j]);
//         }
//     }
//     i++;
//     Swap(&a[i],&a[r]);
//     return i;
// }

// void QuickSort(int* a,int l,int r){
//     if(l>=r) return;
//     int p = Partition(a,l,r);
//     QuickSort(a,l,p-1);
//     QuickSort(a,p+1,r);
// }


//Hoare

// int Partition(int* a,int l,int r){
//     int i=l-1;
//     int j=r+1;
//     int pivot = a[l];
//     while(1){
//         do{
//             ++i;
//         }while(a[i] < pivot);
//         do{
//             --j;
//         }while(a[j] > pivot);

//         if(i<j){
//             Swap(&a[i],&a[j]);
//         }
//         else{
//             return j;
//         }
//     }
// }

// void QuickSort(int* a,int l,int r){
//     if(l>=r) return;
//     int p = Partition(a,l,r);
//     QuickSort(a,l,p);
//     QuickSort(a,p+1,r);
// }


int Partition(int* a,int l,int r){
    int pivot = a[r];
    int i = l-1;
    for(int j = l;j<r;j++){
        if(a[j] <= pivot){
            i++;
            Swap(&a[i],&a[j]);
        }
    }
    i++;
    Swap(&a[i],&pivot);

    return i;
}
//lomuto
void QuickSort(int* a,int l,int r){
    if(l>=r) return;
    int p = Partition(a,l,r);
    QuickSort(a,l,p-1);
    QuickSort(a,p+1,r);
}

int main(){
    int a[1000],n;
    scanf("%d",&n);
    srand(time(NULL));
    for(int i=0;i<n;i++){
        a[i] = rand() %1000;
    }
    QuickSort(a,0,n-1);

    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    return 0;
}