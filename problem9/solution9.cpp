using namespace std;
#include <vector>
#include <iostream>
int search_closest(vector<long long>& arr, int limit){
    int index = -1;
    for(int m=0;m<arr.size();m++){
        if (arr[m]<=limit){
            index = m;
            break;
        }
    }
    //cout << "borramos" << arr[index] << " ";
    return index;
}
 
 
int main() {
	int total_cases;
    cin >> total_cases;
    for(int k=0;k<total_cases;k++){
        int len_arr, limit;
        cin >> len_arr >> limit;
        vector<long long> arr_tickets(len_arr);
        for (int l=0;l<len_arr;l++){
            cin >> arr_tickets[l];
        }
        sort(arr_tickets.begin(),arr_tickets.end());
        reverse(arr_tickets.begin(),arr_tickets.end());
        int contador = 0;
        while ("tobal"){
            int index = search_closest(arr_tickets, limit);
            if (index == -1){
                contador += arr_tickets.size();
                break;
            }
            arr_tickets.erase(arr_tickets.begin()+index);
            for (int n=0;n<arr_tickets.size();n++){
                if(arr_tickets[n]>limit/2 ){
                    //cout << "borre a: " << arr_tickets[n] << endl;
                    arr_tickets.erase(arr_tickets.begin()+n);
                    contador++;
                }
            }
            for (int n=0;n<arr_tickets.size();n++){
                arr_tickets[n]*=2;
            }
            //cout << "index: " << index << endl;
            //for (int l=0;l<arr_tickets.size();l++){
            //    cout << arr_tickets[l] << " ";
            //}
            //cout << endl;
        }
        cout << contador << endl;
    }
    
}
