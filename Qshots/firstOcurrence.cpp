#include<iostream>
using namespace std;


class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=0, j=0, k;
        int n=needle.length();
        while(i<n && j<haystack.length())
        {
            if(needle.at(i)==haystack.at(j))
            {
                i++;
                j++;
            }
            else
            {
                j=j-i+1;
                i=0;
            }
        }
        if(i!=needle.length())
        {
            return -1;
        }
        else
        {
        k=j-needle.length();
        return k;
        }
    }
};
int main(){
    Solution s;
    int n;
    string haystack="mississippi";
    string needle="issi";
    n=s.strStr(haystack,needle);
    cout<<n;
    return 0;
}