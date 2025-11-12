#include <bits/stdc++.h>
using namespace std;

void radixsort(vector<int>&arr){
    int maxvalue=*max_element(arr.begin(),arr.end());
    for(int i=1;maxvalue/i>0;i++){
        vector<vector<int>>bucket(10);
        for(int num:arr){
            int digit=(num/i)%10;
            bucket[digit].push_back(num);
        }
        int idx=0;
        for(int i=0;i<10;i++){
            for(int num:bucket[i]){
                arr[idx++]=num;
            }
        }
    }
}
void countsort(vector<int>&arr){
    int maxvalue=*max_element(arr.begin(),arr.end());
    vector<int>outside(maxvalue+1,0);
    for(int num:arr)outside[num]++;
    int idx=0;
    for(int i=0;i<=maxvalue;i++){
        while(outside[i]-->0){
            arr[idx++]=i;
        }
    }
}

// Helper function to maintain max heap property
// Assumes left and right subtrees are heaps, but root might violate heap property
void heapify(vector<int>&arr, int n, int i){
    int largest = i;  // Initialize largest as root
    int left = 2 * i + 1;      // Left child index
    int right = 2 * i + 2;     // Right child index
    
    // If left child exists and is greater than root
    if(left < n && arr[left] > arr[largest])
        largest = left;
    

    // If right child exists and is greater than largest so far
    if(right < n && arr[right] > arr[largest])
        largest = right;
    
    // If largest is not root, swap and recursively heapify
    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Main heapsort function
// Time Complexity: O(n log n), Space Complexity: O(1)
void heapsort(vector<int>&arr){
    int n = arr.size();
    
    // Build max heap from bottom-up
    // Start from last non-leaf node and heapify downwards
    for(int i = n/2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }
    
    // Extract elements from heap one by one
    // After each extraction, place it at the end
    for(int i = n - 1; i > 0; i--){
        // Move current root (max element) to end
        swap(arr[0], arr[i]);
        // Heapify reduced heap
        heapify(arr, i, 0);
    }
}
void bucketSort(vector<float>& arr) {
    int n = arr.size();
    if (n <= 0) return;

    // Step 1️⃣: Create n empty buckets
    vector<vector<float>> buckets(n);

    // Step 2️⃣: Put array elements into different buckets
    for (int i = 0; i < n; i++) {
        int index = n * arr[i];   // Index depends on value range [0,1)
        if (index == n) index = n - 1; // handle 1.0 edge case
        buckets[index].push_back(arr[i]);
    }

    // Step 3️⃣: Sort individual buckets
    for (int i = 0; i < n; i++)
        sort(buckets[i].begin(), buckets[i].end());

    // Step 4️⃣: Concatenate all buckets into arr
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (float val : buckets[i])
            arr[idx++] = val;
    }
}

int main(){
     vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
     radixsort(arr);
     for(int num:arr)cout<<num<<" ";
     cout << "\n";
     countsort(arr);
     for(int num:arr)cout<<num<<" ";
     cout << "\n";
     heapsort(arr);
     for(int num:arr)cout<<num<<" ";
     cout << "\n";
     vector<float> arr1 = {170, 45, 75, 90, 802, 24, 2, 66};
     bucketSort(arr1);
    for(int num:arr1)cout<<num<<" ";
    return 0;
}