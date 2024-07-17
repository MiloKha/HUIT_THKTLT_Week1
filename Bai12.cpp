#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int tu;
    int mau;
} PhanSo;

void nhapPhanSo(PhanSo* p) {
    printf("Nhap tu so: ");
    scanf("%d", &p->tu);
    do {
        printf("Nhap mau so (khac 0): ");
        scanf("%d", &p->mau);
        if (p->mau == 0) {
            printf("Mau so phai khac 0. Vui long nhap lai.\n");
        }
    } while (p->mau == 0);
}

void xuatPhanSo(PhanSo p) {
    printf("%d/%d", p.tu, p.mau);
}

void nhapMangPhanSo(PhanSo*& a, int& n) {
    printf("Nhap so luong phan so: ");
    scanf("%d", &n);
    a = (PhanSo*)malloc(n * sizeof(PhanSo));
    for (int i = 0; i < n; i++) {
        printf("Nhap phan so thu %d:\n", i + 1);
        nhapPhanSo(&a[i]);
    }
}

void xuatMangPhanSo(PhanSo* a, int n) {
    for (int i = 0; i < n; i++) {
        xuatPhanSo(a[i]);
        printf("\n");
    }
}

float giaTriPhanSo(PhanSo p) {
    return (float)p.tu / p.mau;
}

PhanSo timPhanSoLonNhat(PhanSo* a, int n) {
    PhanSo max = a[0];
    for (int i = 1; i < n; i++) {
        if (giaTriPhanSo(a[i]) > giaTriPhanSo(max)) {
            max = a[i];
        }
    }
    return max;
}

PhanSo timPhanSoNhoNhat(PhanSo* a, int n) {
    PhanSo min = a[0];
    for (int i = 1; i < n; i++) {
        if (giaTriPhanSo(a[i]) < giaTriPhanSo(min)) {
            min = a[i];
        }
    }
    return min;
}

void xoaPhanTuTaiViTri(PhanSo*& a, int& n, int k) {
    if (k < 0 || k >= n) {
        printf("Vi tri xoa khong hop le.\n");
        return;
    }
    for (int i = k; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    n--;
    a = (PhanSo*)realloc(a, n * sizeof(PhanSo));
}

void themPhanTuTaiViTri(PhanSo*& a, int& n, PhanSo x, int k) {
    if (k < 0 || k > n) {
        printf("Vi tri them khong hop le.\n");
        return;
    }
    n++;
    a = (PhanSo*)realloc(a, n * sizeof(PhanSo));
    for (int i = n - 1; i > k; i--) {
        a[i] = a[i - 1];
    }
    a[k] = x;
}

void menu() {
    PhanSo* a;
    int n = 0;
    int choice, k;
    PhanSo x;
    do {
        printf("\n\nMenu:");
        printf("\n1. Nhap mang phan so");
        printf("\n2. Xuat mang phan so");
        printf("\n3. Tim phan so lon nhat");
        printf("\n4. Tim phan so nho nhat");
        printf("\n5. Xoa phan tu tai vi tri k");
        printf("\n6. Them phan tu tai vi tri k");
        printf("\n7. Thoat");
        printf("\nChon: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            nhapMangPhanSo(a, n);
            break;
        case 2:
            xuatMangPhanSo(a, n);
            break;
        case 3: {
            PhanSo max = timPhanSoLonNhat(a, n);
            printf("Phan so lon nhat la: ");
            xuatPhanSo(max);
            printf("\n");
            break;
        }
        case 4: {
            PhanSo min = timPhanSoNhoNhat(a, n);
            printf("Phan so nho nhat la: ");
            xuatPhanSo(min);
            printf("\n");
            break;
        }
        case 5:
            printf("Nhap vi tri can xoa: ");
            scanf("%d", &k);
            xoaPhanTuTaiViTri(a, n, k);
            break;
        case 6:
            printf("Nhap phan tu can them:\n");
            nhapPhanSo(&x);
            printf("Nhap vi tri can them: ");
            scanf("%d", &k);
            themPhanTuTaiViTri(a, n, x, k);
            break;
        case 7:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le.\n");
        }
    } while (choice != 7);
    free(a);
}

int main() {
    menu();
    return 0;
}
