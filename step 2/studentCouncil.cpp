#include <iostream>
#include <vector> 

using ll=long long int; 

bool good ( ll arr[], int N, ll mid, ll sum, int K ) { 
    ll slots = K * mid; 
    for ( int i=0; i<N; i++ ) {
        slots -= std::min ( mid, arr[i] ); 
    }
    return slots <= 0; 
}


int main ( ) { 
    int N, K; 
    std::cin >> K >> N; 

    ll arr[N]; 
    ll left = 1e9, right = 0; 
    ll sum = 0;
    for ( int i=0; i<N; i++ ) { 
        std::cin >> arr[i]; 
        left = std::min ( left, arr[i] ); 
        right += arr[i];
    }
    sum = right; 

    for ( int test = 0; test < 100; test++ ) { 
        ll mid = ( left + ( right - left ) / 2 ); 
        //std::cout << left << " " << mid << " " << right << " , good " << good ( arr, N, mid, sum, K ) << "\n"; 
        if ( good ( arr, N, mid, sum, K ) ) left = mid; 
        else right = mid; 
    }

    std::cout << left << "\n"; 
}
/*
   Hint: X student groups will have X * K students. From each group you can take at most min(X, A[i]) students.

   We want to check if X councils is a valid answer. X councils will have a total of X * K empty slots. 
   It's always optimal to put a student in a council which currently has the least amount of members (you can break down the first example to get the intuition behind this). 
   Unfortunately we can't simulate this, but what we can do is check for each group: the number of councils it's members can be a part of. 
   The answer to this is simply min(X, a[i]).

*/

