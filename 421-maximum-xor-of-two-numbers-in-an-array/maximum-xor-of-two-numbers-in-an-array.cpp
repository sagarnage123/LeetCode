class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {

        unordered_map<int,int>hash;
        
        int mask=0,ans=0;
        for(int i=31;i>=0;i--)
        {
            mask=mask|(1<<i);
            unordered_map<int,int> hash;
            for(auto num:nums)
            {
                hash[num&mask]=1;
            }
            int temp=ans|(1<<i);
            for(auto [key,val]:hash)
            {
                if(hash.count(temp^key))
                {
                    ans=temp;
                    break;
                }
            }
        }
        return ans;
        
    }
};