#include<bits/stdc++.h>
using namespace std;
void calculate()
{
    {
		priority_queue< int> maxh;
	priority_queue< int,vector<int>,greater<int>> minh;
int median = 0 ;
	int maxsize = 0;
	int minsize = 0;
	int size ;
	cin>>size;
	while(size--)
	{
		int n;
		cin>>n;
		if(n < median)
		{
			maxh.push(n);
			maxsize++;
		}
		else
		{
			minh.push(n);
			minsize++;
		}
		if(abs(minsize - maxsize) == 2)
		{
			if(minsize > maxsize)
			{
				int x = minh.top();
				minh.pop();
				minsize--;
				maxh.push(x);
				maxsize++;
			}
			else
			{
			    	int x = maxh.top();
				maxh.pop();
				maxsize--;
				minh.push(x);
				minsize++;	
			}
		}
     
		if(maxsize == minsize)
		
        {
           
            median = (minh.top() + maxh.top() )/2;
        } 
		else if(maxsize > minsize)
		 median = maxh.top();
		else
		 median = minh.top();
		 
		cout<<median<<" ";
	}
	cout<<endl;
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
        calculate();
    }
    return 0;
}
