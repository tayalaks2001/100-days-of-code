#include<iostream.h>
using namespace std;

// More sorting algos - merge sort and counting sort


// merge sort - merge function
void merge(vector<int> &nums, int start, int end){
        int mid = (start+end)/2;
        int i = start, j = mid+1;
        vector<int> v;
        while (i <= mid and j <= end){
            if (nums[i] <= nums[j]){
                v.push_back(nums[i]);
                i++;
            }
            else{
                v.push_back(nums[j]);
                j++;
            }
        }
        while (i <= mid){
            v.push_back(nums[i]);
            i++;
        }
        while (j <= end){
            v.push_back(nums[j]);
            j++;
        }
        
        for (int i=0; i<v.size(); i++){
            nums[start+i] = v[i];
        }
    }
    
// merge sort - main recursive function
    void mergeSort(vector<int> &nums, int start, int end){
        if (start >= end)
            return;
        
        int mid = (start+end)/2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid+1, end);
        merge(nums, start, end);
    }


// counting sort
void countSort(vector<int>& arr){
        int max = *max_element(arr.begin(), arr.end());
        int min = *min_element(arr.begin(), arr.end());
        int range = max - min + 1;

        vector<int> count(range), output(arr.size());
        for (int i = 0; i < arr.size(); i++)
            count[arr[i] - min]++;

        for (int i = 1; i < count.size(); i++)
            count[i] += count[i - 1];

        for (int i = arr.size() - 1; i >= 0; i--) {
            output[count[arr[i] - min] - 1] = arr[i];
            count[arr[i] - min]--;
        }

        for (int i = 0; i < arr.size(); i++)
            arr[i] = output[i];
    }
