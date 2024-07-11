/*
 * define.h
 *
 * File to help with literals, and other magic numbers
 *
 */

#ifndef DEFINE_H
#define DEFINE_H

#include <stdint.h>

/* Cursor Enums */
enum {
        CURSOR_INVISIBLE,
        CURSOR_VISIBLE
};

/* Create Colors */
enum {
        ColorBlack,
        ColorBlue,
        ColorGrey,
        ColorTextRed,
        ColorSelect
};

/* Errors */
#define ERROR_COLOR ( "ERROR: Color could not be initialized\n" )

#endif /* END */