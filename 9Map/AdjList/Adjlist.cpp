#include <iostream>
#include<string>
using namespace std; 

#define MAX_SIZE 20
int visited[MAX_SIZE] = {0};
typedef struct EdgeNode{
    int edgeNodeIndex;
    // int weight = 1;
    EdgeNode* next = NULL;
}EdgeNode;
typedef struct HeadNode{
    char node;
    EdgeNode* next = NULL;
}HeadNode;
typedef struct AdjList{
    int n, e;
    HeadNode List[MAX_SIZE];
}AdjList;

AdjList* InitMap(int flag = 0);
AdjList* CreateMap(char nodes[], string edges[], int nodeSize, int edgeSize);
void ShowMap(AdjList* map);
void DFS(AdjList* map, int node = 0);
void BFS(AdjList* map);
void Topological(AdjList* map);
void ClearVisited();

int main() {
    int i;
    AdjList* map = InitMap(1);
    ShowMap(map);

    cout << "深度优先遍历为：";
    DFS(map);
    ClearVisited();
    cout << endl;

    cout << "广度优先遍历为：";
    BFS(map);
    ClearVisited();
    cout << endl;

    cout << "拓扑排序为：";
    Topological(map);
    ClearVisited();
    cout << endl;

    cin >> i;
    return 0;
}

/**
 * @brief 初始化邻接表图（有向图）
 * 
 * @return AdjList* ：图
 */
AdjList* InitMap(int flag) {
    if (flag = 0) {
        int i;
        char nodes[MAX_SIZE];
        string edges[MAX_SIZE];
        int nodeNumber, edgeNumber;
        cout << "请输入结点数：";
        cin >> nodeNumber;
        for (i = 0; i < nodeNumber; i++) {
            cout << "请输入第" << i+1 << "个结点：";
            cin >> nodes[i];
        }
        while(true) {
            cout << "请输入第" << edgeNumber+1 << "个线（格式为:起始位置,结束位置,输入End结束）：";
            cin >> edges[edgeNumber];
            if (edges[edgeNumber] == "End") {
                break;
            }
            edgeNumber++;
        }
        return CreateMap(nodes, edges, nodeNumber, edgeNumber);
    } else {
        char nodes[MAX_SIZE] = {'A', 'B', 'C', 'D', 'E'};
        string edges[MAX_SIZE] = {"A,B", "A,D", "B,D", "B,C", "D,C", "C,E", "D,E"};
        return CreateMap(nodes, edges, 5, 7);
    }
}

/**
 * @brief 创建一个邻接表图（有向图）
 * 
 * @param nodes ：存放点的数组
 * @param edges ：存放边的数组
 * @param nodeSize ：点的个数
 * @param edgeSize ：边的个数
 * @return AdjList* ：图
 */
AdjList* CreateMap(char nodes[], string edges[], int nodeSize, int edgeSize) {
    int i, j;
    int start, target;
    AdjList* map = new AdjList;
    EdgeNode* temp;
    EdgeNode* work;
    map->n = nodeSize;
    map->e = edgeSize;
    for (i = 0; i < nodeSize; i++) {
        map->List[i].node = nodes[i];
    }
    for (i = 0; i < edgeSize; i++) {
        for (j = 0; j < nodeSize; j++) {
            if (edges[i][0] == nodes[j]) {
                start = j;
            }
            if (edges[i][2] == nodes[j]) {
                target = j;
            }
        }
        temp = new EdgeNode;
        temp->edgeNodeIndex = target;
        if (map->List[start].next == NULL) {
            map->List[start].next = temp;
        } else {
            work = map->List[start].next;
            while (work->next != NULL) {
                work = work->next;
            }
            work->next = temp;
        }
    }
    return map;
}

/**
 * @brief 打印临界表数据
 * 
 * @param map ：图
 */
void ShowMap(AdjList* map) {
    int i, j;
    EdgeNode* work;
    for (i = 0; i < map->n; i++) {
        cout << map->List[i].node;
        if (map->List[i].next != NULL) {
            work = map->List[i].next;
            while (work != NULL) {
                cout << " -> " << work->edgeNodeIndex;
                work = work->next;
            }
        }
        cout << endl;
    }
}

/**
 * @brief 深度优先遍历
 * 
 * @param map ：图
 * @param node ：开始的下标默认为0
 */
void DFS(AdjList* map, int node) {
    int i;
    EdgeNode* work;
    if (visited[node] == 0) {
        cout << map->List[node].node;
        visited[node] = 1;
    }
    if (map->List[node].next != NULL) {
        work = map->List[node].next;
        while (work != NULL) {
            DFS(map, work->edgeNodeIndex);
            work = work->next;
        }
    }
}

/**
 * @brief 广度优先遍历
 * 
 * @param map ：图
 */
void BFS(AdjList* map) {
    EdgeNode* work;
    int i;
    int queue[MAX_SIZE] = {0}, rear = 1;
    for (i = 0; i < map->n; i++) {
        work = map->List[i].next;
        while (work != NULL) {
            queue[rear] = work->edgeNodeIndex;
            rear++;
            work = work->next;
        }
    }
    for (i = 0; i < rear; i++) {
        if (visited[queue[i]] == 0) {
            cout << map->List[queue[i]].node;
            visited[queue[i]] = 1;
        }
    }
}

/**
 * @brief 拓扑排序
 * 
 * @param map ：图
 */
void Topological(AdjList* map) {
    int i, j;
    EdgeNode* work;
    int InDegree[map->n] = {0};
    for (i = 0; i < map->n; i++) {
        if (map->List[i].next != NULL) {
            work = map->List[i].next;
            while (work != NULL) {
                InDegree[work->edgeNodeIndex]++;
                work = work->next;
            }
        }
    }
    for (i = 0; i < map->n; i++) {
        for (j = 0; j < map->n; j++) {
            if (InDegree[j] == 0 && visited[j] == 0) {
                cout << map->List[j].node;
                visited[j] = 1;
            }
        }
        work = map->List[i].next;
        while (work != NULL) {
            InDegree[work->edgeNodeIndex]--;
            work = work->next;
        }
    }
}

/**
 * @brief 去除所有标志位
 * 
 */
void ClearVisited() {
    int i;
    for (i = 0; i < MAX_SIZE; i++) {
        visited[i] = 0;
    }
}