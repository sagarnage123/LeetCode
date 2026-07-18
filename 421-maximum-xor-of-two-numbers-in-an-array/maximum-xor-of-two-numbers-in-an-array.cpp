class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {

        int maxi=*max_element(nums.begin(),nums.end());
        if(maxi==0)
        return 0;
        int n=31- __builtin_clz(maxi);
        int mask=0,ans=0;
        unordered_set<int> hash;
        for(int i=n;i>=0;i--)
        {
            mask=mask|(1<<i);
            for(auto num:nums)
            {
                hash.insert(num&mask);
            }
            int temp=ans|(1<<i);
            for(auto key:hash)
            {
                if(hash.count(temp^key))
                {
                    ans=temp;
                    break;
                }
            }
            hash.clear();
        }
        return ans;
        
    }
};