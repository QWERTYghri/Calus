/*
 * utility.h
 *
 * File to store utility functions for the program
 *
 */

#ifndef UTILITY_H
#define UTILITY_H

#include <stdint.h>

/* Ncurses Initializers*/
int32_t initializeColors ( void );
void enterNcurses ( void );
void exitNcurses ( void );

/* Other Utility */
void errorMessage ( int32_t code, const char* format, ... );

#endif /* END */