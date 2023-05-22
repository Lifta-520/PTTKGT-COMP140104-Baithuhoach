//Ten: Ho Kim Ngan
//MSSV:47.01.103.070
//Huong dan thuc thi: Ta chỉ cần biên dịch và thực thi, chương trình sẽ cho ra kết quả: -2x^0 + 14x^1 + -27x^2 + 13x^3 + 5x^4 + -2x^5 + 0x^6

#include <iostream>
#include <vector>

struct Polynomial {
    int degree;
    int* coefficients;

    Polynomial() : degree(0), coefficients(nullptr) {}

    Polynomial(const std::vector<int>& coeffs) : degree(coeffs.size() - 1) {
        coefficients = new int[degree + 1];
        for (int i = 0; i <= degree; ++i) {
            coefficients[i] = coeffs[i];
        }
    }

    ~Polynomial() {
        delete[] coefficients;
    }

    int getDegree() const {
        return degree;
    }

    int getCoefficient(int power) const {
        if (power <= degree) {
            return coefficients[power];
        }
        return 0;
    }
};

Polynomial addPolynomials(const Polynomial& p1, const Polynomial& p2) {
    int degree1 = p1.getDegree();
    int degree2 = p2.getDegree();
    int maxDegree = std::max(degree1, degree2);

    std::vector<int> resultCoeffs(maxDegree + 1);

    for (int i = 0; i <= degree1; ++i) {
        resultCoeffs[i] += p1.getCoefficient(i);
    }

    for (int i = 0; i <= degree2; ++i) {
        resultCoeffs[i] += p2.getCoefficient(i);
    }

    return Polynomial(resultCoeffs);
}

Polynomial subtractPolynomials(const Polynomial& p1, const Polynomial& p2) {
    int degree1 = p1.getDegree();
    int degree2 = p2.getDegree();
    int maxDegree = std::max(degree1, degree2);

    std::vector<int> resultCoeffs(maxDegree + 1);

    for (int i = 0; i <= degree1; ++i) {
        resultCoeffs[i] += p1.getCoefficient(i);
    }

    for (int i = 0; i <= degree2; ++i) {
        resultCoeffs[i] -= p2.getCoefficient(i);
    }

    return Polynomial(resultCoeffs);
}

Polynomial multiplyPolynomials(const Polynomial& p1, const Polynomial& p2) {
    int degree1 = p1.getDegree();
    int degree2 = p2.getDegree();
    int maxDegree = std::max(degree1, degree2);

    if (maxDegree <= 0) {
        std::vector<int> resultCoeffs(1);
        resultCoeffs[0] = p1.getCoefficient(0) * p2.getCoefficient(0);
        return Polynomial(resultCoeffs);
    }

    int resultDegree = 2 * maxDegree;
    std::vector<int> resultCoeffs(resultDegree + 1, 0);

    for (int i = 0; i <= degree1; ++i) {
        for (int j = 0; j <= degree2; ++j) {
            resultCoeffs[i + j] += p1.getCoefficient(i) * p2.getCoefficient(j);
        }
    }

    return Polynomial(resultCoeffs);
}

int main() {
    Polynomial p1({1, -5, 3, 2});
    Polynomial p2({-2, 4, -1});

    Polynomial result = multiplyPolynomials(p1, p2);

    std::cout << "Ket qua: ";
    for (int i = 0; i <= result.getDegree(); ++i) {
        std::cout << result.getCoefficient(i) << "x^" << i;
        if (i < result.getDegree()) {
            std::cout << " + ";
        }
    }
    std::cout << std::endl;

    return 0;
}
