#include <bits/stdc++.h>
#define MAXN 500005

using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pair;

struct Edge{
    ll next, weight;
    
    Edge(ll _next, ll _weight){
        next = _next;
        weight = _weight;
    }
};

vector<Edge> g[MAXN];

ll n, m;
ll dis[MAXN], vis[MAXN];

void dijkstra(ll s){
    priority_queue<Pair, vector<Pair>, greater<Pair> > q;
    for(ll i = 1; i <= 500000; i++)
        dis[i] = 999999999999999;
    q.push(Pair(0, s));
    dis[s] = 0;
    while(!q.empty()){
        Pair p = q.top();
        q.pop();
        ll u = p.second;
        if(p.first > dis[u])
            continue;
        for(ll i = 0; i < g[u].size(); i++){
            ll v = g[u][i].next;
            if(dis[v] > dis[u] + g[u][i].weight){
                dis[v] = dis[u] + g[u][i].weight;
                q.push(Pair(dis[v], v));
            }
        }
    }
}

int main(){
    scanf("%lld %lld", &n ,&m);//n: node, m: edge
    ll a, b, weight;
    for(int i = 0; i < m; i++){
        scanf(%lld %lld %lld, &a, &b, &weight);
        g[a].push_back(Edge(b, weight);
    }
    ll start, end;
    scanf(%lld %lld, &start, &end);
    dijkstra(start);
    if(dis[end] > (MAXN << 4))//cannot reach
        printf("-1\n");
    else
        printf("%lld\n", dis[end]);
    return 0;
}
