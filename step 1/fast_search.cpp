/* Problem statement 

 Fast search 
 Given an array find how many elements b/w L and R 
 */

#include <iostream>
#include <algorithm>
#include <vector>

using ll=long long int; 

ll closestToLeft ( ll arr[], ll N, ll K ) {  // will search for element <=K [from LEFT till K]
    ll left = -1; 
    ll right = N;

    while ( right > left + 1 ) { 
        ll mid = ( left + right ) / 2; 
        if ( arr[mid] > K ) right = mid; 
        else left = mid;  
     // think it as when arr[mid] <= K means our left will be true till the no.s is there 
     // for ex. 1 5 5 5 5 10 
     // this will get to immediate left element as arr[mid] <= k 
    }

    return left + 1; 
}

ll closestToRight ( ll arr[], ll N, ll K ) {  // will search for element >=K [from RIGHT till K] 
    ll left = -1; 
    ll right = N; 

    while ( right > left + 1 ) { 
        ll mid = ( left + right ) / 2; 
        if ( arr[mid] < K ) left = mid; 
        else right = mid; 
     // think it as when arr[mid] >= K means it will go to till the right won't stop as = condtion also there 
    }
    return right + 1;
}

int main () { 
    ll N, K; 
    scanf ( "%lld", &N); 

    ll arr[N]; 
    for ( ll i=0; i<N; i++ ) scanf ( "%lld", &arr[i]); 
    scanf ( "%lld", &K ); 
    std::sort ( arr, arr + N );

    while ( K-- ) { 
        ll A, B;
        scanf ( "%lld %lld", &A, &B );
        std::cout << closestToLeft ( arr, N, B ) - closestToRight ( arr, N, A ) + 1 << "\n"; 
    }
}
