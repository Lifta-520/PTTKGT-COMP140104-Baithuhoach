// Ten: Ho Kim Ngan
// MSSV: 47.01.103.070

#include <iostream>
#include <vector>
#include <limits>

#define INF std::numeric_limits<int>::max()

// Hàm tìm đường đi ngắn nhất bằng thuật toán Floyd-Warshall
void floydWarshall(const std::vector<std::vector<int>>& graph, std::vector<std::vector<int>>& shortestPaths) {
    int numVertices = graph.size();

    // Khởi tạo ma trận đường đi ngắn nhất ban đầu bằng ma trận trọng số của đồ thị
    shortestPaths = graph;

    // Thực hiện thuật toán Floyd-Warshall
    for (int k = 0; k < numVertices; ++k) {
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                // Kiểm tra nếu tồn tại đường đi từ i đến j thông qua đỉnh k ngắn hơn đường đi hiện tại
                if (shortestPaths[i][k] != INF && shortestPaths[k][j] != INF && shortestPaths[i][k] + shortestPaths[k][j] < shortestPaths[i][j]) {
                    shortestPaths[i][j] = shortestPaths[i][k] + shortestPaths[k][j];
                }
            }
        }
    }
}

int main() {
    int numVertices = 4;

    // Biểu đồ (đồ thị) có trọng số bằng ma trận
    std::vector<std::vector<int>> graph = {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF, 0}
    };

    std::vector<std::vector<int>> shortestPaths;

    // Tìm đường đi ngắn nhất bằng thuật toán Floyd-Warshall
    floydWarshall(graph, shortestPaths);

    // In ma trận đường đi ngắn nhất
    std::cout << "Duong di ngan nhat giua cac dinh:" << std::endl;
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            if (shortestPaths[i][j] == INF) {
                std::cout << "INF\t";
            }
            else {
                std::cout << shortestPaths[i][j] << "\t";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}


// Hướng dẫn thực thi chương trình :
//Ta chỉ cần biên dịch và thực thi chương trình, chương trình sẽ cho ra kết quả :
/*
Duong di ngan nhat giua cac dinh:
0       3       5       6
5       0       2       3
3       6       0       1
2       5       7       0
*/