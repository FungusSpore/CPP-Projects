/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 18:24:39 by jianwong          #+#    #+#             */
/*   Updated: 2025/06/08 22:55:09 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

class Person {
private:
    std::string name;
    int age;

public:
    Person(std::string n, int a) : name(n), age(a) {}

    std::string getName() const { return name; }
    int getAge() const { return age; }
		
		void	setName(std::string new_name){ name = new_name; }
		void	setAge(int new_age){ age = new_age; }
};

void	stringAppend(std::string& str){
	std::cout << "Before: " << str << std::endl;
	str.append("_test");
	std::cout << "After: " << str << std::endl;
}

void	classMod(Person& current){
	std::cout << "Before: " << current.getName() << " aged: " << current.getAge() << std::endl;
	current.setName(current.getName().append("_test"));
	current.setAge(current.getAge() + 1);
	std::cout << "After: " << current.getName() << " aged: " << current.getAge() << std::endl;
}

int main(void){
    int intArr[4] = {10, 25, 42, 7};

    double doubleArr[3] = {3.14, 2.71, 1.62};

    char charArr[3] = {'a', 'b', 'c'};

    std::string strArr[2] = {"apple", "banana"};

    Person personArr[2] = {
        Person("Alice", 30),
        Person("Bob", 45)
    };
		std::cout << "\nInt arr" << std::endl;
		::iter(intArr, 4, valuePlus<int>);
		std::cout << "\ndouble arr" << std::endl;
		::iter(doubleArr, 3, valuePlus<double>);
		std::cout << "\nchar arr" << std::endl;
		::iter(charArr, 3, valuePlus<char>);
		std::cout << "\nstr arr" << std::endl;
		::iter(strArr, 2, stringAppend);
		std::cout << "\nclass arr" << std::endl;
		::iter(personArr, 2, classMod);
}
