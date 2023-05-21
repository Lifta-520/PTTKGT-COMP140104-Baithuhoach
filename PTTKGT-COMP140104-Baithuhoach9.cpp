// Ten: Ho Kim Ngan
// MSSV: 47.01.103.070

#include <iostream>
#include <vector>

// Hàm nhân hai ma trận
std::vector<std::vector<int>> multiplyMatrix(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2) {
    int rows1 = matrix1.size();
    int cols1 = matrix1[0].size();
    int rows2 = matrix2.size();
    int cols2 = matrix2[0].size();

    // Kiểm tra kích thước ma trận đầu vào
    if (cols1 != rows2) {
        std::cout << "Loi: Khong the nhan hai ma tran!" << std::endl;
        return std::vector<std::vector<int>>();
    }

    // Khởi tạo ma trận kết quả với kích thước phù hợp
    std::vector<std::vector<int>> result(rows1, std::vector<int>(cols2, 0));

    // Thực hiện phép nhân ma trận
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

// Hàm in ma trận
void printMatrix(const std::vector<std::vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    // Khởi tạo các ma trận đầu vào
    std::vector<std::vector<int>> matrix1 = { {1, 2, 3}, {4, 5, 6} };
    std::vector<std::vector<int>> matrix2 = { {7, 8}, {9, 10}, {11, 12} };

    // Nhân hai ma trận
    std::vector<std::vector<int>> result = multiplyMatrix(matrix1, matrix2);

    // In ma trận kết quả
    std::cout << "Ma tran ket qua:" << std::endl;
    printMatrix(result);

    return 0;
}


// Hướng dẫn thực thi chương trình :
//Ta chỉ cần biên dịch và thực thi chương trình, chương trình sẽ cho ra kết quả :
/*
Ma tran ket qua:
58 64
139 154
*/