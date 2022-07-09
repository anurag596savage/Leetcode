class Solution {
public:
    int minDeletions(string s) 
    {
        unordered_map<char,int>ourMap;
        for(int i=0;i<s.length();i++)
        {
            ourMap[s[i]]++;
        }
        priority_queue<int>pq;
        for(auto i : ourMap)
        {
            pq.push(i.second);
        }
        int ans = 0;
        while(!pq.empty())
        {
            int x = pq.top();
            pq.pop();
            if(!pq.empty() && x==pq.top())
            {
                ans++;
                if(--x)
                {
                    pq.push(x);
                }
            }
        }
        return ans;
    }
};
