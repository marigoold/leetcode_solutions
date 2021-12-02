class Solution {
public:
    int minimumBuckets(string street) {
        int result = 0;
        if(street.size() < 2)
            return street[0] == '.' ? 0: -1;
        for(int i = 0; i < street.size(); i++)
        {
            if(street[i] == 'H')
            {
                if(i == 0)
                {
                    if(street[i+1] == 'H')
                        return -1;
                    street[i+1] = 'B';
                }
                else if(i == street.size() - 1)
                {
                    if(street[i-1] == 'H')
                        return -1;
                    street[i-1] = 'B';
                }
                else
                {
                    if(street[i-1] == 'H' && street[i+1] == 'H')
                        return -1;
                    if(street[i+1] == 'H')
                    {
                        street[i-1] = 'B';
                        continue;
                    }
                    if(street[i-1] == 'B')
                        continue;
                    if(street[i+1] == '.')
                        street[i+1] = 'B';
                }
            }
        }
        for(char c: street)
            if(c == 'B')
                result ++;
        return result;
    }
};
