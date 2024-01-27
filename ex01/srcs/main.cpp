#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap jin("jin");
	ScavTrap enemy1("enemy1");
	ScavTrap enemy2 = enemy1;
	enemy2.attack("jin");
	jin.takeDamage(500);
	jin.beRepaired(10);
	enemy1.guardGate();

	return (0);
}
