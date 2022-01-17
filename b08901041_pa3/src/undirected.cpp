#include "header.h"

HS::HS() {}
void HS::HeapSort(vector<int> &head, vector<int> &tail, vector<int> &weight)
{
    BuildMaxHeap(head, tail, weight);
    for (int i = weight.size() - 1; i >= 1; i--)
    {
        swap(head[0], head[i]);
        swap(tail[0], tail[i]);
        swap(weight[0], weight[i]);
        heapSize--;
        MaxHeapify(head, tail, weight, 0);
    }
}
void HS::MaxHeapify(vector<int> &head, vector<int> &tail, vector<int> &weight, int root)
{
    int left = root * 2 + 1;
    int right = root * 2 + 2;
    int largest;
    if (left < heapSize && weight[left] > weight[root])
    {
        largest = left;
    }
    else
    {
        largest = root;
    }
    if (right < heapSize && weight[right] > weight[largest])
    {
        largest = right;
    }
    if (largest != root)
    {
        swap(head[root], head[largest]);
        swap(tail[root], tail[largest]);
        swap(weight[root], weight[largest]);
        MaxHeapify(head, tail, weight,largest);
    }
}
void HS::BuildMaxHeap(vector<int> &head, vector<int> &tail, vector<int> &weight)
{
    heapSize = weight.size();
    for (int i = (heapSize / 2) - 1; i >= 0; i--)
    {
        MaxHeapify(head, tail, weight, i);
    }
}

// void QuickSort(vector<int> &head, vector<int> &tail, vector<int> &weight)
// {
//     QuickSortSubVector(head, tail, weight, 0, weight.size() - 1);
// }
// void QuickSortSubVector(vector<int> &head, vector<int> &tail, vector<int> &weight, int low, int high)
// {
//     if (low < high)
//     {
//         int q = Partition(head, tail, weight, low, high);
//         QuickSortSubVector(head, tail, weight, low, q - 1);
//         QuickSortSubVector(head, tail, weight, q + 1, high);
//     }
// }
// int Partition(vector<int> &head, vector<int> &tail, vector<int> &weight, int low, int high)
// {
//     int pivot = weight[high];
//     int index = low;
//     for (int j = low; j < high; j++)
//     {
//         if (weight[j] <= pivot)
//         {
//             std::swap(head[index], head[j]);
//             std::swap(tail[index], tail[j]);
//             std::swap(weight[index], weight[j]);
//             index++;
//         }
//     }
//     std::swap(head[index], head[high]);
//     std::swap(tail[index], tail[high]);
//     std::swap(weight[index], weight[high]);
//     return index;
// }

int Kruskal(vector<int> &head, vector<int> &tail, vector<int> &weight, vector<int> &del, int ver_num, int edge_num)
{
    HS Sort;
    Sort.HeapSort(head, tail, weight);
    // QuickSort(head, tail, weight);
    DisjointSets nodes(ver_num);
    for (int i = edge_num - 1; i >= 0; i--)
    {
        if (nodes.find(head[i]) != nodes.find(tail[i]))
        {
            nodes.merge(head[i], tail[i]);
        }
        else
        {
            del.push_back(i);
        }
    }
    int sum = 0;
    for (int i = 0; i < del.size(); i++)
    {
        sum += weight[del[i]];
    }
    return sum;
}