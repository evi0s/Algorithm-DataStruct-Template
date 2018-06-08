#include <bits/stdc++.h>
#define MAXN 500005

using namespace std;
typedef long long ll;

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

void spfa(ll s){
    queue<ll> q;
    for(ll i = 0; i <= 500000; i++)
        dis[i] = MAXN << 4;
    memset(vis, 0, sizeof vis);
    q.push(s);
    vis[s] = 1;
    dis[s] = 0;
    while(!q.empty()){
        ll u = q.front();
        q.pop();
        vis[u] = 0;
        for(ll i = 0; i < g[u].size(); i++){
            ll v = g[u][i].next;
            if(dis[v] > dis[u] + g[u][i].weight){
                dis[v] = dis[u] + g[u][i].weight;
                if(!vis[v]){
                    vis[v] = 1;
                    q.push(v);
                }
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
    spfa(start);
    if(dis[end] > (MAXN << 4))//cannot reach
        printf("-1\n");
    else
        printf("%lld\n", dis[end]);
    return 0;
}
