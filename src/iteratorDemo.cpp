#include<iostream>
#include<forward_list>
#include<vector>
using namespace std;

int main(){
	
	vector<string>vec={"Lewis Hamilton", "Lewis Hamilton", "Nico Roseberg", "Sebastain Vettel", "Lewis Hamilton", "Sebastian Vettel", "Sebastiann Vettel", "Sebastiann Vettel", "Fernando Alonso"};
	
	auto it=vec.begin();
	cout<<"가장 최근 우승자: "<<it<<endl;
	
	it+=8;
	
	cout<<"8년 전 우승자: "<<it<<endl;
	
	advance(it, -3);
	cout<<"그 후 3년 뒤 우승자: "<<it<<endl;
	
	forward_list<string> fwd(vec.begin(), vec.end());
	
	auto it1=fwd.begin();
	cout<<"가장 최근 우승자: "<<it1<<endl;
	
	advance(it1, 5);
	cout<<"5년 전 우승자: "<<it1<<endl;
	
	return 0;
}
