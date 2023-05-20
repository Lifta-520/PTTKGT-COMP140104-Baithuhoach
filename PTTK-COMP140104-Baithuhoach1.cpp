﻿//Ten: Ho Kim Ngan - MSSV: 47.01.103.070
#include <iostream>
#include <vector>

// Hàm tính giá trị đa thức theo luật Horner
double horner(const std::vector<double>& coefficients, double x) {
    double result = 0.0;

    for (int i = coefficients.size() - 1; i >= 0; i--) {
        result = result * x + coefficients[i];
    }

    return result;
}

int main() {
    std::vector<double> coefficients = { 2.0, -3.0, 1.0 };  // Đa thức: 2x^2 - 3x + 1
    double x = 2.5;

    double value = horner(coefficients, x);
    std::cout << "Gia tri cua da thuc tai x = " << x << " la " << value << std::endl;

    return 0;
}
//Huong dan thuc thi: Ta chỉ cần biên dịch và thực thi chương trình, chương trình sẽ cho ra kết quả: 
//Gia tri da thuc tai x=2.5 la 0.75