#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    double trimMean(vector<int>& arr) {
        
        int n=arr.size();
        cout<<n<<endl;
        int a = (int)(5.0 / 100 * n);
        // int b=(int)a;

        sort(arr.begin(), arr.end());
        for (int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        double  sum=0.0;
        int  count=0;
        for (int i= a; i<n-a;i++){
            sum=sum+arr[i];
            count++;
        }
        double as=sum/count;

        return as;

    }
};
