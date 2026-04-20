    #include <bits/stdc++.h>
    #include <typeinfo>
    using namespace std;
    /*
     *Description:* Rolling hash for fast substring comparison, single hash function
     *Status:* Tested
    */
    template<class T>
    struct rolling_hashing {
      long long base, mod; 
      vector<long long> p, H;
      long long n;
      rolling_hashing(const T &s, long long b, long long m): base(b), mod(m), n(s.size()) {
        p.assign(n+1, 1);
        H.assign(n+1, 0);
        for (long long i = 0; i < n; ++i) {
          H[i+1] = (H[i] * base + s[i]) % mod;
          p[i+1] = (p[i] * base) % mod;
        }
      }
      // get obtiene el hash de s[l..r], es decir, el hash
      // del substring de s desde l hasta r, inclusive.
      long long get(long long l, long long r) {
        long long res = (H[r+1] - H[l]*p[r-l+1]) % mod;
        if (res < 0) res += mod;
        return res;
      }
    };
     
    long long mult(long long amount){
        long long cantidad = 1;
        while (amount>0){
            cantidad *= 26;
            cantidad = cantidad%1000000007;
            amount -=1;
        }
        return cantidad;
    }
     
     
    int main() {
    	long long largo_s, repes_de_p; cin >> largo_s >> repes_de_p;
        string p; cin >> p;
        vector<long long> arr_pos(repes_de_p);
        for(long long k=0;k<repes_de_p;k++)
            cin >> arr_pos[k];
        if (repes_de_p==0){
            long long ret = mult(largo_s);
            cout << ret <<endl;
            //cout << ((long long)(pow(26,(largo_s))))% 1000000007;
            return 0;
        }
        long long largo_p = p.size();
        //cout << final_str <<endl;
        rolling_hashing<string> hash_p(p,67,998244353);
        long long hp = hash_p.get(0,largo_p-1);
        long long ocupados = 0; long long flag = 0;
       
        ocupados +=largo_p;
        for (long long k=0;k<repes_de_p-1;k++){
            long long dif = arr_pos[k+1]-arr_pos[k];
            long long tamaño_inter = max(arr_pos[k]+largo_p - arr_pos[k+1],0ll);
            //cout << tamaño_inter << endl;
            if (arr_pos[k]+largo_p>arr_pos[k+1]){ //se intersectan
                long long hpref =  hash_p.get(largo_p-tamaño_inter,largo_p-1);
                long long hsuf = hash_p.get(0,tamaño_inter-1);
                //cout << p.substr(0,tamaño_inter) << "!!" <<  p.substr(largo_p-tamaño_inter,tamaño_inter) <<endl;
                //cout << hpref << "!!" << hsuf<< endl;
                if (hpref == hsuf){
                    //calcular cantidad de espacio ocupado
                    ocupados += largo_p-tamaño_inter;
                }
                else{
                    cout << 0;
                    return 0;
                }
            }
            else{
                ocupados+=largo_p;
            }
        }
        //cout << "soy el ocupados:" << ocupados << endl;
        long long ret = mult(largo_s-ocupados);
        cout << ret;
        return 0;
 
    }
