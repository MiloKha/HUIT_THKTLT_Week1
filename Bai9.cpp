#include <stdio.h>
#include <stdlib.h>

void nhapHaiSo(int* pa, int* pb) {
    printf("Nhap so thu nhat: ");
    scanf("%d", pa);
    printf("Nhap so thu hai: ");
    scanf("%d", pb);
}

void tinhToan(int* pa, int* pb, int* tong, int* hieu, int* tich, float* thuong) {
    *tong = *pa + *pb;
    *hieu = *pa - *pb;
    *tich = *pa * *pb;
    if (*pb != 0) {
        *thuong = (float)*pa / *pb;
    }
    else {
        *thuong = 0; // Tránh chia cho 0
    }
}

void xuatKetQua(int* tong, int* hieu, int* tich, float* thuong) {
    printf("\nTong: %d, dia chi: %p", *tong, tong);
    printf("\nHieu: %d, dia chi: %p", *hieu, hieu);
    printf("\nTich: %d, dia chi: %p", *tich, tich);
    if (*thuong != 0) {
        printf("\nThuong: %f, dia chi: %p", *thuong, thuong);
    }
    else {
        printf("\nThuong: Khong xac dinh (chia cho 0), dia chi: %p", thuong);
    }
}

int main() {
    int a, b;
    int tong, hieu, tich;
    float thuong;

    int* pa = &a;
    int* pb = &b;
    int* ptong = &tong;
    int* phieu = &hieu;
    int* ptich = &tich;
    float* pthuong = &thuong;

    nhapHaiSo(pa, pb);
    tinhToan(pa, pb, ptong, phieu, ptich, pthuong);
    xuatKetQua(ptong, phieu, ptich, pthuong);

    return 0;
}
