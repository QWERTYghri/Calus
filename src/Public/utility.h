/*
 * utility.h
 *
 * File to store utility functions for the program
 *
 */

#ifndef UTILITY_H
#define UTILITY_H

/* Imports */
#include <ncurses.h>
#include <stdint.h>

/* Ncurses Initializers*/
int32_t initializeColors ( void );
void enterNcurses ( void );
void exitNcurses ( void );

/* Centering Functions */
int32_t determineCenter ( int32_t size, int32_t reference );
void centerPrint ( WINDOW* window, int32_t ySize, char* string );
void listPrint ( WINDOW* window, int32_t ySize, int32_t size, char** stringList );

/* Other Utility */
void errorMessage ( int32_t code, const char* format, ... );
void refreshList ( int32_t count, ... );

#endif /* END */