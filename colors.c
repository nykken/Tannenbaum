#ifndef COLORS_H
#define COLORS_H

#define MIN_HEIGHT 3
#define MAX_HEIGHT 17
#define BRIGHT_RED "\033[1;31m"
#define BRIGHT_GREEN "\033[1;32m"
#define BRIGHT_YELLOW "\033[1;33m"
#define BRIGHT_BLUE "\033[1;34m"
#define BRIGHT_MAGENTA "\033[1;35m"
#define BRIGHT_CYAN "\033[1;36m"
#define BRIGHT_WHITE "\033[1;37m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"
#define COLOR_END "\033[0m"
char STARS[7] = {'*', '@', '&', 'o', '+', '$', '~'};
char *ORNAMENT_COLORS[4] = {BRIGHT_RED, BRIGHT_BLUE, BRIGHT_MAGENTA, BRIGHT_CYAN};
char ORNAMENTS[3] = {'%', 'O', '#'};

#endif