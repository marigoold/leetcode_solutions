// 左右前缀和算最大可行的宽度，上下dp求最大可行的高度

class Solution {
public:
    int countPyramids(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> left(m, vector<int>(n, 0));
        vector<vector<int>> right(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(j == 0)
                    left[i][j] = grid[i][j];
                else
                    left[i][j] = (grid[i][j] == 1) ? left[i][j-1] + 1: 0;
            }
        }
        for(int i = 0; i < m; i++)
        {
            for(int j = n - 1; j >= 0; j--)
            {
                if(j == n - 1)
                    right[i][j] = grid[i][j];
                else
                    right[i][j] = (grid[i][j] == 1) ? right[i][j+1] + 1: 0;
                left[i][j] = min(left[i][j], right[i][j]);
            }
        }
        int result = 0;
        auto dp = left;
        for(int j = 0; j < n; j++)
        {
            for(int i = 0; i < m; i++)
            {
                if(i == 0) 
                    dp[i][j] = min(dp[i][j], 1);
                else
                    dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
                result += max(dp[i][j] - 1, 0);
            }
        }
        dp = left;
        for(int j = 0; j < n; j++)
        {
            for(int i = m - 1; i >= 0; i--)
            {
                if(i == m - 1)
                    dp[i][j] = min(dp[i][j], 1);
                else
                    dp[i][j] = min(dp[i][j], dp[i+1][j] + 1);
                result += max(dp[i][j] - 1, 0);
            }
        }
        return result;
    }
};
