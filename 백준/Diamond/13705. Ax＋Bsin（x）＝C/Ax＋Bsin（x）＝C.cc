#include <iostream>
using namespace std;

#define N 30
using LF=__float128;
using LD=__int128;
using lf=long double;
LF PI2=3.1415926535897932384626Q;

LF Sin(LF a) {
    a-=LD(a/PI2)*PI2;
    LF r=a,x=a,f=-a*a;
    for (LF d=2;d<N;d+=2)
        r+=x*=f/(d*(d+1));
    return r;
}

int main() {
    PI2*=2;
    lf a,b,c;
    cin>>a>>b>>c;
    LF A,B,C,l,r,x;
    A=a,B=b,C=c;

    LF U=1000000, D=0.5;
    l = (C-B)/A;
    r = (C+B)/A;
    int t=80;
    while(t--) {
        x = (l+r)/2;
        LF V=A*x+B*Sin(x);
        (V<C?l:r)=x;
    }
    printf("%Lf\n",lf(LD(U*r+D)/U));
}