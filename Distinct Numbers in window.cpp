
vector<int> helper(vector<int> A,int k)
{
    vector<int> v;
    if(k >A.size())
     return v;
    map<int,int> m;
    int count = 0;
    for(int i=0;i<k;i++)
    {
        if(m[A[i]] == 0)
        {
            count++;
        }
        m[A[i]]++;
    }
    v.push_back(count);
    for(int i=k;i<A.size();i++)
    {
        if(m[A[i-k]] == 1)
         count--;
        m[A[i-k]]--;
        if(m[A[i]] == 0)
         count++;
        m[A[i]]++;
        v.push_back(count);
    }
    return v;
}
vector<int> Solution::dNums(vector<int> &A, int B) {
   return helper(A,B);
}
