#include<iostream>
#include<vector>
#include<string.h>
#include<cstring>
#include<unordered_map>
#include<algorithm>
#include<limits.h>
#include<queue>
#include<stack>
#define ll long long int
#define d double
#define pb push_back
// #define v vector
// #define vi vector<int>
// #define bp __builtin_popcount
// #define bpll __builtin_popcountll
// (char)('A' | (1 << 5))
// (char)('a' |~(1 << 5))
const int mod1 = 1e9 + 7;
using namespace std;
class Graph{
    public:
    vector<int> *adj;
    int V;

    Graph(int n){
        V = n;
        adj = new vector<int>[n];
    }

    void addEdge(int u, int v){
        adj[u].pb(v);
        adj[v].pb(u);
    }
    void StartBFS(int StartVertex){
        vector<bool> visited(V, false);
        queue<int> q;
        q.push(StartVertex);
        visited[StartVertex] = true;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            cout << u << " ";
            for(auto i : adj[u]){
                if(!visited[i]){
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
};
void Solve(){
    Graph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);

    graph.StartBFS(0);

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();
    return 0;
}