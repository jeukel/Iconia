#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "genetico/mutatron.h"
using namespace std;

Mutatron::Mutatron(){

}

/*   Muestra los cromosomas booleanos del elemento dado,
 * se utiliza principalmente para depurar individualmente
 *
 *
 */
void Mutatron::printBits(unsigned short num)
{
   for(unsigned short bit=0;bit<(sizeof(unsigned short) * 8); bit++)
   {
      printf("%i ", num & 0x01);
      num = num >> 1;
   }
   cout << endl;
}

/*   Crea un mutageno a partir de un numero aleatorio que indica la posicion de este
 * el mutageno es un vector de bits con un único elemento en 1 (los demás están en cero)
 *
 * return vector de bits; el mutageno
 */
unsigned short Mutatron::crearMutageno() {

    srand (static_cast <unsigned> (time(0)));
    short RandomGen = static_cast <short> (rand()) / (static_cast <short> (RAND_MAX/32));

    unsigned short Vial = 0;
    Vial = ~Vial;
    Vial=Vial>>31;
    Vial=Vial<<RandomGen;

    return Vial;
}

/*   Esta función maneja la mutacion del individuo que toma como argumento.
 *  siempre devuelve al Individuo con un bit diferente, en forma de  short*
 *   Utiliza la funcion XOR para unir los vectores de bits de esta forma
 *
 */
unsigned short Mutatron::mutar (unsigned short Individuo) {
    unsigned short Mutageno = crearMutageno();
    Individuo =  Individuo^Mutageno;
    return Individuo;
}
