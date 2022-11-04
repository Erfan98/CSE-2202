#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+9;
vector<int> g[N];
bool vis[N];

void dfs(int u) {
    cout<<u<<" ";
    vis[u] =true;
    for(auto i:g[u]) {
        if(!vis[i]) {
            dfs(i);
        }
    }
}


int main()
{
    int n, e;
    cin>>n>>e;
    while(e--) {
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(3);
    return 0;
}
