#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
///Câu 1
void taoMaTran(int a[MAX][MAX], int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % 100;
        }
    }
}

void inMaTran(int a[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}
//Câu 2
void inDuongCheoChinh(int a[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\t", a[i][i]);
    }
    printf("\n");
}
//Câu 3
void inDuongCheoSongSong(int a[MAX][MAX], int n) {
    for (int k = 1; k < n; k++) {
        for (int i = 0; i + k < n; i++) {
            printf("%d\t", a[i][i + k]);
        }
        printf("\n");
        for (int i = 0; i + k < n; i++) {
            printf("%d\t", a[i + k][i]);
        }
        printf("\n");
    }
}
//Câu 4
int timMaxTamGiacTren(int a[MAX][MAX], int n) {
    int max = a[0][1];
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][j] > max) {
                max = a[i][j];
            }
        }
    }
    return max;
}

int soSanh(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
//Câu 5
void sapXepZigZag(int a[MAX][MAX], int n) {
    int temp[MAX * MAX];
    int index = 0;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++) {
                temp[index++] = a[i][j];
            }
        }
        else {
            for (int j = n - 1; j >= 0; j--) {
                temp[index++] = a[i][j];
            }
        }
    }

    qsort(temp, n * n, sizeof(int), soSanh);

    index = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++) {
                a[i][j] = temp[index++];
            }
        }
        else {
            for (int j = n - 1; j >= 0; j--) {
                a[i][j] = temp[index++];
            }
        }
    }
}
//Câu 6
void sapXepDuongCheoChinh(int a[MAX][MAX], int n) {
    int temp[MAX];

    for (int i = 0; i < n; i++) {
        temp[i] = a[i][i];
    }

    qsort(temp, n, sizeof(int), soSanh);

    for (int i = 0; i < n; i++) {
        a[i][i] = temp[i];
    }
}

int main() {
    int n, luaChon;
    int maTran[MAX][MAX];

    do {
        printf("\nMenu:\n");
        printf("1. Tao va in ma tran\n");
        printf("2. In duong cheo chinh\n");
        printf("3. In cac duong cheo song song\n");
        printf("4. Tim max trong tam giac tren\n");
        printf("5. Sap xep ma tran theo kieu zic-zac\n");
        printf("6. Sap xep duong cheo chinh\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf_s("%d", &luaChon);

        switch (luaChon) {
        case 1:
            printf("Nhap kich thuoc ma tran (n >= 5): ");
            scanf_s("%d", &n);
            if (n >= 5) {
                taoMaTran(maTran, n);
                inMaTran(maTran, n);
            }
            else {
                printf("Kich thuoc ma tran phai it nhat la 5.\n");
            }
            break;
        case 2:
            inDuongCheoChinh(maTran, n);
            break;
        case 3:
            inDuongCheoSongSong(maTran, n);
            break;
        case 4:
            printf("Max trong tam giac tren: %d\n", timMaxTamGiacTren(maTran, n));
            break;
        case 5:
            sapXepZigZag(maTran, n);
            inMaTran(maTran, n);
            break;
        case 6:
            sapXepDuongCheoChinh(maTran, n);
            inMaTran(maTran, n);
            break;
        case 0:
            printf("Thoat...\n");
            break;
        default:
            printf("Lua chon khong hop le!\n");
        }
    } while (luaChon != 0);

    return 0;
}
