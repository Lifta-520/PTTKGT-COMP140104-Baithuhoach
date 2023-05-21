// Ten: Ho Kim Ngan
// MSSV: 47.01.103.070

#include <iostream>
#include <vector>

// Hàm tính số cách đổi tiền
int coinChange(int amount, const std::vector<int>& coins) {
    int numCoins = coins.size();

    // Tạo bảng lưu trữ số cách đổi tiền cho mỗi số tiền từ 0 đến amount
    std::vector<int> dp(amount + 1, 0);

    // Khởi tạo giá trị ban đầu
    dp[0] = 1;

    // Duyệt qua tất cả các loại đồng xu
    for (int i = 0; i < numCoins; ++i) {
        int coin = coins[i];

        // Duyệt qua tất cả các số tiền từ coin đến amount
        for (int j = coin; j <= amount; ++j) {
            // Cộng dồn số cách đổi tiền từ các loại đồng xu trước đó
            dp[j] += dp[j - coin];
        }
    }

    // Trả về số cách đổi tiền cho số tiền amount
    return dp[amount];
}

int main() {
    int amount = 12; // Số tiền cần đổi
    std::vector<int> coins = { 1, 2, 5 }; // Các loại đồng xu

    int numWays = coinChange(amount, coins);

    std::cout << "So cach de doi tien: " << numWays << std::endl;

    return 0;
}


// Hướng dẫn thực thi chương trình :
//Ta chỉ cần biên dịch và thực thi chương trình, chương trình sẽ cho ra kết quả :
//So cach de doi tien: 13