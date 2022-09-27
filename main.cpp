#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
#include <random>
#include <chrono>

int main() {

    constexpr size_t size=100'000;
    std::vector<int> data1(size);
    std::vector<int> data2(size);

    std::random_device rd;
    std::mt19937_64 mt{rd()};
    std::uniform_int_distribution<> dist(0,100);
    
    auto t1=std::chrono::high_resolution_clock::now();
    //Standard
    std::generate(data1.begin(),data1.end(),[&mt,&dist](){return dist(mt);});
    std::sort(data1.begin(),data1.end());

    auto t2=std::chrono::high_resolution_clock::now();

    std::cout<<"std::generate : ";
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()<<" ms";
    std::cout <<"\n";



    auto t3=std::chrono::high_resolution_clock::now();
    //RANGES
    std::ranges::generate(data2,[&dist,&mt](){return dist(mt);});
    std::ranges::sort(data2);

    auto t4=std::chrono::high_resolution_clock::now();
  
    std::cout<<"std::ranges::generate : ";
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(t4-t3).count()<<" ms";
    std::cout <<"\n";
}
