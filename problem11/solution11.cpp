#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
    int len;
    cin >> len;
    vector<pair<int,int>> arr(len);
    for(int k=0;k<len;k++){
        int elem;
        cin >> elem;
        pair<int, int> p = make_pair(elem,k);
        arr[k]=p;
    }
 
    sort(arr.begin(),arr.end());
    int contador=1;
    for(int k=0;k<len-1;k++){
        if(arr[k].second>arr[k+1].second){
            contador++;
        }
    }
    cout << contador;
}
