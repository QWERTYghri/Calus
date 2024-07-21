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

/* Screen Size */
#define SIZE_Y ( ( uint32_t ) LINES - 30 )
#define SIZE_X ( ( uint32_t ) COLS - 80 )

/* Screen Offset */
#define LOGO_OFFSET ( ( uint32_t ) 5 )

/* Errors */
#define ERROR_COLOR ( "ERROR: Color could not be initialized\n" )

#endif /* END */