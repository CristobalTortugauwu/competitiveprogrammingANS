using namespace std;
#include <vector>
#include <iostream>
int main() {
	int t; cin >> t;
    for(int m=0;m<t;m++){
        int estudiantes, min_power;
        cin >> estudiantes >> min_power;
        vector<int> arr_est(estudiantes);
        for (int j=0;j<estudiantes;j++){
            cin >> arr_est[j];
        }
        sort(arr_est.begin(),arr_est.end());
        int contador =0;
        vector<int> conjunto(0);
        for (int a=estudiantes-1;a>-1;a--){
            int candidato = arr_est[a];
            if (candidato>=min_power){
                contador++;
            }
            else{
                conjunto.push_back(candidato);
               int min = *min_element(conjunto.begin(), conjunto.end());
                if (min*conjunto.size()>=min_power){
                    contador++;
                    conjunto.clear();
                }
            }
        }
        cout << contador << std::endl;
        
    }
	
}
