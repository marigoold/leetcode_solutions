class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int min_idx = -1;
        int max_idx = -1;
        int max_value = INT_MIN;
        int min_value = INT_MAX;
        for(int i = 0; i < nums.size(); i++)        
        {
            if(nums[i] > max_value)
            {
                max_value = nums[i];
                max_idx = i;
            }
            if(nums[i] < min_value)
            {
                min_value = nums[i];
                min_idx = i;
            }
        }
        int n = nums.size();
        if(min_idx == max_idx)
            return 1;
        if(min_idx > max_idx)
            swap(min_idx, max_idx);
        return min(max_idx + 1, min((n - min_idx), min_idx + 1 + (n - max_idx)));
    }
};
