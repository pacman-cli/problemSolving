#include <climits>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

#define white 1
#define gray 2
#define black 3
#define inf INT_MAX

class Graph {
  int nVertices;
  int **matrix;
  bool directed;           // directed->true, undirected->false
  int *color, *d, *parent; // distance

public:
  Graph(int n, bool dir) {
    nVertices = n;
    directed = dir;
    matrix = new int *[n]; // stores the address of each row //allocate
    for (int i = 0; i < n; i++)
      matrix[i] = new int[n]; // each row contains n integers
    // initialize all cell with 0
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        matrix[i][j] = 0;
      }
    }
    color = new int[n];
    d = new int[n];
    parent = new int[n];
  }

  void addEdge(int u, int v) {
    if (u < 0 || v < 0 || u >= nVertices ||
        v >= nVertices) // to check invalid edge or not
      return;

    matrix[u][v] = 1; // connect
    if (!directed)
      matrix[v][u] = 1;
  }

  bool isEdge(int u, int v) {
    if (u < 0 || v < 0 || u >= nVertices || v >= nVertices)
      return false;
    return matrix[u][v] == 1;
  }

  void BFS(int src) {
    for (int i = 0; i < nVertices; i++) {
      color[i] = white;
      d[i] = inf; // distance from src
      parent[i] = -1;
    }
    d[src] = 0;
    color[src] = gray;

    queue<int> q;
    q.push(src);

    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v = 0; v < nVertices; v++) {
        if (isEdge(u, v)) {
          if (color[v] == white) {
            q.push(v);
            parent[v] = u;
            d[v] = d[u] + 1;
            color[v] = gray;
          }
        }
      }
      color[u] = black;
    }
  }

  int shortestPath(int src, int dest) {
    BFS(src);
    return d[dest];
  }
};

int main() {
  int n = 5;
  vector<vector<int>> queries = {{2, 4}, {0, 2}, {0, 4}};

  Graph g(n, true); // Directed graph

  // Add initial roads
  for (int i = 0; i < n - 1; i++) {
    g.addEdge(i, i + 1);
  }

  vector<int> result;

  // Process each query
  for (const auto &query : queries) {
    int u = query[0], v = query[1];
    g.addEdge(u, v);                            // Add new road
    result.push_back(g.shortestPath(0, n - 1)); // Get shortest path
  }

  // Print results
  cout << "Shortest paths after each query: ";
  for (int dist : result) {
    cout << dist << " ";
  }
  cout << endl;

  return 0;
}
