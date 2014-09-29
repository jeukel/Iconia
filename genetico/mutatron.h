#ifndef MUTATRON_H
#define MUTATRON_H

class Mutatron
{
public:
    /*!
     * \brief Mutatron takes an unsigned short and using bit logic changes the value of a random bit
     * \param Individuo it's the same unsigned short with one bit with opposite value
     */
    Mutatron();
    /*!
     * \brief mutar takes the mutegen from crearMutageno and Individuo and uses the binary function XOR
     *              to modify Individuo
     * \param Individuo the unsigned short to be changed
     * \param Mutageno the unsigned short to cause the modification
     * \return Individuo the altered Individuo
     */
    unsigned short mutar (unsigned short Individuo);
private:
    /*!
     * \brief printBits it's used for debugging, prints bit by bit the unsigned short it receives in the console
     *
     * \param Cromo the unsigned short to be printed bit by bit
     */
    void printBits (unsigned short num);
    /*!
     * \brief crearMutageno creates an unsigned short with all it's bits, except 1 are on cero.
     *                      The one's position is created randomly
     * \return Mutante it's the unsigned created
     */
    unsigned short crearMutageno ();
};

#endif // MUTATRON_H
