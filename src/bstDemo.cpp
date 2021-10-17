#include<iostream>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

struct bst{
	node* root=nullptr;
	
	node* find(int value){
		return find_impl(root, value);
	}
	
private:
	node* find_impl(node* current, int value){
		if(!current){
			cout<<endl;
			return NULL;
		}
		
		if(current->data == value){
			cout<<value<<"을(를) 찾았습니다."<<endl;
			return current;
		}
		
		if(value < current->data){
			cout<<current->data<<"에서 왼쪽으로 이동: ";
			return find_impl(current->left, value);
		}
		
		cout<<current->data<<"에서 오른쪽으로 이동: ";
		return find_impl(current->right, value);
	}
	
public:
	void insert(int value){
		if(!root){
			root=new node{value, NULL, NULL};
		}
		else{
			insert_impl(root, value);
		}
	}
	
private:
	void insert_impl(node* current, int value){
		if(value < current->data){
			if(!current->left){
				current->left=new Node{value, NULL, NULL};
			}
			else{
				insert_impl(current->left, value);
			}
		}
		else{
			if(!current->right){
				current->right=new Node{value, NULL, NULL};
			}
			else{
				insert_impl(current->right, value);
			}
		}
	}
	
// 중위함수
public:
	void inorder(){
		inorder_impl(root);
	}
	
private:
	void inorder_impl(node* start){
		if(!start){
			return;
		}
		inorder_impl(start->left);
		cout<<start->data<<" ";
		inorder_impl(start->right);
	}
	
// 후손 노드를 찾는 함수
public:
	node* successor(node* start){
		auto current=start->right;
		while(current && current->left){
			current=current->left;
		}
		return current;
	}
	

// 원소 삭제
public:
	
	void deleteValue(int value){
		root=delete_impl(root, value);
	}
	
private:
	node* delete_impl(node* start, int value){
		if(!start){
			return NULL;
		}
		
		if(value < start->data){
			start->left=delete_impl(start->left, value);
		}
		else if(value > start->data){
			start->right=delete_impl(start->right, value);
		}
		
		else{
			if(!start->left){
				auto tmp=start->right;
				delete start;
				return tmp;
			}
			
			if(!start -> right){
				auto tmp=start->left;
				delete start;
				return tmp;
			}
			
			auto succNode=successor(start);
			start->data=succNode->data;
			
			start->right=delete_impl(start->right, succNode->data);
		}
		
		return start;
	}
}










