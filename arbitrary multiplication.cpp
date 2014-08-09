#include <iostream>
using namespace std;

void multiplication_table (int width, int height)
{
    // 2D POINTER ARRAY.
    int **p_p_array; // Vores pointer, der skal pointe til en række pointer "array's".
    p_p_array = new int *[width]; // Bemærk * da vi peger på pointers.

    for (int i=0;i<width;i++)
    {
        p_p_array[i]= new int [height]; // Længde nedad.
    }

    // fyld table op fra bunden
    for (int h=0;h<width;h++)
    {
        for (int y=0;y<height;y++)
        {
            p_p_array[h][y] = y*h;
        }
    }

    // Print table
    for (int j=0;j<width;j++)
    {
        for (int l=0;l<height;l++)
        {
            cout << "|" << p_p_array[j][l] << "|";
        }
        cout << "\n";

    }

    // delete array
    for (int k=0;k<height;k++)
    {
        delete[] p_p_array[k];
    }
    delete[] p_p_array;
}

int main()
{
    int height=0;
    int width=0;
    cout << "Enter Height(0 to exit): ";
    cin >> height;
    cout << "Enter width(0 to exit): ";
    cin >> width;

    height++;
    width++;

    multiplication_table(width, height);
}
