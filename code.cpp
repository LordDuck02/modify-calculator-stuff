#include <windows.h>
#include <iostream>
#include <Tlhelp32.h>

HWND button = nullptr;

//Explanation of this function:
//BOOL is cuz it return TRUE/FALSE values obviously
//CALLBACK is a keyword which means that the function can be used as arguments to other functions
//"Enum" is for Enumarate
//HWND hwnd is for the window thingy, LPARAM is a long parameter, used to pass info or a pointer
BOOL CALLBACK EnumStuff(HWND hwnd, LPARAM lParam) {
    char className[256];
    GetClassNameA(hwnd, className, sizeof(className));

    //strcmp: compares two strings to see if they are the same, case sensitive btw
    if (strcmp(className, "Button") == 0) { //I ASSUME, that since its the deafault calculator from win7, it will have a class named "Button"
        char buttonText[256];
        GetWindowTextA(hwnd, buttonText, sizeof(buttonText));

        if (strcmp(buttonText, "1") == 0) { //"1" is the button we're looking for
            button = hwnd;
            return FALSE;  //stop enumarating stuff
        }
    }

    return TRUE; //continue enumarating (i hope this works cuz my brain just told me to do it)
}


int main()
{
    //warning: im PRETTY sure you can nullptr instead of 0 but i will benchmark that later :troll:
    HWND calcWindow = FindWindowA(0, "Calculadora"); //Remember to change "calculadora" mywotrl!!!!!!!!
    if (calcWindow != NULL)
    {
        SetWindowTextA(calcWindow, "hakar");
        EnumChildWindows(calcWindow, EnumStuff, 0);
        if (button != NULL)
        {
            SetWindowText(button, "hax"); //text to change
            std::cout << "Text changed";
        }
        else
        {
            std::cout << "Button not found";
        }
    }
    else
    {
        std::cout << "Calc window not found";
    }
}
