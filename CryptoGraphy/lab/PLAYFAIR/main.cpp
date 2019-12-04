#include <iostream>
#include <string.h>

using namespace std;

int i, j, k, l, c, p, q, pl, cl, kl, i1, j1, i2, j2, temp, choice;
char keyword[20], plaintext[20], ciphertext[20], matrix[5][5], ch;

int main()
{
    void P2C();
    void C2P();
    cout << "Enter Keyword : ";
    cin >> keyword;
    kl = strlen(keyword);
    cout << "\n1...Plaintext to Ciphertext"
         << "\n2...Ciphertext to Plaintext";
    cin >> choice;
    ch = 65;
    c = 0;
    k = 0;
    l = 0;
    for (i=0; i<5; i++)
    {
        for (j=0; j<5; j++)
        {
            if (k<kl)
            {
                again:
                for (l=0; l<k; l++)
                {
                    if (keyword[k] == keyword[l])
                    {
                        if (k == kl-1)
                        {
                            k++;
                            goto next;
                        }
                        k++;
                        goto again;
                    }
                }
                matrix[i][j] = keyword[k];
                k++;
            }
            else
            {
                next:
                if (char(ch) == 'J')
                {
                    ch++;
                }
                for (k=0; k<kl; k++)
                {
                    if (ch == int(keyword[k]))
                    {
                        ch++;
                        c = 0;
                        goto next;
                    }
                }
                if (c == 0)
                {
                    matrix[i][j] = char(ch);
                    ch++;
                }
            }
        }
    }
    cout << endl;
    for (i=0; i<5; i++)
    {
        for (j=0; j<5; j++)
        {
            cout << matrix[i][j];
            if (matrix[i][j] == 'I')
            {
                cout << "/J";
            }
            cout << '\t';
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

        pt:
        for (p=0; p<pl; p++)
        {
            if (plaintext[p] == plaintext[p+1])
            {
                pl++;
                for (q=pl-1; q>p; q--)
                {
                    plaintext[q] = plaintext[q-1];
                }
                plaintext[p] = 'X';
                plaintext[pl] = '\0';
                goto pt;
            }
            p++;
        }
        if (pl%2 != 0)
        {
            plaintext[pl] = 'X';
            plaintext[pl+1] = '\0';
            pl++;
        }
        cout << "Plaintext : " << plaintext << endl;

        for (p=0; p<pl; p++)
        {
            for (i=0; i<5; i++)
            {
                for (j=0; j<5; j++)
                {
                    if (matrix[i][j] == plaintext[p])
                    {
                        i1 = i;
                        j1 = j;
                    }
                    if (matrix[i][j] == plaintext[p+1])
                    {
                        i2 = i;
                        j2 = j;
                    }
                }
            }
            if (i1 == i2)
            {
                j1++;
                j2++;
                if (j1 > 4)
                {
                    j1 = 0;
                }
                if (j2 > 4)
                {
                    j2 = 0;
                }
                ciphertext[p] = matrix[i1][j1];
                ciphertext[p+1] = matrix[i2][j2];
                goto last;
            }
            if (j1 == j2)
            {
                i1++;
                i2++;
                if (i1 > 4)
                {
                    i1 = 0;
                }
                if (i2 > 4)
                {
                    i2 = 0;
                }
                ciphertext[p] = matrix[i1][j1];
                ciphertext[p+1] = matrix[i2][j2];
                goto last;
            }
            if ((i1 != i2) && (j1 != j2))
            {
                temp = j2;
                j2 = j1;
                j1 = temp;
                ciphertext[p] = matrix[i1][j1];
                ciphertext[p+1] = matrix[i2][j2];
                goto last;
            }
            last:
            p++;
        }
        ciphertext[pl] = '\0';
        cout << "Ciphertext : " << ciphertext << endl;
    }

    void C2P()
    {
        cout << "Enter CipherText : ";
        cin >> ciphertext;
        cl = strlen(ciphertext);

        ct:
        for (p=0; p<cl; p++)
        {
            if (ciphertext[p] == ciphertext[p+1])
            {
                cl++;
                for (q=cl-1; q>p; q--)
                {
                    ciphertext[q] = ciphertext[q-1];
                }
                ciphertext[p] = 'X';
                goto ct;
            }
            p++;
        }
        if (cl%2 != 0)
        {
            ciphertext[cl] = 'X';
            ciphertext[cl+1] = '\0';
            cl++;
        }
        cout << "Ciphertext : " << ciphertext << endl;

        for (p=0; p<cl; p++)
        {
            for (i=0; i<5; i++)
            {
                for (j=0; j<5; j++)
                {
                    if (matrix[i][j] == ciphertext[p])
                    {
                        i1 = i;
                        j1 = j;
                    }
                    if (matrix[i][j] == ciphertext[p+1])
                    {
                        i2 = i;
                        j2 = j;
                    }
                }
            }
            if (i1 == i2)
            {
                j1--;
                j2--;
                if (j1 < 0)
                {
                    j1 = 4;
                }
                if (j2 < 0)
                {
                    j2 = 4;
                }
                plaintext[p] = matrix[i1][j1];
                plaintext[p+1] = matrix[i2][j2];
                goto last2;
            }
            if (j1 == j2)
            {
                i1--;
                i2--;
                if (i1 < 0)
                {
                    i1 = 4;
                }
                if (i2 < 0)
                {
                    i2 = 4;
                }
                plaintext[p] = matrix[i1][j1];
                plaintext[p+1] = matrix[i2][j2];
                goto last2;
            }
            if ((i1 != i2) && (j1 != j2))
            {
                temp = j2;
                j2 = j1;
                j1 = temp;
                plaintext[p] = matrix[i1][j1];
                plaintext[p+1] = matrix[i2][j2];
                goto last2;
            }
            last2:
            p++;
        }
        plaintext[cl] = '\0';
        cout << "Plaintext : " << plaintext << endl;
    }
