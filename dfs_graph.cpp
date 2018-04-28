#include <vector>
#include <iostream>

using namespace std;

class DFS {
    public:
        DFS(int vertexCount);
        ~DFS();
        void build(const vector<vector<int>> &input, int startVertex);
        void visit(const vector<vector<int>> &input, int vertex, int &time);

        bool checkCycle(); // TODO
        int getNumOfConnectedComponent();
        void topologySort(); // TODO

    private:
        int mVertexCount;
        int *color; // 0:white; 1:grey; 2:black
        int *predecessor;
        int *discover;
        int *finish;
};

DFS::DFS(int vertexCount) {
    if(vertexCount > 0) {
        color = new int[vertexCount];
        predecessor = new int[vertexCount];
        discover = new int[vertexCount];
        finish = new int[vertexCount];

        for(int i=0; i<vertexCount; ++i) {
            color[i] = 0;
            predecessor[i] = -1;
            discover[i] = 0;
            finish[i] = 0;
        }
        mVertexCount = vertexCount;
    }
    else {
        cout << "invalid vertexCount " << vertexCount << endl;
        mVertexCount = 0;
    }

}

DFS::~DFS() {
    if(color)
        delete[] color;
    if(predecessor)
        delete[] predecessor;
    if(discover)
        delete[] discover;
    if(finish)
        delete[] finish;
}

void DFS::build(const vector<vector<int>> &input, int startVertex) {
    int time = 0;

    visit(input, startVertex, time);
    for(int i=0; i<mVertexCount; ++i) {
        if(color[i] == 0)
            visit(input, i, time);
        else
            ; // cout << "already visit " << i << endl; // already visit
    }

}

void DFS::visit(const vector<vector<int>> &input, int vertex, int &time) {
    color[vertex] = 1;
    discover[vertex] = ++time;
    cout << "discover " << vertex << endl;

    for(int i=0; i<input[vertex].size(); ++i) {
        if(color[input[vertex][i]] == 0) {
            predecessor[input[vertex][i]] = vertex;
            visit(input, input[vertex][i], time);
        }
    }

    finish[vertex] = ++time;
    color[vertex] = 2;
}

int DFS::getNumOfConnectedComponent() {
    int ret = 0;
    for(int i=0; i<mVertexCount; ++i) {
        if(predecessor[i] == -1)
            ++ret;
    }

    return ret;
}


int main() {
    vector<vector<int>> input(8);
    input[0].push_back(1);
    input[0].push_back(2);
    input[1].push_back(3);
    input[2].push_back(1);
    input[2].push_back(5);
    input[3].push_back(4);
    input[3].push_back(5);
    input[5].push_back(1);
    input[6].push_back(4);
    input[6].push_back(7);
    input[7].push_back(6);

    DFS test(8);
    test.build(input, 0);

    cout << "number of connected component " << test.getNumOfConnectedComponent() << endl;

    return 0;
}
