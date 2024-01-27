#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->_name = "default";
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "FragTrap string constructor called" << std::endl;
	// this->_name = name;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}

FragTrap::FragTrap(const FragTrap &copy_src) : ClapTrap(copy_src)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = copy_src;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hit_points = rhs._hit_points;
		this->_energy_points = rhs._energy_points;
		this->_attack_damage = rhs._attack_damage;
	}
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if(this->_hit_points > 0 && this->_energy_points > 0)
	{
		this->_energy_points--;
		std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing "
		<< this->_attack_damage << " points of damage!" 
		<< " (HP: " << this->_hit_points 
		<< ", EP: " << this->_energy_points << ")" << std::endl;
	}
	else
		std::cout << "FragTrap " << this->_name << " cannot move because his hit points or energy points are running low." << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " requests a high five!" << std::endl;
}
