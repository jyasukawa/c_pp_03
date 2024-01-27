#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("default"), _hit_points(10), _energy_points(10), _attack_damage(0) 
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "String constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy_src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy_src;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hit_points = rhs._hit_points;
		this->_energy_points = rhs._energy_points;
		this->_attack_damage = rhs._attack_damage;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if(this->_hit_points > 0 && this->_energy_points > 0)
	{
		this->_energy_points--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing "
		<< this->_attack_damage << " points of damage!" 
		<< " (HP: " << this->_hit_points 
		<< ", EP: " << this->_energy_points << ")" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " cannot move because his hit points or energy points are running low." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points == 0)
	{
		std::cout << this->_name << " is already dead." << std::endl;
	}
	else if (this->_hit_points > amount)
	{
		this->_hit_points -= amount;
		std::cout << this->_name << " took " << amount << " ponts of damage!"
		<< " (HP: " << this->_hit_points 
		<< ", EP: " << this->_energy_points << ")" << std::endl;
	}
	else
	{
		this->_hit_points = 0;
		std::cout << this->_name << " took " << amount << " ponts of damage!"
		<< ", " << this->_name << " is defeated." << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hit_points > 0 && this->_energy_points > 0)
	{
		this->_energy_points--;
		this->_hit_points += amount;
		std::cout << this->_name << " get reapaird for " << amount << " points!"
		<< " (HP: " << this->_hit_points 
		<< ", EP: " << this->_energy_points << ")" << std::endl;
	}
	else
		std::cout << this->_name << " cannot move because his hit points or energy points are running low." << std::endl;
}
//回復上限は10にするべき？