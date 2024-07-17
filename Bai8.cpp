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

void xuatPhanSoMauLonHonTu(PhanSo* a, int n) {
    printf("Cac phan so co mau lon hon tu la:\n");
    for (int i = 0; i < n; i++) {
        if (a[i].mau > a[i].tu) {
            xuatPhanSo(a[i]);
            printf("\n");
        }
    }
}

int demPhanSoMauVaTuChan(PhanSo* a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].tu % 2 == 0 && a[i].mau % 2 == 0) {
            count++;
        }
    }
    return count;
}

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

void rutGonPhanSo(PhanSo* p) {
    int ucln = gcd(abs(p->tu), abs(p->mau));
    p->tu /= ucln;
    p->mau /= ucln;
    if (p->mau < 0) { // Đảm bảo mẫu số luôn dương
        p->tu = -p->tu;
        p->mau = -p->mau;
    }
}

void rutGonMangPhanSo(PhanSo* a, int n) {
    for (int i = 0; i < n; i++) {
        rutGonPhanSo(&a[i]);
    }
}

PhanSo tichMangPhanSo(PhanSo* a, int n) {
    PhanSo tich = { 1, 1 };
    for (int i = 0; i < n; i++) {
        tich.tu *= a[i].tu;
        tich.mau *= a[i].mau;
    }
    rutGonPhanSo(&tich);
    return tich;
}

PhanSo timPhanSoLonNhat(PhanSo* a, int n) {
    PhanSo max = a[0];
    for (int i = 1; i < n; i++) {
        if ((double)a[i].tu / a[i].mau > (double)max.tu / max.mau) {
            max = a[i];
        }
    }
    return max;
}

void menu() {
    PhanSo* a;
    int n = 0;
    int choice;
    do {
        printf("\n\nMenu:");
        printf("\n1. Nhap mang phan so");
        printf("\n2. Xuat mang phan so");
        printf("\n3. Xuat cac phan so co mau lon hon tu");
        printf("\n4. Dem so phan so co mau va tu chan");
        printf("\n5. Rut gon phan so");
        printf("\n6. Tinh tich cac phan so");
        printf("\n7. Tim phan so lon nhat");
        printf("\n8. Thoat");
        printf("\nChon: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            nhapMangPhanSo(a, n);
            break;
        case 2:
            xuatMangPhanSo(a, n);
            break;
        case 3:
            xuatPhanSoMauLonHonTu(a, n);
            break;
        case 4:
            printf("So phan so co mau va tu chan: %d\n", demPhanSoMauVaTuChan(a, n));
            break;
        case 5:
            rutGonMangPhanSo(a, n);
            printf("Mang phan so sau khi rut gon:\n");
            xuatMangPhanSo(a, n);
            break;
        case 6: {
            PhanSo tich = tichMangPhanSo(a, n);
            printf("Tich cac phan so la: ");
            xuatPhanSo(tich);
            printf("\n");
            break;
        }
        case 7: {
            PhanSo max = timPhanSoLonNhat(a, n);
            printf("Phan so lon nhat la: ");
            xuatPhanSo(max);
            printf("\n");
            break;
        }
        case 8:
            printf("\nThoat chuong trinh.");
            break;
        default:
            printf("\nLua chon khong hop le.");
        }
    } while (choice != 8);
    free(a);
}

int main() {
    menu();
    return 0;
}
