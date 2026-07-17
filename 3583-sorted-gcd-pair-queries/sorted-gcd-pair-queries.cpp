class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        int maxi=*max_element(nums.begin(),nums.end());
        vector<int> freq(maxi+1,0);
        vector<long long> gcd(maxi+1,0);
        for(auto num:nums)
        freq[num]++;
        
        for(int i=maxi;i>0;i--)
        {
            long long tot=0;
            long long totgcd=0;
            for(int j=i;j<=maxi;j+=i)
            {
                tot+=freq[j];
                totgcd+=gcd[j];

            }
            
            gcd[i]=tot*(tot-1)/2;
            gcd[i]-=totgcd;
        }
        for(int i=1;i<=maxi;i++)
        gcd[i]+=gcd[i-1];

        vector<int> ans(queries.size());
        for(int i=0;i<queries.size();i++)
        ans[i]=upper_bound(gcd.begin(),gcd.end(),queries[i])-gcd.begin();

        return ans;
    }
};