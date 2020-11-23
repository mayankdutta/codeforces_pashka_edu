#include <iostream>
#include <vector> 
#include <iomanip> 

using ll=long long int; 
using lld=long double;

class Info { 
    std::vector <ll> X, V; 
    ll N; 
    lld left, right; 

    public: 

    Info ( ) { 
        std::cin >> N; 
        X.resize ( N ); 
        V.resize ( N ); 
        for ( ll i=0; i<N; i++ ) { 
            std::cin >> X[i] >> V[i]; 
        }
        left = 0;
        right = 1e9; 

        solve ( ); 
    }

    void solve ( ) { 
        while ( right - left > 1e-9 ) {
            lld mid = ( left + ( right - left ) / 2 ); 
            //std::cout << left << " " << mid << " " << right << "\n"; 
            if ( good ( mid ) ) right = mid; 
            else left = mid; 
        }
        std::cout << std::setprecision ( 20 ) << right << "\n"; 
    }

    bool good ( lld mid ) { 
        //code 
        lld mx = -1e9, mn = 1e9; 

        for ( ll i=0; i<N; i++ ) { 
            lld local_left = (lld) X[i] - (lld) mid * V[i]; 
            lld local_right = (lld) X[i] + (lld) mid * V[i]; 

            mx = std::max ( mx, local_left ); 
            mn = std::min ( mn, local_right ); 

            if ( mx > mn ) return false; 
        }
        return true;
        //return mx <= mn;
    }
}; 

int main ( ) { 
    Info i; 
}


