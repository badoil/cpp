// 문제
// One of the most important data structures in computer science is the tree. You already dealt with binary trees in the qualification round. 
// This problem is about general trees.
// Trees are the subset of graphs that have the following 3 properties:

// It is connected: for every node you can reach every other node following edges.
// If an edge is removed, the graph is no longer connected. That is, some nodes cannot be reached anymore.
// When an edge is added between two existing nodes A and B, a cycle is created. There is a cycle if there is more than one way to go from A to B.
// Your task is to decide if a given graph is a tree or not.

// 입력
// The first line will contain an integer T representing the number of graphs to check. There will be at most 10 graphs in each test case.
// Each of the graph will be represented as follows:

// The first line will contain an integer N with the number of nodes in the graph. The number of nodes will be between 1 and 1,000. 
// The identifier of each node will be an integer from 1 to N. 
// The next line will contain an integer M with the number of edges in the graph. There will be at most 106 edges.

// The next M lines will contain 2 integers A and B each. These are the two nodes connected by an edge.
// The total sum of M in all test cases is at most 106.

// 출력
// For each graph, a single line with “tree” if the graph represents a tree or “graph“ otherwise.


#include<bits/stdc++.h>
using namespace std;

int n, m, t, a, b, cnt, visited[1004];
vector<int> adj[1004];

void dfs(int here) {
    visited[here] = 1;
    for(int there: adj[here]) {
        if (visited[there] == 0) {
            dfs(there);
        }
    }
    return;
}

int main() {
    scanf("%d", t);

    while(t--) {
        for (int i=0; i<1004; i++) adj[i].clear();
        fill(visited, visited+1004, 0);
        for(int i=0; i<m; i++) {
            scanf("%d %d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a); 
        }

        for (int i=0; i<n; i++) {
            if (visited[i] == 0) {
                dfs(i);
                cnt++;
            }
        }
    }

    if (m = n-1 && cnt == 1) puts("tree");
    else puts("graph");
}



// 트리는 그래프의 일종임
// 트리는 모든 노드가 연결되어 있는 것이 특징임
// 어떤 노드에서 시작하면 전체 노드를 다 방문할 수 있는 것이 트리
// dfs 걸어서 확인해보면 됨