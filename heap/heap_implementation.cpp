#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
    int *arr;
    int size;
    int capacity;
    MinHeap(int c)
    {
        arr = new int[c];
        size = 0;
        capacity = c;
    }
    int left(int i)
    {
        return 2 * i + 1;
    }
    int right(int i)
    {
        return 2 * i + 2;
    }
    int parent(int i)
    {
        return (i - 1) / 2;
    }
    void insert(int x) // timecomplexity O(logsize)
    {
        if (size == capacity)
            return;
        size++;
        arr[size - 1] = x;
        for (int i = size - 1; i != 0 && arr[parent(i)] > arr[i]; i--)
        {
            swap(arr[i], arr[parent(i)]);
        }
    }
    void minHeapify(int i) //timecomplexity O(logn) auxiliary space O(h)
    {
        int lt = left(i), rt = right(i);
        int smallest = i;
        if(lt<size && arr[lt]<arr[i])
            smallest = lt;
        if(rt<size && arr[rt]<arr[i])
            smallest = rt;
        if(smallest!=i){
            swap(arr[i], arr[smallest]);
            minHeapify(smallest);
        }
    }
    int extractMin(){ //timecomplexity O(logn) auxiliary space O(h)
        if(size==0)
            return INT_MAX;
        if(size==1){
            size--;
            return arr[0];
        }
        swap(arr[0], arr[size-1]);
        size--;
        minHeapify(0);
        return arr[size];
    }
};