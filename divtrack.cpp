#include <windows.h>
#include <stdio.h>
#include <iostream>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

//Windows-Only console clear shortcut
void clear_screen(char fill = ' ') { 
    COORD tl = {0,0};
    CONSOLE_SCREEN_BUFFER_INFO s;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);   
    GetConsoleScreenBufferInfo(console, &s);
    DWORD written, cells = s.dwSize.X * s.dwSize.Y;
    FillConsoleOutputCharacter(console, fill, cells, tl, &written);
    FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
    SetConsoleCursorPosition(console, tl);
}

void center_Title(string title) { 
    CONSOLE_SCREEN_BUFFER_INFO s;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(console, &s);

    int width = s.dwSize.X;

    DWORD written;

    WORD originalAttributes = s.wAttributes;

    int padding = ((width - title.size()) / 2) - 1;

    COORD start = {0, 0};

    SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE );

    FillConsoleOutputCharacter(console, '=', padding, start, &written);
    FillConsoleOutputAttribute(console, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE, padding, start, &written);

    COORD title_pos = {static_cast<SHORT>(padding), 0 };
    SetConsoleCursorPosition(console, title_pos);
    cout << " " << title << " ";

    int right_fill = width - (padding + title.size()) - 2;
    COORD right_pos = { static_cast<SHORT>(padding + title.size() + 2), 0 };
    FillConsoleOutputCharacter(console, '=', right_fill, right_pos, &written);
    FillConsoleOutputAttribute(console, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE, right_fill, right_pos, &written);

    COORD next_line = { 0, 2 };
    SetConsoleCursorPosition(console, next_line);

    SetConsoleTextAttribute(hConsole, originalAttributes);
}

void handleCreatePortfolio(){
    string portfolioName;
    char choice;
    clear_screen();
    cout<<"Porfolio name: ";
    cin >> portfolioName;
    clear_screen();
    center_Title(portfolioName);
    cout<<"\n \n New Portfolio created!";
    Sleep(1500);

    while(true){
        clear_screen();
        center_Title(portfolioName);
        cout<<"[a] Add entries from file \n";
        cout<<"[b] Add entries manually \n";
        cin >> choice;
        switch(choice){
        case 'a':
            clear_screen();
            center_Title(portfolioName);
            cout << "Not implemented yet.";
            Sleep(1500);
            //handleFileEntries()
            break;
        case 'b':
            clear_screen();
            center_Title(portfolioName);
            cout << "Not implemented yet.";
            //handleManualEntries()
            Sleep(1500);
            break;
    }
    }
}

int main(){
    bool running = true;
    char choice;

    clear_screen();

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    printf("  _____  _    _______             _    \n");
    printf(" |  __ \\(_)  |__   __|           | |   \n");
    printf(" | |  | |___   _| |_ __ __ _  ___| | __\n");
    printf(" | |  | | \\ \\ / / | '__/ _` |/ __| |/ /\n");
    printf(" | |__| | |\\ V /| | | | (_| | (__|   < \n");
    printf(" |_____/|_| \\_/ |_|_|  \\__,_|\\___|_|\\_\\\n");
    printf("                                       \n");
    printf("Version 0.0                              \n");
    Sleep(2000);

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    clear_screen();
    while(running == true){
        printf("What do you want to do?\n \n");
        printf("[v] View dividend portfolio \n");
        printf("[c] Create dividend portfolio \n");
        printf("[e] Edit existing dividend portfolio \n");
        printf("[q] Quit program \n");
        cin >> choice;
        switch(choice){
            case 'v':
                break;
            case 'c':
                handleCreatePortfolio();
                break;
            case 'e':
                break;
            case 'q':
                running = false;
                break;
        }
        clear_screen();
    }
    return 0;
}