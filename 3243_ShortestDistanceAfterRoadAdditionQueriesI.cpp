#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Function to perform BFS and find the shortest path from city 0 to city n-1
int bfs(int n, const vector<vector<int>> &graph) {
  vector<bool> visited(n, false);
  queue<pair<int, int>> q; // pair: (current city, distance)
  q.push({0, 0});          // Start from city 0 with distance 0
  visited[0] = true;

  while (!q.empty()) {
    auto [current, distance] = q.front();
    q.pop();

    if (current == n - 1)
      return distance; // Reached city n-1

    for (int neighbor : graph[current]) {
      if (!visited[neighbor]) {
        visited[neighbor] = true;
        q.push({neighbor, distance + 1});
      }
    }
  }
  return -1; // If city n-1 is not reachable (should not happen in this problem)
}

// Main function to process queries and compute shortest distances
vector<int> shortestPathAfterQueries(int n, vector<vector<int>> &queries) {
  vector<vector<int>> graph(n);
  for (int i = 0; i < n - 1; i++) {
    graph[i].push_back(i + 1); // Initial unidirectional roads
  }

  vector<int> result;

  for (const auto &query : queries) {
    int u = query[0], v = query[1];
    graph[u].push_back(v);           // Add the new road
    result.push_back(bfs(n, graph)); // Find the shortest path using BFS
  }

  return result;
}

// Driver code
int main() {
  int n = 5;
  vector<vector<int>> queries = {{2, 4}, {0, 2}, {0, 4}};
  vector<int> result = shortestPathAfterQueries(n, queries);

  cout << "Shortest paths after each query: ";
  for (int dist : result) {
    cout << dist << " ";
  }
  cout << endl;

  return 0;
}
