#include <bits/stdc++.h>
usning namespace std;

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