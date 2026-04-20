#include <vector>
#include <iostream>
using namespace std;
 
 
void change_position(int i, int limit, vector<int> &arreglo){
    if(i>=limit){
        return;
    }
    int x,y;
    x=arreglo[i];y=arreglo[i+1];    
    if(x>y){
        arreglo[i]=y;arreglo[i+1]=x;
        return;
    }
}
void print_array(vector<int> &arreglo, int length){
    for(int i=0;i<length;i++){
        cout <<arreglo[i]<<"//";
    }
    cout << '\n';
}
        
 
 
int main() {
	int cantidad_pruebas; cin >> cantidad_pruebas;
    for (int k=0;k<cantidad_pruebas;k++){
        int cantidad_enteros; //siempre es impar
        cin >> cantidad_enteros;
        vector<int> arreglo(cantidad_enteros);
        for(int i=0;i<cantidad_enteros;i++){
            cin >> arreglo[i];
        }
        int iteraciones=0;
        for(int i=0;i<cantidad_enteros;i++){
            if(is_sorted(arreglo.begin(), arreglo.end())){
                cout << iteraciones << std::endl;
                break;
            }
            iteraciones++;
            if (i%2!=0){
                for (int m=1;m<cantidad_enteros-1;m+=2){
                    change_position(m, cantidad_enteros, arreglo);
                }                
            }
            else{
                for (int m=0;m<cantidad_enteros-2;m+=2){
                    change_position(m, cantidad_enteros, arreglo);
                }
            }
            if(is_sorted(arreglo.begin(), arreglo.end())){
                cout << iteraciones << std::endl;
                break;
            }
        }   
    }
} 
