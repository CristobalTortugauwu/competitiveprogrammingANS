#include <iostream>
#include <vector>
using namespace std;
int main() {
	int totaltest,length;
    cin >> totaltest;
    for(int n=0;n<totaltest;n++){
        cin >> length;
        vector<int> arr(length);
        int contadorPar=0;
        int contadorImpar=0;
        for(int m=0;m<length;m++){
            cin >> arr[m];
            if (arr[m]%2==0){
                contadorPar+=1;
            }
            else {
                contadorImpar+=1;
            }
        }
        //cout << contadorImpar << "!!" << contadorPar<< "\n";
        int found=1;
        if ((contadorPar>=2 && contadorImpar>=1)){
            found=0;
            cout << "YES\n";
            int cantidadPar=0;
            int cantidadImpar=0;
            for(int m=0;m<length;m++){
                if (cantidadPar>=2 && cantidadImpar>=1)
                    break;
                else if(arr[m]%2==0){
                    cantidadPar+=1;
                    if (cantidadPar>2){
                        continue;
                    }
                    cout << m+1 << " ";
                }
                else if (!(arr[m]%2==0)){
                    cantidadImpar+=1;
                    if (cantidadImpar>1){
                        continue;
                    }
                    cout << m+1 << " ";
                }
            }
            cout << std::endl;
        }
        else if (contadorImpar>=3 && found){
            cout << "YES\n";
            int contador=0;
            for(int m=0;m<length;m++){
                if (contador==3)
                    break;        
                else if(arr[m]%2!=0){
                    contador++;
                    cout << m+1 << " ";
                }
            }
            cout << std::endl;
        }
        else {
            cout << "NO\n";
        }
    }
}   
