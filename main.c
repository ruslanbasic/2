#include <ncursesw/curses.h>
#include <locale.h>

#define COLOR_BLUE_YELLOW 1

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, ""); // Включення підтримки юнікод

    // Ініціалізація ncurses (зчитування конфігурації термінала)
    WINDOW *stdscr = initscr();

    // Ініціалізація кольорового режиму і створення пари кольорів для фону і тексту
    start_color();

    init_pair(COLOR_BLUE_YELLOW, COLOR_YELLOW, COLOR_BLUE);

    // Початок відображення в заданому кольоровому режимі
    attron(COLOR_PAIR(COLOR_BLUE_YELLOW));

    //COLOR_YELLOW фактично є коричневим. Для того щоб отримати жовтий, використовують COLOR_YELLOW 
    //в поєднанні з атрибутом A_BOLD.
    attron(A_BOLD);

    printw("Текст має вивестись жовтим кольором на синьому фоні!\n");

    attroff(A_BOLD);

    // Вивести текст без налаштування кольору
    attroff(COLOR_PAIR(1));
    printw("Натисніть будь-яку клавішу для виходу\n");

    // Оновлення екрану
    refresh();

    // Очікування натиснення клавіші перед завершенням програми
    getch();

    // Відновлення початкового налаштування терміналу
    endwin();
}
