#include <iostream>
#include <ctime>
#include <vector>

using ll=long long int; 

class Info { 
    ll left, right; 
    ll N, X, Y; 
    public: 

    Info ( ) { 
        std::cin >> N >> X >> Y; 
        left = 0; 
        right = 1e10;
    }

    void pseudo_main ( ) { 

        for ( int test = 0; test < 50; test ++ ) { 
            ll mid = ( left + right ) / 2; 
            //std::cout << left << " " << mid << " " << right << "\n";

            if ( good ( mid ) ) right = mid; 
            else left = mid; 
        }

        std::cout << right+ 1 << "\n"; 
    }


    bool good ( ll mid ) { 

        ll count = 0; 
        ll mn = std::min ( X, Y );
        ll mx = std::max ( X, Y ); 

        ll range1 = mid + 1; 
        count += range1 / mn; 

        ll range2 = mid - ( mn ) + 1; 
        count += range2 / mx; 

        /*
           for ( ll i=mn; i<=mid; i+=mn ) {
           count ++; 
           }

           for ( ll i=mn+mx; i<=mid; i+=mx ) { 
           count ++; 
           }
           */

        return count >= N; 
    }
};

int main ( ) { 
    //clock_t tStart = clock ( ); 

    Info i; 
    i.pseudo_main ( ); 

    //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
}

