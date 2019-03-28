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

    init_pair(COLOR_BLUE_YELLOW, COLOR_YELLOW, COLOR_BLUE);

    // Початок відображення в заданому кольоровому режимі
    attron(COLOR_PAIR(COLOR_BLUE_YELLOW));

    //COLOR_YELLOW фактично є коричневим. Для того щоб отримати жовтий, використовують COLOR_YELLOW 
    //в поєднанні з атрибутом A_BOLD.
    attron(A_BOLD);

    
    
	printf ("Bm=\t");
    refresh();
	scanf ("%f", &Bm);
	
	printf ("g=\t");
    refresh();
	scanf ("%f", &g);
	
	Hg = Bm /mo;
	printf ("Hg=\t%8.4f\n", Hg);
	refresh();
	printf ("Le=\t");
	scanf ("%f", &Le);
	
	printf ("Hm=\t");
	scanf ("%f", &Hm);


	IW = Hg * g * 1e-3 + Hm * 1e-3 * Le;
	printf ("IW=\t%3.1f\n", IW);
	
	
	printf ("U1min=\t");
	scanf ("%f", &U1min);

	printf ("U_2=\t");
	scanf ("%f", &U2);
	
	Kt = U1min / (U2 * 2);
	printf ("Kt=\t%2.2f\n", Kt);
	
	printf ("I_2=\t");
	scanf ("%f", &I2);

	I2ef = I2 * sqrt(0.5);
	printf ("I2ef=\t%2.2f\n", I2ef);
	
	I1ef = I2ef / Kt;
	printf ("I1ef=\t%2.2f\n", I1ef);
	
	I1= I2/Kt;
	printf ("I1=\t%2.2f\n", I1);
	
	printf ("f=\t");
	scanf ("%f", &f);
	
	printf ("J=\t");
	scanf ("%f", &J);

	printf ("ko=\t");
	scanf ("%f", &ko);
	
	Pu = U2 * 2 * I2ef;
	printf ("Pu=\t%3.1f\n", Pu);
	
	ScSo = (100 * Pu)/(f * Bm * ko * J);
	printf ("ScSo=\t%3.3f\n", ScSo);
	
	
	printf ("Sc=\t");
	scanf ("%f", &Sc);

	printf ("So=\t");
	scanf ("%f", &So);
	
	if ((Sc * So) > ScSo) printf ("ScSo=\t%3.3f\t\tГодится\n", Sc * So); 
		else  printf ("ScSo=\t%3.3f\t\tНЕ годится\n", Sc * So);
	
	ew = 2e-4 * f * Bm * Sc; 
	printf ("ew=\t%3.1f\n", ew);
	
	w1= U1min / ew;
	w2= w1 / Kt;
	printf ("w1=\t%4.1f\nw2=\t%4.1f\n", w1, w2);
    
    printw("kekekekekekedsdfsdvsdfvsd!\n");

    attroff(A_BOLD);

    // Вивести текст без налаштування кольору
    attroff(COLOR_PAIR(1));
    printw("sdfgsdfsdfvgsfrierpiehjrij\n");

    // Оновлення екрану
    refresh();

    // Очікування натиснення клавіші перед завершенням програми
    getch();

    // Відновлення початкового налаштування терміналу
    endwin();
}
// gcc main.c  !!!! -lncurses
