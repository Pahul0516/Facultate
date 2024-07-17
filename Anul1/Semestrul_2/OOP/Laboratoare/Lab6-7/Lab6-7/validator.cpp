#include "validator.h"
#include <stdexcept>
#include <sstream>

void verificare_date(string titlul, string descrierea, string tipul, string durata)
{
    if (titlul.empty())
        throw std::runtime_error("Nu ai introdus niciun titlu");
    if (descrierea.empty())
        throw std::runtime_error("Nu ai introdus niciun titlu");
    if (tipul.empty())
        throw std::runtime_error("Nu ai introdus niciun titlu");

    int durataInt;
    std::istringstream iss(durata);
    if (!(iss >> durataInt) || iss.peek() != EOF)
        throw std::runtime_error("Durata trebuie sa fie un numar intreg");

    if (durataInt <= 0)
        throw std::runtime_error("Durata trebuie sa fie un numar intreg pozitiv");
}