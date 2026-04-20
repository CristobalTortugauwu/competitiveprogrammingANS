#include <map>
#include <string>
#include <iostream>
using namespace std;
 
int main() {
	int tests_cases; cin >> tests_cases;
    for(int m=0;m<tests_cases;m++){
        map<char, int> dict_amount_chars;
        string X, Y;
        cin >> X >> Y;
        //recorremos Y para contar la cantidad de letras que hay en él
        for(int n=0;n<Y.size();n++){
            if ( dict_amount_chars.find(Y[n]) ==  dict_amount_chars.end()) {
		        dict_amount_chars[Y[n]] = 1;
	        } else {
	        	dict_amount_chars[Y[n]]++;
	        }
        }
        //vamos a recorrer el string X, para ver si sus letras estan en Y
        int mayor_prefijo=0;
        for(int j=0;j<X.size();j++){
            //cout << X[j] << "::" << dict_amount_chars[X[j]] << "---";
            if(!(dict_amount_chars.find(X[j]) == dict_amount_chars.end() )){
                if (dict_amount_chars[X[j]]>0){
                    mayor_prefijo++;
                    dict_amount_chars[X[j]]--;
                }
                else{
                    break;
                }
            }
            else{
                break;
            }
        }
        cout << mayor_prefijo << std::endl;
    }
}
