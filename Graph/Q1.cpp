//Graph class ADT
#include<iostream>
using namespace std;

class graph{
    private:
        int **Arr;
        int v; //no of vertices
        int e; //no of edges
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
}

graph::~graph(){
    for(int i = 1; i <= v; i++)
        delete [] Arr[i];
    delete [] Arr;
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
    g.DeleteEdge(3,1);
    cout<<"Adjacency matrix after deleting......."<<endl;
    g.DisplayAdjMatrix();
    if(g.EdgeExists(1,2)){
        cout<<"Edge exists..."<<endl;
    }
    else{
        cout<<"No edge exists..."<<endl;
    }
    cout<<"Degree of 1 is: ";
    cout<<g.Degree(1)<<endl;
    cout<<"Degree of 2 is: ";
    cout<<g.Degree(2)<<endl;
    return 0;
}