#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int test; cin >> test;
    while (test>0){
        int tam; cin >> tam;
        vector<int> arr(tam);
        for(int m=0;m<tam;m++)
            cin >> arr[m];
        for(int j=0;j<tam-1;j++){
            int minimo = min(arr[j],arr[j+1]);
            arr[j]-=minimo;
            arr[j+1]-=minimo;
        }
        //for(int m=0;m<tam;m++)
        //    cout << arr[m];
        int flag = 1;
        for(int j=0;j<tam-1;j++){
            if(arr[j]!=0){
                flag =0;
            }
        }
        if (flag){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
        cout << endl;
        test--;
    }
}
