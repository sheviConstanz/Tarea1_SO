#include "caballo.hpp"
#include <cstdlib>
#include <ncurses.h>
Caballo::Caballo(){
    this -> posicionCaballo = 0; // posición inicial del caballo = 0
} 

void Caballo::MoverCaballo(){
    int prob = rand()%10+1; //se genera la probabilidad de movimiento entre 1 y 10
    if (prob > 5)
    {
        this -> posicionCaballo++;
    }
    else if (prob > 9)
    {
        this -> posicionCaballo= this->posicionCaballo+2;
    }
    else if(prob <9)
    {
        this -> posicionCaballo= this->posicionCaballo+3;
    }
    //printw("caballo se mueve ")
}

void Caballo::setPosicion(int posicion) {
    this -> posicionCaballo = posicion;
}

int Caballo::getPosicion() {
    return this -> posicionCaballo;
}

bool Caballo::verificarGanador(){
    if (this -> posicionCaballo >= 150)
    {
        return true;
    }
    else
    {
        return false;
    }
}
Caballo::~Caballo(){
    posicionCaballo=0;
}
