//BFS & DFS
#include<iostream>
#include "samplequeue.cpp"
using namespace std;

class graph{
    private:
        int **Arr;
        int v; //no of vertices
        int e; //no of edges
        int *visited; //Visited Array
    public:
        graph(int vertices,int edge);
        ~graph();
        bool isEmpty();
        int NumberOfVertices();
        int NumberOfEdges();
        int Degree(int p);
        bool EdgeExists(int p,int q);
        void InsertEdge(int p,int q);
        void DeleteEdge(int p,int q);
        void DisplayAdjMatrix();
        void BFS(int u);
        void DFS(int u);
};

graph::graph(int vertices, int edge){
    v = vertices;
    e = edge;
    Arr = new int *[v+1];
    for(int i = 1; i <= v; i++){
        Arr[i] = new int [v+1];
    }
    for(int i = 1; i <= v; i++){
        for(int j = 1; j <= v; j++){
            Arr[i][j] = 0;
        }
    }
    cout<<"Constructor is called..."<<endl;

    //Initialising visited array
    visited = new int[v+1];
    for(int i = 1; i <= v; i++){
        visited[i] = 0;
    }
}

graph::~graph(){
    for(int i = 1; i <= v; i++)
        delete [] Arr[i];
    delete [] Arr;
    delete [] visited;
    cout<<"Destructor is called..."<<endl;
}

bool graph::isEmpty(){
    return v == 0;
}

int graph::NumberOfVertices(){
    return v;
}

int graph::NumberOfEdges(){
    return e;
}

int graph::Degree(int p){
    int sum = 0;
    for(int i = 1; i <= v; i++){
        sum += Arr[p][i];
    }
    return sum;

    //It returns the sum (count of 1) as it denotes how much vertices are adjacent to 'p' vertex.
}

bool graph::EdgeExists(int p,int q){
    if(p < 1 || p > v || q < 1 || q > v){
        cout<<"Bad Input, No such element in vertex set!..."<<endl;
    }
    if(Arr[p][q] == 1) return true;
    return false;
}

void graph::InsertEdge(int p,int q){
    if(p < 1 || p > v || q < 1 || q > v){
        cout<<"Bad Input, No such element in vertex set!..."<<endl;
    }
    Arr[p][q] = 1;
    Arr[q][p] = 1;
    e++;
}

void graph::DeleteEdge(int p,int q){
    if(p < 1 || p > v || q < 1 || q > v){
        cout<<"Bad Input, No such element in vertex set!..."<<endl;
    }
    Arr[p][q] = 0;
}

void graph::DisplayAdjMatrix(){
    for(int i = 1; i <= v; i++){
        for(int j = 1; j <= v; j++){
            cout<<Arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void graph::BFS(int u){
    Queue<int> q(30);
    cout<<endl;
    visited[u] = 1;
    q.EnQueue(u);
    int x;
    while(!q.isEmpty()){
        int w = q.front();
        cout<<w<<" ";
        q.DeQueue(x); //here I've kept x because our queue is coded that way. There is no need of x in the function.
        for(int i = 1; i <= v; i++){
            if(Arr[w][i] == 1 && visited[i] == 0){
                q.EnQueue(i);
                visited[i] = 1;
            }
        }
    }
}

void graph::DFS(int u){
    visited[u] = 1;
    int w;
    for(int i = 1; i <= v; i++){
        if(Arr[u][i] == 1 && visited[i] == 0){
            w = i;
            cout<<w<<" ";
            visited[w] = 1;
            DFS(w);
        }
    }
}

int main(){
    int v,e,p,q;
    cout<<"Enter the no of vertex in the graph: ";
    cin>>v;
    cout<<"Enter the no of edge in the graph: ";
    cin>>e;
    graph g(v,e);
    for(int i = 1; i <= e; i++){
        cout<<"Enter the vertex p of edge "<<i<<" : ";
        cin>>p;
        cout<<"Enter the vertex q of edge "<<i<<" : ";
        cin>>q;
        g.InsertEdge(p,q);
    }
    cout<<"Adjacency Matrix......"<<endl;
    g.DisplayAdjMatrix();
    // cout<<"The BFS travsersal of graph is..."<<endl;
    // g.BFS(1);
    // cout<<endl;
    cout<<"The DFS travsersal of graph is..."<<endl;
    cout<<"1 ";
    g.DFS(1);
    cout<<endl;
    return 0;
}
//Keep one of the traversal commented while working with the other one as visited gets all 1 in bfs so dfs won't give ans.
//TIME COMPLEXITY: O(n^2) for BFS AND DFS