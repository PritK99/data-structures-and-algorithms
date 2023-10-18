/*
Approach 1: Brute force method to try and test all possible combinations
TLE
Time Complexity: O(n*k)
*/
class Solution {
public:
    int count = 0;
    void eval(vector <bool> &mask,vector<int>& nums, int pos, int target)
    {
        int sum = 0;
        for (int i = 0; i < mask.size(); i++)
        {
            if (mask[i] == 0)
            {
                sum+=nums[i];
            }
            else
            {
                sum-=nums[i];
            }
        }
        if (sum == target)
        {
            count++;
        }
    }

    void gen (vector <bool> &mask, vector<int>& nums, int pos, int target)
    {
        //base case
        if (pos == mask.size())
        {
            eval(mask, nums, pos, target);
            return;
        }
        // mask will be 0
        gen(mask, nums, pos+1, target);
        //mask will be 1
        mask[pos]=1;
        gen(mask, nums, pos+1, target);
        mask[pos]=0;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        vector <bool> mask (nums.size());
        gen(mask, nums, 0, target);
        return count;
    }
};