class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) 
    {
        int sum = accumulate(cardPoints.begin(),cardPoints.end(),0);
        if(k==cardPoints.size())
        {
            return sum;
        }
        int remaining = cardPoints.size()-k;
        int window_sum = 0;
        for(int i=0;i<remaining;i++)
        {
            window_sum = window_sum + cardPoints[i];
        }
        int current_sum = window_sum;
        for(int i=remaining;i<cardPoints.size();i++)
        {
            current_sum = current_sum - cardPoints[i-remaining];
            current_sum += cardPoints[i];
            window_sum = min(window_sum,current_sum);
        }
        
        return (sum-window_sum);
    }
};
