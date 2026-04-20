using namespace std;
#include <vector>
#include <iostream>
int main() {
	int cantidad_tests;
    cin >> cantidad_tests;
    for(int k=0;k<cantidad_tests;k++){
        int cantidad_vidrios;
        cin >> cantidad_vidrios;
        vector<int> vector(cantidad_vidrios);
        for(int m=0;m<cantidad_vidrios;m++){
            cin >> vector[m];
        }
        sort(vector.begin(),vector.end());
 
        //for(int m=0;m<vector.size();m++){
        //    cout << vector[m] ;
        //}
        for(int m=0;m<cantidad_vidrios-1;m++){
            int value = vector[m]-vector[m+1];
            if (abs(value)<=1){
                vector[m]=0;
            }
        }
        int m=0,j=0;
        while (m<cantidad_vidrios){
            if(vector[j]==0){
                vector.erase(vector.begin()+j);
                j--;
            }
            m++;
            j++;
        }
        //for(int m=0;m<vector.size();m++){
        //    cout << vector[m] ;
        //}
        if (vector.size()==1)
            cout << "YES" << std::endl;
        else
            cout << "NO" << std::endl;
    }
}
