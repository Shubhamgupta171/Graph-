// Def-->Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u-v, vertex u comes before v in the ordering.

//Approach-->Check if its directed acyclic graph and we have to arrange the elements in an order in which we need to select the most independent node at first. Number of in-node 0
class Solution {
 	int V;
 	list<int>*adj;
 	
 	bool isCyclicUtil(int v, vector<bool>&visited, vector<bool>&recStack) {
 		
 		visited[v] = true;
 		recStack[v] = true;
 		
 		for (auto it = adj[v].begin(); it != adj[v].end(); it++) {
 			if (!visited[*it] && isCyclicUtil(*it, visited, recStack))
 				return true;
 			else if (recStack[*it])
 				return true;
 		}
 		
 		recStack[v] = false;
 		return false;
 	}
 	
 	bool isCyclic() {
 		vector<bool>visited(V, false);
 		vector<bool>recStack(V, false);
 		
 		for (int i = 0; i < V; i++) {
 			if (isCyclicUtil(i, visited, recStack))
 				return true;
 		}
 		
 		return false;
 	}
 	
 	void topologicalSortUtil(int v, vector<bool>&visited, vector<int>& res) {
 		visited[v] = true;
 		
 		for (auto it = adj[v].begin(); it != adj[v].end(); it++)
 			if (!visited[*it])
 				topologicalSortUtil(*it, visited, res);
 		
 		res.push_back(v);
 	}
 	
 	vector<int>topologicalSort(int v) {
 		vector<int>res;
 		
 		vector<bool>visited(V, false);
 		topologicalSortUtil(v, visited, res);
 		
 		for (int i = 0; i < V; i++) {
 			if (!visited[i])
 				topologicalSortUtil(i, visited, res);
 		}
 		
 		return res;
 	}
 	
 	public:
 	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
 		V = numCourses;
 		adj = new list<int>[V];
 	
 		unordered_map<int, vector<int>>hm;
 		
 		for (int i = 0; i < prerequisites.size(); i++) {
 			adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
 			hm[prerequisites[i][1]].push_back(prerequisites[i][0]);
 		}
 		
 		if (isCyclic()) return vector<int>();
 		
 		int i = 0;
 		for (i = 0; i < V; i++) {
 			if (hm.find(i) == hm.end())
 				break;
 		}
 		
 		return topologicalSort(i);
 	}
};
