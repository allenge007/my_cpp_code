#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int N=4e5+10; 
int n,m,a[N];
char s[N];
signed main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		if(s[i]=='A')m+=2,a[m]=a[m-1]=1;
		else if(s[i]=='B')m++,a[m]=1;
		else m++,a[m]=0;
	int i=1;
	while(i<=m){
		if(a[i]&&a[i+1])putchar('A'),i+=2;
		else if(a[i])putchar('B'),i++;
		else putchar('C'),i++;
	}
	putchar('\n');
	return 0;
}
