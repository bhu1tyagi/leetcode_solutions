// Approach:

// We will apply the BFS(Breadth First Search) traversal technique. Breadth First Search or BFS is 
// a traversal technique where we visit the nodes level-wise, i.e., it visits the same level nodes 
// simultaneously, and then moves to the next level.

// Initial Configuration:

// Indegree Array: Initially all elements are set to 0. Then, We will count the incoming edges 
//                 for a node and store it in this array. For example, if the indegree of node 3 
//                 is 2, indegree[3] = 2.

// Queue: As we will use BFS, a queue is required. Initially, the node with indegree 0 will be 
//        pushed into the queue.

// Answer array: Initially empty and is used to store the linear ordering.

// The algorithm steps are as follows:

// 1. First, we will form the adjacency list of the graph using the pairs. For example, for the pair 
//     {u, v} we will add node v as an adjacent node of u in the list.
// 2. Then, we will calculate the in-degree of each node and store it in the indegree array. We can 
//     iterate through the given adj list, and simply for every node u->v, we can increase the 
//     indegree of v by 1 in the indegree array. 
// 3. Initially, there will be always at least a single node whose indegree is 0. So, we will push 
//     the node(s) with indegree 0 into the queue.
// 4. Then, we will pop a node from the queue including the node in our answer array, and for all 
//     its adjacent nodes, we will decrease the indegree of that node by one. For example, if node
//     u that has been popped out from the queue has an edge towards node v(u->v), we will decrease
//     indegree[v] by 1.
// 5. After that, if for any node the indegree becomes 0, we will push that node again into the queue.
// 6. We will repeat steps 3 and 4 until the queue is completely empty. Now, completing the BFS we 
//     will get the linear ordering of the nodes in the answer array.
// 7. For the first problem(Course Schedule): We will return the answer array if the length of the
//     ordering equals the number of tasks. Otherwise, we will return an empty array.

// For the Second problem(Prerequisite tasks): We will return true if the length of the ordering 
// equals the number of tasks. otherwise, we will return false.



#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
	vector<int> findOrder(int V, int m, vector<vector<int>> prerequisites)
	{
		vector<int> adj[V];
		for (auto it : prerequisites) {
			adj[it[1]].push_back(it[0]);
		}



		int indegree[V] = {0};
		for (int i = 0; i < V; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}

		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		vector<int> topo;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			topo.push_back(node);
			// node is in your topo sort
			// so please remove it from the indegree

			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		if (topo.size() == V) return topo;
		return {};
	}
};


int main() {

	int N = 4;
	int M = 3;

	vector<vector<int>> prerequisites(3);
	prerequisites[0].push_back(0);
	prerequisites[0].push_back(1);

	prerequisites[1].push_back(1);
	prerequisites[1].push_back(2);

	prerequisites[2].push_back(2);
	prerequisites[2].push_back(3);

	Solution obj;
	vector<int> ans = obj.findOrder(N, M, prerequisites);

	for (auto task : ans) {
		cout << task << " ";
	}
	cout << endl;
	return 0;
}