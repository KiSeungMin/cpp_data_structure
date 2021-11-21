#include<string>
#include<vector>
#include<iostream>
#include<set>
#include<map>
#include<queue>
using namespace std;

template<typename T>
struct Edge{

    unsigned src;
    unsigned dst;
    T weight;
}

template <typename T>
class Graph{
    
public:

    // N개의 정점으로 구성된 그래프
    Graph(unsigned N) : V(N){}

    // 그래프의 정점 개수 반환 
    auto vertices() const {return V;}


    // 전체 에지 리스트 반환
    auto& edges() const{return edge_list;환

    // 정점 v에서 나가는 모든 에지 반환
    auto edges(unsigned v) const{

        vector<Edge<T>> edges_from_v;
        for(auto& e : edge_list){
            if(e.src == v)
                edges_from_v.emplace_back(e);
        }

        return edges_from_v;
    }

    void add_edge(Edge<T>&& e){

        if(e.src >= 1 && e.src <= V && e.dst >=1 && e.dst <= V)
            edge_list.emplace_back(e);
        else
            cerr<"에러: 유효 범위를 벗어난 정점!"<<endl;
    }

    template <typename U>
    friend ostream& operator<<(ostream& os, const Graph<U>& G);

private:
    unsigned V;
    vector<Edge<T>> edge_list;

};

template<typename T>
auto breadth_first_search(const Graph<T>& G, unsigned start){

    queue<unsigned>queue;
    set<unsigned> visited;
    vector<unsigned>visit_order;
    queue.push(start);

    while(!queue.empty()){
        
        auto current_vertex = queue.front();
        queue.pop();


        // 현재 정점을 이전에 방문하지 않았다면
        if(visited.find(current_vertex) == visited.end())

            visited.insert(current_vertex);
            visit_order.push_back(current_vertex);

            for(auto& e : G.edges(current_vertex)){

                // 인접한 정점 중에서 방문하지 않은 정점이 있다면 큐에 추가
                if(visited.find(e.dst) == visited.end()){
                    queue.push_(e.dst);
                }
            }
        }
    }

    return visit_order;
}

