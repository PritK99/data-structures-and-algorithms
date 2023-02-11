#include <iostream>
#include <chrono>
#include <ctime>

int main()
{
    // Using time point and system_clock
    std::chrono::time_point<std::chrono::system_clock> start, end;
    long long int a = 50000000;
    long long int b = 10000000;

    start = std::chrono::system_clock::now();
    std::cout << "Addition: " << a + b << '\n';
    end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count()*1000 << "s\n";

    start = std::chrono::system_clock::now();
    std::cout << "Multiplication: " << a * b << '\n';
    end = std::chrono::system_clock::now();

    elapsed_seconds = end - start;
    end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count()*1000 << "s\n";
}