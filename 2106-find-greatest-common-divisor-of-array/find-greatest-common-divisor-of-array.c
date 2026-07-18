int gcd(int a,int b)
{
    if(a<b)
    return gcd(b,a);
    if(b==0)
    return a;

    return gcd(b,a%b);
}
int findGCD(int* nums, int numsSize) {

    int maxi=0;
    int mini=1000;

    for(int i=0;i<numsSize;i++)
    {
        maxi=fmax(maxi,nums[i]);
        mini=fmin(mini,nums[i]);
    }
    return gcd(mini,maxi);
    
}