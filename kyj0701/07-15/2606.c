#include <stdio.h>

int graph[1001][1001] = {0,};
int visited[1001] = {0,};
int queue[1001];
int virus = 0;

void DFS(int start, int m);

int main(void)
{
    int n, m;
    int x, y;

    scanf("%d", &n);
    scanf("%d", &m);

    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &x, &y);
        graph[x][y] = 1;
        graph[y][x] = 1;
    }

    DFS(1, n);
    printf("%d", virus);

    return 0;
}

void DFS(int start, int n)
{
    visited[start] = 1;

    for (int i = 0; i <= n; i++)
    {
        if (graph[start][i] == 1 && visited[i] == 0)
        {
            DFS(i, n);
            virus++;
        }
    }
}