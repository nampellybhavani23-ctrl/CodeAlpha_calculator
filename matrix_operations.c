
#include <stdio.h>

void addMatrices(int a[10][10], int b[10][10], int r, int c) {
    int i, j;

    printf("\nMatrix Addition:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%d ", a[i][j] + b[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrices(int a[10][10], int b[10][10],
                      int r1, int c1, int c2) {
    int i, j, k, sum;

    printf("\nMatrix Multiplication:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            sum = 0;
            for (k = 0; k < c1; k++) {
                sum += a[i][k] * b[k][j];
            }
            printf("%d ", sum);
        }
        printf("\n");
    }
}

void transposeMatrix(int a[10][10], int r, int c) {
    int i, j;

    printf("\nMatrix Transpose:\n");
    for (j = 0; j < c; j++) {
        for (i = 0; i < r; i++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a[10][10], b[10][10];
    int r, c, r2, c2;
    int i, j, choice;

    printf("===== MATRIX OPERATIONS =====\n");

    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d", &r, &c);

    if (r < 1 || r > 10 || c < 1 || c > 10) {
        printf("Invalid matrix size.\n");
        return 1;
    }

    printf("Enter elements of Matrix A:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nChoose an operation:\n");
    printf("1. Matrix Addition\n");
    printf("2. Matrix Multiplication\n");
    printf("3. Matrix Transpose\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1 || choice == 2) {
        printf("Enter rows and columns of Matrix B: ");
        scanf("%d %d", &r2, &c2);

        if (r2 < 1 || r2 > 10 || c2 < 1 || c2 > 10) {
            printf("Invalid matrix size.\n");
            return 1;
        }

        printf("Enter elements of Matrix B:\n");
        for (i = 0; i < r2; i++) {
            for (j = 0; j < c2; j++) {
                scanf("%d", &b[i][j]);
            }
        }
    }

    switch (choice) {
        case 1:
            if (r == r2 && c == c2) {
                addMatrices(a, b, r, c);
            } else {
                printf("Addition requires equal matrix sizes.\n");
            }
            break;

        case 2:
            if (c == r2) {
                multiplyMatrices(a, b, r, c, c2);
            } else {
                printf("Columns of A must equal rows of B.\n");
            }
            break;

        case 3:
            transposeMatrix(a, r, c);
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
