/*
Approach 1: Brute force method to try and test all possible combinations
TLE
Time Complexity: O(2^n)
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

/*
Approach 2: Brute Force Recursion with better method to obtain sum
TLE
Time Complexity: O(2^n), where m*n is dimension of board and w is length of word
*/
class Solution {
public:
int count = 0;
    void gen (vector <bool> &mask, vector<int>& nums, int pos, int target, int sum)
    {
        //base case
        if (pos == mask.size())
        {
            if (sum == target)
            {
                count++;
            }
            return;
        }

        //rec case

        // mask will be 0
        gen(mask, nums, pos+1, target, sum+nums[pos]);
        //mask will be 1
        mask[pos]=1;
        gen(mask, nums, pos+1, target, sum-nums[pos]);
        mask[pos]=0;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        vector <bool> mask (nums.size());
        gen(mask, nums, 0, target, 0);
        return count;
    }
};