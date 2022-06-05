#include <windows.h>
#include <conio.h>

#ifndef shared_h
#define shared_h

    #include <iostream>
    #include <map>
    #include <algorithm>

    using namespace std;

#endif

class userInterface
{
    private:
        int defaultX, defaultY;
        CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
        CONSOLE_CURSOR_INFO cursorInfo;
        WORD dayModeWord;
        HWND consoleWindow;
        HANDLE handleOutput;
        COORD tempCoord;
        bool dayMode;
        int choiceMenu;
    
    public:
        userInterface();

        void setCursorPosition(int x, int y);

        void deleteLine(int x, int y);

        void successMessage(int time);

        void displayMessage(string message);

        void deleteTableContent();

        void displayListTable();

        void clearListTable(int mode);

        int menuHelp(int j, int i);

        void menu();

        void displayDayModeChoice();

        int menuChoice(int k);

        int getChoiceMenu();

        void setChoiceMenu(int tempChoiceMenu);

        int getDefaultX();
        
        int getDefaultY();
};