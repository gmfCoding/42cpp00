#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void scavTrapTest()
{
    ScavTrap rose("rose");
    ClapTrap mark("mark");
    
    mark.attack(rose.getName());
    for (size_t i = 0; i < 3; i++)
    {
        rose.attack(mark.getName());
        mark.takeDamage(rose.getDamage());
    }
    mark.attack(rose.getName());
    mark.beRepaired(10);
    rose.guardGate();
}

int main(void)
{
    scavTrapTest();
    return (0);
}