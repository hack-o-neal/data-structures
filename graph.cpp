#include <iostream>
#include <list>
using namespace std;

template <typename T>
struct Graph {
    int V;
    list<int>* l;    
    T* value;

    Graph(int V) {           
        this->V = V;
        l = new list<int>[V];  
        value = new T[V];
    }

    ~Graph() {
        delete[] l;
        delete[] value;      
    }

    void setVertex(int u, T data) {  
        value[u] = data;             
    }

    void addEdge(int source, int destination) {
        l[source].push_back(destination);    
        l[destination].push_back(source);
    }

    void print() {
        for (int i = 0; i < V; i++) {
            cout << value[i] << " -> ";
            for (auto val : l[i]) {
                cout << value[val] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph<char> g(5);       

    g.setVertex(0, 'H');    // data comes second, index comes first
    g.setVertex(1, 'H');
    g.setVertex(2, 'C');
    g.setVertex(3, 'H');
    g.setVertex(4, 'C');

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    g.print();
    return 0;
}
