vector<int> Solution::plusOne(vector<int> &A) 
{
    A.insert(A.begin(),0);
    int n=A.size();
    int i;
    for(i=n-1;i>=0;i--)
    {
        if(A[i]<9)
        {
            A[i]++;
            break;
        }
        else
        {
            A[i]=0;
        }
    }
    while(A[0]==0 && A.size()>1)
    {
        A.erase(A.begin());
    }
    return A;
}
