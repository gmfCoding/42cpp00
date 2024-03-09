#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
    ClapTrap michael("michael");
    ClapTrap ryan("ryan");
    
    ryan.attack(michael.getName());
    for (size_t i = 0; i < 11; i++)
    {
        michael.attack(ryan.getName());
        ryan.takeDamage(2);
    }
    ryan.attack(michael.getName());
    ryan.beRepaired(10);
    return (0);
}