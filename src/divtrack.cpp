#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "divTrack.h"
#include <bits/stdc++.h>

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

void printTitle(){
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    printf("\n");
    printf("      _____  _    _______             _    \n");
    printf("     |  __ \\(_)  |__   __|           | |   \n");
    printf("     | |  | |___   _| |_ __ __ _  ___| | __\n");
    printf("     | |  | | \\ \\ / / | '__/ _` |/ __| |/ /\n");
    printf("     | |__| | |\\ V /| | | | (_| | (__|   < \n");
    printf("     |_____/|_| \\_/ |_|_|  \\__,_|\\___|_|\\_\\\n");
    printf("                                           \n");
    printf("            Version 0.0                              \n\n\n");
    Sleep(750);
    clear_screen();
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

    printf("\n");
    printf("      _____  _    _______             _    \n");
    printf("     |  __ \\(_)  |__   __|           | |   \n");
    printf("     | |  | |___   _| |_ __ __ _  ___| | __\n");
    printf("     | |  | | \\ \\ / / | '__/ _` |/ __| |/ /\n");
    printf("     | |__| | |\\ V /| | | | (_| | (__|   < \n");
    printf("     |_____/|_| \\_/ |_|_|  \\__,_|\\___|_|\\_\\\n");
    printf("                                           \n");
    printf("            Version 0.0                              \n\n\n");
    Sleep(750);
    clear_screen();
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    printf("\n");
    printf("      _____  _    _______             _    \n");
    printf("     |  __ \\(_)  |__   __|           | |   \n");
    printf("     | |  | |___   _| |_ __ __ _  ___| | __\n");
    printf("     | |  | | \\ \\ / / | '__/ _` |/ __| |/ /\n");
    printf("     | |__| | |\\ V /| | | | (_| | (__|   < \n");
    printf("     |_____/|_| \\_/ |_|_|  \\__,_|\\___|_|\\_\\\n");
    printf("                                           \n");
    printf("            Version 0.0                              \n\n\n");
    Sleep(750);
    clear_screen();
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

    printf("\n");
    printf("      _____  _    _______             _    \n");
    printf("     |  __ \\(_)  |__   __|           | |   \n");
    printf("     | |  | |___   _| |_ __ __ _  ___| | __\n");
    printf("     | |  | | \\ \\ / / | '__/ _` |/ __| |/ /\n");
    printf("     | |__| | |\\ V /| | | | (_| | (__|   < \n");
    printf("     |_____/|_| \\_/ |_|_|  \\__,_|\\___|_|\\_\\\n");
    printf("                                           \n");
    printf("            Version 0.0                              \n\n\n");
    Sleep(750);
    clear_screen();
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }

void center_Title(string action,string title) { 
    CONSOLE_SCREEN_BUFFER_INFO s;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(console, &s);

    int width = s.dwSize.X;

    DWORD written;

    WORD originalAttributes = s.wAttributes;

    string prefix = "";

    if(action == "mainmenu"){
        prefix = "Main Menu";
    }
    else if(action == "add"){
        prefix = "New Portfolio: ";
    }
    else if (action == "view"){
        prefix = "Viewing: ";
    }
    else if (action == "view"){
        prefix = "Editing: ";
    }
    else {
        prefix = "";
    }

    string header = prefix + title;

    int padding = ((width - header.size()) / 2) - 1;

    COORD start = {0, 0};

    SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE );

    FillConsoleOutputCharacter(console, '=', padding, start, &written);
    FillConsoleOutputAttribute(console, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE, padding, start, &written);

    COORD title_pos = {static_cast<SHORT>(padding), 0 };
    SetConsoleCursorPosition(console, title_pos);

    cout << " " << header << " ";

    int right_fill = width - (padding + header.size()) - 2;
    COORD right_pos = { static_cast<SHORT>(padding + header.size() + 2), 0 };
    FillConsoleOutputCharacter(console, '=', right_fill, right_pos, &written);
    FillConsoleOutputAttribute(console, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE, right_fill, right_pos, &written);

    COORD next_line = { 0, 2 };
    SetConsoleCursorPosition(console, next_line);

    SetConsoleTextAttribute(hConsole, originalAttributes);
}

portfolioSummary(string portfolio, vector<vector<string>>tabledata){
    clear_screen();
    center_Title("view","Portfolio");
    cout << "   You're viewing a summary of " << portfolio << "\n";
    drawMonthGraph();
    Sleep(16000);
};

void openPortfolio(string portfolio){
    try{
        clear_screen();
        center_Title("view", portfolio);
        string PortfolioData;
        vector<string> row;

        ifstream ReadFile("./portfolios/"+ portfolio +".txt");
        vector<vector<string>> tabledata;
        getline(ReadFile, PortfolioData); //Skips over first line (headers)
        while (getline (ReadFile, PortfolioData)) {
            stringstream ss(PortfolioData);
            string token;
            string word;
            string dateString;
            int date[3];

            vector<string> row;

            for(int i = 0; i < 4; i++){
                getline(ss, word, ',');
                    row.push_back(word);
            }

            dateString = row[1];

            stringstream dss(dateString);

            getline(dss, token, '-');
            date [0] = stoi(token);

            getline(dss, token, '-');
            date [1] = stoi(token);

            getline(dss, token, '-');
            date [2] = stoi(token);

            if(!isValidDate(date[0], date[1], date[2])){
                throw tabledata.size();
            }

            tabledata.push_back(row);
        }

        tabledata = sortByDate(tabledata);

        cout<<"   " << portfolio << " - " << tabledata.size() << " entries" <<" \n \n";

        printf( "%10s %15s %10s %10s\n", "Ticker", "Date", "Amount", "Currency");
        for(int i = 0; i < tabledata.size(); i++){
            printf( "%10s %15s %10s %10s\n", tabledata[i][0].c_str(), tabledata[i][1].c_str(), tabledata[i][2].c_str(), tabledata[i][3].c_str());
        }

        bool viewing = true;
        while (viewing == true){
            if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
                viewing = false;
                portfolioSummary(portfolio, tabledata);
                return;
            }
        }
    }
    catch (size_t invalidRow){
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "Error:";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        cout << " Invalid date at row #" << invalidRow << ". \n Check the date and try again";
        Sleep(3000);
    }
        catch (...){
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "   Error:";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        cout << " There was an error opening this file. Ensure the format matches: \n\n";
        cout << "           Ticker,Date,Amount,Currency\n";
        cout << "           EXMP,01-01-2000,1.01,USD";
        Sleep(5000);
    }
    return;
}

void handleViewPortfolio(){
    string portfolioName;
    //char choice;
    bool choosing = true;

    WIN32_FIND_DATAA FindFileData;
    HANDLE hFind = FindFirstFileA("./portfolios/*.txt", &FindFileData);

    vector<string> portfolios;

    do{
        string filename(FindFileData.cFileName);
        filename.erase (filename.end() - 4, filename.end());
        portfolios.push_back(filename);
    } while (FindNextFileA(hFind, &FindFileData));

    FindClose(hFind);

    size_t highlight = 0;

    while(choosing == true){
        //UNBUFFERED INPUT
        HANDLE hstdin;
        DWORD  mode;

        hstdin = GetStdHandle( STD_INPUT_HANDLE );
        GetConsoleMode( hstdin, &mode );
        SetConsoleMode( hstdin, ENABLE_ECHO_INPUT | ENABLE_PROCESSED_INPUT ); 
        
        clear_screen();
        center_Title("view"," ");
        cout<<"     Portfolios availible to view: \n \n";

        for(size_t i = 0; i < portfolios.size(); i++){
            if(highlight == i){
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                cout << "     " << portfolios[i] << " \n";
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
            else{
                cout<<"     " << portfolios[i] << " \n";
            }

        }

        cout << "\n     [q] Go Back";

        cout << "\n\n\n\n";

        while (true){
            if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
                if(highlight < portfolios.size()-1){
                    highlight++;
                }
            break;
            }
            if (GetAsyncKeyState(VK_UP) & 0x8000) {
                if(highlight > 0){
                    highlight--;
                }
                break;
            }

            if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
                while (GetAsyncKeyState(VK_RETURN) & 0x8000);
                openPortfolio(portfolios[highlight]);
                break;
            }
            if (GetAsyncKeyState(0x51) & 0x8000) {
                choosing = false;
                while (GetAsyncKeyState(0x51) & 0x8000);
                FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
                break;
            }
        }
        SetConsoleMode( hstdin, mode );
        //BUFFERED INPUT
        Sleep(125);
    }

    clear_screen();
}

void handleCreatePortfolio(){
    string portfolioName;
    char choice;
    clear_screen();
    center_Title("add","Unnamed");
    cout<<"Porfolio name: ";
    cin >> portfolioName;
    clear_screen();
    center_Title("add",portfolioName);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout<<"\n   New Portfolio created!";
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE );
    Sleep(1500);
    bool creating = true;

    while(creating == true){
        clear_screen();
        center_Title("add",portfolioName);

        //UNBUFFERED INPUT
        HANDLE hstdin;
        DWORD  mode;

        hstdin = GetStdHandle( STD_INPUT_HANDLE );
        GetConsoleMode( hstdin, &mode );
        SetConsoleMode( hstdin, ENABLE_ECHO_INPUT | ENABLE_PROCESSED_INPUT ); 

        cout<<" [a] Add entries from file \n";
        cout<<" [b] Add entries manually \n";
        cout<<" [q] Quit \n";
        choice = getchar();
        SetConsoleMode( hstdin, mode );
        //BUFFERED INPUT
        switch(choice){
        case 'a':
            clear_screen();
            center_Title("add",portfolioName);
            cout << "Not implemented yet.";
            Sleep(1500);
            //handleFileEntries()
            break;
        case 'b':
            clear_screen();
            center_Title("add",portfolioName);
            cout << "Not implemented yet.";
            //handleManualEntries()
            Sleep(1500);
            break;
        case 'q':
            clear_screen();
            center_Title("add",portfolioName);
            cout << "   Are you sure? Progress will be lost. \n\n";
            //UNBUFFERED INPUT
            HANDLE hstdin;
            DWORD  mode;

            hstdin = GetStdHandle( STD_INPUT_HANDLE );
            GetConsoleMode( hstdin, &mode );
            SetConsoleMode( hstdin, ENABLE_ECHO_INPUT | ENABLE_PROCESSED_INPUT ); 

            cout<<"     [y] Yes, I want to quit to main menu. \n";
            cout<<"     [n] No, I want to keep my progress. \n";
            choice = getchar();
            SetConsoleMode( hstdin, mode );
            //BUFFERED INPUT

            switch(choice){
                case 'y':
                    creating = false;
                    break;
                case 'n':
                    break;
            }
        }
    }
}

int main(){
    bool running = true;
    char choice;

    clear_screen();

    printTitle();

    clear_screen();
    while(running == true){
        HANDLE hstdin;
        DWORD  mode;

        hstdin = GetStdHandle( STD_INPUT_HANDLE );
        GetConsoleMode( hstdin, &mode );
        SetConsoleMode( hstdin, ENABLE_ECHO_INPUT | ENABLE_PROCESSED_INPUT );

        center_Title("mainmenu","");

        cout << " What do you want to do?\n \n";
        cout<<" [v] View dividend portfolio \n";
        cout<<" [c] Create dividend portfolio \n";
        cout<<" [e] Edit existing dividend portfolio \n";
        cout<<" [q] Quit program \n";
        choice = getchar();

        SetConsoleMode( hstdin, mode );
        switch(choice){
            case 'v':
                handleViewPortfolio();
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