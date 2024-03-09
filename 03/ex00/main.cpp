#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap michael("michael");
    ClapTrap ryan("ryan");
    
    ryan.attack(michael.getName());
    michael.takeDamage(0);
    michael.attack(ryan.getName());
    ryan.takeDamage(0);
    ryan.beRepaired(10);
    return (0);
}