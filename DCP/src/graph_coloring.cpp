//
// Created by asmu270293 on 25.01.2019.
//

#include <iostream>
#include <vector>

void printSolution(int color[], int size);

bool isSafe(int v, std::vector<std::vector<bool>> graph, int color[], int c, int size){
    for(int i=0; i<size; i++){
        if(graph[v][i] && c == color[i]){
            return false;
        }
    }
    return true;
}

bool graph_color_util(std::vector<std::vector<bool>> graph, int m, int color[], int v, int size){
    if(v==size){
        return true;
    }
    for(int c=1; c<=m; c++){
        if(isSafe(v, graph, color, c, size)){
            color[v] = c;

            if(graph_color_util(graph, m, color, v+1, size) == true){
                return true;
            }
            color[v] = 0;
        }
    }
    return false;
}

bool graph_coloring(std::vector<std::vector<bool>> graph, int m, int size){
    int *color = new int[size];
    for(int i=0; i<size; i++){
        color[i] = 0;
    }
    if(graph_color_util(graph, m, color, 0, size) == false){
        std::cout<<"Solution does not exist!\n";
        return false;
    }
    printSolution(color, size);
    return true;
}

void printSolution(int color[], int size){
    printf("Solution Exists:"
           " Following are the assigned colors \n");
    for(int i=0; i<size; i++){
        std::cout<<color[i];
    }
}

int main(){
    std::vector<std::vector<bool>> graph = {{0, 1, 1, 1},
                                            {1, 0, 1, 0},
                                            {1, 1, 0, 1},
                                            {1, 0, 1, 0},};
    int m = 3;
    graph_coloring(graph, m, graph.size());
    return 0;
}