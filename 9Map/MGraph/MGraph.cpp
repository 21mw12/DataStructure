#include <iostream>
using namespace std; 

#define MAX_SIZE 20
typedef struct{
    int node, edge;
    char nodes[MAX_SIZE];
    int edges[MAX_SIZE][MAX_SIZE];
}MGraph;

MGraph* CreateMGraph(char nodes[], int** edges, int size);
void ShowGMrapg (MGraph* map);

int main() {
    char nodes[4] = {'A', 'B', 'C', 'D'};
    int* edges[4];

    //edges[0][0] = 0;
    cout << *edges[0];
    // int size = sizeof(nodes) / sizeof(nodes[0]);
    // cout << size;
    // MGraph* mGraph = CreateMGraph(nodes, *edges, size);
    //cout << mGraph->edge;
    //cout << mGraph->node;
    //ShowGMrapg (mGraph);
    return 0;
}

MGraph* CreateMGraph(char nodes[], int** edges, int size) {
    int i, j;
    MGraph* mGraph = new MGraph;
    mGraph->node = size;
    mGraph->edge = 0;
    for (i = 0; i < size; i++) {
        //cout << nodes[i];
    }
    // for (i = 0; i < size; i++) {
    //     if (nodes[i] != ' ') {
    //         mGraph->node++;
    //         mGraph->nodes[i] = nodes[i];
    //     }
    // }
    // for (i = 0; i < size; i++) {
    //     for (j = 0; j < size; j++) {
    //         if (edges[i][j] == 1) mGraph->edge++;
    //         mGraph->edges[i][j] = edges[i][j];
    //     }
    // }
    return mGraph;
}

void ShowGMrapg (MGraph* map) {
    int i, j;
    cout << "   ";
    for (i = 0; i < map->node; i++) {
        cout << map->nodes[i] << "  ";
    }
    for (i = 0; i < map->node; i++) {
        cout << endl;
        cout << map->nodes[i] << "  ";
        for (j = 0; j < map->node; j++) {
            cout << map->edges[i][j] << "  ";
        }
    }
}
