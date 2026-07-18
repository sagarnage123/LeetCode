class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {

        unordered_map<int,int>hash;
        
        int mask=0,ans=0;
        for(int i=31;i>=0;i--)
        {
            mask=mask|(1<<i);
            unordered_set<int> hash;
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
        }
        return ans;
        
    }
};