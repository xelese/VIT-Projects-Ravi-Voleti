#include <iostream>
#include <math.h>

using namespace std;

int P, g, a, b, X, Y, SKa, SKb;

int main()
{
    cout << "Select a large prime number(P) : ";
    cin >> P;

    cout << "Select a primitive element(g) : ";
    cin >> g;

    cout << "Secret number of A : ";
    cin >> a;
    X = fmod(pow(g,a),P);
    cout << "Public key of A = " << X << endl;

    cout << "Secret number of B : ";
    cin >> b;
    Y = fmod(pow(g,b),P);
    cout << "Public key of B = " << Y << endl;

    cout << " A --> X --> B " << endl
         << " A <-- Y <-- B " << endl;

    SKa = fmod(pow(Y,a),P);
    cout << "Shared secret key of A = " << SKa << endl;
    SKb = fmod(pow(X,b),P);
    cout << "Shared secret key of B = " << SKb << endl;

    return 0;
}
