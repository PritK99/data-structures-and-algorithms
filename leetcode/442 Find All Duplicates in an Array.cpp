/*
Approach 1: Sort and find duplicates
Runtime: 44ms
Memory: 33.9MB
Time Complexity: O(nlogn)
Space Complexity: 0(1)
*/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector <int> answer;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == nums[i-1])
            {
                answer.push_back(nums[i]);
            }
        }
        return answer;
    }
};

/*
Approach 2: Using unordered maps
Runtime: 74ms
Memory: 44.96MB
Time Complexity: O(n)
Space Complexity: 0(n)
*/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map <int, int> umap;
        vector <int> ans;
        for (int i = 0; i< nums.size(); i++)
        {
            if (umap[nums[i]] == 1)
            {
                ans.push_back(nums[i]);
            }
            umap[nums[i]]++;
        }
        return ans;
    }
};

/*
Approach 3: Using array indices itself to track if the number has appeared before.
Runtime: 48ms
Memory: 33.87MB
Time Complexity: O(n)
Space Complexity: 0(1)
*/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans;
        for (int i = 0; i<n; i++)
        {
            if (nums[i] > 0)
            {
                if(nums[nums[i]-1] < 0)
                {
                    ans.push_back(nums[i]);
                }
                else
                {
                    nums[nums[i]-1] = -nums[nums[i]-1];
                }
            }
            else
            {
                if(nums[(-nums[i])-1] < 0)
                {
                    ans.push_back(-nums[i]);
                }
                else
                {
                    nums[(-nums[i])-1] = -nums[(-nums[i])-1];
                }
            }
        }
        return ans;
    }
};