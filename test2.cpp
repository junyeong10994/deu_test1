#include <iostream>
#include <vector>
#include <algorithm>

struct Edge {
    int w, u, v;

    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

struct DisjointSet {
    std::vector<int> parent;

    explicit DisjointSet(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (u == parent[u])
            return u;
        return parent[u] = find(parent[u]);
    }

    void unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            parent[rootU] = rootV;
        }
    }
};

struct WeightedGraph {
    int n;
    std::vector<Edge> edges;

    explicit WeightedGraph(int n) : n(n) {}

    void addEdge(int u, int v, int w) {
        edges.push_back({ w, u, v });
    }

    void kruskalMST() const {
        auto sorted_edges = edges;
        std::sort(sorted_edges.begin(), sorted_edges.end());

        DisjointSet ds(n);

        long long total_weight = 0;
        std::vector<Edge> mst_edges;

        for (const auto& edge : sorted_edges) {
            if (ds.find(edge.u) != ds.find(edge.v)) {
                ds.unite(edge.u, edge.v);
                total_weight += edge.w;
                mst_edges.push_back(edge);

                if (mst_edges.size() == n - 1) {
                    break;
                }
            }
        }

        std::cout << "Kruskal's Algorithm MST Result:\n";
        std::cout << "-----------------------------\n";
        std::cout << "Included Edges:\n";
        for (const auto& edge : mst_edges) {
            std::cout << "  (" << edge.u << " - " << edge.v << ") with weight " << edge.w << "\n";
        }
        std::cout << "-----------------------------\n";
        std::cout << "Total weight of MST: " << total_weight << std::endl;
    }
};

int main() {
    WeightedGraph g(5);

    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 5);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 4, 1);

    g.kruskalMST();

    return 0;
} 

