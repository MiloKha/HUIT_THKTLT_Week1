#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void nhapChuoi(char** st) {
    char buffer[1000];
    printf("Nhap chuoi: ");
    fgets(buffer, 1000, stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // Loại bỏ ký tự xuống dòng
    *st = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(*st, buffer);
}

void xuatGiaTriTungKyTu(char* st) {
    char* p = st;
    while (*p != '\0') {
        printf("Ky tu: %c, Dia chi: %p\n", *p, p);
        p++;
    }
}

void chuyenChuHoa(char* st) {
    char* p = st;
    while (*p != '\0') {
        *p = toupper(*p);
        p++;
    }
}

void chuyenKyTuDauMoiTuChuHoa(char* st) {
    int inWord = 0;
    char* p = st;
    while (*p != '\0') {
        if (!inWord && isalpha(*p)) {
            *p = toupper(*p);
            inWord = 1;
        }
        else if (isspace(*p)) {
            inWord = 0;
        }
        p++;
    }
}

int main() {
    char* st;
    nhapChuoi(&st);

    printf("\nXuat gia tri tung ky tu cua chuoi:\n");
    xuatGiaTriTungKyTu(st);

    chuyenChuHoa(st);
    printf("\nChuoi sau khi chuyen sang chu hoa:\n%s\n", st);

    chuyenKyTuDauMoiTuChuHoa(st);
    printf("\nChuoi sau khi chuyen ky tu dau moi tu thanh chu hoa:\n%s\n", st);

    free(st);
    return 0;
}
