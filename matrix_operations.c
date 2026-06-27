/*
 * ============================================
 *   Matrix Operations Program
 *   CodeAlpha C Programming Internship
 *   Task 2: Matrix Operations
 * ============================================
 *   Features:
 *   1. Matrix Addition
 *   2. Matrix Multiplication
 *   3. Matrix Transpose
 * ============================================
 */

#include <stdio.h>

#define MAX 10  // Maximum matrix size

/* ---- Function Prototypes ---- */
void inputMatrix(int matrix[MAX][MAX], int rows, int cols, char name);
void displayMatrix(int matrix[MAX][MAX], int rows, int cols);
void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int r1, int c1, int c2);
void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void printSeparator();

/* ============================================
   MAIN FUNCTION
   ============================================ */
int main() {
    int choice;
    int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX];
    int rows, cols, r1, c1, r2, c2;
    printf("       MATRIX OPERATIONS PROGRAM      \n");
    printf("         CodeAlpha Internship          \n");

    int running = 1;

    while (running) {
        printf("             MAIN MENU                \n");;
        printf("  1. Matrix Addition                  \n");
        printf("  2. Matrix Multiplication            \n");
        printf("  3. Matrix Transpose                 \n");
        printf("  4. Exit                             \n");
        printf("  Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            /* ---- MATRIX ADDITION ---- */
            case 1:
                printSeparator();
                printf("  [ MATRIX ADDITION ]\n");
                printSeparator();

                printf("\n  Enter number of rows (max %d): ", MAX);
                scanf("%d", &rows);
                printf("  Enter number of columns (max %d): ", MAX);
                scanf("%d", &cols);

                // Validate input
                if (rows <= 0 || cols <= 0 || rows > MAX || cols > MAX) {
                    printf("\n  ❌ Invalid dimensions! Please enter values between 1 and %d.\n", MAX);
                    break;
                }

                printf("\n  Enter elements of Matrix A (%dx%d):\n", rows, cols);
                inputMatrix(A, rows, cols, 'A');

                printf("\n  Enter elements of Matrix B (%dx%d):\n", rows, cols);
                inputMatrix(B, rows, cols, 'B');

                addMatrices(A, B, result, rows, cols);

                printf("\n  Matrix A:\n");
                displayMatrix(A, rows, cols);

                printf("\n  Matrix B:\n");
                displayMatrix(B, rows, cols);

                printf("\n  Result (A + B):\n");
                displayMatrix(result, rows, cols);
                break;

            /* ---- MATRIX MULTIPLICATION ---- */
            case 2:
                printSeparator();
                printf("  [ MATRIX MULTIPLICATION ]\n");
                printSeparator();

                printf("\n  Enter rows of Matrix A: ");
                scanf("%d", &r1);
                printf("  Enter columns of Matrix A (= rows of Matrix B): ");
                scanf("%d", &c1);
                printf("  Enter columns of Matrix B: ");
                scanf("%d", &c2);

                // Validate input
                if (r1 <= 0 || c1 <= 0 || c2 <= 0 || r1 > MAX || c1 > MAX || c2 > MAX) {
                    printf("\n  ❌ Invalid dimensions! Please enter values between 1 and %d.\n", MAX);
                    break;
                }

                r2 = c1; // rows of B must equal cols of A

                printf("\n  Enter elements of Matrix A (%dx%d):\n", r1, c1);
                inputMatrix(A, r1, c1, 'A');

                printf("\n  Enter elements of Matrix B (%dx%d):\n", r2, c2);
                inputMatrix(B, r2, c2, 'B');

                multiplyMatrices(A, B, result, r1, c1, c2);

                printf("\n  Matrix A:\n");
                displayMatrix(A, r1, c1);

                printf("\n  Matrix B:\n");
                displayMatrix(B, r2, c2);

                printf("\n  Result (A x B):\n");
                displayMatrix(result, r1, c2);
                break;

            /* ---- MATRIX TRANSPOSE ---- */
            case 3:
                printSeparator();
                printf("  [ MATRIX TRANSPOSE ]\n");
                printSeparator();

                printf("\n  Enter number of rows (max %d): ", MAX);
                scanf("%d", &rows);
                printf("  Enter number of columns (max %d): ", MAX);
                scanf("%d", &cols);

                // Validate input
                if (rows <= 0 || cols <= 0 || rows > MAX || cols > MAX) {
                    printf("\n  ❌ Invalid dimensions! Please enter values between 1 and %d.\n", MAX);
                    break;
                }

                printf("\n  Enter elements of Matrix A (%dx%d):\n", rows, cols);
                inputMatrix(A, rows, cols, 'A');

                transposeMatrix(A, result, rows, cols);

                printf("\n  Original Matrix A:\n");
                displayMatrix(A, rows, cols);

                printf("\n  Transpose of A:\n");
                displayMatrix(result, cols, rows); // Note: rows and cols are swapped
                break;

            /* ---- EXIT ---- */
            case 4:
                printf("\n  ✅ Thank you for using Matrix Operations Program!\n");
                printf("  Exiting...\n\n");
                running = 0;
                break;

            default:
                printf("\n  ❌ Invalid choice! Please select between 1 and 4.\n");
        }
    }

    return 0;
}

/* ============================================
   FUNCTION: Input Matrix Elements
   ============================================ */
void inputMatrix(int matrix[MAX][MAX], int rows, int cols, char name) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("    %c[%d][%d] = ", name, i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

/* ============================================
   FUNCTION: Display Matrix
   ============================================ */
void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("  ┌");
    for (int j = 0; j < cols; j++) printf("────────");
    printf("┐\n");

    for (int i = 0; i < rows; i++) {
        printf("  │");
        for (int j = 0; j < cols; j++) {
            printf("  %4d  ", matrix[i][j]);
        }
        printf("│\n");
    }

    printf("  └");
    for (int j = 0; j < cols; j++) printf("────────");
    printf("┘\n");
}

/* ============================================
   FUNCTION: Matrix Addition
   Formula: result[i][j] = A[i][j] + B[i][j]
   ============================================ */
void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

/* ============================================
   FUNCTION: Matrix Multiplication
   Formula: result[i][j] = sum of A[i][k] * B[k][j]
   ============================================ */
void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int r1, int c1, int c2) {
    // Initialize result matrix to 0
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            result[i][j] = 0;

    // Multiply
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

/* ============================================
   FUNCTION: Matrix Transpose
   Formula: result[j][i] = A[i][j]
   ============================================ */
void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

/* ============================================
   FUNCTION: Print Separator Line
   ============================================ */
void printSeparator() {
    printf("\n  ==============================\n");
}
