#include <ncursesw/ncurses.h>

//#include <ncursesw/cursesw.h>
#include <locale.h>
#include <math.h>


float Bm, g, Hg, U1min, U2, Kt, I1, I1ef, I2, I2ef, Le, Hm, IW, f, J, ko, Pu;
float ScSo, Sc, So, ew, w1, w2;
const float mo = 4 * M_PI * 1e-7;

int mx, my, x, y, s;

#define COLOR_BLUE_YELLOW 1

int main(int argc, char *argv[])
{


//    printw("y=%d  x=%d", my, mx);

    setlocale(LC_ALL, "uk_UA.utf8"); // Включення підтримки юнікод
//
//    // Ініціалізація ncurses (зчитування конфігурації термінала)
    WINDOW *stdscr = initscr();
    getmaxyx(stdscr, my, mx);
//    // Ініціалізація кольорового режиму і створення пари кольорів для фону і тексту
    start_color();
    
    init_pair(COLOR_BLUE_YELLOW, COLOR_BLACK, COLOR_WHITE);

//    // Початок відображення в заданому кольоровому режимі
    attron(COLOR_PAIR(COLOR_BLUE_YELLOW));

//    //COLOR_YELLOW фактично є коричневим. Для того щоб отримати жовтий, використовують COLOR_YELLOW 
//    //в поєднанні з атрибутом A_BOLD.
//    attron(A_BOLD);
//	erase();
//	refresh();



bkgdset (COLOR_PAIR(COLOR_BLUE_YELLOW));
clear();
y=0;
for (x=1; x < (mx-1); x++)
{
y++;
//mvaddwstr(1,x,y);

move (0,x);
echochar('*');
//printw ("%s",'*');
move (my-1,x);
//printw ("%s",'*');
//move (3,x);
echochar('*');
}
for (x=0; x < (my); x++)
{
y++;
//mvaddwstr(1,x,y);

move (x,0);
echochar('*');
//printw ("%s",'*');
move (x,mx-1);
//printw ("%s",'*');
//move (3,x);
echochar('*');
}

move (2,2);
printw ("y=%d x=%d", my, mx);
//erase();
refresh();
    
move (10, 20);

//getyx(10,10);


	curs_set(2);
	printw ("Bm=\t");
//    refresh();
	scanw ("%f", &Bm);
	move (11,20);
	printw ("g=\t");
//    refresh();
	scanw ("%f", &g);
//	curs_set(0);
	Hg = Bm /mo;
	move (11,30);
	printw ("Hg=\t%8.4f", Hg);
	refresh();
	move (12,20);
	printw ("Le=\t");
	scanw ("%f", &Le);
	move (13,20);
	printw ("Hm=\t");
	scanw ("%f", &Hm);

	move (15,25);
	IW = Hg * g * 1e-3 + Hm * 1e-3 * Le;
	printw ("IW=\t%3.1f", IW);
	
	
	move (18,25);    
    printw("The End!");

//    attroff(A_BOLD);

    // Вивести текст без налаштування кольору
    attroff(COLOR_PAIR(1));

move (20,27);
    printw("OUT");

    // Оновлення екрану
    refresh();

    // Очікування натиснення клавіші перед завершенням програми
    getch();

    // Відновлення початкового налаштування терміналу
    endwin();
}
// gcc main.c  !!!! -lncurses
