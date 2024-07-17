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

// Hàm xuất các phần tử cực tiểu
void xuatCucTieu(int* a, int n) {
    if (n < 2) {
        printf("Mang khong du so phan tu de co so cuc tieu.\n");
        return;
    }
    for (int i = 1; i < n - 1; i++) {
        if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
            printf("\nSo cuc tieu: %d o dia chi %p", a[i], (a + i));
        }
    }
}

// Hàm xóa phần tử tại vị trí k
void xoaPhanTuTaiViTri(int*& a, int& n, int k) {
    if (k < 0 || k >= n) {
        printf("Vi tri xoa khong hop le.\n");
        return;
    }
    for (int i = k; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    n--;
    a = (int*)realloc(a, n * sizeof(int));
}

// Hàm thêm phần tử x tại vị trí k
void themPhanTuTaiViTri(int*& a, int& n, int x, int k) {
    if (k < 0 || k > n) {
        printf("Vi tri them khong hop le.\n");
        return;
    }
    n++;
    a = (int*)realloc(a, n * sizeof(int));
    for (int i = n - 1; i > k; i--) {
        a[i] = a[i - 1];
    }
    a[k] = x;
}

// Hàm chuyển số chẵn lên đầu mảng, số lẻ xuống cuối mảng
void chuyenChanLenDauLeXuongCuoi(int* a, int n) {
    int* temp = (int*)malloc(n * sizeof(int));
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            temp[index++] = a[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            temp[index++] = a[i];
        }
    }
    for (int i = 0; i < n; i++) {
        a[i] = temp[i];
    }
    free(temp);
}

// Hàm kiểm tra mảng có chứa chẵn lẻ xen kẽ không
int kiemTraChanLeXenKe(int* a, int n) {
    for (int i = 0; i < n - 1; i++) {
        if ((a[i] % 2 == 0 && a[i + 1] % 2 == 0) || (a[i] % 2 != 0 && a[i + 1] % 2 != 0)) {
            return 0; // Không xen kẽ
        }
    }
    return 1; // Xen kẽ
}

void menu() {
    int* a, n = 0;
    int choice, x, k;
    do {
        printf("\n\nMenu:");
        printf("\n1. Nhap mang phan so");
        printf("\n2. Xuat mang phan so");
        printf("\n3. Xuat cac so cuc tieu");
        printf("\n4. Xoa phan tu tai vi tri k");
        printf("\n5. Them phan tu tai vi tri k");
        printf("\n6. Chuyen so chan len dau, so le xuong cuoi");
        printf("\n7. Kiem tra mang co chua chan le xen ke");
        printf("\n8. Thoat");
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
            xuatCucTieu(a, n);
            break;
        case 4:
            printf("Nhap vi tri can xoa: ");
            scanf("%d", &k);
            xoaPhanTuTaiViTri(a, n, k);
            break;
        case 5:
            printf("Nhap gia tri can them: ");
            scanf("%d", &x);
            printf("Nhap vi tri can them: ");
            scanf("%d", &k);
            themPhanTuTaiViTri(a, n, x, k);
            break;
        case 6:
            chuyenChanLenDauLeXuongCuoi(a, n);
            break;
        case 7:
            if (kiemTraChanLeXenKe(a, n)) {
                printf("Mang co chua chan le xen ke.\n");
            }
            else {
                printf("Mang khong chua chan le xen ke.\n");
            }
            break;
        case 8:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le.\n");
        }
    } while (choice != 8);
    free(a);
}

int main() {
    menu();
    return 0;
}
