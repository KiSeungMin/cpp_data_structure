#include<deque>
#include<iostream>
using namespace std;

int main(){
	
	deque<int>deq={1,2,3,4,5};
	
	deq.push_front(0);
	deq.push_back(6);
	deq.insert(deq.begin() + 2 , 10);
	deq.pop_back();
	deq.pop_front();
	deq.erase(deq.begin() + 1);
	deq.erase(deq.begin() + 3, deq.end());
	
	for(auto it : deq){
		cout<<it<<" ";
	}
	
	return 0;
}
