int gcd(int a,int b)
{
    if(a<b)
    return gcd(b,a);

    if(b==0)
    return a;

    return gcd(a%b,b);
}
int cmp(const void *a,const void* b)
{
    int aval=*(const int *)a;
    int bval=*(const int *)b;

    return aval-bval;
    
}
long long gcdSum(int* nums, int numsSize) {

    int pref[numsSize];
    int maxi=0;
    for(int i=0;i<numsSize;i++)
    {
        maxi=fmax(maxi,nums[i]);
        pref[i]=gcd(maxi,nums[i]);

    }
    qsort(pref,numsSize,sizeof(int),cmp);
    
    long long ans=0;
    int i=0,j=numsSize-1;
    while(i<j)
    ans+=gcd(pref[i++],pref[j--]);
    return ans;
    
}