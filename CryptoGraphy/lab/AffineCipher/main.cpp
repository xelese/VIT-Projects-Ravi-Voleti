#include <iostream>
#include <string.h>

using namespace std;

int a, b, i, j, pl, cl, ch, inva, choice;
char plaintext[20], ciphertext[20];

int main()
{
    void P2C();
    void C2P();
    cout << "Enter Key A : ";
    cin >> a;
    cout << "Enter Key B : ";
    cin >> b;
    cout << "\n1...Plaintext to Ciphertext"
         << "\n2...Ciphertext to Plaintext";
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

    void P2C()
    {
        cout << "Enter PlainText : ";
        cin >> plaintext;
        pl = strlen(plaintext);
        cout << endl;

        for (i=0; i<pl; i++)
        {
            ch = (a*(int(plaintext[i])-65) + b) % 26;
            ciphertext[i] = char(ch+65);
        }
        ciphertext[pl] = '\0';
        cout << "Ciphertext : " << ciphertext << endl;
    }

    void C2P()
    {
        cout << "Enter CipherText : ";
        cin >> ciphertext;
        cl = strlen(ciphertext);
        cout << endl;

        for (j=0; j<26; j++)
        {
            if ((j*a) % 26 == 1)
            {
                inva = j;
                break;
            }
        }
        for (i=0; i<cl; i++)
        {
            ch = (inva*((int(ciphertext[i])-65) - b)) % 26;
            plaintext[i] = char(ch+65);
        }
        plaintext[cl] = '\0';
        cout << "Plaintext : " << plaintext << endl;
    }
