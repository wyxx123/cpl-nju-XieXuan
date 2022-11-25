#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dl;
typedef unsigned long long ull;
#define mod 100003
#define R register
#define next lglGLgLG
#define chkmin(x, y) (x=min(x, y))
#define chkmax(x, y) (x=max(x, y))
#define debug puts("lg")

inline ll random(ll x) {
	return 1ll*rand()*rand()*rand()%x+1;
}

int n, K;
ll mx;
ll num[10000];
int main() {
	srand(time(0));
	freopen("data.in", "w", stdout);
	n=10;
	for (int i=1; i<=n; i++) num[i]=i;
	random_shuffle(num+1, num+n+1);
	for (int i=1; i<=n; i++) printf("%d ", num[i]); putchar('\n');
}