#include <stdio.h>
#include <stdlib.h>

void nhapMang(int*& arr, int& n) {
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void xuatMang(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void tinhChia(int* a, int n_a, int* b, int n_b) {
    for (int i = 0; i < n_a; i++) {
        for (int j = 0; j < n_b; j++) {
            if (b[j] == 0) {
                printf("Phan tu a[%d] / b[%d]: Khong the chia cho 0.\n", i, j);
            }
            else {
                float result = (float)a[i] / b[j];
                printf("Phan tu a[%d] / b[%d] = %.2f\n", i, j, result);
            }
        }
    }
}

int main() {
    int* a, * b;
    int n_a, n_b;

    nhapMang(a, n_a);
    nhapMang(b, n_b);

    printf("\nMang a: ");
    xuatMang(a, n_a);
    printf("Mang b: ");
    xuatMang(b, n_b);

    printf("\nKet qua phep chia:\n");
    tinhChia(a, n_a, b, n_b);

    free(a);
    free(b);
    return 0;
}
