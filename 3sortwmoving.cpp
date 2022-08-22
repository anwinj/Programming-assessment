#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void sortArray(int a[], int n)
{
    vector<int> ans;                                            // Store all non-negative values
    for (int i = 0; i < n; i++) {
        if (a[i] > 0)
            ans.push_back(a[i]);
    }

    sort(ans.begin(), ans.end());                               // Sort non-negative values

    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0)
        {
            a[i] = ans[j];
            j++;
        }
    }

    for (int i = 0; i < n; i++)                                  // Printing the sorted array
        cout << a[i] << " ";
}

int main()
{
    int n,i,ts,c;
    cout<<"No of elements including trees=";
    cin>>n;
    while (n <= 4 || n >15)                                      //checks if row between 5 and 15
        {
           cout << "Row should be between 5 & 15. Re-enter.";
           cin>>n;
        }
    int A[n];
    cout<<"\nElements=";
    for(i=0;i< n;i++)
    {
      cin>>c;
      while (c < 0 || c > 200)                                    //checks if height of tree is -1
        {
           if(c < 0)
           {
               while(c != -1)
               {
                    cout << "Negative should be -1. Re-enter.";
                    cin>>c;
               }
               break;
           }

           else if(c > 200)
           {
               while(c > 200)
               {
                   cout << "Max height is 200. Re-enter.";
                   cin>>c;
               }
            }
        }
        A[i] = c;
    }
    sortArray(A, n);
    return 0;
}
