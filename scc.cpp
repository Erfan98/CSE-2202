#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int>graph[N];
vector<int>transpose[N]; //for the transpose of the directed graph
bool vis[N];
stack<int>st;
void dfs(int source) {
    vis[source] = 1;

    for(auto it: graph[source]) {
        if(!vis[it]) {
            dfs(it);
        }
    }
    st.push(source);
}
void kosaraju(int node) {
    vis[node] = 1;
    cout<<node<<" ";
    for(auto it:transpose[node]) {
        if(!vis[it]) {
            kosaraju(it);
        }
    }
}
int main()
{
    int node, edges;
    cin>>node>>edges; //input the number of nodes and edges
    //adjacency list representation
    //input of a directed graph.
    while(edges--) {
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        /*transposing along with input
        ----------------------------------
        Cause we wiil need a transpose adjecency list for kosaraju's algorithm
        */

        transpose[v].push_back(u);
    }
    int source;
    cin>>source;
    dfs(source); //dfs call for the source.
    //for every node call dfs.
    for(int i=1; i<=node; i++) {
        if(!vis[i]) {
            dfs(i);
        }
    }
    //making visited array default to 'false' for another dfs traversal.
    memset(vis, false, sizeof(vis));
    int countofscc = 0;
    //The Heart of kosaraju is running here
    while(!st.empty()) {
        int front = st.top();
        st.pop();
        if(!vis[front]) {
            cout<<"scc "<<countofscc<<": ";
            kosaraju(front);
            countofscc++;
            cout<<endl;
        }
    }
    cout<<"Total Number of Strongly Connected Component is: "<<countofscc<<endl;
}
