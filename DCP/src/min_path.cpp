//
// Created by Ashwath on 30.11.2018.
//

#include <iostream>
#include <queue>

#define ROW 4
#define COL 4

struct Point{
    int x;
    int y;
};

struct qNode{
    Point p;
    int dist;
};

bool isValid(int row, int col){
    return (row>=0) && (row<ROW) && (col>=0) && (col<COL);
}

int rowList[] = {-1, 0, 0, 1};
int colList[] = {0, -1, 1, 0};

int minCost(int mat[][COL], Point src, Point dst){
    if(!mat[src.x][src.y] || !mat[dst.x][dst.y]){
        return -1;
    }
    bool visited[ROW][COL];
    memset(visited, false, sizeof(visited));
    visited[src.x][src.y] = true;
    std::queue<qNode> q;
    qNode s = {src, 0};
    q.push(s);

    while(!q.empty()){
        qNode current = q.front();
        Point pt = current.p;

        if(pt.x == dst.x && pt.y == dst.y){
            return current.dist;
        }
        q.pop();
        for(int i=0; i<4; i++){
            int row = pt.x + rowList[i];
            int col = pt.y + colList[i];

            if(isValid(row, col) && mat[row][col] && !visited[row][col]){
                visited[row][col] = true;
                qNode adj = {{row, col}, current.dist+1};
                q.push(adj);
            }
        }
    }
    return -1;
}

int main(){
    int mat[ROW][COL] =
            {
                    {1,1,1,1},
                    {0,0,1,0},
                    {1,1,1,1},
                    {1,1,1,1}
            };
    Point source = {3, 0};
    Point dest = {0, 0};
    std::cout<<minCost(mat, source, dest);
}