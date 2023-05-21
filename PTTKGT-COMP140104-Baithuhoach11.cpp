// Ten: Ho Kim Ngan
// MSSV: 47.01.103.070

#include <iostream>
#include <vector>
#include <algorithm>

struct Job {
    int id;
    int deadline;
    int profit;
};

bool compareProfit(const Job& job1, const Job& job2) {
    return job1.profit > job2.profit;
}

int scheduleJobs(const std::vector<Job>& jobs) {
    int maxProfit = 0;
    int maxDeadline = 0;

    for (const Job& job : jobs) {
        maxDeadline = std::max(maxDeadline, job.deadline);
    }

    std::vector<Job> sortedJobs = jobs;
    std::sort(sortedJobs.begin(), sortedJobs.end(), compareProfit);

    std::vector<bool> slot(maxDeadline, false);

    for (const Job& job : sortedJobs) {
        for (int i = job.deadline - 1; i >= 0; --i) {
            if (!slot[i]) {
                slot[i] = true;
                maxProfit += job.profit;
                break;
            }
        }
    }

    return maxProfit;
}

int main() {
    std::vector<Job> jobs = {
        {1, 2, 100},
        {2, 1, 50},
        {3, 2, 75},
        {4, 1, 200},
    };

    int maxProfit = scheduleJobs(jobs);

    std::cout << "Loi nhuan toi da: " << maxProfit << std::endl;

    return 0;
}


// Hướng dẫn thực thi chương trình :
//Ta chỉ cần biên dịch và thực thi chương trình, chương trình sẽ cho ra kết quả :
//Loi nhuan toi da: 300