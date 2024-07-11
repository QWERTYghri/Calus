/*
 * utility.c
 *
 * File to store utility functions for the program
 * Holds the functionality for the program
 */

/* Imports */
#include <ncurses.h>
#include <locale.h>
#include <stdlib.h>
#include <stdint.h>

/* Local Import */
#include "../Public/define.h"
#include "../Public/utility.h"

/* Initialize Colors */
int32_t
initializeColors ( void )
{
        /* Check for Color Support */
        if ( has_colors () )
                start_color ();
        else
                return -1;

        /* Initialize Colors */
        init_pair ( ColorBlack, COLOR_BLACK, COLOR_BLACK );
        init_pair ( ColorBlue, COLOR_BLUE, COLOR_BLUE );
        init_pair ( ColorGrey, COLOR_BLACK, COLOR_WHITE );
        init_pair ( ColorTextRed, COLOR_RED, COLOR_BLACK );
        init_pair ( ColorSelect, COLOR_WHITE, COLOR_GREEN );

        return 0;
}

/* Initialize Ncurses */
void
enterNcurses ( void )
{
        setlocale ( LC_ALL, "" );
        initscr ();

        //raw ();
        noecho ();
        nonl ();
        keypad ( stdscr, TRUE );
        curs_set ( CURSOR_INVISIBLE );

        if ( initializeColors () != 0 )
                errorMessage ( EXIT_FAILURE, ERROR_COLOR );
}

/* Exit Ncurses */
void
exitNcurses ( void )
{
        erase ();
        refresh ();
        endwin ();
}


/* Error Function */
void
errorMessage ( int32_t code, const char* format, ... )
{
        va_list list;
	va_start ( list, format );

	exitNcurses ();
	vfprintf ( stderr, format, list );
	
	va_end ( list );
	exit ( code );
}