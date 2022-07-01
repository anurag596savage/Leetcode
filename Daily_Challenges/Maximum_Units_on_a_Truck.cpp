class Solution {
public:
    static bool compare(vector<int>&a,vector<int>&b)
    {
        if(a[1]==b[1])
        {
            return a[0]>b[0];
        }
        return a[1]>b[1];
    }

int maximumUnits(vector<vector<int>>& boxTypes, int truckSize)
{
	sort(boxTypes.begin(),boxTypes.end(),compare);

	int cost=0,count=0;
	for(int i=0;i<boxTypes.size();i++)
	{
		if(count==truckSize)
		{
			break;
		}
		if(count+boxTypes[i][0]<=truckSize)
		{
			cost += boxTypes[i][0]*boxTypes[i][1];
			count += boxTypes[i][0];
		}
		else if(count+boxTypes[i][0]>truckSize)
		{
			int is_Possible = truckSize-count;
			cost += is_Possible*boxTypes[i][1];
			count += is_Possible;
		}
	}
	
	return cost;
}
};
