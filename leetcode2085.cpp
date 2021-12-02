class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> m1, m2;
        for(string& s: words1)
            m1[s]++;
        for(string& s: words2)
            m2[s]++;
        int result = 0;
        for(auto& p: m1)
            if(m2[p.first] == 1 && p.second == 1)
                result++;
        return result;
    }
};
