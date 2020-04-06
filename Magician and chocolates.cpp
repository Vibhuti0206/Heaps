long int helper(int k,vector<int> B)
{
    if(k==0)
     return 0;
   long int count = 0;
   
    priority_queue<long int> pq;
    for(int i=0;i<B.size();i++)
      pq.push(B[i]);
    while(k--)
    {
        long int front = pq.top();
        count += front;
        pq.pop();
        pq.push(front/2);
    }
    return count;
}
int Solution::nchoc(int A, vector<int> &B) {
    long int choco = helper(A,B);
    int ans = choco %(1000000007);
    return ans;
    
}
