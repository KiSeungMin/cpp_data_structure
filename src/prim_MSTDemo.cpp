#include<string>
#include<vector>
#include<iostream>
#include<set>
#include<map>
#include<queue>
#include<limits>
using namespace std;

template<typename T>
auto create_reference_graph(){

    Graph<T> G(9);

    map<unsigned, vector<pair<unsigned, T>>> edge_map;
    edge_map[1] = {{2, 2}, {5, 3}};
    edge_map[2] = {{1, 2}, {5, 5}, {4, 1}};
    edge_map[3] = {{4, 2}, {7, 3}};
    edge_map[4] = {{2, 1}, {3, 2}, {5, 2}, {6, 4}, {8, 5}};
    edge_map[5] = {{1, 3}, {2, 5}, {4, 2}, {8, 3}};
    edge_map[6] = {{4, 4}, {7, 4}, {8, 1}};
    edge_map[7] = {{3, 3,}, {6, 4}};
    edge_map[8] = {{4, 5}, {5, 3}, {6, 1}};

    for(auto& i : edge_map)
        for(auto& j : i.second)
            G.add_edge(Edge<T>{i.first, j.first, j.second});
}

template<typename T>
struct Label
{
    unsigned ID;
    T distance;

    inline bool operator> (const Label<T>& l) const{
        return this->distance > l.distance;
    }
};

template<typename T>
auto prim_MST(const Graph<T>& G, unsigned src){

    priority_queue<Label<T>, vector<Label<T>>, greater<Label<T>>> heap;

    vector<T> distance(G.vertices(), numeric_limits<T>::max());

    set<unsigned> visited;

    vector<unsigned> MST;

    heap.emplace(Label<T>{src, 0});

    while(!heap.empty()){

        auto current_vertex = heap.top();
        heap.pop();

        if(visited.find(current_vertex.ID) == visited.end()){

            MST.push_back(current_vertex.ID);

            for(auto& e : G.edges(current_vertex.ID)){
                auto neightbor = e.dst;
                auto new_distance =e.weight;

                if(new_distance < distance[neighbor]){
                    heap.emplace(Lable<T>{neighbor, new_distance});
                    distance[neighbor] = new_distance;
                }
            }

            visited.insert(current_vertex.ID);
        }
    }

    return MST:
}