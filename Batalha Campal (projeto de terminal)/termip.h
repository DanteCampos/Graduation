/*
 * termip.h
 *
 *  Created on: 12 de mai de 2017
 *      Author: Gustavo Teodoro Laureano
 *      email: gustavo@inf.ufg.br
 *
 *		>> CSI codes description
 *      https://en.wikipedia.org/wiki/ANSI_escape_code#graphics
 *      http://wiki.bash-hackers.org/scripting/terminalcodes
 *
 *		>> List of UNICODE characters
 *      https://en.wikipedia.org/wiki/List_of_Unicode_characters
 *      https://en.wikipedia.org/wiki/Box-drawing_character
 */

#ifndef TERM_IP_H_
#define TERMIP_H_

#include <stdio.h>

#define QUOTE(n) 		#n
#define ESC				"\033["

/*********************************************************************
 * General useful ASCII codes
 *********************************************************************/
#define BEL				"\a"
#define BACKSPACE 		"\b"
#define TAB				"\t"
#define NEW_LINE		"\n"
#define VTAB			"\v"
#define NEW_PAGE		"\f"
#define CR				"\r"

/*********************************************************************
 * Cursor handling
 *********************************************************************/
#define CURSOR_UP(n)		ESC QUOTE(n) "A"				// Move cursor up n lines
#define CURSOR_DOWN(n)		ESC QUOTE(n) "B"				// Move cursor down n lines
#define CURSOR_FORWARD(n)	ESC QUOTE(n) "C"				// Move cursor right n columns
#define CURSOR_BACK(n)		ESC QUOTE(n) "D"				// Move cursor left n columns
#define CURSOR_NEXT_LINE(n)	ESC QUOTE(n) "E"				// Move cursor to next line
#define CURSOR_PREV_LINE(n)	ESC QUOTE(n) "F"				// Move cursor to previous line
#define CURSOR_COLUMN(n)	ESC QUOTE(n) "G"				// Move cursor to column n
#define CURSOR_HOME			ESC "H"							// Move cursor to position (1,1)
#define CURSOR( row, col )	ESC QUOTE(row)";"QUOTE(col)"H"	// Move cursor to position (row,col)

#define CURSOR_INVISIBLE	ESC "?25l"						// Make cursor invisible
#define CURSOR_VISIBLE		ESC "?25h"						// Make cursor visible

#define CURSOR_SAVE_POSITION		ESC "s"					// Save current position of cursor
#define CURSOR_RESTORE_POSITION		ESC "u"					// Move cursor to last saved position

/*********************************************************************
 * Clear Screen
 *********************************************************************/
#define CLEAR			ESC "H" ESC "J"						// Clear screen and move cursor to position (1,1)
#define CLEAR_DOWN		ESC "0J"
#define CLEAR_UP		ESC "1J"
#define CLEAR_SCREEN	ESC "2J"
#define CLEAR_ALL		ESC "3J"

/*********************************************************************
 * Erasing text
 *********************************************************************/
#define CLEAR_END_LINE		ESC "0K"						// Erase current line from current column to end
#define CLEAR_BACK_LINE		ESC "1K"						// Erase current line from current column to start
#define CLEAR_WHOLE_LINE	ESC "2K"						// Erase whole current line

/*********************************************************************
 * Scroll
 *********************************************************************/
#define SCROLL_UP(n)		ESC QUOTE(n) "S"				// Scroll up n lines
#define SCROLL_DOWN(n)		ESC QUOTE(n) "T"				// Scroll down n lines

/*********************************************************************
 * General text attributes
 *********************************************************************/
#define ATTR_RESET_ALL		ESC "0m"

#define ATTR_BOLD			ESC "1m"
#define ATTR_BOLD_OFF		ESC "21m"

#define ATTR_HALF_BRIGHT	ESC "2m"
#define ATTR_NORMAL_BRIGHT	ESC "22m"

#define ATTR_ITALIC_ON		ESC "3m"
#define ATTR_ITALIC_OFF		ESC "23m"

#define ATTR_UNDERLINE_ON	ESC "4m"
#define ATTR_UNDERLINE_OFF	ESC "24m"

#define ATTR_BLINK_ON		ESC "5m"
#define ATTR_BLINK_FAST_ON	ESC "6m"
#define ATTR_BLINK_OFF		ESC "25m"

#define ATTR_CONCEAL_ON		ESC "8m" 						// Hide text
#define ATTR_CONCEAL_OFF	ESC "28m"						// Unhide text

#define ATTR_NEGATIVE_ON	ESC "7m"
#define ATTR_NEGATIVE_OFF	ESC "27m"

#define ATTR_CROSSED_ON		ESC "9m"
#define ATTR_CROSSED_OFF	ESC "29m"

/*********************************************************************
 * Foreground colouring
 *********************************************************************/
#define FG_BLACK		ESC "90m"
#define FG_RED			ESC "91m"
#define FG_GREEN		ESC "92m"
#define FG_YELLOW		ESC "93m"
#define FG_BLUE			ESC "94m"
#define FG_MAGENTA		ESC "95m"
#define FG_CYAN			ESC "96m"
#define FG_WHITE		ESC "97m"

#define FG_black		ESC "30m"
#define FG_red			ESC "31m"
#define FG_green		ESC "32m"
#define FG_yellow		ESC "33m"
#define FG_blue			ESC "34m"
#define FG_magenta		ESC "35m"
#define FG_cyan			ESC "36m"
#define FG_white		ESC "37m"

#define FG_DEFAULT		ESC "39m"

#define FG_SET(r,g,b)	ESC "38;2;"QUOTE(r)";"QUOTE(g)";"QUOTE(b)"m"

#define FG_COLOR_MODE(n)	ESC "38;5;" QUOTE(n) "m" // 256-Color Mode (n: 0-255)

/*********************************************************************
 * Background colouring
 *********************************************************************/
#define BG_BLACK		ESC "100m"
#define BG_RED			ESC "101m"
#define BG_GREEN		ESC "102m"
#define BG_YELLOW		ESC "103m"
#define BG_BLUE			ESC "104m"
#define BG_MAGENTA		ESC "105m"
#define BG_CYAN			ESC "106m"
#define BG_WHITE		ESC "107m"

#define BG_black		ESC "40m"
#define BG_red			ESC "41m"
#define BG_green		ESC "42m"
#define BG_yellow		ESC "43m"
#define BG_blue			ESC "44m"
#define BG_magenta		ESC "45m"
#define BG_cyan			ESC "46m"
#define BG_white		ESC "47m"

#define BG_DEFAULT		ESC "49m"

#define BG_SET(r,g,b )	ESC "48;2;"QUOTE(r)";"QUOTE(g)";"QUOTE(b)"m"

#define BG_COLOR_MODE(n)	ESC "48;5;" QUOTE(n) "m" // 256-Color Mode (n: 0-255)

/*********************************************************************
 * Auxiliary Functions
 *********************************************************************/
#define COLOR_BLACK			0
#define COLOR_RED			1
#define COLOR_GREEN			2
#define COLOR_YELLOW		3
#define COLOR_BLUE			4
#define COLOR_MAGENTA		5
#define COLOR_CYAN			6
#define COLOR_WHITE			7

/**
 * Same of getchar without '\n'. Get the key immediately pressed.
 * 
 * @return ASCII code of pressed key.
 */
int getch();

/*
 * Clear screen and moves cursor to home.
 * Screen is fully with previous defined background color.
 */
void clear();

/**
 * Moves cursor to position (row,col)
 *
 * @param row
 * @param col
 */
void gotoxy(int row, int col);

/**
 * Set foreground color using a color from definition type COLOR_*
 *
 * @param color is a definition from COLOR_*
 * @param b 0 for half bright and 1 to high bright
 */
void set_fg(int color, char b);

/**
 * Set background color using a color from definition type COLOR_*
 *
 * @param color is a definition from COLOR_*
 * @param b 0 for half bright and 1 to high bright
 */
void set_bg(int color, char b);

/**
 * Set foreground color using predefined 256-color mode
 *
 * @param color: 	0-7 	for Standard colors (half bright)
 * 					8-15 	for High-intensity colors (full bright)
 * 					16-231 	from color palette
 * 					232-255 for gray scalecolors (black to white)
 */
void set_fg_color_mode(int color);

/**
 * Set background color using predefined 256-color mode
 *
 * @param color: 	0-7 	for Standard colors (half bright)
 * 					8-15 	for High-intensity colors (full bright)
 * 					16-231 	from color palette
 * 					232-255 for gray scalecolors (black to white)
 */
void set_bg_color_mode(int color);

/**
 * Set foreground color using R G B
 *
 * @param r 	red channel (0-255)
 * @param g 	green channel (0-255)
 * @param b 	blue channel (0-255)
 */
void set_fg_rgb(int r, int g, int b);

/**
 * Set background color using R G B
 *
 * @param r 	red channel (0-255)
 * @param g 	green channel (0-255)
 * @param b 	blue channel (0-255)
 */
void set_bg_rgb(int r, int g, int b);

/**
 * Get number of columns of terminal window
 * @return number of columns
 */
int get_terminal_ncols();

/**
 * Get number of rows of terminal window
 * @return number of rows
 */
int get_terminal_nrows();

void cursor_up(int n);
void cursor_down(int n);
void cursor_righ(int n);
void cursor_left(int n);

void scrow_up(int n);
void scrow_down(int n);

/**
 * Draw window border
 *
 * @param r1
 * @param c1
 * @param r2
 * @param c2
 * @param name
 */
void window(int r1, int c1, int r2, int c2, const char * name);

#endif /* TERM_IP_H_ */
