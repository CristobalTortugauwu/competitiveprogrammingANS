#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int casos_prueba;
    cin >> casos_prueba;
    while(casos_prueba>0){
        int largo;
        cin >> largo; int len = 0;
        int right=0; int switching = 0;
        string propuesta = "";
        vector<string> arr = {"1","0"};
        int num_queries=0;
        while(len<largo){
            if(switching){
                //llenar hacia la izquierda
                for (int k =0;k<arr.size();k++){
                    num_queries++;
                    string prop = arr[k];
                    prop.append(propuesta);
                    if (num_queries>largo*2){
                        len++;
                        propuesta = prop;
                        break;
                    }
                    cout << "? " << prop <<endl;
                    int resp; cin >> resp;
                    if (resp == 1){
                        propuesta = prop;
                        len++;
                        break;
                    }
                    else if (resp == 0){
                        //borramos
                        continue;
                    }
                    else{
                        exit(0);
                    }
                }                
            }
            else{
                //primero intentamos hacia la derecha
                for (int k =0;k<arr.size();k++){
                    num_queries++;
                    propuesta.append(arr[k]);
                    if (num_queries>largo*2){
                        len++;
                        break;
                    }
                    cout << "? " << propuesta <<endl;
                    int resp; cin >> resp;
                    if (resp == 1){
                        right=0;
                        len++;
                        break;
                    }
                    else if (resp == 0){
                        //borramos
                        right=1;
                        propuesta.erase(propuesta.size()-1,1);
                    }
                    else{
                        exit(0);
                    }
                }
                if (right){
                    switching =1;
                }
 
            }
        }
        cout << "! " << propuesta <<endl;
        casos_prueba--;
    }
}