#include "userInterface.h"

userInterface::userInterface()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    handleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    consoleWindow = GetConsoleWindow();
    SetWindowPos(consoleWindow, HWND_TOP, -7, 0, 0, 0, SWP_SHOWWINDOW);
    ShowWindow(consoleWindow, SW_MAXIMIZE);
    SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX & ~WS_MAXIMIZE);
    GetConsoleScreenBufferInfo(handleOutput, &csbiInfo);
    COORD tempCoord;
    tempCoord.X = csbiInfo.dwMaximumWindowSize.X;
    tempCoord.Y = csbiInfo.dwMaximumWindowSize.Y;
    SetConsoleScreenBufferSize(handleOutput, tempCoord);
    GetConsoleCursorInfo(handleOutput, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(handleOutput, &cursorInfo);
    dayModeWord = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY;
    choiceMenu = 0;
}

void userInterface::setCursorPosition(int x, int y)
{
    tempCoord.X = x;
    tempCoord.Y = y;
    SetConsoleCursorPosition(handleOutput, tempCoord);
}

void userInterface::deleteLine(int x, int y)
{
    setCursorPosition(x, y);
    cout << "                                                                                                                                      ";
    setCursorPosition(x, y);
}

void userInterface::successMessage(int time)
{
    deleteLine(defaultX, defaultY - 1);
    deleteLine(defaultX, defaultY + 1);
    deleteLine(defaultX, defaultY);
    cout << " Успех!";
    Sleep(time);
    deleteLine(defaultX, defaultY);
}

void userInterface::displayMessage(string message)
{
    deleteLine(defaultX, defaultY);
    cout << " " << message;
    deleteLine(defaultX, defaultY + 1);           
}

void userInterface::deleteTableContent()
{
    for (int i = defaultY + 6; i < (defaultY + 24); i++)
        deleteLine(defaultX, i);
}

int userInterface::menuHelp(int j, int i)
{
    switch (j)
    {
        case 1:
            while (i--)
            {
                if (i == 0) cout << " ";
                else
                    if (i % 2 == 0) cout << "  ";
                    else cout << "¤¤";
            }
            break;

        case 2:
            while (i--)
            {
                if (i == 0) cout << " ";
                else
                    if (i % 2 == 0) cout << "¤¤";
                    else cout << "  ";
            }
            break;

        case 3:
            while (i--)
            {
                if (i == ((csbiInfo.dwMaximumWindowSize.X - 172) / 4) - 1) cout << " ";
                else
                    if (i % 2 == 0) cout << "  ";
                    else cout << "¤¤";
            }
            cout << "¤¤";
            break;

        case 4:
            while (i--)
            {
                if (i == ((csbiInfo.dwMaximumWindowSize.X - 172) / 4) - 1) cout << " ";
                else
                    if (i % 2 == 0) cout << "¤¤";
                    else cout << "  ";
            }
            cout << "  ";
            break;
    }
    i = ((csbiInfo.dwMaximumWindowSize.X - 172) / 4);
    return i;
}

void userInterface::menu()
{
    int i, j;
    if (dayMode)
    {
        system("color F5");
        SetConsoleTextAttribute(handleOutput, dayModeWord | FOREGROUND_RED | FOREGROUND_BLUE);
    }
    else SetConsoleTextAttribute(handleOutput, FOREGROUND_RED | FOREGROUND_BLUE);
    for (i = 0; i < ((csbiInfo.dwMaximumWindowSize.Y - 30) / 2); i++)
    {
        if (i % 2 == 0)
            for (j = 0; j < (csbiInfo.dwMaximumWindowSize.X / 4); j++)
            {
                if (dayMode) SetConsoleTextAttribute(handleOutput, dayModeWord | FOREGROUND_RED | FOREGROUND_BLUE);
                else SetConsoleTextAttribute(handleOutput, FOREGROUND_RED | FOREGROUND_BLUE);
                cout << "¤¤";
                if (dayMode) SetConsoleTextAttribute(handleOutput, dayModeWord | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                else SetConsoleTextAttribute(handleOutput, 0);
                cout << "¤¤";
            }
        else
            for (j = 0; j < (csbiInfo.dwMaximumWindowSize.X / 4); j++)
            {
                if (dayMode) SetConsoleTextAttribute(handleOutput, dayModeWord | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                else SetConsoleTextAttribute(handleOutput, 0);
                cout << "¤¤";
                if (dayMode) SetConsoleTextAttribute(handleOutput, dayModeWord | FOREGROUND_RED | FOREGROUND_BLUE);
                else SetConsoleTextAttribute(handleOutput, FOREGROUND_RED | FOREGROUND_BLUE);
                cout << "¤¤";
            }
        cout << endl;
    }
    int l, g;
    if (i % 2 != 0)
    {
        for (j = 0; j < (csbiInfo.dwMaximumWindowSize.X / 4); j++)
        {
            if (dayMode) SetConsoleTextAttribute(handleOutput, dayModeWord | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            else SetConsoleTextAttribute(handleOutput, 0);
            cout << "¤¤";
            if (dayMode) SetConsoleTextAttribute(handleOutput, dayModeWord | FOREGROUND_RED | FOREGROUND_BLUE);
            else SetConsoleTextAttribute(handleOutput, FOREGROUND_RED | FOREGROUND_BLUE);
            cout << "¤¤";
        }
        cout<<endl;
        defaultY = i + 5;
        g = 1;
        l = 2;
    }
    else 
        {
            defaultY = i + 4;
            l = 1;
            g = 2;
        }
   
    csbiInfo.dwCursorPosition.Y = defaultY - 1;
    if (dayMode) SetConsoleTextAttribute(handleOutput, dayModeWord | FOREGROUND_RED | FOREGROUND_BLUE);
    else SetConsoleTextAttribute(handleOutput, FOREGROUND_RED | FOREGROUND_BLUE);
    i = ((csbiInfo.dwMaximumWindowSize.X - 172) / 4);
    defaultX = (i * 2) + 36;
    csbiInfo.dwCursorPosition.X = defaultX - 37;
    if (i % 2 )
    j = 1; 
    i = menuHelp(l, i); cout << "__________________________________  ________________________________________________________________________________________________________________________________________"; i = menuHelp(4, i); cout << endl;
    i = menuHelp(g, i); cout << "|             Меню               |  |                                                     Сообщения для пользователя                                                       |"; i = menuHelp(3, i); cout << endl;
    i = menuHelp(l, i); cout << "|--------------------------------|  |--------------------------------------------------------------------------------------------------------------------------------------|"; i = menuHelp(4, i); cout << endl;
    i = menuHelp(g, i); cout << "| Создать форму страховки        |  |                                                                                                                                      |"; i = menuHelp(3, i); cout << endl;
    i = menuHelp(l, i); cout << "|--------------------------------|  |                                                                                                                                      |"; i = menuHelp(4, i); cout << endl;
    i = menuHelp(g, i); cout << "| Создать заявление на страховку |  |                                                                                                                                      |"; i = menuHelp(3, i); cout << endl;
    i = menuHelp(l, i); cout << "|--------------------------------|  |--------------------------------------------------------------------------------------------------------------------------------------|"; i = menuHelp(4, i); cout << endl;
    i = menuHelp(g, i); cout << "| Создать денежную транзакцию    |  |                                                        Результаты запроса                                                            |"; i = menuHelp(3, i); cout << endl;
    i = menuHelp(l, i); cout << "|--------------------------------|  |--------------------------------------------------------------------------------------------------------------------------------------|"; i = menuHelp(4, i); cout << endl;
    i = menuHelp(g, i); cout << "| Вернуть данные о тр-ии клиента |  |                                                                                                                                      |"; i = menuHelp(3, i); cout << endl;
    i = menuHelp(l, i); cout << "|--------------------------------|  |                                                                                                                                      |"; i = menuHelp(4, i); cout << endl;
    i = menuHelp(g, i); cout << "| Вернуть данные о ст-ке клиента |  |                                                                                                                                      |"; i = menuHelp(3, i); cout << endl;
    i = menuHelp(l, i); cout << "|--------------------------------|  |                                                                                                                                      |"; i = menuHelp(4, i); cout << endl;
    i = menuHelp(g, i); cout << "| Вернуть детали о клиенте       |  |                                                                                                                                      |"; i = menuHelp(3, i); cout << endl;
    i = menuHelp(l, i); cout << "|--------------------------------|  |                                                                                                                                      |"; i = menuHelp(4, i); cout << endl;
    i = menuHelp(g, i); cout << "| Вернуть детали о форме ст-ки   |  |                                                                                                                                      |"; i = menuHelp(3, i); cout << endl;
    i = menuHelp(l, i); cout << "|--------------------------------|  |                                                                                                                                      |"; i = menuHelp(4, i); cout << endl;
    i = menuHelp(g, i); cout << "| Изменить детали о клиенте      |  |                                                                                                                                      |"; i = menuHelp(3, i); cout << endl;
    i = menuHelp(l, i); cout << "|--------------------------------|  |                                                                                                                                      |"; i = menuHelp(4, i); cout << endl;
    i = menuHelp(g, i); cout << "| Изменить детали о форме ст-ки  |  |                                                                                                                                      |"; i = menuHelp(3, i); cout << endl;
    i = menuHelp(l, i); cout << "|--------------------------------|  |                                                                                                                                      |"; i = menuHelp(4, i); cout << endl;
    i = menuHelp(g, i); cout << "| Изменить статус клиента        |  |                                                                                                                                      |"; i = menuHelp(3, i); cout << endl;
    i = menuHelp(l, i); cout << "|--------------------------------|  |                                                                                                                                      |"; i = menuHelp(4, i); cout << endl;
    i = menuHelp(g, i); cout << "| Изменить статус ст-ки клиента  |  |                                                                                                                                      |"; i = menuHelp(3, i); cout << endl;
    i = menuHelp(l, i); cout << "|--------------------------------|  |                                                                                                                                      |"; i = menuHelp(4, i); cout << endl;
    i = menuHelp(g, i); cout << "| Удалить форму страховки        |  |                                                                                                                                      |"; i = menuHelp(3, i); cout << endl;
    i = menuHelp(l, i); cout << "|--------------------------------|  |                                                                                                                                      |"; i = menuHelp(4, i); cout << endl;
    i = menuHelp(g, i); cout << "| Выход                          |  |                                                                                                                                      |"; i = menuHelp(3, i); cout << endl;
    i = menuHelp(l, i); cout << "|________________________________|  |______________________________________________________________________________________________________________________________________|"; i = menuHelp(4, i); cout << endl;
    i = menuHelp(g, i); cout << "                                                                                                                                                                            "; i = menuHelp(3, i); cout << endl;
    for (i = 0; i < ((csbiInfo.dwMaximumWindowSize.Y - 30) / 2); i++)
    {
        if ((i % 2 == 0))
            for (j = 0; j < (csbiInfo.dwMaximumWindowSize.X / 4); j++)
            {
                if (dayMode) SetConsoleTextAttribute(handleOutput, dayModeWord | FOREGROUND_RED | FOREGROUND_BLUE);
                else SetConsoleTextAttribute(handleOutput, FOREGROUND_RED | FOREGROUND_BLUE);
                cout << "¤¤";
                if (dayMode) SetConsoleTextAttribute(handleOutput, dayModeWord | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                else SetConsoleTextAttribute(handleOutput, 0);
                cout << "¤¤";
            }
        else
            for (j = 0; j < (csbiInfo.dwMaximumWindowSize.X / 4); j++)
            {
                if (dayMode) SetConsoleTextAttribute(handleOutput, dayModeWord | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                else SetConsoleTextAttribute(handleOutput, 0);
                cout << "¤¤";
                if (dayMode) SetConsoleTextAttribute(handleOutput, dayModeWord | FOREGROUND_RED | FOREGROUND_BLUE);
                else SetConsoleTextAttribute(handleOutput, FOREGROUND_RED | FOREGROUND_BLUE);
                cout << "¤¤";
            }
        cout << endl;
    }
}

void userInterface::displayDayModeChoice()
{
    int key;
    cout << " Включить дневной режим работы программы?" << endl;
    cout << endl << " | Y | | N |";
    setCursorPosition(1, 2);
    dayMode = true;
    cout << "> Y <";
    do
    {
        fflush(stdin);
        key = _getch();
        if (key == 224) key = _getch();
        switch (key)
        {
            case 75:
                setCursorPosition(1, 2);
                cout << "> Y < | N |";
                dayMode = true;
                break;
            case 77:
                setCursorPosition(1, 2);
                cout << "| Y | > N <";
                dayMode = false;
                break;

            case 13:
                break;
        }
    } while (key != 13);
    system("cls");
}

int userInterface::menuChoice(int k)
{
    char menuChoiceArray[13][63] =
    {
        "> Создать форму страховки        <",
        "> Создать заявление на страховку <",
        "> Создать денежную транзакцию    <",
        "> Вернуть данные о тр-ии клиента <",
        "> Вернуть данные о ст-ке клиента <",
        "> Вернуть детали о клиенте       <",
        "> Вернуть детали о форме ст-ки   <",
        "> Изменить детали о клиенте      <",
        "> Изменить детали о форме ст-ки  <",
        "> Изменить статус клиента        <",
        "> Изменить статус ст-ки клиента  <",
        "> Удалить форму страховки        <",
        "> Выход                          <"
    },
        menuArray[13][63] =
    {
        "| Создать форму страховки        |",
        "| Создать заявление на страховку |",
        "| Создать денежную транзакцию    |",
        "| Вернуть данные о тр-ии клиента |",
        "| Вернуть данные о ст-ке клиента |",
        "| Вернуть детали о клиенте       |",
        "| Вернуть детали о форме ст-ки   |",
        "| Изменить детали о клиенте      |",
        "| Изменить детали о форме ст-ки  |",
        "| Изменить статус клиента        |",
        "| Изменить статус ст-ки клиента  |",
        "| Удалить форму страховки        |",
        "| Выход                          |"
    };
    int key;
    do
    {
        if (dayMode) SetConsoleTextAttribute(handleOutput, dayModeWord | FOREGROUND_RED | FOREGROUND_GREEN);
        else SetConsoleTextAttribute(handleOutput, FOREGROUND_RED | FOREGROUND_GREEN);
        deleteLine(defaultX, defaultY - 1);
        deleteLine(defaultX, defaultY);
        deleteLine(defaultX, defaultY + 1);
        SetConsoleCursorPosition(handleOutput, csbiInfo.dwCursorPosition);
        cout << menuChoiceArray[k];
        key = _getch();
        if (key == 224) key = _getch();
        switch (key)
        {
        case 72:
            if (dayMode) SetConsoleTextAttribute(handleOutput, dayModeWord | FOREGROUND_RED | FOREGROUND_BLUE);
            else SetConsoleTextAttribute(handleOutput, FOREGROUND_RED | FOREGROUND_BLUE);
            SetConsoleCursorPosition(handleOutput, csbiInfo.dwCursorPosition);
            cout << menuArray[k];
            k--;
            csbiInfo.dwCursorPosition.Y -= 2;
            if (k < 0) k = 0;
            if (csbiInfo.dwCursorPosition.Y < defaultY) csbiInfo.dwCursorPosition.Y = defaultY - 1;
            break;

        case 80:
            if (dayMode) SetConsoleTextAttribute(handleOutput, dayModeWord | FOREGROUND_RED | FOREGROUND_BLUE);
            else SetConsoleTextAttribute(handleOutput, FOREGROUND_RED | FOREGROUND_BLUE);
            SetConsoleCursorPosition(handleOutput, csbiInfo.dwCursorPosition);
            cout << menuArray[k];
            k++;
            csbiInfo.dwCursorPosition.Y += 2;
            if (k > 12) k = 12;
            if (csbiInfo.dwCursorPosition.Y > (defaultY + 24)) csbiInfo.dwCursorPosition.Y = defaultY + 23;
            break;

        case 13: return k; break;

        default:
            deleteLine(defaultX, defaultY);
            cout << " ВНИМАНИЕ: Ошибка";
            Sleep(1000);
            break;
        }
    } while (key != 13);
    return k;
}

int userInterface::getChoiceMenu()
{
    return choiceMenu;
}

void userInterface::setChoiceMenu(int tempChoiceMenu)
{
    choiceMenu = tempChoiceMenu;
}

int userInterface::getDefaultX()
{
    return defaultX;
}

int userInterface::getDefaultY()
{
    return defaultY;
}