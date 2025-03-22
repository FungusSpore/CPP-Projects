#include <iostream>
#include <string>

class ClapTrap {
public:
    ClapTrap() { std::cout << "ClapTrap constructed\n"; }
    ~ClapTrap() { std::cout << "ClapTrap destructed\n"; }
    
    // Non-virtual function
    virtual void attack(const std::string &target) {
        std::cout << "ClapTrap attacks " << target << "\n";
    }
};

class ScavTrap : public virtual ClapTrap {
public:
    ScavTrap() { std::cout << "ScavTrap constructed\n"; }
    ~ScavTrap() { std::cout << "ScavTrap destructed\n"; }
    
    // This function hides the base class attack() function
    void attack(const std::string &target) {
        std::cout << "ScavTrap attacks " << target << " with a unique style\n";
    }
};

class FragTrap : public virtual ClapTrap {
public:
    FragTrap() { std::cout << "FragTrap constructed\n"; }
    ~FragTrap() { std::cout << "FragTrap destructed\n"; }
};

class DiamondTrap : public ScavTrap, public FragTrap{
public:
    DiamondTrap() { std::cout << "DiamondTrap constructed\n"; }
    ~DiamondTrap() { std::cout << "DiamondTrap destructed\n"; }
};

int main() {
    ClapTrap* robot = new ScavTrap();
    ClapTrap* robot2 = new ClapTrap();
    ScavTrap* robot3 = new ScavTrap();
    FragTrap* robot4 = new FragTrap();
    DiamondTrap* robot5 = new DiamondTrap();
    robot->attack("Enemy");  // Calls ClapTrap::attack due to static binding.
    robot2->attack("Enemy2");  // Calls ClapTrap::attack due to static binding.
    robot3->attack("Enemy3");  // Calls ClapTrap::attack due to static binding.
    robot4->attack("Enemy4");  // Calls ClapTrap::attack due to static binding.
    robot5->attack("Enemy5");  // Calls ClapTrap::attack due to static binding.
    delete robot;
    return 0;
}
