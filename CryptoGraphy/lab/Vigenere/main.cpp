#include <iostream>
#include <string.h>

using namespace std;

int i, j, pl, kl, temp;
char keyword[20], plaintext[20], ciphertext[20];

int main()
{
    cout << "Enter Keyword : ";
    cin >> keyword;
    kl = strlen(keyword);

    cout << "Enter PlainText : ";
    cin >> plaintext;
    pl = strlen(plaintext);

    for (i=0; i<pl; )
    {
        for (j=0; j<kl; j++)
        {
            temp = (int(plaintext[i])-65) + (int(keyword[j])-65);
            ciphertext[i] = char((temp%26)+65);
            i++;
        }
    }
    cout << "CipherText : " << ciphertext << endl;

    return 0;
}
