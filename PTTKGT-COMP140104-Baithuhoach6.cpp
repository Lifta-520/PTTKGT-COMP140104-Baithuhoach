// Ten: Ho Kim Ngan
// MSSV: 47.01.103.070

#include <iostream>

// Hàm di chuyển đĩa từ cột nguồn đến cột đích
void moveDisk(int disk, char source, char destination) {
    std::cout << "Di chuyen dia " << disk << " tu cot " << source << " den cot " << destination << std::endl;
}

// Hàm thực hiện giải thuật Tháp Hà Nội
void towerOfHanoi(int disks, char source, char auxiliary, char destination) {
    if (disks == 1) {
        moveDisk(disks, source, destination);
    }
    else {
        // Di chuyển (n-1) đĩa từ cột nguồn đến cột phụ
        towerOfHanoi(disks - 1, source, destination, auxiliary);

        // Di chuyển đĩa còn lại từ cột nguồn đến cột đích
        moveDisk(disks, source, destination);

        // Di chuyển (n-1) đĩa từ cột phụ đến cột đích
        towerOfHanoi(disks - 1, auxiliary, source, destination);
    }
}

int main() {
    int disks = 3;  // Số đĩa ban đầu
    char source = 'A';  // Cột nguồn
    char auxiliary = 'B';  // Cột phụ
    char destination = 'C';  // Cột đích

    std::cout << "Giai thuat Thap Ha Noi:" << std::endl;
    towerOfHanoi(disks, source, auxiliary, destination);

    return 0;
}


// Hướng dẫn thực thi chương trình :
//Ta chỉ cần biên dịch và thực thi chương trình, chương trình sẽ cho ra kết quả : 
// Giai thuat Thap Ha Noi:
//Di chuyen dia 1 tu cot A den cot C
//Di chuyen dia 2 tu cot A den cot B
//Di chuyen dia 1 tu cot C den cot B
//Di chuyen dia 3 tu cot A den cot C
//Di chuyen dia 1 tu cot B den cot A
//Di chuyen dia 2 tu cot B den cot C
//Di chuyen dia 1 tu cot A den cot C
