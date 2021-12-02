// 思路：并查集
// 遍历每个时间，对在这个时间开会的人中进行一次并查集合并，模拟信息交流，并查集合并完将没有听到秘密的人重置，再遍历下个时间

class Solution {
public:
    struct cmp
    {
        bool operator()(vector<int>& a, vector<int>& b){
            return a[2] < b[2];
        }
    };

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        meetings.push_back({0, firstPerson, 0});
        vector<int> father(n);
        iota(father.begin(), father.end(), 0);
        sort(meetings.begin(), meetings.end(), cmp());
        for(int i = 0; i < meetings.size(); )
        {
            for(int j = i + 1; j <= meetings.size(); j++)
            {
                if(j == meetings.size() || meetings[i][2] != meetings[j][2])
                {
                    make_union(meetings, i, j, father, firstPerson);
                    i = j;
                    break;
                }
            }
        }
        vector<int> result;
        int first_father = find_union(father, firstPerson);
        for(int i = 0; i < n; i++)
            if(find_union(father, i) == first_father)
                result.push_back(i);
        return result;
    }

    void make_union(const vector<vector<int>>& meetings, int begin, int end, vector<int>& father, int first_person)
    {   
        // unordered_set<int> candidate;
        for(int i = begin; i < end; i++)    
        {
            int a = meetings[i][0];
            int b = meetings[i][1];
            // candidate.insert(a);
            // candidate.insert(b);
            if(a > b)
                swap(a, b);
            combine_union(father, a, b);
        }
        init_union(meetings, father, begin, end, first_person);
    }

    int find_union(vector<int>& father, int x)
    {
        if(father[x] != x)
            father[x] = find_union(father, father[x]);
        return father[x];
    }

    void combine_union(vector<int>& father, int i, int j)
    {
        int i_father = find_union(father, i);
        int j_father = find_union(father, j);
        if(i_father != j_father)
            father[i_father] = j_father;
    }

    void init_union(const vector<vector<int>>& meetings, vector<int>& father, int begin, int end, int first_person)
    {
        int first_person_father = find_union(father, first_person);
        for(int i = begin; i < end; i++)
        {
            if(find_union(father, meetings[i][0]) != first_person_father)
                father[meetings[i][0]] = meetings[i][0];
            if(find_union(father, meetings[i][1]) != first_person_father)
                father[meetings[i][1]] = meetings[i][1];
        }
    }
};
