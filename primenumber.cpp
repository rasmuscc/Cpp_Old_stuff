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

int *growarray(int* p_array, int size)
{
    int *p_temp_array = new int [size*2]; // lav en ny array der er dobbelt så stor.

    for (int i=0;i<size;i++) // fyld den nye array op med den forriges.
    {
        p_temp_array[i]=p_array[i];
    }
    delete[] p_array;
    return p_temp_array;
}

int main ()
{
    int size=10;
    int *p_array = new int [size];
    int ArrayIndex=0; // Holds the next array number.

        for (unsigned int i=1;i<100000;i++) // Check primtal op til 1000 og fyld dem i memory fra heap.
    {
        if (isprime(i)==true)
        {
            cout << i << endl;
            p_array[ArrayIndex]=i;
            ArrayIndex++;

            if (ArrayIndex + 1==size) // Double array hvis den ikke er stor nok.
            {
                p_array = growarray(p_array, size);
                size = size*2; // Så vi bare ganger 100 med 2, men 200 med 2, osv....
            }
        }
    }
}
