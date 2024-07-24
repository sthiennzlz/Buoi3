#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_M 100
#define MAX_N 100
//Câu 1
void taoMang(int a[MAX_M][MAX_N], int m, int n, int k) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % (k + 1);
        }
    }
}

void xuatMang(int a[MAX_M][MAX_N], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}
//Câu 2
void tinhTongDong(int a[MAX_M][MAX_N], int m, int n) {
    for (int i = 0; i < m; i++) {
        int tong = 0;
        for (int j = 0; j < n; j++) {
            tong += a[i][j];
        }
        printf("Tong dong %d: %d\n", i, tong);
    }
}
//Câu 3
void timMaxCot(int a[MAX_M][MAX_N], int m, int n) {
    for (int j = 0; j < n; j++) {
        int max = a[0][j];
        for (int i = 1; i < m; i++) {
            if (a[i][j] > max) {
                max = a[i][j];
            }
        }
        printf("Max cot %d: %d\n", j, max);
    }
}
//Câu 4
void xuatBien(int a[MAX_M][MAX_N], int m, int n) {
    printf("Cac phan tu bien:\n");
    for (int j = 0; j < n; j++) printf("%d ", a[0][j]);
    for (int i = 1; i < m - 1; i++) printf("%d %d\n", a[i][0], a[i][n - 1]);
    for (int j = 0; j < n; j++) printf("%d ", a[m - 1][j]);
    printf("\n");
}
//Câu 5
void timCucDai(int a[MAX_M][MAX_N], int m, int n) {
    printf("Cac phan tu cuc dai:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int laCucDai = 1;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    if (di == 0 && dj == 0) continue;
                    int ni = i + di, nj = j + dj;
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && a[ni][nj] >= a[i][j]) {
                        laCucDai = 0;
                        break;
                    }
                }
                if (!laCucDai) break;
            }
            if (laCucDai) printf("%d ", a[i][j]);
        }
    }
    printf("\n");
}
//Câu 6
void timHoangHau(int a[MAX_M][MAX_N], int m, int n) {
    printf("Cac phan tu hoang hau:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int laHoangHau = 1;
            for (int k = 0; k < n; k++) {
                if (a[i][k] > a[i][j]) {
                    laHoangHau = 0;
                    break;
                }
            }
            for (int k = 0; k < m; k++) {
                if (a[k][j] > a[i][j]) {
                    laHoangHau = 0;
                    break;
                }
            }
            if (laHoangHau) printf("%d ", a[i][j]);
        }
    }
    printf("\n");
}
//Câu 7
void timYenNgua(int a[MAX_M][MAX_N], int m, int n) {
    printf("Cac phan tu yen ngua:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int laYenNgua = 1;
            for (int k = 0; k < n; k++) {
                if (a[i][k] < a[i][j]) {
                    laYenNgua = 0;
                    break;
                }
            }
            for (int k = 0; k < m; k++) {
                if (a[k][j] > a[i][j]) {
                    laYenNgua = 0;
                    break;
                }
            }
            if (laYenNgua) printf("%d ", a[i][j]);
        }
    }
    printf("\n");
}
//Câu 8
void xuatDongChan(int a[MAX_M][MAX_N], int m, int n) {
    printf("Cac dong chi chua so chan:\n");
    for (int i = 0; i < m; i++) {
        int dongChan = 1;
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 != 0) {
                dongChan = 0;
                break;
            }
        }
        if (dongChan) {
            for (int j = 0; j < n; j++) {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
        else
        {
            printf("Khong tim thay dong chua so chan.\n");
        }
    }
}

void sapXepTang(int a[MAX_M][MAX_N], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (a[i][j] > a[i][k]) {
                    int temp = a[i][j];
                    a[i][j] = a[i][k];
                    a[i][k] = temp;
                }
            }
        }
    }
    printf("Mang sau khi sap xep tang theo tung dong:\n");
    xuatMang(a, m, n);
}

int main() {
    int a[MAX_M][MAX_N], m, n, k;
    srand(time(NULL));

    printf("Nhap so dong m: ");
    scanf_s("%d", &m);
    printf("Nhap so cot n: ");
    scanf_s("%d", &n);
    printf("Nhap gia tri lon nhat k: ");
    scanf_s("%d", &k);

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Tao va xuat mang\n");
        printf("2. Tinh tong tung dong\n");
        printf("3. Tim phan tu lon nhat tren tung cot\n");
        printf("4. Xuat cac phan tu bien\n");
        printf("5. Tim cac phan tu cuc dai\n");
        printf("6. Tim cac phan tu hoang hau\n");
        printf("7. Tim cac phan tu yen ngua\n");
        printf("8. Xuat cac dong chi chua so chan\n");
        printf("9. Sap xep mang tang theo tung dong\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            taoMang(a, m, n, k);
            xuatMang(a, m, n);
            break;
        case 2:
            tinhTongDong(a, m, n);
            break;
        case 3:
            timMaxCot(a, m, n);
            break;
        case 4:
            xuatBien(a, m, n);
            break;
        case 5:
            timCucDai(a, m, n);
            break;
        case 6:
            timHoangHau(a, m, n);
            break;
        case 7:
            timYenNgua(a, m, n);
            break;
        case 8:
            xuatDongChan(a, m, n);
            break;
        case 9:
            sapXepTang(a, m, n);
            break;
        case 0:
            printf("Tam biet!\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 0);

    return 0;
}