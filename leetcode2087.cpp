class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int result = 0;
        for(int i = homePos[0]; i != startPos[0]; )
        {
            result += rowCosts[i];
            if(homePos[0] < startPos[0])
                i++;
            else
                i--;
        }
        for(int i = homePos[1]; i != startPos[1]; )
        {
            result += colCosts[i];
            if(homePos[1] < startPos[1])
                i++;
            else
                i--;
        }
        return result;
    }
};
