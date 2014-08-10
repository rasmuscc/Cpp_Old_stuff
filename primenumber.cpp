/*
Finder primtal og gemmer dem i en dynamisk allokeret array.
Rasmus C. Christensen - 30-07-2014
*/

#include <iostream>

using namespace std;

bool isprime(unsigned int numb)
{
    if (numb<2) // Alle primtal er over 1
    {
        return false;
    }

    for (int i=2;i<numb;i++) // Hvis nummeret % i er ==0 != prime.
    {
        if (numb % i==0)
        {
            return false;
        }
    }
    return true;
}

int *growarray(int* p_array, int size) // Husk * ved growarray.
{
    int *p_temp_array = new int [size*2]; // lav en ny array der er dobbelt så stor.

    for (int i=0;i<size;i++) // fyld den nye array op med den forriges.
    {
        p_temp_array[i]=p_array[i];
    }
    delete[] p_array; // pointer, derfor original værdi.
    return p_temp_array;
}

int main ()
{

    int size=100;
    int *p_array = new int [size];
    int ArrayIndex=0; // Holds the next array number.
    int upto=1; // Max range.
    int primecount=0; // Holds how many prime numbers are found. Used for printing.

    while (upto>0)
    {
        cout << "Enter max range (0 to exit):";
        cin >> upto;

        for (unsigned int i=1;i<upto;i++) // Check primtal op til 1000 og fyld dem i memory fra heap.
        {
            if (isprime(i)==true)
            {
                primecount++;
                cout << i << endl;
                p_array[ArrayIndex]=i;
                ArrayIndex++;

                if (ArrayIndex + 1==size) // Double array hvis den ikke er stor nok.
                {
                    p_array = growarray(p_array, size);
                    size = size*2; // Så vi ikke ganger 100 med 2 hvergang.
                }
            }
        }
        cout << "Printing array..." << endl;
        for (int j=0;j<primecount;j++)
            {
                cout << p_array[j] << endl;
            }
    }
}

