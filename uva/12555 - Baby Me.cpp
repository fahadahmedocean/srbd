#include <bits/stdc++.h>
using namespace std;


#define Fin(f) freopen(f, "r", stdin)
#define Fout(f) freopen(f, "w", stdout)
#define SR() srand((unsigned)time(NULL))
#define random(m) ((rand() << 16 | rand()) % m)
#define AS(a) assert(a)

#define all(a) a.begin(), a.end()

#define Inter(v, a, n, b, m) v.resize(set_intersection(a, a + (n), b, b + (m), v.begin()) - v.begin())
#define SInter(v, a, n, b, m) v.resize((n) + (m)); sort(a, a + (n)); sort(b, b + (m)); Inter(v, a, n, b, m)
#define Union(v, a, n, b, m) v.resize(set_union(a, a + (n), b, b + (m), v.begin()) - v.begin());
#define SUnion(v, a, n, b, m) v.resize((n) + (m)); sort(a, a + (n)); sort(b, b + (m)); Union(v, a, n, b, m)
#define Diff(v, a, n, b, m) v.resize(set_difference(a, a + (n), b, b + (m), v.begin()) - v.begin())
#define SDiff(v, a, n, b, m) v.resize((n) + (m)); sort(a, a + (n)); sort(b, b + (m)); Diff(v, a, n, b, m)
#define Sym(v, a, n, b, m) v.resize(set_symmetric_difference(a, a + (n), b, b + (m) v.begin()) - v.begin())
#define SSym(v, a, n, b, m) v.resize((n) + (m)); sort(a, a + (n)); sort(b, b + (m)); Sym(v, a, n, b, m)

#define PB push_back
#define MP make_pair
#define Cnt1(n) (__builtin_popcount(n))
#define Cntt1(n) (__builtin_popcountll(n))
#define cb(n) (32 - __builtin_clz(n))
#define cbb(n) (64 - __builtin_clzll(n))
#define sq(x) ((x) * (x))

//get integer value
#define SI(a) scanf("%d", &a)
#define SII(a, b) scanf("%d%d", &a, &b)
#define SIII(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define SIIII(a, b, c, d) scanf("%d%d%d%d", &a, &b, &c, &d)
#define SIIIII(a, b, c, d, e) scanf("%d%d%d%d%d", &a, &b, &c, &d, &e)
#define SIIIIII(a, b, c, d, e, f) scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f)

//get long long
#define SL(a) scanf("%lld", &a)
#define SLL(a, b) scanf("%lld%lld", &a, &b)
#define SLLL(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)
#define SLLLL(a, b, c, d) scanf("%lld%lld%lld%lld", &a, &b, &c, &d)

#define SD(a) scanf("%lf", &a)
#define SDD(a, b) scanf("%lf%lf", &a, &b)
#define SDDD(a, b, c) scanf("%lf%lf%lf", &a, &b, &c)
#define SDDDD(a, b, c, d) scanf("%lf%lf%lf%lf", &a, &b, &c, &d)

#define SA(a, i, n) For(i, n) scanf("%d", a + i)
#define SAA(a, i, n, j, m) For(i, n) For(j, m) SI(a[i][j])
#define GC(c) (c = getchar())
#define Gn() getchar()
#define UC(c) ungetc(c, stdin)
#define SS(s) scanf("%s", s)
#define SSS(s, s2) scanf("%s%s", s, s2)
#define SC(c) scanf(" %c", &c)

#define PI(a) printf("%d\n", a)
#define PII(a, b) printf("%d %d\n", a, b)
#define PIII(a, b, c) printf("%d %d %d\n", a, b, c)
#define PIIII(a, b, c, d) printf("%d %d %d %d\n", a, b, c, d)
#define PIIIII(a, b, c, d, e) printf("%d %d %d %d %d\n", a, b, c, d, e)

#define PL(a) printf("%lld\n", a)
#define PLL(a, b) printf("%lld %lld\n", a, b)
#define PLLL(a, b, c) printf("%lld %lld %lld\n", a, b, c)
#define PD(a) printf("%f\n", a)
#define PDD(a, b) printf("%f %f\n", a, b)
#define PDDD(a, b, c) printf("%f %f %f\n", a, b, c)
#define PA(a, i, n) For(i, (n) - 1) printf("%d ", a[i]); PI(a[(n) - 1])
#define PAA(a, i, n, j, m) For(i, n) {For(j, (m) - 1) printf("%d ", a[i][j]); PI(a[i][(m) - 1]);}
#define PAn(a, i, n) For(i, n) PI(a[i])
#define PiA(a, i, n) For(i, n) PII(i, a[i]) /// debug
#define rPA(a, i, n) rForr(i, n - 1, 1) printf("%d ", a[i]); PI(a[0])
#define rPAn(a, i, n) rFor(i, n - 1) PI(a[i])
#define PC(c) putchar(c)
#define Pn() putchar(10)
#define Ps() putchar(32)

#define Uni(a) a.resize(unique(all(a)) - a.begin())
#define SUni(a) sort(all(a)); Uni(a)
#define Unii(a, n) (unique(a, a + (n)) - a)
#define SUnii(a, n) sort(a, a + n); Unii(a, n)
#define Accv(a, n) (accumulate(a.begin(), a.begin() + (n), 0))
#define AaddB(a, n, b) transform(a, a + (n), b, a, plus<int>())
#define mem(a, num) memset(a, num, sizeof(a))
#define cpy(to, from) memcpy(to, from, sizeof(from))
#define Rcpy(l, r, b) reverse_copy(l, r, b)
#define kTo10(ans, str, s, m, k) strncpy(str, s, m), str[m] = 0, ans = strtol(str, NULL, k)

#define gr() greater<int>()
#define nth(a, k, n) nth_element(a + 0, a + k, a + n)
#define nthg(a, k, n) nth_element(a + 0, a + k, a + n, greater<int>())
#define Min(a, n) (*min_element(a, a + (n)))
#define Max(a, n) (*max_element(a, a + (n)))
#define Minpos(a, n) (min_element(a, a + (n)) - (a))
#define Maxpos(a, n) (max_element(a, a + (n)) - (a))
#define Lowpos(a, n, x) (lower_bound(a, a + (n), x) - (a))
#define Upppos(a, n, x) (upper_bound(a, a + (n), x) - (a))
#define BS(a, n, x) binary_search(a, a + (n), x)
#define Range(a, n, x) equal_range(a, a + (n), x)
#define Fpos(a, n, x) (find(a, a + (n), x) - (a))
#define Fd(a, x) (find(all(a), x) != a.end())
template<class T> inline void Qmin(T &a, const T b) {if (b < a) a = b;}
template<class T> inline void Qmax(T &a, const T b) {if (a < b) a = b;} /// *若考虑位置，加上等号
inline int Qceil(int x, int y) {return (x - 1) / y + 1;}
#define FR0(i,N) for(i=0;i<(N);i++)
#define FR1(i,N) for(i=1;i<=(N);i++)
#define FRN(i,k,N) for(i=k;i<(N);i++)
#define pf printf
#define db double
#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)

#define scc(n) scanf("%c",&n)
#define sci(n) scanf("%d",&n)
#define scf(n) scanf("%f",&n)
#define scd(n) scanf("%lf",&n)
#define scs(s) scanf("%s",&s)
#define scll(n) scanf("%%I64d",&n)



int X_D[9] = { 0, -1, -1, -1, 0, 1, 1,  1};
int Y_D[9] = {-1, -1,  0,  1, 1, 1, 0, -1};
int bin_0_9[]= {0,1,1,2,1,1,2,3,1,1};
int month[]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
char chr[]={'0','1','2','3','4','5','6','7','8','9'};
string day_0_7[]= {"Friday","Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday"};
int power_of_2s[] = {1,2, 4, 8, 16, 32, 64, 128, 256,512, 1024, 2048, 4096, 8192, 16384, 32768, 65536,131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216,33554432, 67108864, 134217728, 268435456, 536870912};
string ans[13][32];
typedef long long LL;
int prime[1000001];

// Utility functions to get minimum of two integers
int min (int x, int y)
{
    return x < y? x : y;
}

// Utility functions to get maximum of two integers
int max (int x, int y)
{
    return x > y? x : y;
}
int main()
{
   int t;
   cin>>t;
   int tc=1;
   while(t--)
   {
       string s;
       int a;
       cin>>a;
       getline(cin,s);
       int b;
       if(s.length()>3)  b=s[3]-'0';
       else b=0;
       //cout<<a<<b<<endl;
       cout<<"Case "<<tc++<<": "<<a*0.5+0.05*b<<endl;
   }
}

