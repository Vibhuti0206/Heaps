#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main() {
    long long int q,k;
    cin>>q>>k;
    priority_queue<long long int> pq;
    while(q--)
    {
        int query;
        long long int x,y;
        cin>>query;
        if(query==1)
        {   cin>>x>>y;
           long long int distance=x*x+y*y;
           if(pq.size() < k)
           {
               pq.push(distance);
           }
           else if(pq.top() > distance)
        {
            pq.pop();
            pq.push(distance);
        }
        
        }
        else 
          cout<<pq.top()<<endl;
    }
	return 0;
}
