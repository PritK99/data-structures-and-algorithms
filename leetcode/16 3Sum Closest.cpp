/*
Approach 1: Checking all possible combinations after sorting
Runtime: 44ms
Memory: 10.50MB
Time Complexity: O(nlog(n) + n^2) or O(n^2)     //Sorting + linear search for all elements
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int sum = 0, curr = 9999999;

        for (int i = 0; i < n-2; i++)
        {
            int start = i+1;
            int end = n-1;
            while(end>start)
            {
                int temp = nums[start]+nums[end]+nums[i];
                if (abs(temp-target)<curr)
                {
                    sum = temp;
                    curr = abs(temp-target);
                }
                if (temp>target)
                {
                    end--;
                }
                else
                {
                    start++;
                }
            }
        }
        return sum;
    }
};

/*
Approach 1: Checking all possible combinations after sorting with better pruning strategies
Runtime: 4ms
Memory: 10.45MB
Time Complexity: O(nlog(n) + n^2) or O(n^2)     //Sorting + linear search for all elements
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());

        if (nums[0] + nums[1] + nums[2] >= target) {
            return nums[0] + nums[1] + nums[2];
        }
        if (nums[nums.size() - 1] + nums[nums.size() - 2] + nums[nums.size() - 3] <= target) {
            return nums[nums.size() - 1] + nums[nums.size() - 2] + nums[nums.size() - 3];
        }

        int closest = nums[0] + nums[1] + nums[2];
        int n = nums.size();
        for (int i = 0; i < n - 2; ++i) {
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(sum - target) < abs(closest - target)) {
                    closest =sum;
                }
                if (sum < target) {
                    while (j + 1 < k && nums[j] == nums[j + 1]) {
                        ++j;
                    }
                    ++j;
                } else if (sum > target) {
                    while (k - 1 > j && nums[k] == nums[k - 1]) {
                        --k;
                    }
                    --k;
                } else {
                    return target;
                }
            }
        }
        return closest;
    }
};