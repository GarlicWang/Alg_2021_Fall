// **************************************************************************
//  File       [sort_tool.cpp]
//  Author     [Yu-Hao Ho]
//  Synopsis   [The implementation of the SortTool Class]
//  Modify     [2020/9/15 Mu-Ting Wu]
// **************************************************************************

#include "sort_tool.h"
#include <iostream>

// Constructor
SortTool::SortTool() {}

// Insertsion sort method
void SortTool::InsertionSort(vector<int> &data)
{
    // Function : Insertion sort
    // TODO : Please complete insertion sort code here
    for (int i = 1; i < data.size(); i++)
    {
        int key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > key)
        {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}

// Quick sort method
void SortTool::QuickSort(vector<int> &data)
{
    QuickSortSubVector(data, 0, data.size() - 1);
}
// Sort subvector (Quick sort)
void SortTool::QuickSortSubVector(vector<int> &data, int low, int high)
{
    // Function : Quick sort subvector
    // TODO : Please complete QuickSortSubVector code here
    // Hint : recursively call itself
    //        Partition function is needed
    if (low < high)
    {
        int q = Partition(data, low, high);
        QuickSortSubVector(data, low, q - 1);
        QuickSortSubVector(data, q + 1, high);
    }
}

int SortTool::Partition(vector<int> &data, int low, int high)
{
    // Function : Partition the vector
    // TODO : Please complete the function
    // Hint : Textbook page 171
    int pivot = data[high];
    int index = low;
    for (int j = low; j < high; j++)
    {
        if (data[j] <= pivot)
        {
            std::swap(data[index], data[j]);
            index++;
        }
    }
    std::swap(data[index], data[high]);
    return index;
}

// Merge sort method
void SortTool::MergeSort(vector<int> &data)
{
    MergeSortSubVector(data, 0, data.size() - 1);
}

// Sort subvector (Merge sort)
void SortTool::MergeSortSubVector(vector<int> &data, int low, int high)
{
    // Function : Merge sort subvector
    // TODO : Please complete MergeSortSubVector code here
    // Hint : recursively call itself
    //        Merge function is needed
    if (high - low > 0)
    {
        int middle1 = (low + high) / 2;
        int middle2 = middle1 + 1;
        MergeSortSubVector(data, low, middle1);
        MergeSortSubVector(data, middle2, high);
        Merge(data, low, middle1, middle2, high);
    }
}

// Merge
void SortTool::Merge(vector<int> &data, int low, int middle1, int middle2, int high)
{
    // Function : Merge two sorted subvector
    // TODO : Please complete the function
    int leftlength = middle1 - low + 1;
    int rightlength = high - middle2 + 1;
    vector<int> Left(leftlength + 1);
    vector<int> Right(rightlength + 1);
    for (int i = 0; i < leftlength; i++)
    {
        Left[i] = data[i + low];
    }
    Left[leftlength] = 1000000;

    for (int i = 0; i < rightlength; i++)
    {
        Right[i] = data[i + middle2];
    }
    Right[rightlength] = 1000000;

    int left = 0;
    int right = 0;

    for (int i = low; i <= high; i++)
    {
        if (Left[left] <= Right[right])
        {
            data[i] = Left[left];
            left++;
        }
        else
        {
            data[i] = Right[right];
            right++;
        }
    }

    //以下為PA0使用之演算法，因實測結果效率極差，故不用
    /*
    vector<int> combined(data.size());
    int leftindex = low;
    int rightindex = middle2;
    int combinedIndex = low;
    while (leftindex <= middle1 && rightindex <= high)
    {
        if (data[leftindex] <= data[rightindex])
        {
            combined[combinedIndex] = data[leftindex];
            combinedIndex++;
            leftindex++;
        }
        else
        {
            combined[combinedIndex] = data[rightindex];
            combinedIndex++;
            rightindex++;
        }
    }
    if (leftindex > middle1)
    {
        for (int i = rightindex; i <= high; i++, combinedIndex++)
        {
            combined[combinedIndex] = data[i];
        }
    }
    else
    {
        for (int i = leftindex; i <= middle1; i++, combinedIndex++)
        {
            combined[combinedIndex] = data[i];
        }
    }
    //copy value back
    for (int i = low; i <= high; i++)
    {
        if (combined[i] != 0)
        {
            data[i] = combined[i];
        }
    }
    */
}

// Heap sort method
void SortTool::HeapSort(vector<int> &data)
{
    // Build Max-Heap
    BuildMaxHeap(data);
    // 1. Swap data[0] which is max value and data[i] so that the max value will be in correct location
    // 2. Do max-heapify for data[0]
    for (int i = data.size() - 1; i >= 1; i--)
    {
        swap(data[0], data[i]);
        heapSize--;
        MaxHeapify(data, 0);
    }
}

//Max heapify
void SortTool::MaxHeapify(vector<int> &data, int root)
{
    // Function : Make tree with given root be a max-heap if both right and left sub-tree are max-heap
    // TODO : Please complete max-heapify code here
    int left = root * 2 + 1;
    int right = root * 2 + 2;
    int largest;
    if (left < heapSize && data[left] > data[root]) //data[left]不知道會不會出事
    {
        largest = left;
    }
    else
    {
        largest = root;
    }
    if (right < heapSize && data[right] > data[largest])
    {
        largest = right;
    }
    if (largest != root)
    {
        std::swap(data[root], data[largest]);
        MaxHeapify(data, largest);
    }
}

//Build max heap
void SortTool::BuildMaxHeap(vector<int> &data)
{
    heapSize = data.size(); // initialize heap size
    // Function : Make input data become a max-heap
    // TODO : Please complete BuildMaxHeap code here
    for (int i = (heapSize / 2) - 1; i >= 0; i--)
    {
        MaxHeapify(data, i);
    }
}
