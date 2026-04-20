using namespace std;
#include <vector>
#include <iostream>
int main() {
	int casos_prueba;
    cin >> casos_prueba;
    for(int k=0;k<casos_prueba;k++){
        int largo, num_operaciones;
        cin >> largo >> num_operaciones;
        vector<int> arr_a(largo), arr_b(largo);
        for (int l=0;l<largo;l++){
            cin >> arr_a[l];
        }
        for (int l=0;l<largo;l++){
            cin >> arr_b[l];
        }
        sort(arr_a.begin(),arr_a.end());
        sort(arr_b.begin(),arr_b.end());
        
        //cuando ocurre un intercambio tengo que disminuir el numero de operaciones
        // y se puede terminar cuando ya recorrí todo el arreglo o cuando se acaban las operaciones
        int index_a=0;
        int index_b=largo-1;
        while(true){
            if (index_a==largo || index_b==-1 || num_operaciones==0){
                break;
            }
            if(arr_a[index_a]<arr_b[index_b]){
                arr_a[index_a]=arr_b[index_b];
                num_operaciones--;
                index_a++;
                index_b--;
            }
            else{
                index_b--;
            }   
        }
        int total=0;
        for (int m=0;m<largo;m++){
            total+=arr_a[m];
        }
        cout << total << endl;
    }
}
