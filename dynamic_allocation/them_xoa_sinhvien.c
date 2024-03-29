#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SinhVien
{
    char name[30];
    int age;
    double gpa;
};

struct SinhVien* CapPhatMang(struct SinhVien *arr, int n)
{
    arr = (struct SinhVien *)malloc(n * sizeof(struct SinhVien));
    return arr;
}

struct SinhVien *NhapThongTin(struct SinhVien *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Nhap thong tin sinh vien thu %d :\n", i + 1);
        fflush(stdin);
        printf("Name: ");
        gets(arr[i].name);
        printf("Tuoi: ");
        scanf("%d", &arr[i].age);
        printf("Gpa: ");
        scanf("%lf", &arr[i].gpa);
    }
    return arr;
}

void InThongTin(struct SinhVien *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Thong tin cua sinh vien thu %d la:\n", i + 1);
        printf("Name: %s\nAge: %d\nDiem: %.2lf\n", arr[i].name, arr[i].age, arr[i].gpa);
    }
}
struct SinhVien *ThemSinhVien(struct SinhVien *arr, int *n, int m)
{
    for (int i = 0; i < m; i++)
    {
        *n += 1;
        printf("Nhap thong tin cua sinh vien thu %d :\n", *n);
        arr = (struct SinhVien *)realloc(arr, (*n) * sizeof(struct SinhVien));
        fflush(stdin);
        printf("Name: ");
        gets(arr[(*n) - 1].name);
        printf("Tuoi: ");
        scanf("%d", &arr[(*n) - 1].age);
        printf("Gpa: ");
        scanf("%lf", &arr[(*n) - 1].gpa);
    }

    return arr;
}

struct SinhVien *XoaSinhVien(struct SinhVien *arr, int *n, int index)
{
    for (int i = index; i < *n - 1; i++)
    {
        // arr[i].name = arr[i+1].name;
        // arr[i].age = arr[i+1].age;
        // arr[i].gpa = arr[i+1].gpa;
        memcpy(&arr[i], &arr[i + 1], sizeof(struct SinhVien));
    }
    *n -= 1;
    arr = (struct SinhVien *)realloc(arr, (*n) * sizeof(struct SinhVien));
    return arr;
}

int main()
{
    int n;
    scanf("%d", &n);
    // fflush(stdin);
    struct SinhVien *arr = CapPhatMang(arr, n);
    arr = NhapThongTin(arr, n);
    // InThongTin(arr,n);
    int m;
    printf("Nhap so sinh vien can them vao mang: ");
    scanf("%d", &m);
    fflush(stdin);

    arr = ThemSinhVien(arr, &n, m);

    // InThongTin(arr, n);
    int i;
    printf("Xoa thong tin cua sinh vien thu: ");
    scanf("%d", &i);
    fflush(stdin);
    arr = XoaSinhVien(arr, &n, i - 1);

    InThongTin(arr, n);

    return 0;
}