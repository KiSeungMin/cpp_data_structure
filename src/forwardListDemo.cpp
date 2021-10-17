#include<iostream>
#include<string>
#include<forward_list>
using namespace std;

struct citizen{
	std::string name;
	int age;
}

ostream &operator<<(std::ostream& os, const citizen &c){
	return (os<<"["<<c.name<<", "<<c.age<<"]");
}

int main(){
	forward_list<citizen> citizens={
		{"Kim", 22}, {"Lee", 25}, {"Park", 18}, {"Jin", 16}
	};
	
	auto citizens_copy=citizens;
	
	cout<<"전체 시민들: ";
	for(const auto &c : citizens){
		cout<<"c"<<" ";
	}
	cout<<endl;
	
	citizens.remove_if([](const citizen &c){
		return (c.age < 19);
	});
	
	cout<<"투표권이 있는 시민들: ";
	for(const auto &c : citizens){
		cout<<c<< " ";
	}
	cout<<endl;
	
	citizens.copy.remove_if([](const citizen& c){
		return (c.age!=18);
	});
	
	cout<<"내년에 투표권이 생기는 시민들: ";
	for(const auto &c  : citizens_copy){
		cout<<c<<" ";
	}
	cout<<endl;
	
	return 0;
}
