// Ten: Ho Kim Ngan
// MSSV: 47.01.103.070

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// Hàm hoán đổi hai phần tử
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Chọn phần tử cuối cùng làm pivot
    int i = low - 1;  // Vị trí của phần tử nhỏ hơn pivot

    for (int j = low; j <= high - 1; j++) {
        // Nếu phần tử hiện tại nhỏ hơn hoặc bằng pivot, hoán đổi nó với phần tử đứng sau vị trí i
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);  // Hoán đổi pivot với phần tử đầu tiên lớn hơn pivot
    return i + 1;  // Trả về vị trí của pivot sau khi được đặt đúng vị trí
}
// Hàm chọn ngẫu nhiên một vị trí mốc và hoán đổi phần tử tại vị trí đó với phần tử cuối cùng
int randomPartition(std::vector<int>& arr, int low, int high) {
    srand(time(nullptr));  // Thiết lập hạt giống cho hàm ngẫu nhiên
    int randomIndex = low + rand() % (high - low + 1);  // Chọn vị trí mốc ngẫu nhiên
    swap(arr[randomIndex], arr[high]);  // Hoán đổi phần tử mốc với phần tử cuối cùng
    return partition(arr, low, high);  // Gọi hàm partition sử dụng phần tử mốc đã chọn
}

// Hàm chia mảng và sắp xếp đối với một phần tử chốt (pivot)


// Hàm sắp xếp QuickSort
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = randomPartition(arr, low, high);  // Chọn vị trí mốc ngẫu nhiên

        // Đệ quy sắp xếp các phần tử trước và sau pivot
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Hàm in mảng
void printArray(const std::vector<int>& arr) {
    for (int element : arr) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {9, 5, 1, 8, 3, 2, 7}; // Mảng đầu vào
    std::cout << "Mang ban dau: ";
    printArray(arr);

    int n = arr.size();
    quickSort(arr, 0, n - 1);  // Sắp xếp mảng

    std::cout << "Mang sau khi sap xep: ";
    printArray(arr);

    return 0;
}

//Hướng dẫn thực thi chương trình:
//Ta chỉ cần biên dịch và thực thi chương trình, chương trình sẽ cho ra kết quả :
/*Mang ban dau: 9 5 1 8 3 2 7
Mang sau khi sap xep: 1 2 3 5 7 8 9*/
