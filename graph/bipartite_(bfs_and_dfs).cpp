#include <bits/stdc++.h>
usning namespace std;

// BFS Approach
class Solution {
public:
    //making a different function to check for disconnected graphs
    bool detect(int s, vector<vector<int>>& graph, int n, vector<int> &color){
        queue<int> q;
        q.push(s);
        color[s]=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto nbr: graph[node]){
                if(color[nbr] == -1){
                    color[nbr] = !color[node];
                    q.push(nbr);
                }
                else if(color[nbr] == color[node]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n, -1);
        bool ans;
        for(int i=0; i<n; i++){
            if(color[i]==-1){
                if(detect(i, graph, n, color) == false){
                    return false;
                }
            }
        }
        return true;
    }
};

//DFS Approach

#include<bits/stdc++.h>
using namespace std;

class Solution {
private: 
    bool dfs(int node, int col, int color[], vector<int> adj[]) {
        color[node] = col; 
        
        // traverse adjacent nodes
        for(auto it : adj[node]) {
            // if uncoloured
            if(color[it] == -1) {
                if(dfs(it, !col, color, adj) == false) return false; 
            }
            // if previously coloured and have the same colour
            else if(color[it] == col) {
                return false; 
            }
        }
        
        return true; 
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    int color[V];
	    for(int i = 0;i<V;i++) color[i] = -1; 
	    
	    // for connected components
	    for(int i = 0;i<V;i++) {
	        if(color[i] == -1) {
	            if(dfs(i, 0, color, adj) == false) 
	                return false; 
	        }
	    }
	    return true; 
	}
};

void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
	
	// V = 4, E = 4
	vector<int>adj[4];
	
	addEdge(adj, 0, 2);
   	addEdge(adj, 0, 3);
	addEdge(adj, 2, 3);
	addEdge(adj, 3, 1);

	Solution obj;
	bool ans = obj.isBipartite(4, adj);    
	if(ans)cout << "1\n";
	else cout << "0\n";  
	
	return 0;
}

