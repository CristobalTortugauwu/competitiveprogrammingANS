using namespace std;
    #include <map>
    #include <iostream>
    #include <vector>
    int main() {
    	int cantidad_test;
    	cin >> cantidad_test;
        for(int m=0;m<cantidad_test;m++){
            int numproblemas, guias; string letters;
            cin >> numproblemas; cin >> guias; cin >> letters;
            //cout << numproblemas << std::endl << guias  << std::endl << letters << std::endl;
            map<char, int> map;
            for(int n=0;n<letters.length();n++){
                if (map.find(letters[n]) == map.end()){
                    map[letters[n]]=1;
                }
                else{
                    map[letters[n]]++;
                }
            }
            vector<char> grades;
            for (int i = 0; i < 7; i++)
                grades.push_back('A' + i);    
            int guias_faltantes=0;
            for (int k=0;k<7;k++) {
            	if(map.find(grades[k]) == map.end()){
                    guias_faltantes+=guias;
                }
                else{
                    if (map[grades[k]]-guias<0){
                        guias_faltantes+= -(map[grades[k]]-guias);
                    }
                }
                //cout << (it->first) << " : " << (it->second) << '\n';
            }   
            cout << guias_faltantes << std::endl;
        }
    }
