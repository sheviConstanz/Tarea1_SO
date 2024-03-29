//compilar en terminal con g++ main.cpp caballo.cpp  -o main -lncurses
#include <ncurses.h>
#include <cstdlib>
#include "caballo.hpp"
#include <vector>

using namespace std;
int main(int argc, char const *argv[]) {
    initscr();

    printw("Ingrese nuemro de caballos (1-20): ");
    int cantidad_caballos = 1;
    scanw("%d", &cantidad_caballos);
    getch();
    clear();

    vector <Caballo> Lista_caballos;

    for (int i = 0; i < cantidad_caballos; i++)
    {
        Caballo caballo;
        Lista_caballos.push_back(caballo);
    }

    bool ganador=false;
    int caballoGanador=0;
    while (true)
    {
        for (int i = 0; i < cantidad_caballos; i++)
        {
            Lista_caballos[i].MoverCaballo();
            mvprintw(20+i, 0, "caballo %i", i+1);
            mvprintw(20+i, Lista_caballos[i].getPosicion()+10, "c");
            //printw("caballo %d: %d   ganador: %d\n", i, Lista_caballos[i].getPosicion(), Lista_caballos[i].verificarGanador());
            if (Lista_caballos[i].verificarGanador()){
                caballoGanador=i;
                ganador=true;
                break;
            }
        }
        if (ganador == true)
        {
            break;
        }
        getch();
        clear();
    }
    clear();
    mvprintw(20, 80, "el caballo ganador es %i", caballoGanador+1);
    getch();
    endwin();

    return 0;
}
