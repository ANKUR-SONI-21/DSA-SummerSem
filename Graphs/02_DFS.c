#include <stdio.h>
#include <stdlib.h>
// DFS - Depth First Search
int A[7][7] = {{0, 1, 1, 1, 0, 0, 0},
               {1, 0, 1, 0, 0, 0, 0},
               {1, 1, 0, 1, 1, 0, 0},
               {1, 0, 1, 0, 1, 0, 0},
               {0, 0, 1, 1, 0, 1, 1},
               {0, 0, 0, 0, 1, 0, 0},
               {0, 0, 0, 0, 1, 0, 0}};
int visited[7] = {0};
// since we nedd stack for DFS, we can use functions as stack because functions are stored in stack
void DFS(int node)
{
    // 1. print the node
    printf("%d ", node);
    // 2. mark the node as visited
    visited[node] = 1;
    // 3. find the neighbour nodes of the current node
    for (int j = 0; j < 7; j++)
    {
        // 4. if the neighbour node is not visited, then call DFS on that node
        if (A[node][j] == 1 && visited[j] == 0)
        {
            DFS(j);
        }
    }
}
int main()
{
    int sourceNode = 1;
    DFS(sourceNode);
    return 0;
}
