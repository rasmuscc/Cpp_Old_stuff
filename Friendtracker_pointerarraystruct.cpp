#include <iostream>
#include <string>
using namespace std;

struct friends
    {
    string name = "Empty";
    int time=0;
    };

// Clear screen.
void cls()
{
    for (int i=0;i<50;i++)
    {
        cout << "\n";
    }
}

friends *addfriend(friends *p_friends, int size)
{
    friends *p_temp = new friends[size]; // Lav en ny array der er én større.

    for (int i=0;i<size-1;i++) // Fyld p_temp op med p_friends værdier.
    {
        p_temp[i].name=p_friends[i].name;
        p_temp[i].time=p_friends[i].time;
    }

    // Fylder den nye struct op.
    string name;
    int time;
    cout << "Enter new name:";
    cin >> name;
    cout << "Enter time since last communication: ";
    cin >> time;
    p_temp[size-1].name=name;
    p_temp[size-1].time=time;

    delete[] p_friends;
    return p_temp;
}

int main()
{
    friends *p_friends = new friends[1];

    p_friends[0].name="Guest";
    p_friends[0].time=100;

    int size=1;
    int i=0;

    while (i==0)
    {
        cls(); // Clear screen.

        int menuchoice=0;
        // option 2.
        int time=0;
        string name="Empty";
        int id=0;


        cout << "Welcome to friendstracker! - Track the last time you spoke to a friend." << endl;
        cout << "Option 1. Add a new friend." << endl;
        cout << "Option 2. Update a friend." << endl;
        cout << "Option 3. Show a sorted list of your friends." << endl;
        cin >> menuchoice;

        switch(menuchoice)
        {
        case 1:
            cls();
            size++; // gør den ikke selv.
            p_friends=addfriend(p_friends, size);
            break;
        case 2:
            cls();
            cout << "Enter friend id: (Can be found by choosing option 3. from the menu.)";
            cin >> id;
            cout << "Enter new name: ";
            cin >> name;
            cout << "Enter time since last communication: ";
            cin >> time;

            p_friends[id].name=name;
            p_friends[id].time=time;
            break;
        case 3:
            cls();
            cout << "Current friend(s):\n";
            for (int j=0;j<size;j++)
            {
                cout << "Name: " << p_friends[j].name;
                cout << "\n";
                cout << "time: " << p_friends[j].time;
                cout << "\n";
                cout << "ID: " << j;
                cout << "\n\n";
                cout << "Press any key to return to the menu.";
            }
            cin.ignore(256,'\n');
            cin.get();
            break;
        case 0:
            i=1; // quit.
            break;
        default:
            cout << "Not an option." << endl;
            break;
        }
    }
}
