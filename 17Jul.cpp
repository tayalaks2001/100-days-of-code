// Question - given undirected graph which forms a perfect ring, print nodes in the order in which they appear in the ring (either clockwise or anti-clockwise)

#include<bits/stdc++.h>
using namespace std;

vector<char> listOrderOfNodes (unordered_map<char, vector<char>> graph) {
	vector<char> nodesOrder;
	char start = pick_any_key(graph), parent = ‘*’, current = start;
bool continueTraversal = true;	
	while (continueTraversal) {
		nodesOrder.push_back(current);
		if ((graph[current][0] == parent or graph[current][0] == start) and (graph[current][1] == parent or graph[current][1] == start)){
	// stop traversal
	continueTraversal = false;
	continue;
}
		if (graph[current][0] != parent) {
			parent = current;
			current = graph[current][0];
		}
		else {
			parent = current;
			current = graph[current][1];
		}

	}

	Return nodesOrder;
}

