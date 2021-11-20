#include<iostream>
#include<vector>
using namespace std;

template<typename T>
auto partition(typename vector<T>::iterator begin, typename <vector<T>::iterator end){

    auto pivot_val= *begin;
    auto left_iter = begin + 1;
    auto right_iter = end;

    while(true){

        while(*left_iter <= pivot_val && distance(left_iter, right_iter) > 0)
            left_iter++;

        while(*right_iter > pivot_val && distance(left_iter, right_iter) > 0)
            right_iter--;

        if(left_iter == right_iter)
            break;
        else
            iter_swap(left_iter, right_iter);
    }

    if(pivot_val > *right_iter)
        iter_swap(begin. right_iter);

    return right_iter;
}

template<typename T>
void quick_sort(typename vector<T>:: iterator begin, typename vector<T>:: iterator last){

    if(distance(begin, last) >= 1){

        auto partition_iter = partition<T>(begin, last);

        quick_sort<T>(begin, partition_iter - 1);
        quick_sort<T>(partition_iter, last);
    }

}

