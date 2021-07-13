#include <stdio.h>

int graph[1001][1001] = {0,};
int dfs_visited[1001] = {0,};
int bfs_visited[1001] = {0,};
int queue[1001];

void DFS(int start, int m);
void BFS(int start, int m);

int main(void)
{
    int n, m, v;
    int x, y;

    scanf("%d %d %d", &n, &m, &v);

    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &x, &y);
        graph[x][y] = 1;
        graph[y][x] = 1;
    }

    DFS(v, n);
    printf("\n");
    BFS(v, n);
    printf("\n");

    return 0;
}

void DFS(int start, int n)
{
    printf("%d ", start);
    dfs_visited[start] = 1;

    for (int i = 0; i <= n; i++)
    {
        if (graph[start][i] == 1 && dfs_visited[i] == 0)
        {
            DFS(i, n);
        }
    }
}

void BFS(int start, int n)
{
    int front = 0;
    int rear = 0;
    int pop;

    printf("%d ", start);
    bfs_visited[start] = 1;
    queue[0] = start;
    rear++;
    
    while(front < rear)
    {
        pop = queue[front];
        front++;

        for (int i = 0; i <= n; i++)
        {
            if (graph[pop][i] && !bfs_visited[i])
            {
                printf("%d ", i);
                queue[rear] = i;
                rear++;
                bfs_visited[i] = 1;
            }
        }
    }
}