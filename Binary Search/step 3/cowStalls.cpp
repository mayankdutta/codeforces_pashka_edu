#include <iostream>
#include <vector>
#include <algorithm>

using ll=long long int; 
using lld=long double; 

class Info { 
    ll N, K; 
    ll right, left; 
    std::vector <ll> arr; 

    public: 

    Info ( ) { 
        std::cin >> N >> K;
        arr.resize ( N ); 

        for ( ll i=0; i<N; i++ ) { 
            std::cin >> arr[i]; 
        }

        std::sort ( arr.begin(), arr.end() ); 
        left = 0;
        right = 1e10;

        Solve ( );
    }

    void Solve ( ) { 
        for ( int test = 0; test < 100; test ++ ) { 
            ll mid = ( left + ( right - left ) / 2 ); 
            //std::cout << left << " " << mid << " " << right << "\n";
            if ( good ( mid ) ) left = mid; 
            else right = mid; 
        }

        std::cout << left << "\n"; 
    }

    bool good ( ll mid ) { 
        ll count = 1; 
        ll distance = 0; 
        ll J = 0;

        for ( ll I=1; I < N; I++ ) { 
            if ( arr[I] - arr[J] >= mid ) { 
                J = I; 
                count ++; 
                distance += arr [I] - arr[J]; 
            }
        }

        return count >= K; 
    }
};

int main ( ) { 
    Info i; 
}



