#include<cstdio>

int main()
{

    int a = 0;
    int result = ++a > 0 || ++a > 1;
    printf("%d %d", a, result);
    return 0;
}