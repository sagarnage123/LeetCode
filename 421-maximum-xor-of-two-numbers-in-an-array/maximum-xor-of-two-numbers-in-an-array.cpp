struct Node{

    Node* links[2];
    Node()
    {
        this->links[0]=this->links[1]=NULL;
    }

};
class Trie{
    Node *root;
    public:
    Trie()
    {
        root=new Node();
    }

    void add(int num)
    {
        Node* mover=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(!mover->links[bit])
            {
                mover->links[bit]=new Node();
            }
            
            
            mover=mover->links[bit];
        }
        
    }
    int query(int num)
    {
        int ans=0;
        Node* mover=root;
        for(int i=31;i>=0 ;i--)
        {
            int bit=(num>>i)&1;
            
            if(mover->links[!bit])
            {
                ans=ans|(1<<i);
                mover=mover->links[!bit];
                
            }
            else 
            {
                mover=mover->links[bit];
            }
              
        }
        
        
        return ans;
    }

};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {

        Trie tr;
        for(auto num:nums)
        tr.add(num);

        int ans=0;
        for(auto num:nums)
        ans=max(ans,tr.query(num));

        return ans;
        
    }
};