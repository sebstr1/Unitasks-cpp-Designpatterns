/* 2018-03-14
* Namn: Sebastian Strindlund
*/

#include <iostream>
#include <exception>
#include <stdexcept>
#include <sstream>
using namespace std;

class NoBakingException : public exception
{
    public:
        virtual const char *what() const throw()
        {
            return "No recepies exists";
        }
};