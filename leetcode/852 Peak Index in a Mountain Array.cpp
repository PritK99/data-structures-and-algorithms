/*
Approach 1: Static Sliding Window of size 3
Runtime: 89ms
Memory: 59.95MB
Time Complexity: O(n)   
*/
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        for (int i = 1; i < n-1; i++)
        {
            if (arr[i]>arr[i+1] && arr[i]>arr[i-1])
            {
                return i;
            }
        }
        return 0;
    }
};

/*
Approach 1: Binary Search
Runtime: 74ms
Memory: 59.97MB
Time Complexity: O(log(n))
*/
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0;
        int end = arr.size()-1;
        int i = 0;

        while(end > start)
        {
            i = (start+end) / 2;

            if (arr[i]>arr[i+1] && arr[i]>arr[i-1])
            {
                return i;
            }
            else if (arr[i]>arr[i-1] && arr[i]<arr[i+1])
            {
                start = i;
            }
            else
            {
                end = i;
            }
        }
        return 0;
    }
};