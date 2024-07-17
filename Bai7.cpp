#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void nhapM1C_SoNguyen(int*& a, int& n) {
    printf("Nhap so phan tu: ");
    scanf("%d", &n);
    a = (int*)malloc(n * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        *(a + i) = rand() % 100;
}

void xuatM1C_SoNguyen(int* a, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nPhan tu thu %d co gia tri %d va dia chi o nho la %p", i, *(a + i), (a + i));
        printf("\nPhan tu thu %d co gia tri %d va dia chi o nho la %p", i, a[i], (a + i));
    }
}

void timMax(int* a, int n) {
    int max = *a;
    int* pMax = a;
    for (int i = 1; i < n; i++) {
        if (*(a + i) > max) {
            max = *(a + i);
            pMax = (a + i);
        }
    }
    printf("\nPhan tu lon nhat la %d o dia chi %p", max, pMax);
}

void timChanLe(int* a, int n) {
    int* pChanMax = NULL, * pLeMin = NULL;
    for (int i = 0; i < n; i++) {
        if (*(a + i) % 2 == 0) {
            if (pChanMax == NULL || *(a + i) > *pChanMax)
                pChanMax = (a + i);
        }
        else {
            if (pLeMin == NULL || *(a + i) < *pLeMin)
                pLeMin = (a + i);
        }
    }
    if (pChanMax != NULL)
        printf("\nPhan tu chan lon nhat la %d o dia chi %p", *pChanMax, pChanMax);
    else
        printf("\nKhong co phan tu chan trong mang");

    if (pLeMin != NULL)
        printf("\nPhan tu le nho nhat la %d o dia chi %p", *pLeMin, pLeMin);
    else
        printf("\nKhong co phan tu le trong mang");
}

void xoaPhanTu(int*& a, int& n, int value) {
    int* p = a;
    int newSize = n;
    for (int i = 0; i < n; i++) {
        if (*(p + i) == value) {
            for (int j = i; j < n - 1; j++) {
                *(p + j) = *(p + j + 1);
            }
            newSize--;
            i--; // Giảm i để kiểm tra lại vị trí vừa dịch
        }
    }
    a = (int*)realloc(a, newSize * sizeof(int));
    n = newSize;
}

void themPhanTu(int*& a, int& n, int value) {
    n++;
    a = (int*)realloc(a, n * sizeof(int));
    for (int i = n - 1; i > 0; i--)
        *(a + i) = *(a + i - 1);
    *a = value;
}

int laSoChinhPhuong(int x) {
    int sqrtX = sqrt(x);
    return (sqrtX * sqrtX == x);
}

void tinhTongSoChinhPhuong(int* a, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (laSoChinhPhuong(*(a + i))) {
            sum += *(a + i);
        }
    }
    printf("\nTong cac phan tu la so chinh phuong la: %d", sum);
}

void xuatCucDai(int* a, int n) {
    for (int i = 1; i < n - 1; i++) {
        if (*(a + i) > *(a + i - 1) && *(a + i) > *(a + i + 1)) {
            printf("\nSo cuc dai: %d o dia chi %p", *(a + i), (a + i));
        }
    }
}

void menu() {
    int* a, n = 0;
    int choice, x;
    do {
        printf("\n\nMenu:");
        printf("\n1. Nhap mang");
        printf("\n2. Xuat mang");
        printf("\n3. Tim phan tu lon nhat");
        printf("\n4. Tim phan tu chan lon nhat va phan tu le nho nhat");
        printf("\n5. Xoa phan tu co gia tri 0");
        printf("\n6. Them phan tu vao sau phan tu dau tien");
        printf("\n7. Tinh tong cac phan tu la so chinh phuong");
        printf("\n8. Xuat cac so cuc dai trong mang");
        printf("\n9. Thoat");
        printf("\nChon: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            nhapM1C_SoNguyen(a, n);
            break;
        case 2:
            xuatM1C_SoNguyen(a, n);
            break;
        case 3:
            timMax(a, n);
            break;
        case 4:
            timChanLe(a, n);
            break;
        case 5:
            xoaPhanTu(a, n, 0);
            break;
        case 6:
            printf("\nNhap gia tri can them: ");
            scanf("%d", &x);
            themPhanTu(a, n, x);
            break;
        case 7:
            tinhTongSoChinhPhuong(a, n);
            break;
        case 8:
            xuatCucDai(a, n);
            break;
        case 9:
            printf("\nThoat chuong trinh.");
            break;
        default:
            printf("\nLua chon khong hop le.");
        }
    } while (choice != 9);
}

int main() {
    menu();
    return 0;
}
