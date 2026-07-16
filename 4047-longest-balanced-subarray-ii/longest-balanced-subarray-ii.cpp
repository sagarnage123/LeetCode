struct Node{
    int maxi,mini,lazy;
    Node():maxi(-100001),mini(100001),lazy(0){}
    Node(int x):maxi(x),mini(x),lazy(0){}
};

class SegmentTree{

    vector<Node> tree;
    public:
    SegmentTree(int n)
    {
        tree.resize(n*4,Node(0));
    }

    void add(int ind,int l,int r,int idx,int val)
    {
        if(l==r)
        {
            tree[ind].mini=tree[ind].maxi=val;
            
            return ;
        }
        int mid=(l+r)>>1;

        if(idx<=mid)
        add(ind*2+1,l,mid,idx,val);
        else add(ind*2+2,mid+1,r,idx,val);

        pull(ind);
    }
    void rangeUpdate(int ind,int l,int r,int x,int y,int val)
    {
        
        push(ind,l,r);

        if(l>y || r<x)
        return;
        if(l==r)
        {
            tree[ind].mini+=val;
            tree[ind].maxi+=val;
            return;
        }


        if(l>=x && r<=y)
        {
            tree[ind].lazy+=val;
            push(ind,l,r);
            return;
        }

        int mid=(l+r)>>1;
        rangeUpdate(ind*2+1,l,mid,x,y,val);
        rangeUpdate(ind*2+2,mid+1,r,x,y,val);
        pull(ind);
        
    }
    // void temp(int ind,int l,int r)
    // {
    //     push(ind,l,r);
    //     if(l==r)
    //     {
    //         cout<<l<<","<<tree[ind].mini<<"  ";
    //         return;
    //     }
    //     int mid=(l+r)>>1;
    //     temp(ind*2+1,l,mid);
    //     temp(ind*2+2,mid+1,r);
    // }
    int last0(int ind,int l,int r)
    {

        push(ind,l,r);
        
        if(l>r)
        return -1;

        if(tree[ind].mini>0 || tree[ind].maxi<0)
        return -1;

        if(l==r)
            return l;

        int mid=(l+r)>>1;
        int idx=last0(ind*2+2,mid+1,r);
        
        if(idx==-1)
        {
            idx=last0(ind*2+1,l,mid);
        }
        pull(ind);
        return idx;
        
    }
    void pull(int ind)
    {
        tree[ind].maxi=max(tree[ind*2+1].maxi,tree[ind*2+2].maxi);
        tree[ind].mini=min(tree[ind*2+1].mini,tree[ind*2+2].mini);
    }
    void push(int ind,int l,int r)
    {
        tree[ind].maxi+=tree[ind].lazy;
        tree[ind].mini+=tree[ind].lazy;
        if(l<r)
        {
            tree[ind*2+1].lazy+=tree[ind].lazy;
            tree[ind*2+2].lazy+=tree[ind].lazy;
        }
            tree[ind].lazy=0;
        return;
    }

};

bitset<100001> seen;

class Solution {
    
public:
    int longestBalanced(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        int n=nums.size();
        SegmentTree tr(n);
        int cur=0;
        vector<int> next(n,n);
        vector<int> hash(maxi+1);
        seen=0;
        for(int i=0;i<n;i++)
        {
            if(!seen[nums[i]])
            {
                cur+=(1-2*(nums[i]&1));
                seen[nums[i]]=1;
            }
            
            tr.add(0,0,n-1,i,cur);
            
        }
        
        if(cur==0)
        return n;

        for(int i=n-1;i>=0;i--)
        {
            if(hash[nums[i]])
            next[i]=hash[nums[i]];

            hash[nums[i]]=i;
        }

        int ans=tr.last0(0,0,n-1)+1;

        for(int i=0;i<n;i++)
        {
            int r=next[i]-1;
            int val=1-2*(1&nums[i]);
            tr.rangeUpdate(0,0,n-1,i,r,-val);
            
            
            if(i+ans<n)
            {
                int last=tr.last0(0,0,n-1);
                if(last>=i)
                ans=max(ans,last-i);
                cout<<last<<" \n";

            }
            else break;

        }
        return ans;



        

    }
};