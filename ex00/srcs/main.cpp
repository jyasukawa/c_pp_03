#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	jin("jin");
	ClapTrap	enemy1("enemy1");
	ClapTrap	enemy2;

	enemy2 = enemy1;

	jin.attack("enemy1");
	jin.beRepaired(2);
	enemy1.takeDamage(0);
	enemy1.takeDamage(132);
	enemy1.attack("jin");
	enemy1.beRepaired(2);
	enemy1.takeDamage(10);
	enemy2.attack("jin");

	return (0);
}
