#include <stdio.h>

#define INF 11
#define MAX_VERTICES 20

int dijkstra[MAX_VERTICES][MAX_VERTICES];
int distance[MAX_VERTICES];
int visit[MAX_VERTICES];

void Print_Dijkstra(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%2d ", dijkstra[i][j]);
        }
        printf("\n");
    }
}

void Reset_List(int n)
{
    for (int i = 0; i < n; i++)
    {
        visit[i] = 0;
        for (int j = 0; j < n; j++)
        {
            if (i == j) dijkstra[i][j] = 0;
            else dijkstra[i][j] = INF;
        }
    }
}

int Shortest_Index(int n)
{
    int index = 0;
    int min = INF;

    for (int i = 0; i < n; i++)
    {
        if(distance[i] < min && visit[i] == 0) 
        {
            min = distance[i];
            index = i;
        }
    }

    return index;
}

void Shortest_Path(int start, int n)
{
    for (int i = 0; i < n; i++)
    {
        distance[i] = dijkstra[start-1][i];
    }
    visit[start] = 1;
    int index;

    for (int i = 0; i < n - 1; i++)
    {
        index = Shortest_Index(n);
        visit[index] = 1;

        for (int j = 0; j < n; j++)
        {
            if (visit[j] == 0)
            {
                if (distance[j] > distance[i] + dijkstra[i][j]) distance[j] = distance[i] + dijkstra[i][j];
            }
        }
    }
}

int main(void)
{
    int y, e, k;
    int u, v, w;

    scanf("%d %d", &y, &e);
    scanf("%d", &k);

    Reset_List(y);

    for (int i = 0; i < e; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        dijkstra[u-1][v-1] = w;
    }

    Shortest_Path(k, y);

    for(int i = 0; i < y; i++)
    {
        if (distance[i] > 10) printf("INF\n");
        else printf("%d\n", distance[i]);
    }

    return 0;
}