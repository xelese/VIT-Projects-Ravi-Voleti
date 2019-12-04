#include <iostream>
#include <string.h>

using namespace std;

int i, j, k, p, keymat[3][3], plainmat[3][1], ciphermat[3][1], pl, cl, choice;
char keyword[10], plaintext[20], ciphertext[20];
int det, invdet, keyinv[3][3];

int main()
{
    void P2C();
    void C2P();
    cout << "Enter Keyword (of 9 letters): ";
    cin >> keyword;
    cout << "\n1...Plaintext to Ciphertext";
    cin >> choice;
    cout << "Key Matrix : " << endl;
    k = 0;
    for (i=0; i<3; i++)
    {
        for (j=0; j<3; j++)
        {
            keymat[i][j] = int(keyword[k])-65;
            k++;
            cout << keymat[i][j] << '\t';
        }
        cout << endl;
    }
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

        if (pl%3 != 0)
        {
            if (pl%3 == 1)
            {
                plaintext[pl] = 'X';
                plaintext[pl+1] = 'X';
                plaintext[pl+2] = '\0';
                pl = pl+2;
            }
            else
            {
                plaintext[pl] = 'X';
                plaintext[pl+1] = '\0';
                pl++;
            }
        }
        cout << "Plaintext : " << plaintext << endl;

        for (p=0; p<pl; p++)
        {
            for (i=0; i<3; i++)
            {
                plainmat[i][0] = int(plaintext[p+i])-65;
            }
            for (i=0; i<3; i++)
            {
                ciphermat[i][0] = ((keymat[i][0]*plainmat[0][0])+(keymat[i][1]*plainmat[1][0])+(keymat[i][2]*plainmat[2][0]))%26;
            }
            for (i=0; i<3; i++)
            {
                ciphertext[p+i] = char(ciphermat[i][0]+65);
            }
            p = p+2;
        }
        cout << "Ciphertext : " << ciphertext << endl;
    }

    void C2P()
    {
        cout << "Enter CipherText : ";
        cin >> ciphertext;
        cl = strlen(ciphertext);

        // computes the inverse of a key matrix
        det = keymat[0][0] * (keymat[1][1] * keymat[2][2] - keymat[2][1] * keymat[1][2]) - keymat[0][1] * (keymat[1][0] * keymat[2][2] - keymat[1][2] * keymat[2][0]) + keymat[0][2] * (keymat[1][0] * keymat[2][1] - keymat[1][1] * keymat[2][0]);
        det = det%26;
        for (j=0; j<26; j++)
        {
            if ((j*det) % 26 == 1)
            {
                invdet = j;
                break;
            }
        }
        cout<<det<<'\t'<<invdet<<endl;

        keyinv[0][0] = ((keymat[1][1] * keymat[2][2] - keymat[2][1] * keymat[1][2]) * invdet) % 26;
        keyinv[0][1] = ((keymat[2][1] * keymat[0][2] - keymat[0][1] * keymat[2][2]) * invdet) % 26;
        keyinv[0][2] = ((keymat[0][1] * keymat[1][2] - keymat[0][2] * keymat[1][1]) * invdet) % 26;
        keyinv[1][0] = ((keymat[1][2] * keymat[2][0] - keymat[1][0] * keymat[2][2]) * invdet) % 26;
        keyinv[1][1] = ((keymat[0][0] * keymat[2][2] - keymat[0][2] * keymat[2][0]) * invdet) % 26;
        keyinv[1][2] = ((keymat[1][0] * keymat[0][2] - keymat[0][0] * keymat[1][2]) * invdet) % 26;
        keyinv[2][0] = ((keymat[1][0] * keymat[2][1] - keymat[2][0] * keymat[1][1]) * invdet) % 26;
        keyinv[2][1] = ((keymat[2][0] * keymat[0][1] - keymat[0][0] * keymat[2][1]) * invdet) % 26;
        keyinv[2][2] = ((keymat[0][0] * keymat[1][1] - keymat[1][0] * keymat[0][1]) * invdet) % 26;

        for (i=0; i<3; i++)
        {
            for (j=0; j<3; j++)
            {
                cout << keyinv[i][j] << '\t';
            }
            cout << endl;
        }

        if (cl%3 != 0)
        {
            if (cl%3 == 1)
            {
                ciphertext[cl] = 'X';
                ciphertext[cl+1] = 'X';
                ciphertext[cl+2] = '\0';
                cl = cl+2;
            }
            else
            {
                ciphertext[cl] = 'X';
                ciphertext[cl+1] = '\0';
                cl++;
            }
        }
        cout << "Ciphertext : " << ciphertext << endl;

        for (p=0; p<cl; p++)
        {
            for (i=0; i<3; i++)
            {
                ciphermat[i][0] = int(ciphertext[p+i])-65;
            }
            for (i=0; i<3; i++)
            {
                plainmat[i][0] = ((keyinv[i][0]*ciphermat[0][0])+(keyinv[i][1]*ciphermat[1][0])+(keyinv[i][2]*ciphermat[2][0]))%26;
            }
            for (i=0; i<3; i++)
            {
                plaintext[p+i] = char(plainmat[i][0]+65);
            }
            p = p + 2;
        }
        cout << "Plaintext : " << plaintext << endl;
    }
