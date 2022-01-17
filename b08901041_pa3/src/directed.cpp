#include "header.h"

void Graph::Kruskal_d(vector<int> &head, vector<int> &tail, vector<int> &weight, int edge_num)
{
    HS Sort;
    Sort.HeapSort(head, tail, weight);
    DisjointSets nodes(num_vertex);
    for (int i = edge_num - 1; i >= 0; i--)
    {
        if (nodes.find(head[i]) != nodes.find(tail[i]))
        {
            nodes.merge(head[i], tail[i]);
            AddEdgeList(head[i], tail[i]);
        }
        else
        {
            if (weight[i] <= 0)
            {
                del_to_vec(head[i], tail[i], weight[i]);
            }
            else
            {
                AddEdgeList(head[i], tail[i]);
                if (DFS(0)) // has cycle
                {
                    Delete(head[i], tail[i], weight[i]);
                    del_to_vec(head[i], tail[i], weight[i]);
                }
                else
                {
                    nodes.merge(head[i], tail[i]);
                }
            }
        }
    }
}

void Graph::del_to_vec(int h, int t, int w)
{
    del_head.push_back(h);
    del_tail.push_back(t);
    del_weight.push_back(w);
    del_sum += w;
}

void Graph::AddEdgeList(int from, int to)
{
    AdjList[from].push_back(to);
}

bool Graph::DFS(int Start) // True : Find a cycle
{
    color = new int[num_vertex];
    for (int i = 0; i < num_vertex; i++)
    {
        color[i] = 0;
    }
    int i = Start;
    for (int j = 0; j < num_vertex; j++)
    {
        if (color[i] == 0)
        {
            if (DFSVisit(i))
            {
                return true;
            }
        }
        i = j;
    }
    return false;
}

bool Graph::DFSVisit(int vertex) // True : find a cycle
{
    color[vertex] = 1;
    for (list<int>::iterator itr = AdjList[vertex].begin(); itr != AdjList[vertex].end(); itr++)
    {
        if (color[*itr] == 1) // find a cycle
        {
            return true;
        }
        else if (color[*itr] == 0)
        {
            if (DFSVisit(*itr))
            {
                return true;
            }
        }
    }
    color[vertex] = 2;
    return false;
}

void Graph::Delete(int del_s, int del_e, int del_w)
{
    list<int>::iterator del_itr = find(AdjList[del_s].begin(), AdjList[del_s].end(), del_e);
    if (del_itr == AdjList[del_s].end())
    {
        cout << "Error! Can't find deletion position" << endl;
        return;
    }
    AdjList[del_s].erase(del_itr);
}

void Graph::write(fstream &fout)
{
    fout << del_sum << endl;
    for (int i = 0; i < del_head.size(); i++)
    {
        fout << del_head[i] << " " << del_tail[i] << " " << del_weight[i] << endl;
    }
}