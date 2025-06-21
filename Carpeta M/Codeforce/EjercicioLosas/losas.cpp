#include <iostream>
using namespace std;
int main(){
    long long n, m, a;
    cin>> n>> m >> a;
    long long flagstones_in_n = (n + a -1)/a;
    long long flagstones_in_m = (m + a- 1)/a;
    cout <<flagstones_in_n * flagstones_in_m <<endl;
    return 0;
}