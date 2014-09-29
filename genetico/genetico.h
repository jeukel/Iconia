#ifndef GENETICO_H
#define GENETICO_H

#include "SimpleList/SimpleList.h"

class Genetico
{
public:
   /*!
    * \brief runs
    */
   Genetico(short Fitness);
   /*!
    * \brief start: it creates and reproduces a genetic algorythm for X generations of X subjects
    * \param Generaciones the amount of generations that the program is going to run
    * \param Densidad the amount of persons in the population. It has to be pair since two parents have to children
    */
   short start(short Generaciones, short Densidad);
private:
   short Fitness ;
   SimpleList<short>* nuevaGeneracion;
   SimpleList<short>* Poblacion;
   /*!
    * \brief conseguirFitness with the help of OpenCV gets the fitness from the original picture and assigns it to a global variable
    */
   void conseguirFitness();

   /*!
    * \brief crearIndividuo creates random short to populate a list
    * \return an new random short
    */
   short crearIndividuo();
   /*!
    * \brief crearPoblacion creates a random population of X elements
    * \param Densidad the amount of objects the population has
    */
   void crearPoblacion(short Densidad);
   /*!
    * \brief escogerPadre chooses an object based in a a random posibility that increases with a better fitness
    * \return an short with the index of the location of the parent in the list
    */
   short escogerPadre ();
   /*!
    * \brief fitnessTest substracts a number with conseguiFitness and gets the absolute value,
    *                    the lower the fitness the better it is
    * \param SubjectD the subject to be tested
    * \return the fitness value of the object
    */
   short fitnessTest (short SubjectD);
   /*!
    * \brief seleccionNatural adds the best 2 objects of a selection of 4 (two parents and two sons) to a temporal list
    * \param SubjectA father
    * \param SubjectB mather
    * \param SubjectC first son
    * \param SubjectD second son
    */
   void seleccionNatural (short SubjectA, short SubjectB, short SubjectC, short SubjectD);
   /*!
    * \brief Reproducir takes a random pair of elements (may be the same) from the population
    *        to create other 2 objects, then itgit  runs seleccionNatural to choose the best two
    * \param seed is the value of j in the for loop, it supports the random function
    * \param Densidad used with to create the upper limit of the random function
    */
   void Reproducir(int seed, short Densidad);
   /*!
    * \brief cambiarGeneraciones converts the temporal list (nuevaGeneracion), with the best objects in the main list (Poblacion)
    *
    */
   void cambiarGeneraciones ();
   /*!
    * \brief conceguirMejorIndividuo searches through the list to find the best object
    * \return the object with best fitness
    */
   short conseguirMejorIndividuo();
};

#endif // GENETICO_H
