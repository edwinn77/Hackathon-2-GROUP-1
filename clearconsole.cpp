#ifdef _WIN32
#include <windows.h>
#endif

#include "clearconsole.h"

void clearConsole() {
#ifdef _WIN32
    system("cls");  // For Windows
#else
    system("clear");  // For Linux and macOS
#endif
}

