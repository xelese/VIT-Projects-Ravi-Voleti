#include <iostream>
#include <string>
#include <stdlib.h>
#include <new>

using namespace std;

int main()
{
    string *states, *fstates, *trap, **transition, input, tmp;
    char *alph, temp;
    int nos, nots, nofs, noa, i, j, k, current, flag;

    cout<<"\n\n Enter the number of states : ";
    cin >> nos;
    cout<<"\n Enter the number of final states : ";
    cin >> nofs;
    cout<<"\n Enter the number of trap states : ";
    cin >> nots;
    cout<<"\n Enter the number of symbols in the alphabet : ";
    cin >> noa;

    states = new string[nos];
    fstates = new string[nofs];
    trap = new string[nots];
    alph = new char[noa+1];

    cout<<"\n\n Enter the states (initial state first) : \n";
    for (i = 0; i < nos; i++)
    {
        cin >> states[i];
    }

    cout<<"\n Enter the final states : \n";
    for (i = 0; i < nofs; i++)
    {
        cin >> fstates[i];
    }
    if (nots != 0)
    {
            cout<<"\n Enter the trap states : \n";
        for (i = 0; i < nots; i++)
        {
            cin >> trap[i];
        }
    }

    cout<<"\n Enter the alphabet for the DFA : \n";
    for (i = 0; i < noa; i++)
    {
        cin >> alph[i];
    }

    //allocating space for the transition table
    transition = new string *[nos];
    for (i = 0; i < nos; i++)
    {
        transition[i] = new string[noa];
    }

    //getting the values for the transition table
    cout<<"\n\n Enter the transition for the given states : \n";
    for (i = 0; i < nos; i++)
    {
        cout<<"\n For state "<<states[i]<<endl;
        for (j = 0; j < noa; j++)
        {
            cout<<"\t On input "<<alph[j]<<" to state : ";
            cin >> transition[i][j];
        }
    }

    //displaying the values for the transition table
    cout<<"\n\n The transition table you entered is : \n";
    cout<<"\nstate\t";
    for (i = 0; i < noa; i++)
    {
        cout<<alph[i]<<"\t";
    }
    for (i = 0; i < nos; i++)
    {
        cout<<endl<<states[i]<<"\t";
        for (j = 0; j < noa; j++)
        {
            cout<<transition[i][j]<<"\t";
        }
    }

    while (true)
    {
        again:
        current = 0, flag = 0;  // current will keep track of the current state

        cout<<"\n\n Enter the input string (enter 'exit' to terminate) : ";
        cin >> input;
        if (input.compare("exit") == 0 || input.compare("EXIT") == 0)
        {
            exit(0);
        }
        for (i = 0; i < input.length(); i++)
        {
            // process the string and change the state accordingly
            temp = input.at(i);
            // getting the index of the input from the alphabet set
            for (j = 0; j < noa; j++)
            {
                if (alph[j] == temp)
                {
                    break;
                }
            }
            // storing the value of transition state
            tmp = transition[current][j];
            // changing the current state to the next state
            for (k = 0; k < nos; k++)
            {
                if (states[k].compare(tmp) == 0)
                {
                    current = k;
                    break;
                }
            }
            // loop for checking if the dfa is in a trap state
            for (j = 0; j < nots; j++)
            {
                if (states[current].compare(trap[j]) == 0)
                {
                    cout<<"\n\n The input string has been rejected!!!";
                    goto again;
                }
            }
        }
        // loop for checking if the dfa has reached the final state
        for (i = 0; i < nofs; i++)
        {
            if (states[current].compare(fstates[i]) == 0)
            {
                cout<<"\n\n The input has been accepted by the DFA!!!";
                flag = 1;
            }
            if (flag == 0)
            {
                cout<<"\n\n The input string has been rejected!!!";
            }
            goto again;
        }
    }
    return 0;
}
