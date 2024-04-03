#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>

using namespace std;

void count1m(int id, struct tm* ptm)
{
    time_t targetTime = mktime(ptm);
   // std::this_thread::sleep_until(std::chrono::system_clock::from_time_t(targetTime));

    for (int i = 0; i < 1000000; ++i)
    {
    }
    cout << id;
}

int main()
{
    time_t tt = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    struct tm* ptm = localtime(&tt);

    char timeStr[9];
    strftime(timeStr, sizeof(timeStr), "%H:%M:%S", ptm);

    cout << "Time is now " << timeStr << endl;

    ptm->tm_min++; // New time is the next minute
    ptm->tm_sec = 0;

    strftime(timeStr, sizeof(timeStr), "%H:%M:%S", ptm);

    cout << "Race will start at " << timeStr << endl;

    std::thread threads[10];
    for (int i = 0; i < 10; i++)
        threads[i] = std::thread(count1m, i, ptm);

    for (int i = 0; i < 10; i++)
        threads[i].join();

    cout << endl;
    return 0;
}
