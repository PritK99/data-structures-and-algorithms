/*
Approach 1: Maitaining succesor and predecessor product
Runtime: 16ms
Memory: 25.3MB
Time Complexity: O(n)
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector <int> pred (n);
        vector <int> succ (n);
        pred[0]=1;
        succ[n-1]=1;
        for (int i = 1; i < n; i++)
        {
            pred[i] = nums[i-1]*pred[i-1];
        }

        for (int i = n-2; i >= 0; i--)
        {
            succ[i] = nums[i+1]*succ[i+1];
        }

        for (int i = 0; i < n; i++)
        {
            nums[i] = pred[i]*succ[i];
        }

        return nums;
    }
};