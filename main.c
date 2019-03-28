#include <ncursesw/curses.h>
#include <locale.h>
#include <math.h>


float Bm, g, Hg, U1min, U2, Kt, I1, I1ef, I2, I2ef, Le, Hm, IW, f, J, ko, Pu;
float ScSo, Sc, So, ew, w1, w2;
const float mo = 4 * M_PI * 1e-7;

#define COLOR_BLUE_YELLOW 1

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, ""); // Включення підтримки юнікод

    // Ініціалізація ncurses (зчитування конфігурації термінала)
    WINDOW *stdscr = initscr();

    // Ініціалізація кольорового режиму і створення пари кольорів для фону і тексту
    start_color();

    init_pair(COLOR_BLUE_YELLOW, COLOR_BLACK, COLOR_WHITE);

    // Початок відображення в заданому кольоровому режимі
    attron(COLOR_PAIR(COLOR_BLUE_YELLOW));

    //COLOR_YELLOW фактично є коричневим. Для того щоб отримати жовтий, використовують COLOR_YELLOW 
    //в поєднанні з атрибутом A_BOLD.
//    attron(A_BOLD);
//	erase();
//	refresh();

bkgdset (COLOR_PAIR(COLOR_BLUE_YELLOW));
//clear();
erase();
refresh();
    
move (10, 10);

//getyx(10,10);


	curs_set(2);
	printw ("Bm=\t");
    refresh();
	scanw ("%f", &Bm);
	
	printw ("g=\t");
    refresh();
	scanw ("%f", &g);
	curs_set(0);
	Hg = Bm /mo;
	printw ("Hg=\t%8.4f\n", Hg);
	refresh();
	printw ("Le=\t");
	scanw ("%f", &Le);
	
	printw ("Hm=\t");
	scanw ("%f", &Hm);


	IW = Hg * g * 1e-3 + Hm * 1e-3 * Le;
	printw ("IW=\t%3.1f\n", IW);
	
	
	    
    printw("\n\n\nThe End!\n");

    attroff(A_BOLD);

    // Вивести текст без налаштування кольору
    attroff(COLOR_PAIR(1));
    printw("OUT\n");

    // Оновлення екрану
    refresh();

    // Очікування натиснення клавіші перед завершенням програми
    getch();

    // Відновлення початкового налаштування терміналу
    endwin();
}
// gcc main.c  !!!! -lncurses
