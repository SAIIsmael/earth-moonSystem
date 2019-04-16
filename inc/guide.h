#include <ncurses.h>
#include <cstdlib>
#include <cstring>

int startx = 0;
int starty = 0;

void display_guide_shell()
{
    startx = (80 - COLS) / 2;
    starty = (24 - LINES) / 2;

    WINDOW *win = newwin(LINES - 1, COLS - 1, starty, startx);
    char titre[] = "Ce programme va simuler l'intéraction entre la Terre et la Lune de manière réaliste.\n Appuuyé sur la touche entrée pour lancer le programme.";
    int taille = strlen(titre), ch;

    initscr();

    box(win, ACS_VLINE, ACS_HLINE);
    raw();
    keypad(win, TRUE);
    noecho();
    cbreak();

    // while(1) {
    // clear();


    // boite = subwin(stdscr, 35, 60, LINES - LINES + 2, COLS / 2 - COLS / 4);
    // box(boite, ACS_VLINE, ACS_HLINE);

    start_color();
    init_pair(4, COLOR_BLUE, COLOR_BLACK);

    attron(A_UNDERLINE | A_BOLD | COLOR_PAIR(4));
    mvprintw(LINES - LINES + 1, (COLS / 2) - (taille / 2), titre);
    attroff(A_UNDERLINE | A_BOLD | COLOR_PAIR(4));

    whline(win, ACS_HLINE, 3);

    wprintw(win, "\nVous pouvez modifier certaines caractéristiques du système grâce aux touches suivantes: \n\n");
    wprintw(win, "    F1 : Diminuer la vitesse de la Lune\n");
    wprintw(win, "    F2 : Augmenter la vitesse de la Lune\n");
    wprintw(win, "    F3 : Diminuer la masse de la Terre\n");
    wprintw(win, "    F4 : Augmenter la masse de la Terre\n");
    wprintw(win, "    F5 : Diminuer la masse de la Lune\n");
    wprintw(win, "    F6 : Augmenter la masse de la Lune\n");

    wprintw(win, "\nVoici d'autres fonctionnalités disponibles: \n\n");
    wprintw(win, "    n : Réinitialiser le système\n");
    wprintw(win, "    s : Entrer dans/Quitter le mode schéma\n");

    wprintw(win, "\nLes touches directionnelles vous permettent de vous déplacer.\n\n");

    attron(A_BOLD);
    wprintw(win, "AUTEURS :\n\n");
    attroff(A_BOLD);
    wprintw(win, "    BARRY Mamadou Djoulde\n    DEDEBANT Louis\n    DIABATE Amara\n    QUENETTE Christophe\n    SAI Ismaël\n");
    // }
    refresh();
    wrefresh(win);
    getch();			/* Wait for user input */

    endwin();
}
