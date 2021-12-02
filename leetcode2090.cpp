class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(2 * k + 1 > nums.size())
            return vector<int>(nums.size(), -1);
        vector<int> result;
        long long curr = 0;
        for(int i = 0; i < k; i++)
            curr += nums[i];
        for(int i = 0; i < nums.size(); i++)
        {
            if(i + k < nums.size())
                curr += nums[i+k];
            if(i - k > 0)
                curr -= nums[i-k-1];
            if(k <= i && i < nums.size() - k)
                result.push_back(curr / (2 * k + 1));
            else
                result.push_back(-1);
        }
        return result;
    }
};
