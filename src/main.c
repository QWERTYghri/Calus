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

/* Start */
int
main ( void )
{
        enterNcurses ();

        printw ( "test" );
        getch ();

        exitNcurses ();
        return 0;
}