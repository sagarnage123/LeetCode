class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> pref(n);
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,nums[i]);
            pref[i]=__gcd(maxi,nums[i]);
        }
        sort(pref.begin(),pref.end());
        int i=0,j=n-1;
        long long ans=0;
        while(i<j)
        ans+=__gcd(pref[i++],pref[j--]);

        return ans;

        
    }
};