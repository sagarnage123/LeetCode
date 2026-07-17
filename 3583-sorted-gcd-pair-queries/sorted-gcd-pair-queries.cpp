int freq[50001];
long long gcdArray[50001]={0};
class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        int maxi=*max_element(nums.begin(),nums.end());
        // vector<int> freq(maxi+1,0);
        // vector<long long> gcd(maxi+1,0);
        memset(freq,0,sizeof(freq));
        memset(gcdArray,0,sizeof(gcdArray));
        for(auto num:nums)
        freq[num]++;
        
        for(int i=maxi;i>0;i--)
        {
            long long tot=0;
            long long totgcd=0;
            for(int j=i;j<=maxi;j+=i)
            {
                tot+=freq[j];
                totgcd+=gcdArray[j];

            }
            
            gcdArray[i]=tot*(tot-1)/2;
            gcdArray[i]-=totgcd;
        }
        for(int i=1;i<=maxi;i++)
        gcdArray[i]+=gcdArray[i-1];

        vector<int> ans(queries.size());
        for(int i=0;i<queries.size();i++)
        ans[i]=upper_bound(gcdArray,gcdArray+maxi,queries[i])-gcdArray;

        return ans;
    }
};