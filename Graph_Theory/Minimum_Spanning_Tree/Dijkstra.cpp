#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;

struct edge{
    int u, v, weight;
}Edge[MAXN];

int w[MAXN];

bool cmp(const edge& p1, const edge& p2){
    return p1.weight < p2.weight;
}

inline int find(int x){
    return (w[x] == x) ? x : (w[x] = find(w[x]));
}

int main(){
    int n, m, a, b, counter = 0;
    int v, sum = 0, weight;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &a, &b, &v);
        Edge[i].u = a;
        Edge[i].v = b;
        Edge[i].weight = v;
    }
    for(int i = 0; i <= n; i++)
        w[i] = i;
    sort(Edge, Edge + m, cmp);
    int x, y;
    for(int i = 0; i < m; i++){
        weight = Edge[i].weight;
        x = find(Edge[i].u);
        y = find(Edge[i].v);
        if(x != y){
            sum += weight;
            w[y] = x;
            counter++;
            if(counter == n - 1)
                break;
        }
    }
    printf("%d\n", sum);
    return 0;
}
