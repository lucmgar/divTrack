#include "divTrack.h"
#include <windows.h>
#include <iostream>

using namespace std;

void draw_char_at(int x, int y, wchar_t wc, WORD attribute = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD written;
    COORD coord = { static_cast<SHORT>(x), static_cast<SHORT>(y) };

    //write character at coordinate
    WriteConsoleOutputCharacterW(console, &wc, 1, coord, &written);

    //set text attributes
    WriteConsoleOutputAttribute(console, &attribute, 1, coord, &written);
}

void drawMonthGraph(){
    draw_char_at(3, 4, L'┌');
    for (int i = 0; i < 49; i++){
        draw_char_at(i+4, 4, L'─');
    };
    draw_char_at(53, 4, L'┐');
    for (int i = 0; i < 16; i++){
        draw_char_at(3, i+5, L'│');
        draw_char_at(53, i+5, L'│');
    };
    draw_char_at(3, 21, L'└');
    for (int i = 0; i < 49; i++){
        draw_char_at(i+4, 21, L'─');
    };
    draw_char_at(53, 21, L'┘');

    draw_char_at(5, 16, L'J');
    draw_char_at(6, 16, L'A');
    draw_char_at(7, 16, L'N');

    draw_char_at(9, 16, L'F');
    draw_char_at(10, 16, L'E');
    draw_char_at(11, 16, L'B');

    draw_char_at(13, 16, L'M');
    draw_char_at(14, 16, L'A');
    draw_char_at(15, 16, L'R');

    draw_char_at(17, 16, L'A');
    draw_char_at(18, 16, L'P');
    draw_char_at(19, 16, L'R');

    draw_char_at(21, 16, L'M');
    draw_char_at(22, 16, L'A');
    draw_char_at(23, 16, L'Y');

    draw_char_at(25, 16, L'J');
    draw_char_at(26, 16, L'U');
    draw_char_at(27, 16, L'N');

    draw_char_at(29, 16, L'J');
    draw_char_at(30, 16, L'U');
    draw_char_at(31, 16, L'L');

    draw_char_at(33, 16, L'A');
    draw_char_at(34, 16, L'U');
    draw_char_at(35, 16, L'G');

    draw_char_at(37, 16, L'S');
    draw_char_at(38, 16, L'E');
    draw_char_at(39, 16, L'P');

    draw_char_at(41, 16, L'O');
    draw_char_at(42, 16, L'C');
    draw_char_at(43, 16, L'T');

    draw_char_at(45, 16, L'N');
    draw_char_at(46, 16, L'O');
    draw_char_at(47, 16, L'V');

    draw_char_at(49, 16, L'D');
    draw_char_at(50, 16, L'E');
    draw_char_at(51, 16, L'C');
}

void drawYearGraph(){
    return;
}