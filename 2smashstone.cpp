#include<iostream>
#include<queue>
using namespace std;

int main()
{
    int n;
    cout<<"No of stones=";
    cin>>n;
    int stones[n];
    priority_queue<int> pq;
    cout<<"\nStones=";
    for(int i=0;i<n;i++)
    {
        cin>>stones[i];
        pq.push(stones[i]);
    }
    while(pq.size()>1)
    {
        int y=pq.top();                      //choosing heaviest stone
        pq.pop();

        int x=pq.top();                      //choosing second heaviest stone
        pq.pop();

        if(x!=y)
        {
            pq.push(y-x);
        }
    }
    cout<<"\nResult: ";
    if(pq.empty())
    {
        cout<<0<<endl;
    }
    else
    {
        cout<<pq.top()<<endl;
    }
    return 0;
}
