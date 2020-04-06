vector<int> helper(vector<int>A,vector<int> B)
{
   sort(A.begin(),A.end());
   sort(B.begin(),B.end());
   int n = A.size();
   int k = n;
   priority_queue<pair<int,pair<int,int>>> heap;
   vector<int> v;
   set<pair<int,int>> s;
   heap.push(make_pair((A[n-1] + B[n-1]),make_pair(n-1,n-1)));
   s.insert(make_pair(n-1,n-1));
   while(k--)
   {
       pair<int,pair<int,int>> front = heap.top();
       heap.pop();
       v.push_back(front.first);
       int i = front.second.first;
       int j = front.second.second;
       pair<int,int> temp1 = make_pair(i-1,j);
       if(s.find(temp1) == s.end())
       {
            heap.push(make_pair((A[i-1]+B[j]),temp1));
            s.insert(temp1);
       }
      pair<int,int> temp2 = make_pair(i,j-1);
       if(s.find(temp2) == s.end())
       {
            heap.push(make_pair((A[i]+B[j-1]),temp2));
            s.insert(temp2);
       }

   }
   return v;
}
vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    return helper(A,B);
}
