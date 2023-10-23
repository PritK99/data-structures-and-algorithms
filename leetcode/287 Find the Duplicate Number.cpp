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
Approach 2: Linear search maintaing count for all numbers in [1,n]
Runtime: TLE
Time Complexity: O(n^2)
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        for (int j = 1; j <= n; j++)
        {
            int count = 0;
            for (int i = 0; i < n; i++)
            {
                if (j >= nums[i])
                {
                    count++;
                }
            }
            if (count > j)
            {
                return j;
            }
        }
        return 0;
    }
};

/*
Approach 3: Using binary search and maintaining count
Runtime: 122ms
Memory: 61.56MB
Time Complexity: O(nlog(n))
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int start = 1;
        int end = n;
        int mid = 0;
        int duplicate = -1;
        
        while (end >= start)
        {
            mid = (end + start)/2;
            int count = 0;
            for (int i = 0; i < n; i++)
            {
                if (mid >= nums[i])
                {
                    count++;
                }
            }
            if (count > mid)
            {
                duplicate = mid;
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
        
        return duplicate;
    }
};

/*
Approach 4: Using flyod cycle detection algorithm using fast and slow pointers
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