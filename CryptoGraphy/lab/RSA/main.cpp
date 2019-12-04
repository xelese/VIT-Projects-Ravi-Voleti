#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

int i, j, p, q, n, phi, e, d, choice, pl, cl, ch;
char plaintext[20], ciphertext[20];
double bigd;
string num, bigs;

void P2C();
void C2P();
int gcd(int,int);

int main()
{
    cout << "\n Select two prime numbers (p and q) : ";
    cin >> p >> q;
    n = p * q;
    phi = (p-1) * (q-1);
    E:
    cout << "\n Select public key (e) [ 0<e<" << phi <<" and gcd(e," << phi << ")=1 ] : ";
    cin >> e;
    if (e<0 || e>phi)
    {
        cout << "\n\t\t Invalid number!! Value of 'e' is not in range!!!";
        goto E;
    }
    if (gcd(e,phi) != 1)
    {
        cout << "\n\t\t Invalid number!! gcd(e," << phi << ")!=1 !!!";
        goto E;
    }
    for (i=0; i<phi; i++)
    {
        if ((i*e) % phi == 1)
        {
            d = i;
            break;
        }
    }
    cout << "\n1...Plaintext to Ciphertext";
    cin >> choice;
    cout << endl;
    if (choice == 1)
    {
        P2C();
    }
    else if (choice == 2)
    {
        C2P();
    }
    else
    {
        cout << "INVALID INPUT!!";
    }
    return 0;
}

int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    return gcd(b%a, a);
}

void P2C()
{
    cout << "Enter PlainText : ";
    cin >> plaintext;
    pl = strlen(plaintext);
    cout << endl;
    for (i=0; i<pl; i++)
    {
        ch = fmod(fmod(pow((int(plaintext[i])-65),e),n),26);
        ciphertext[i] = char(ch+65);
    }
    ciphertext[pl] = '\0';
    cout << "CipherText : " << ciphertext << endl;
}

void C2P()
{
    cout << "Enter CipherText : ";
    cin >> ciphertext;
    cl = strlen(ciphertext);
    cout << endl;
    for (i=0; i<cl; i++)
    {
        ch = fmod(fmod(pow((int(ciphertext[i])-65),d),n),26);
        plaintext[i] = char(ch+65);
    }
    plaintext[cl] = '\0';
    cout << "PlainText : " << plaintext << endl;
}
