/*
You are given a positive integer n representing n cities numbered from 1 to n. 
You are also given a 2D array roads where roads[i] = [ai, bi, distancei] 
indicates that there is a bidirectional road between cities ai and bi with a 
distance equal to distancei. The cities graph is not necessarily connected.

The score of a path between two cities is defined as the minimum distance 
of a road in this path.

Return the minimum possible score of a path between cities 1 and n.

Note:

A path is a sequence of roads between two cities.
It is allowed for a path to contain the same road multiple times, 
and you can visit cities 1 and n multiple times along the path.
The test cases are generated such that there is at least one path 
between 1 and n.

*/
#include <vector>
#include <queue>
using namespace std; 

class Solution {
public:
    int bfs(int& n, vector<vector<pair<int, int>>>& adj) {
        vector<bool> visit(n + 1);
        queue<int> q;
        int answer = numeric_limits<int>::max();

        q.push(1);
        visit[1] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto& edge : adj[node]) {
                answer = min(answer, edge.second);
                if (!visit[edge.first]) {
                    visit[edge.first] = true;
                    q.push(edge.first);
                }
            }
        }
        return answer;
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        return bfs(n, adj);
    }
};