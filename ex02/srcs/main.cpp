#include "FragTrap.hpp"

int	main(void)
{
	FragTrap jin("jin");
	FragTrap enemy1("enemy1");
	FragTrap enemy2 = enemy1;
	enemy2.attack("jin");
	jin.takeDamage(500);
	jin.beRepaired(10);
	enemy1.highFivesGuys();

	return (0);
}
