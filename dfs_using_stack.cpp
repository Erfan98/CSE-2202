#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+9;
vector<int> graph[N];
bool vis[N];


void dfs(int source){
    stack<int> st;
    st.push(source);

    while(!st.empty()){
        int top = st.top();
        if(!vis[top]){
            cout<<top<< " ";
        }
        vis[top] = 1;
        st.pop();

        for(auto i:graph[top]){
            if(!vis[i]){
                st.push(i);
            }
        }
    }

}

int main(){
   // graph input
    int node,edge;
    cin>>node>>edge;
    while(edge--){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int source;
    cin>>source;

    dfs(source);

}

