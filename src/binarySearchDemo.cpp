#include<iostream>
#include<vector>
#include<algorithm>
#include<chrono>
#include<random>
using namespace std;

bool binary_search(int N, vector<int>& S){

    auto first=S.begin();
    auto last=S.end();

    while(true){

        auto range_length=distance(first, last);
        auto mid_element_index=first+floor(range_length / 2);
        auto mid_element = *(first + mid_element_index);

        if(mid_element == N)
            return true;

        else if(mid_element > N)
            advance(last, mid_element_index);
        
        if(mid_element < N)
            advance(first, mid_element_index);

        if(range_length == 1)
            return false;
    }
}