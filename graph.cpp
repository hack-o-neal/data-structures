#include <iostream>
#include <list>
using namespace std;

template <typename T>
struct Graph {
    int V;
    list<int>* l;    // list<int> not list<T>, stores vertex indexes
    T* value;

    Graph(int V) {           // int V, not T V
        this->V = V;
        l = new list<int>[V];  // V not v, C++ is case sensitive
        value = new T[V];
    }

    ~Graph() {
        delete[] l;
        delete[] value;      // was missing
    }

    void setVertex(int u, T data) {  // int u, not T u
        value[u] = data;             // value[u] not l[u]
    }

    void addEdge(int source, int destination) {
        l[source].push_back(destination);    // no assignment, no l.push_back
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
    Graph<char> g(5);       // 5 vertices since you set 0,1,2,3,4

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
