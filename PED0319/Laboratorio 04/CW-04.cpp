#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n);
int addPrime(int start, int prime, int aux);

int main(void)
{
    int n = 0;
    cin >> n;

    cout << addPrime(2, n, 0) << endl;

    return 0;
}

bool isPrime(int n)
{
    if (n == 2)
    {
        return true;
    }
    else
    {
        for (int i = 0; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                cout << "A " << n << " lo divide " << i << endl;
                return false;
            }
            return true;
        }
    }
}

int addPrime(int start, int prime, int aux)
{
    if (aux == prime)
    {
        return 0;
    }
    else
    {
        if (isPrime(start) == true)
        {
            cout << start << endl;
            return start + addPrime(start + 1, prime, aux + 1);
        }
        else
        {
            return 0 + addPrime(start + 1, prime, aux + 1);
        }
    }
}
