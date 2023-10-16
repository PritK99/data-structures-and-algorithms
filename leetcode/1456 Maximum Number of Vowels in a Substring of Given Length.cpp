/*
Approach 1: sliding a static window of size k over string and checking maximum everytime
Runtime: 2077ms
Memory: 10.20MB
Time Complexity: O(n+k)
*/
class Solution {
public:
    int maxVowels(string s, int k) {
        int l = s.length();
        int max = 0;
        for (int i = 0; i <= l - k && max != k; i++)
        {
            int curr = 0;
            //if a vowel is hit
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                curr++;
                for (int j = i+1; j < k+i; j++)
                {
                    if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
                    {
                        curr++;
                    }
                }
                if (curr > max)
                {
                    max = curr;
                }
            }
        }
        int curr = 0;
        for (int j = l-k+1; j < l && max!=k; j++)
        {
            if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
            {
                curr++;
            }
        }
        if (curr > max)
        {
            max = curr;
        }
        return max;
    }
};

/*Approach 2: sliding a static window of size k over string and tracking vowels which came in and went out of window
Runtime: 15ms
Memory: 10.26MB
Time Complexity: O(n+k)
*/
class Solution {
public:
    int maxVowels(string s, int k) {
        int l = s.length();
        //case1
        if (l <= k)
        {
            int curr = 0;
            for (int i = 0; i < l; i++)
            {
                if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                {
                    curr++;
                }
            }
            return curr;
        }
        else
        {
            int max = 0;
            int curr = 0;
            //check first k letters as baseline
            for (int i = 0; i < k; i++)
            {
                if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                {
                    max++;
                }
            }  
            curr = max;
            for (int i = 1; i <= l-k; i++)
            {
                //if we a vowel was dropped from sliding window
                if (s[i-1] == 'a' || s[i-1] == 'e' || s[i-1] == 'i' || s[i-1] == 'o' || s[i-1] == 'u')
                {
                    curr--;
                }
                //if new letter of window is a vowel
                if (s[i+k-1] == 'a' || s[i+k-1] == 'e' || s[i+k-1] == 'i' || s[i+k-1] == 'o' || s[i+k-1] == 'u')
                {
                    curr++;
                }
                if (curr > max)
                {
                    max = curr;
                }
            } 
            return max;        
        }
    }
};