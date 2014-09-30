#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <string>

/*!
 * \brief The constants class will let us accesss to values that must not change.
 */
class constants
{
public:
    /*!
     * \brief Several constants used on the proyect.
     */
    //static String JSON_PATH = "";
    constants();
    short Generations;
    short Density;
    std::string* path00;
    std::string* path01;
};

#endif // CONSTANTS_H
