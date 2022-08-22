 #include<iostream>
 using namespace std;

 int Targsum(int B[],int size,int x)                  //fn to check if sum is possible
 {
    for (int i = 0; i < (size - 1); i++)
        {
            for (int j = (i + 1); j < size; j++)
            {
                if (B[i] + B[j] == x)
                {
                    return 1;
                }
            }
        }
    return 0;
 }
 int main()
  {
    int n,i,ts,c;
    cout<<"No of integers=";
    cin>>n;
    int A[n];
    cout<<"\nNumbers=";
    for(i=0;i<n;i++)
    {
      cin>>c;
      while (c <= 0 || c > 100)                         //checks if integer between 1 & 100
        {
           cout << "Range is 1 to 100. Re-enter.";
           cin>>c;
        }
        A[i] = c;
    }
    cout<<"\nTarget Sum=";
    cin>>ts;

    if(Targsum(A,n,ts))                               //checks if target sum is possible
    {
        cout<<"\nPossible";
    }
    else
    {
        cout<<"\nNot Possible";
    }

    return 0;
  }
