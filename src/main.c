/*
 * main.c
 *
 * Main file for the calus program
*/

/* Imports */
#include <ncurses.h>
#include <stdint.h>

/* Local Imports */
#include "./Public/define.h"
#include "./Public/utility.h"

/* Global Variables */
WINDOW* frontMain = NULL;
WINDOW* backMain = NULL;

/* Decoration */
char* logo[LOGO_SIZE] =
{
        "Lalalalala bored"
};

/* Create Main Window */
static void
createMainScreen ( void )
{
        int32_t yPosition = determineCenter ( SIZE_Y, LINES );
        int32_t xPosition = determineCenter ( SIZE_X, COLS );

        frontMain = newwin ( SIZE_Y, SIZE_X, yPosition, xPosition );
        backMain = newwin ( SIZE_Y, SIZE_X, yPosition + 1, xPosition + 1 );
}

/* Create Main Screens */
static void
initializeScreen ( void )
{
        /* Window Decoration */
        bkgd ( COLOR_PAIR ( ColorBlue ) );
        wbkgd ( backMain, COLOR_PAIR ( ColorBlack ) );
        wbkgd ( frontMain, COLOR_PAIR ( ColorGrey ) );
        box ( frontMain, 0, 0 );

        /* Refresh List */
        refreshList ( 3, stdscr, backMain, frontMain );
}

/* Create Main Menu */
static void
initializeMainMenu ( void )
{
        char* menuList[] =
        {
                "Open Tracker",
                "Exit"
        };

        /* Initiialize Menu */
        int32_t cursorMark = listPrint ( frontMain, LOGO_OFFSET, LOGO_SIZE, logo );
        wrefresh ( frontMain );

        int32_t result = createMenu ( frontMain, cursorMark + 1, OPTION_AMOUNT, menuList );
}


/* Start */
int
main ( void )
{
        /* Initialize NCurses */
        enterNcurses ();

        /* Handle Main Menu */
        createMainScreen ();
        initializeScreen ();
        initializeMainMenu ();
        getch ();

        /* Exit */
        exitNcurses ();
        return 0;
}