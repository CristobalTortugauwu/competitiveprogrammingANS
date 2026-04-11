using namespace std;
#include <stack>
#include <iostream>
#include <string>
 
string construirString(stack<tuple<char,int>>&minus, stack<tuple<char,int>>&mayus){
    //ver ambas pilas, y ver quien tiene el indice mayor, y esa colocarla al final.
    //luego ir colocando la siguiente mayor y asi.
    string final_str = "";
    while (true){
        char letterminus; int indexminus;
        char lettermayus; int indexmayus;
        if (!minus.empty() && !mayus.empty()){
            tie(letterminus,indexminus) = minus.top();
            tie(lettermayus,indexmayus) = mayus.top();
            if (indexminus>indexmayus) {
                final_str+=letterminus;
                minus.pop();
            }
            else{
                final_str+=lettermayus;
                mayus.pop();
            }
        }
        else if (!mayus.empty() && minus.empty()){
            while(!mayus.empty()){
                tie(lettermayus,indexmayus) = mayus.top();
                final_str+=lettermayus;    
                mayus.pop();
            }
        }
        else if (mayus.empty() && !minus.empty()){
            while(!minus.empty()){
                tie(letterminus,indexminus) = minus.top();
                final_str+=letterminus;    
                minus.pop();
            }
        }
        else{
            break;
        }
    }
    reverse(final_str.begin(), final_str.end());
    return final_str;
}
 
int main() {
    int  numero_total_casos;
    cin >> numero_total_casos;
 
    for(int m=0;m< numero_total_casos;m++){
        string str, final_str;
        cin >> str;
        stack<tuple<char,int>> minus;
        stack<tuple<char,int>> mayus;
        for(int n=0;n<str.length();n++){
            char letter = str[n];
            //cout << letter << std::endl;            
            if(letter=='b'){
                if(!minus.empty()){
                    minus.pop();
                }
            }
            else if(letter=='B'){
                if(!mayus.empty()){
                    mayus.pop();
                }
            }
            else if(isupper(letter) && letter!='B')
                mayus.push({letter,n});
            else if(islower(letter) && letter!='b')
                minus.push({letter,n});
        }
        final_str=construirString(minus,mayus);
        cout << final_str << std::endl;
 
    }
}