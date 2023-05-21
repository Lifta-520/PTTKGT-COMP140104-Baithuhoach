// Ten: Ho Kim Ngan
// MSSV: 47.01.103.070

#include <iostream>
#include <vector>
#include <string>

// Hàm tìm độ dài chuỗi chung dài nhất (LCS)
int longestCommonSubsequence(const std::string& str1, const std::string& str2) {
    int m = str1.length();
    int n = str2.length();

    // Khởi tạo bảng lưu trữ độ dài LCS
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    // Xây dựng bảng dp
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    std::string str1 = "ABCDEF";
    std::string str2 = "AEDBF";

    int length = longestCommonSubsequence(str1, str2);

    std::cout << "Do dai chuoi chung dai nhat: " << length << std::endl;

    return 0;
}


// Hướng dẫn thực thi chương trình :
//Ta chỉ cần biên dịch và thực thi chương trình, chương trình sẽ cho ra kết quả:
//Do dai chuoi chung dai nhat: 3