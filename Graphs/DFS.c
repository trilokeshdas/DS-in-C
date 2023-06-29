#include<stdio.h>
#include<stdlib.h>
 //DFS implementation
    //    0---1
    //    | \ |
    //    3---2
    //     \ /              GIVEN GRAPH
    //      4       
    //     / \
    //    5   6
     //This is source. Source can be any vertex
    int visited[7]={0,0,0,0,0,0,0}; //as no vertex are visited so all are initialised to zero
        int adj[7][7]={
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };
    void DFS(int source);

int main(){
    DFS(0);
    return 0;
}
void DFS(int source){
    printf("%d ",source);
    visited[source]=1;
    for(int j=0; j<7;j++){
        if(adj[source][j]==1 && visited[j]==0){
            DFS(j);
        }
    }
}