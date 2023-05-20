// Ten: Ho Kim Ngan
// MSSV: 47.01.103.070

#include <iostream>
#include <vector>

// Hàm cộng hai ma trận
std::vector<std::vector<int>> matrixAddition(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    int n = A.size();
    std::vector<std::vector<int>> result(n, std::vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    return result;
}

// Hàm trừ hai ma trận
std::vector<std::vector<int>> matrixSubtraction(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    int n = A.size();
    std::vector<std::vector<int>> result(n, std::vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }

    return result;
}

// Hàm nhân ma trận theo giải thuật Strassen
std::vector<std::vector<int>> strassenMultiplication(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    int n = A.size();

    // Trường hợp cơ sở: ma trận 1x1
    if (n == 1) {
        std::vector<std::vector<int>> C(1, std::vector<int>(1, 0));
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    // Chia ma trận A và B thành các ma trận con
    int halfSize = n / 2;
    std::vector<std::vector<int>> A11(halfSize, std::vector<int>(halfSize, 0));
    std::vector<std::vector<int>> A12(halfSize, std::vector<int>(halfSize, 0));
    std::vector<std::vector<int>> A21(halfSize, std::vector<int>(halfSize, 0));
    std::vector<std::vector<int>> A22(halfSize, std::vector<int>(halfSize, 0));
    std::vector<std::vector<int>> B11(halfSize, std::vector<int>(halfSize, 0));
    std::vector<std::vector<int>> B12(halfSize, std::vector<int>(halfSize, 0));
    std::vector<std::vector<int>> B21(halfSize, std::vector<int>(halfSize, 0));
    std::vector<std::vector<int>> B22(halfSize, std::vector<int>(halfSize, 0));

    for (int i = 0; i < halfSize; i++) {
        for (int j = 0; j < halfSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + halfSize];
            A21[i][j] = A[i + halfSize][j];
            A22[i][j] = A[i + halfSize][j + halfSize];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + halfSize];
            B21[i][j] = B[i + halfSize][j];
            B22[i][j] = B[i + halfSize][j + halfSize];
        }
    }
    // Tính các ma trận con theo công thức Strassen
    std::vector<std::vector<int>> M1 = strassenMultiplication(matrixAddition(A11, A22), matrixAddition(B11, B22));
    std::vector<std::vector<int>> M2 = strassenMultiplication(matrixAddition(A21, A22), B11);
    std::vector<std::vector<int>> M3 = strassenMultiplication(A11, matrixSubtraction(B12, B22));
    std::vector<std::vector<int>> M4 = strassenMultiplication(A22, matrixSubtraction(B21, B11));
    std::vector<std::vector<int>> M5 = strassenMultiplication(matrixAddition(A11, A12), B22);
    std::vector<std::vector<int>> M6 = strassenMultiplication(matrixSubtraction(A21, A11), matrixAddition(B11, B12));
    std::vector<std::vector<int>> M7 = strassenMultiplication(matrixSubtraction(A12, A22), matrixAddition(B21, B22));

    // Tính các ma trận kết quả theo công thức Strassen
    std::vector<std::vector<int>> C11 = matrixAddition(matrixSubtraction(matrixAddition(M1, M4), M5), M7);
    std::vector<std::vector<int>> C12 = matrixAddition(M3, M5);
    std::vector<std::vector<int>> C21 = matrixAddition(M2, M4);
    std::vector<std::vector<int>> C22 = matrixAddition(matrixSubtraction(matrixAddition(M1, M3), M2), M6);

    // Tạo ma trận kết quả C bằng cách ghép các ma trận con
    std::vector<std::vector<int>> C(n, std::vector<int>(n, 0));
    for (int i = 0; i < halfSize; i++) {
        for (int j = 0; j < halfSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + halfSize] = C12[i][j];
            C[i + halfSize][j] = C21[i][j];
            C[i + halfSize][j + halfSize] = C22[i][j];
        }
    }

    return C;
}

int main() {
    std::vector<std::vector<int>> A = { {1, 2}, {3, 4} }; // Ma trận A
    std::vector<std::vector<int>> B = { {5, 6}, {7, 8} }; // Ma trận B
    std::vector<std::vector<int>> C = strassenMultiplication(A, B);  // Nhân ma trận A và B

    std::cout << "Ma tran C (A x B):" << std::endl;
    for (const auto& row : C) {
        for (int element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

//Hướng dẫn thực thi chương trình:
//Ta chỉ cần biên dịch và thực thi chương trình, chương trình sẽ cho ra kết quả : 
//Ma tran C (AxB)=
// 19 22
// 43 50
