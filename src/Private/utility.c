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
#include <string.h>

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

/* Determine Center Value */
int32_t
determineCenter ( int32_t size, int32_t reference )
{
        return ( reference / 2 ) - ( size / 2 );
}

/* Create Center Print */
void
centerPrint ( WINDOW* window, int32_t ySize, char* string )
{
        /* Get Window Sizes */
        int32_t xWindow = getmaxx ( window );
        mvwprintw ( window, ySize, determineCenter ( strlen ( string ), xWindow ), "%s", string );
}

/* List Print of Strings */
void
listPrint ( WINDOW* window, int32_t ySize, int32_t size, char** stringList )
{
        for ( int32_t index = 0; index < size; index++ )
                centerPrint ( window, ySize + index, stringList[index] );
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

/* Refresh List */
void
refreshList ( int32_t count, ... )
{
        va_list windows;
        va_start ( windows, count );

        for ( int32_t index = 0; index < count; index++ )
                wrefresh ( va_arg ( windows, WINDOW* ) );

        va_end ( windows );
}