#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct Product
{
    char ten[30];
    long long gia;
    int soluong;
} product;

int MeNu();
product *CapPhatMang(product *arr, int n);
void XemGioHang(product *arr, int n);
product *ThemSanPham(product *arr, int *n, int x);
product *XoaSanPham(product *arr, int *n, int index);

int main()
{
    product *arr;
    int n = 0;
    arr = CapPhatMang(arr, n);
    while (true)
    {
        int luachon = MeNu();
        switch (luachon)
        {
        case 1:
            XemGioHang(arr, n);
            break;
        case 2:
            // them san pham
            printf("So san pham ban muon them la:");
            int x;
            scanf("%d", &x);
            fflush(stdin);
            arr = ThemSanPham(arr, &n, x);
            break;
        case 3:
            // xoa san pham
            printf("Ban muon xoa san pham thu :");
            int index;
            scanf("%d", &index);
            arr = XoaSanPham(arr, &n, index);
            break;
        case 4:
            printf("BYE BYE!!\n");
            break;
        default:
            printf("Lua chon cua ban khong hop le\n");
        }
        printf("Ban co muon tiep tuc khong(1/0):");
        int x;
        scanf("%d", &x);
        if (!x)
        {
            printf("BYE BYE!!\n");
            break;
        }
    }
    return 0;
}

int MeNu()
{
    system("cls");
    printf("=============MENU============\n");
    printf("1.Xem gio hang cua ban\n");
    printf("2.Them san pham vao gio hang cua ban\n");
    printf("3.Xoa san pham\n");
    printf("4.Thoat chuong trinh\n");
    printf("Ban chon: ");
    int luachon;
    scanf("%d", &luachon);

    return luachon;
}

product *CapPhatMang(product *arr, int n)
{
    arr = (product *)malloc(n * sizeof(product));
    return arr;
}
void XemGioHang(product *arr, int n)
{
    if (n == 0)
    {
        printf("Gio hang cua ban dang rong\n");
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            printf("Thong tin san tham thu %d:\n", i + 1);
            printf("Ten san pham: %s\nGia San pham: %lld\nSo luong san pham: %d\n", arr[i].ten, arr[i].gia, arr[i].soluong);
        }
        printf("\n");
    }
}

product *ThemSanPham(product *arr, int *n, int x)
{
    for (int i = 0; i < x; i++)
    {
        *n += 1;
        arr = (product *)realloc(arr, (*n) * sizeof(product));
        printf("Nhap thong tin cua san pham thu %d\n", *n);
        for (int j = *n - 1; j < *n; j++)
        {
            printf("Nhap ten san pham: ");
            fflush(stdin);
            gets(arr[i].ten);
            // fgets(arr[i].ten,sizeof(arr[i].ten),stdin);
            printf("Nhap Gia san pham: ");
            scanf("%lld", &arr[i].gia);
            fflush(stdin);
            printf("Nhap so luong san pham: ");
            scanf("%d", &arr[i].soluong);
        }
    }
    return arr;
}
product *XoaSanPham(product *arr, int *n, int index)
{
    for (int i = index - 1; i < *n - 1; i++)
    {
        memcpy(&arr[i], &arr[i + 1], sizeof(product));
    }
    *n -= 1;
    arr = (product *)realloc(arr, (*n) * sizeof(product));

    return arr;
}