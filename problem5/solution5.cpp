using namespace std;
#include <iostream>
#include <string>
#include <set>
 
int main() {
	int cantidadnombres;
	cin >> cantidadnombres;
    set<string> set;
    for(int m =0; m<cantidadnombres;m++){
        string name;
        cin >> name;
        if (set.find(name) == set.end()) {
            set.insert(name);
            cout << "NO" << std::endl;
        }
        else{
            cout << "YES"<< std::endl;
        }
    }
}
