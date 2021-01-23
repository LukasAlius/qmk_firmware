#pragma once
 
/* key matrix size */
#undef MATRIX_ROWS
#undef MATRIX_COLS
#define MATRIX_ROWS 7
#define MATRIX_COLS 8

// add two more switches: F6 F5 and F4 D1
// I know this is not a best way to do it, but I don't have any extra diodes...

/* key matrix pins */
#undef MATRIX_ROW_PINS
#undef MATRIX_COL_PINS
#define MATRIX_ROW_PINS { F7, B1, B3, B2, B6, D1, F5}
#define MATRIX_COL_PINS { B4, E6, D7, C6, D4, D0, F4, F6 }