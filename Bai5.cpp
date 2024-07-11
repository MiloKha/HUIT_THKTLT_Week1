#include <stdio.h>

int main()
{
    int a, b, c;
    float result;

    // Nh?p giá tr? c?a a, b, c t? ng??i dùng
    printf("Nhap gia tri cua a: ");
    scanf_s("%d", &a);
    printf("Nhap gia tri cua b: ");
    scanf_s("%d", &b);

    // Ki?m tra a - b có b?ng 0 không
    if (a - b == 0)
    {
        printf("Loi: a - b bang 0. Khong the chia cho 0.\n");
    }
    else
    {
        printf("Nhap gia tri cua c: ");
        scanf_s("%d", &c);

        // Tính và in ra k?t qu? c?a c / (a - b)
        float KQ = (float)c / (a - b);
        printf("Ket qua c / (a - b) la: %.2f\n", KQ);
    }

    return 0;
}
