#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<queue>
using namespace std;

int isvalid(int nextx,int nexty,int m,int n)                  //checking valid node
{
	if(nextx>=0 && nextx<m && nexty>=0 && nexty<n)
		return 1;
	return 0;
}

class point                                                   //defining point
{
	public:
	int row;
	int col;
	void mpoint(int m,int n){
		row=m;
		col=n;
	}
};

class node                                                    //defining node
{
	public:
	point p;
	int d;
	void mnode(point q,int dis)
	{
		p.row=q.row;
		p.col=q.col;
		d=dis;
	}
};

int shortest(int** a,int m,int n,int x1,int y1)                //finding shortest path
{
	if(a[0][0]==0)
		return -1;

	bool visited[m][n];
	memset(visited,false,sizeof(visited));
	queue<node> q;

	point curr;
	curr.mpoint(0,0);

	node t;
    t.mnode(curr,0);
	q.push(t);

	int arrx[]={-1,0,1,0};
	int arry[]={0,1,0,-1};

	point c;
	node v;
	while(!q.empty()){
		                                                       //DEQUEUE
		v=q.front();

		c=v.p;
		                                                       //if destination node is reached
		if(x1==c.row && y1==c.col ){
			return v.d;
		}
		q.pop();
		                                                       //check for all four neighbors
		for(int i=0;i<4;i++){
			int nextx=c.row+arrx[i];
			int nexty=c.col+arry[i];
			if(isvalid(nextx,nexty,m,n) && a[nextx][nexty] && !visited[nextx][nexty]){
				curr.mpoint(nextx,nexty);
				t.mnode(curr,(v.d)+1);
				q.push(t);
				visited[nextx][nexty]=true;  				  //mark as visited
			}
		}
     }
     return -1;
}

int main()
{
    int m,n,x,y,c,r;
    cout<<"enter matrix row & coloumn";
    cin>>m>>n;
    x=m-1;
    y=n-1;
    int **a=(int**)malloc(sizeof(int*)*m);

	for(int i=0;i<m;i++)
		a[i]=(int*)(malloc(sizeof(int)*n));

	cout<<"enter matrix elements (0/1)"<<endl;
	for(int i=0;i<m;i++)
	{
	    for(int j=0;j<n;j++)
	    {
	        cin>>c;
            while (c < 0 || c > 1)                                        //checks if its either 0 or 1
            {
                cout << "It should be either 0 or 1. Re-enter.";
                cin>>c;
            }
            a[i][j]=c;
	    }
    }
    cout << "\n{{ ";
    for (int i=0;i<m;i++)                                                   //printing the matrix
    {
        for (int j=0;j<n;j++)
        {
            cout << a[i][j] << " ";
        }
        if (i!=m-1)
            cout << "}\n { ";
        else
            cout << "}}";
    }

    r=shortest(a,m,n,x,y);

    if(r!=-1)                                                               //checking if r is -1
    {
        cout<<"\n\nShortest Path is "<<r;
    }
    else
    {
        cout<<"\n\nPath not Possible";
    }

	return 0;
}
