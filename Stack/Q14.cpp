//Mazing Problem
#include<iostream>
using namespace std;
bool isPathExist(int **Maze, int x, int y, int n){
    if(x < n && y < n && Maze[x][y] == 0){
        return true;
    }
    return false;
}

bool Mazing(int **Maze, int x, int y, int n, int **Path){
    if(x == n-1 && y == n - 1){
        Path[x][y] = 0;
        return true;
    }
    if(isPathExist(Maze,x,y,n)){
        Path[x][y] = 0;
        if(Mazing(Maze,x+1,y,n,Path)){
            return true;
        }
        if(Mazing(Maze,x,y+1,n,Path)){
            return true;
        }
        Path[x][y] = 1;
        return false;
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    int **Maze = new int *[n];
    for(int i = 0; i < n; i++){
        Maze[i] = new int[n];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>Maze[i][j];
        }
    }
    int **Path = new int *[n];
    for(int i = 0; i < n; i++){
        Path[i] = new int[n];
        for(int j = 0; j < n; j++){
           Path[i][j] = 1;
        }
    }
    if(Mazing(Maze,0,0,n,Path)){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout<<Path[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}