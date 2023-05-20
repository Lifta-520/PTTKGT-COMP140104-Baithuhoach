//Ten: Ho Kim Ngan
//MSSV:47.01.103.070
//Huong dan thuc thi: Ta chỉ cần biên dịch và thực thi, chương trình sẽ cho ra kết quả: -2x^5 + 3x^4 - 9x^3 + 21x^2 -12x +2

#include <iostream>
#include <vector>

// Cấu trúc đa thức
struct Polynomial {
    std::vector<int> coefficients;

    Polynomial() {}

    Polynomial(const std::vector<int>& coeffs) : coefficients(coeffs) {}

    int degree() const {
        return coefficients.size() - 1;
    }
};

// Hàm cộng hai đa thức
Polynomial addPolynomials(const Polynomial& p1, const Polynomial& p2) {
    int degree1 = p1.degree();
    int degree2 = p2.degree();
    int maxDegree = std::max(degree1, degree2);

    std::vector<int> resultCoeffs(maxDegree + 1);

    for (int i = 0; i <= degree1; ++i) {
        resultCoeffs[i] += p1.coefficients[i];
    }

    for (int i = 0; i <= degree2; ++i) {
        resultCoeffs[i] += p2.coefficients[i];
    }

    return Polynomial(resultCoeffs);
}

// Hàm trừ hai đa thức
Polynomial subtractPolynomials(const Polynomial& p1, const Polynomial& p2) {
    int degree1 = p1.degree();
    int degree2 = p2.degree();
    int maxDegree = std::max(degree1, degree2);

    std::vector<int> resultCoeffs(maxDegree + 1);

    for (int i = 0; i <= degree1; ++i) {
        resultCoeffs[i] += p1.coefficients[i];
    }

    for (int i = 0; i <= degree2; ++i) {
        resultCoeffs[i] -= p2.coefficients[i];
    }

    return Polynomial(resultCoeffs);
}

// Hàm nhân hai đa thức theo giải thuật Strassen
Polynomial multiplyPolynomials(const Polynomial& p1, const Polynomial& p2) {
    int degree1 = p1.degree();
    int degree2 = p2.degree();
    int maxDegree = std::max(degree1, degree2);

    // Nếu bậc của đa thức nhỏ hơn hoặc bằng 0, ta có thể tính trực tiếp kết quả
    if (maxDegree <= 0) {
        std::vector<int> resultCoeffs(1);
        resultCoeffs[0] = p1.coefficients[0] * p2.coefficients[0];
        return Polynomial(resultCoeffs);
    }

    // Tính bậc của đa thức kết quả
    int resultDegree = 2 * maxDegree;

    // Mở rộng các đa thức ban đầu đến bậc của đa thức kết quả
    std::vector<int> p1Coeffs(resultDegree + 1, 0);
    std::vector<int> p2Coeffs(resultDegree + 1, 0);

    for (int i = 0; i <= degree1; ++i) {
        p1Coeffs[i] = p1.coefficients[i];
    }
    for (int i = 0; i <= degree2; ++i) {
        p2Coeffs[i] = p2.coefficients[i];
    }

    // Chia đa thức ban đầu thành các đa thức con
    int mid = maxDegree / 2;

    std::vector<int> p1LowCoeffs(p1Coeffs.begin(), p1Coeffs.begin() + mid + 1);
    std::vector<int> p1HighCoeffs(p1Coeffs.begin() + mid + 1, p1Coeffs.end());

    std::vector<int> p2LowCoeffs(p2Coeffs.begin(), p2Coeffs.begin() + mid + 1);
    std::vector<int> p2HighCoeffs(p2Coeffs.begin() + mid + 1, p2Coeffs.end());

    // Tính các đa thức con
    Polynomial p1Low(p1LowCoeffs);
    Polynomial p1High(p1HighCoeffs);
    Polynomial p2Low(p2LowCoeffs);
    Polynomial p2High(p2HighCoeffs);

    // Tính các đa thức con sau khi nhân với nhau
    Polynomial p1LowHigh = addPolynomials(p1Low, p1High);
    Polynomial p2LowHigh = addPolynomials(p2Low, p2High);

    Polynomial p1LowHighMul = multiplyPolynomials(p1LowHigh, p2LowHigh);
    Polynomial p1LowMul = multiplyPolynomials(p1Low, p2Low);
    Polynomial p1HighMul = multiplyPolynomials(p1High, p2High);

    // Tính đa thức kết quả
    Polynomial term1 = p1LowMul;
    Polynomial term2 = subtractPolynomials(subtractPolynomials(p1LowHighMul, p1LowMul), p1HighMul);
    Polynomial term3 = p1HighMul;

    // Tạo đa thức kết quả bằng cách ghép các đa thức con
    std::vector<int> resultCoeffs(resultDegree + 1, 0);

    for (int i = 0; i <= term1.degree(); ++i) {
        resultCoeffs[i] += term1.coefficients[i];
    }

    for (int i = 0; i <= term2.degree(); ++i) {
        resultCoeffs[mid + i + 1] += term2.coefficients[i];
    }

    for (int i = 0; i <= term3.degree(); ++i) {
        resultCoeffs[2 * mid + i + 1] += term3.coefficients[i];
    }

    return Polynomial(resultCoeffs);
}

int main() {
    // Đa thức P(x) = 2x^3 + 3x^2 - 5x + 1
    Polynomial p1({ 1, -5, 3, 2 });
    // Đa thức Q(x) = -x^2 + 4x - 2
    Polynomial p2({ -2, 4, -1 });

    // Nhân đa thức P và Q
    Polynomial result = multiplyPolynomials(p1, p2);

    // In đa thức kết quả
    std::cout << "Ket qua: ";
    for (int i = 0; i <= result.degree(); ++i) {
        std::cout << result.coefficients[i] << "x^" << i;
        if (i < result.degree()) {
            std::cout << " + ";
        }
    }
    std::cout << std::endl;
    return 0;
}
