/**********************************************************
 * C++ Learning Practise
 * 7/3/2019
 * Heap sort 
 * https://www.youtube.com/watch?v=2DmK_H7IdTo
 * **********************************************************/

#include<iostream>
#include<iomanip>
#include<vector>
#include"time.h"
using namespace std;

class MyVector
{
    public:
        vector<int> array;
        int length;

        MyVector(vector<int> &arr, int len)
        {
            length = len;
            if (arr.size() < len)
            {
                array = arr;
                for (int i = 0; i < (len - arr.size()); i++)
                {
                    array.push_back(rand() % 100);
                }
            }
        }

        MyVector(int len)
        {
            length = len;
            for (int i=0; i<len; i++)
            {
                array.push_back(rand() % 100);
            }
        }
};

void print_array(int arr[], int len);
/* Input: vector arr and the length.
   Output: std, printing all int numbers in the arr */

void heapSort(int arr[], int length);
/* */

void heapify(int arr[], int ind ,int length);
/* Since a Binary Heap is a Complete Binary Tree, it can be 
 easily represented as array and array based representation 
 is space efficient. If the parent node is stored at index
 I, the left child can be calculated by 2 * I + 1 and right
 child by 2 * I + 2 (assuming the indexing starts at 0). */

int main(int argc, char* argv[])
{
    struct timespec start, end;
    int length = atoi(argv[1]);
    MyVector* arr1 = new MyVector(length);
    int* arr = &arr1->array[0];
    //print_array(arr, length);

    clock_gettime(CLOCK_MONOTONIC, &start);
    heapSort(arr, length);
    clock_gettime(CLOCK_MONOTONIC, &end);
    //print_array(arr, length);

    double time_taken;
    time_taken = (end.tv_sec - start.tv_sec) * 1e9;
    time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9;

    cout //<< "Time taken by program is : " << fixed
         << time_taken*1000.0 << setprecision(9)<<endl;
    //cout << " msec" << endl;

    return 0;
}

void print_array(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void heapSort(int arr[], int length)
{
    // Build max heap.
    for (int i=length/2-1; i>=0; i--)
    {
        heapify(arr, i , length);
    }

    // Extract element from the heap.
    for (int i=length-1; i>=0; i--)
    {
        //print_array(arr, length);
        // Move the current max to the end.
        swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap.
        heapify(arr, 0, i);
    }
}

void heapify(int arr[], int ind, int length)
{
    int left   = ind*2 + 1; // True for ind starting with
    int right  = ind*2 + 2; // zero
    int larger = ind;       // Initialize the largering index.

    // if left child is larger than parent. 
    if (left<length  && arr[larger]<arr[left])
    {
        larger = left;
    }
    if (right<length && arr[larger]<arr[right])
    {
        larger = right;
    }

    // If the largest is not yet found.
    if (larger != ind)
    {
        swap(arr[larger],arr[ind]);
        // Continue heapify recursively.
        heapify(arr, larger, length);
    }
} 