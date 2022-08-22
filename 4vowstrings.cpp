#include<iostream>
#include<string>
#include<stdio.h>
#include <vector>
#include <set>
#include <map>
using namespace std;

bool isVowstring(string str)                                            //fn to check if its vowstring
{
    char ch;
    int a=0,e=0,i=0,o=0,u=0;
    while( str.empty()!=0)
    {
        ch=str.back();
        switch(ch)
        {
            case 'A' : case 'a':
            {
                a++;
                break;
            }
            case 'E' : case 'e':
            {
                e++;
                break;
            }
            case 'I' : case 'i':
            {
                i++;
                break;
            }
            case 'O' : case 'o':
            {
                o++;
                break;
            }
            case 'U' : case 'u':
            {
                u++;
                break;
            }
        }
        str.erase(std::prev(str.end()));
    }
    if(a==e && a==i && a==o && a==u && e==i && e==o && e==u && i==o && i==u && o==u)
    {
        return 1;
    }

    return 0;
}

bool isVowel(char x)                                                    //fn to check if its vowel
{
    return (x == 'a' || x == 'e' || x == 'i' ||
                        x == 'o' || x == 'u');
}

void FindSubstring(string str)
{
    set<char> hash;                                                     // To store vowels

    int n = str.length();
    if (isVowstring(str)==0)
    {
        cout<<"Not Wovstring";
    }
    for (int i = 0; i < n; i++)
    {
       for (int j = i; j < n; j++)
       {
            if (isVowel(str[j]) == false)                                //not wovel
               break;

            hash.insert(str[j]);                                         //insert into hash

            if (hash.size() == 5)                                        // If all vowels are present
               cout << str.substr(i, j-i+1) << " ";
        }

        hash.clear();
    }
}

int main()
{
    string str;
    cout<<"Enter string:";
    cin>>str;
    FindSubstring(str);
    return 0;
}
