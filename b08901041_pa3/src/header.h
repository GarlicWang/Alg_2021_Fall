#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

// void QuickSort(vector<int> &head, vector<int> &tail, vector<int> &weight);
// void QuickSortSubVector(vector<int> &head, vector<int> &tail, vector<int> &weight, int low, int high);
// int Partition(vector<int> &head, vector<int> &tail, vector<int> &weight, int low, int high);
int Kruskal(vector<int> &head, vector<int> &tail, vector<int> &weight, vector<int> &del, int ver_num, int edge_num);

struct DisjointSets
{
    int *parent, *rnk;
    int n;
    DisjointSets(int n)
    {
        this->n = n;
        parent = new int[n + 1];
        rnk = new int[n + 1];
        for (int i = 0; i <= n; i++)
        {
            rnk[i] = 0;
            parent[i] = i;
        }
    }
    // Path Compression
    int find(int u)
    {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }
    // Union by rank
    void merge(int x, int y)
    {
        x = find(x), y = find(y);
        if (rnk[x] > rnk[y])
            parent[y] = x;
        else 
            parent[x] = y;

        if (rnk[x] == rnk[y])
            rnk[y]++;
    }
};
class HS{
    public:
        HS();
        void HeapSort(vector<int>&, vector<int>&, vector<int>&);
    private:
        void MaxHeapify(vector<int>&, vector<int>&, vector<int>&, int); 
        void BuildMaxHeap(vector<int>&, vector<int>&, vector<int>&); 
        int heapSize;
};
class Graph{
    public:
        Graph(int N) : num_vertex(N)
        {
            AdjList.resize(num_vertex);
            del_sum = 0;
        };
        void AddEdgeList(int from, int to);
        bool DFS(int Start);
        bool DFSVisit(int vertex);
        void del_to_vec(int h, int t, int w);
        void write(fstream& fout);
        void Kruskal_d(vector<int>& head, vector<int>& tail, vector<int>& weight, int edge_num);
    private:
        int num_vertex;
        // vector<list<int> > AdjList;
        vector<list<int> > AdjList;
        int *color; // 0:white, 1:gray, 2:black
        int del_sum;
        vector<int> del_head, del_tail, del_weight;
        void Delete(int del_s, int del_e, int del_w);
};