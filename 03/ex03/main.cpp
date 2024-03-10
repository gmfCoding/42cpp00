#include <iostream>

#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

void fragTrapTest()
{
    DiamondTrap lofty("lofty");
    FragTrap icecream("icecream");
    
    icecream.attack(lofty.getName());
    for (size_t i = 0; i < 3; i++)
    {
        lofty.attack(icecream.getName());
        icecream.takeDamage(lofty.getDamage());
    }
    icecream.attack(lofty.getName());
    icecream.beRepaired(10);
    lofty.guardGate();
    icecream.highFivesGuys();

    lofty.takeDamage(1000);
    lofty.guardGate();
    icecream.takeDamage(1000);
    icecream.highFivesGuys();
    lofty.whoAmI();
}

int main(void)
{
    fragTrapTest();
    return (0);
}