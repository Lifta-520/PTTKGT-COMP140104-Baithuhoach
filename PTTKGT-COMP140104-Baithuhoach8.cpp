// Ten: Ho Kim Ngan
// MSSV: 47.01.103.070

#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    int weight;
    int value;
};

// Hàm tính giá trị tối đa có thể đạt được trong balo1
int balo1(const std::vector<Item>& items, int capacity) {
    int n = items.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            if (items[i - 1].weight <= w) {
                dp[i][w] = std::max(items[i - 1].value + dp[i - 1][w - items[i - 1].weight], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    std::vector<Item> items = {{2, 3}, {3, 4}, {4, 5}, {5, 6}};
    int capacity = 8;

    int maxValue = balo1(items, capacity);

    std::cout << "Gia tri toi da co the dat duoc: " << maxValue << std::endl;

    return 0;
}


// Hướng dẫn thực thi chương trình :
//Ta chỉ cần biên dịch và thực thi chương trình, chương trình sẽ cho ra kết quả : 
// Gia tri toi da co the dat duoc: 10
