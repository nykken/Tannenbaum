#include <stdio.h>

int main(void)
{
    #define BRIGHT_RED "\033[1;31m"
    #define BRIGHT_GREEN "\033[1;32m"
    #define BRIGHT_YELLOW "\033[1;33m"
    #define BRIGHT_BLUE "\033[1;34m"
    #define BRIGHT_MAGENTA "\033[1;35m"
    #define BRIGHT_CYAN "\033[1;36m"
    #define BRIGHT_WHITE "\033[1;37m"
    #define COLOR_END "\033[0m"
    char *ORNAMENT_COLORS[4] = {BRIGHT_RED, BRIGHT_BLUE, BRIGHT_MAGENTA, BRIGHT_CYAN};
    printf("\033[1;31mThis text is bright red.\033[0m\n");
    printf("\033[1;32mThis text is bright green.\033[0m\n");
    printf("\033[1;33mThis text is bright yellow.\033[0m\n");
    printf("\033[1;34mThis text is bright blue.\033[0m\n");
    printf("\033[1;35mThis text is bright magenta.\033[0m\n");
    printf("\033[1;36mThis text is bright cyan.\033[0m\n");
    printf("\033[1;37mThis text is bright white.\033[0m\n");
    printf("\033[0;31mThis text is red.\033[0m\n");
    printf("\033[0;32mThis text is green.\033[0m\n");
    printf("\033[0;33mThis text is yellow.\033[0m\n");
    printf("\033[0;34mThis text is blue.\033[0m\n");
    printf("\033[0;35mThis text is magenta.\033[0m\n");
    printf("\033[0;36mThis text is cyan.\033[0m\n");
    printf("\033[0;37mThis text is white.\033[0m\n");



    printf("Teste:\n%sCyan berrante%s\n", BRIGHT_CYAN, COLOR_END);
}
