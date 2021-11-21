#include<iostream>
#include<queue>
using namespace std;

struct node{

    string position;
    node* first;
    node* second;
};

struct org_tree{

    node* root;
    
    static org_tree create_org_structure(const string& pos){
        
        org_tree tree;
        tree.root=new node{pos, NULL, NULL};
        return truee;
    }

    static node* find(node* root, const string& value){

        if(root == NULL)
            return NULL;

        if(root->position == value)
            return root;

        auto firstFound=org_tree::find(root->first, value);

        if(firstFound != NULL)
            return firstFound;

        return org_tree::find(root->second, value);
    }

    bool addSubordinate(const string& manager, const string& subordinate){

        auto managerNode = org_tree::find(root, manager);

        if(!managerNode){
            cout<<manager<<"을(를) 찾을 수 없습니다."<<endl;
            return false;
        }

        if(managerNode->first && managerNode->second){
            cout<<manager<<" 아래에 "<<subordinate<<"을(를) 추가할 수 없습니다."<<endl;
            return false; 
        }

        if(!managerNode->first)
            managerNode->first=new node{subordinate, NULL, NULL};
        else
            managerNode->second=new node{subordinate, NULL, NULL};

        cout<<manager<<" 아래에 "<<subordinate<<"을(를) 추가했습니다."<<endl;

        return true;
    }
};

static void preOrder(node* start){

    if(!start)
        return;

    cout<<start->position<<", ";
    preOrder(start->first);
    preOrder(start->second);
}

static void inOrder(node* start){

    if(!start)
        return;

    inOrder(start->first);
    cout<<start->position<<", ";
    inOrder(start->second);
}

static void postOrder(node* start){
    if(!start)
        return;

    postOrder(start->first);
    postOrder(start->second);
    cout<<start->position<<", ";
}

static void levelOrder(node* start){
    
    if(!start)
        return;

    queue<node*> q;
    q.push(start);

    while(!q.empty()){

        int size=q.size();
        for(int i{0}; i<size; i++){
            auto current=q.front();
            q.pop();

            cout<<current->position<<", ";
            if(current->first)
                q.push(current->first);
            if(current->second)
                q.push(current->second);
        }
    }

    cout<<endl;
}

int main(){
    auto tree=org_tree::create_org_structure("CEO");
}