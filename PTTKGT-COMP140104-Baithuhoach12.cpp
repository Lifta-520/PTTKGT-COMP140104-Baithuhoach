// Ten: Ho Kim Ngan
// MSSV: 47.01.103.070

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

#define INF std::numeric_limits<int>::max()

// Cấu trúc đỉnh
struct Vertex {
    int id;
    int distance;
};

// So sánh theo khoảng cách tăng dần
struct CompareVertex {
    bool operator()(const Vertex& v1, const Vertex& v2) {
        return v1.distance > v2.distance;
    }
};

// Hàm tìm đường đi ngắn nhất từ đỉnh xuất phát đến các đỉnh còn lại
void dijkstra(const std::vector<std::vector<std::pair<int, int>>>& graph, int source, std::vector<int>& distances) {
    int numVertices = graph.size();

    // Khởi tạo khoảng cách ban đầu
    distances.assign(numVertices, INF);
    distances[source] = 0;

    // Hàng đợi ưu tiên lưu trữ các đỉnh theo khoảng cách tăng dần
    std::priority_queue<Vertex, std::vector<Vertex>, CompareVertex> pq;
    pq.push({ source, 0 });

    while (!pq.empty()) {
        int u = pq.top().id;
        pq.pop();

        // Duyệt qua các đỉnh kề của đỉnh u
        for (const std::pair<int, int>& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // Cập nhật khoảng cách nếu tìm thấy đường đi ngắn hơn
            if (distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                pq.push({ v, distances[v] });
            }
        }
    }
}

int main() {
    int numVertices = 6;
    int source = 0; // Đỉnh xuất phát

    // Biểu đồ (đồ thị) có trọng số
    std::vector<std::vector<std::pair<int, int>>> graph(numVertices);

    // Thêm các cạnh và trọng số
    graph[0].push_back({ 1, 2 });
    graph[0].push_back({ 2, 5 });
    graph[1].push_back({ 2, 2 });
    graph[1].push_back({ 3, 1 });
    graph[2].push_back({ 3, 3 });
    graph[2].push_back({ 4, 1 });
    graph[3].push_back({ 4, 4 });
    graph[3].push_back({ 5, 3 });
    graph[4].push_back({ 5, 1 });

    std::vector<int> distances(numVertices);

    // Tìm đường đi
    dijkstra(graph, source, distances);

    // In đường đi ngắn nhất từ đỉnh xuất phát đến các đỉnh còn lại
    std::cout << "Duong di ngan nhat xuat phat tu dinh " << source << ":" << std::endl;
    for (int i = 0; i < numVertices; ++i) {
        std::cout << "Dinh  " << i << ": ";
        if (distances[i] == INF) {
            std::cout << "Not reachable" << std::endl;
        }
        else {
            std::cout << distances[i] << std::endl;
        }
    }

    return 0;
}


// Hướng dẫn thực thi chương trình :
//Ta chỉ cần biên dịch và thực thi chương trình, chương trình sẽ cho ra kết quả :
/*
Duong di ngan nhat xuat phat tu dinh 0:
Dinh  0: 0
Dinh  1: 2
Dinh  2: 4
Dinh  3: 3
Dinh  4: 5
Dinh  5: 6
*/