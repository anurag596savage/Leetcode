int minMoves2(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());

        int start = 0,end = nums.size()-1;
        int ans = 0;
        while(start<end)
        {
            ans += abs(nums[end]-nums[start]);
            start++;
            end--;
        }

        return ans;
    } 
