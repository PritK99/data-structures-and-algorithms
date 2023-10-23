/*
Approach 1: Compare each element with all elements of array
Runtime: TLE
Time Complexity: O(n^2)
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j< n; j++)
            {
                if (nums[i]==nums[j])
                {
                    return nums[i];
                }
            }
        }
        return 0;
    }
};

/*
Approach 2: Using flyod cycle detection algorithm using fast and slow pointers
Runtime: 81ms
Memory: 61.64MB
Time Complexity: O(n)
*/
class Solution {
public:
    int findDuplicate(vector<int>& num) {
        int slow = 0;
        int fast = 0;

        do
        {
            slow = num[slow];
            fast = num[num[fast]];
        }
        while (slow != fast);
        cout << slow << fast ;
        fast = 0;

        while(slow != fast)
        {
            fast = num[fast];
            slow=num[slow];
        }

        return slow;
    }
};