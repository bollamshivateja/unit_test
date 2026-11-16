#include <stdio.h>

typedef unsigned __int128 ll;

ll power10(int n)
{
    ll p = 1;

    while (n--)
        p *= 10;

    return p;
}

// Convert string to unsigned __int128
ll stringToLL(char str[])
{
    ll num = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        num = num * 10 + (str[i] - '0');
    }

    return num;
}

ll multiply(ll x, ll y, int n)
{
    if (n <= 4)
        return x * y;

    int m = n / 2;
    ll p = power10(m);

    ll x1 = x / p;
    ll x0 = x % p;

    ll y1 = y / p;
    ll y0 = y % p;

    ll a = multiply(x1, y1, m);
    ll b = multiply(x1, y0, m);
    ll c = multiply(x0, y1, m);
    ll d = multiply(x0, y0, m);

    return a * p * p + (b + c) * p + d;
}

void print(ll n)
{
    if (n > 9)
        print(n / 10);

    printf("%d", (int)(n % 10));
}

int main()
{
    char input1[100];
    char input2[100];

    ll a, b;

    printf("Enter first large integer: ");
    scanf("%99s", input1);

    printf("Enter second large integer: ");
    scanf("%99s", input2);

    a = stringToLL(input1);
    b = stringToLL(input2);

    printf("\nFirst large integer: ");
    print(a);

    printf("\nSecond large integer: ");
    print(b);

    printf("\n\nProduct = ");
    print(multiply(a, b, 16));

    printf("\n");

    return 0;
}
