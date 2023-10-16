/*
Approach 1: count number of 0s, 1s and 2s and then edit the array in next pass
Runtime: 0ms
Memory: 8.50MB
Time Complexity: O(n)
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0;
        int white = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                red++;
            }
            else if (nums[i] == 1)
            {
                white++;
            }
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (red > 0)
            {
                red--;
                nums[i] = 0;
            }
            else if (white > 0)
            {
                white--;
                nums[i] = 1;
            }
            else
            {
                nums[i]=2;
            }
        }
    }
};

/*
Approach 2: One pass algorithm using two pointers
Runtime: 4ms
Memory: 8.43MB
Time Complexity: O(n)
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int x = 0, i = 0, y = nums.size()-1;

        while (i <= y)
        {
            if (nums[i] == 0)
            {
                swap(nums[i], nums[x]);
                i++;
                x++;
            }
            else if (nums[i] == 2)
            {
                swap(nums[y], nums[i]);
                y--;
            }
            else
            {
                i++;
            }
        }
    }
};