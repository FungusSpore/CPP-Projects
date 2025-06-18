/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 23:15:11 by jianwong          #+#    #+#             */
/*   Updated: 2025/06/18 22:34:26 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <iostream>

int main()
{
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << "\n" << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;

		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);

		while (!s.empty()){
			std::cout << s.top() << std::endl;
			s.pop();
		}
	}
	{
		std::cout << "\n" << std::endl;
		std::cout << "Test2" <<std::endl;
		MutantStack<int, std::list<int> > mlist;

		mlist.push(5);
		mlist.push(17);
		std::cout << mlist.top() << std::endl;
		mlist.pop();
		std::cout << mlist.size() << "\n" << std::endl;

		mlist.push(3);
		mlist.push(5);
		mlist.push(737);
		//[...]
		mlist.push(0);

		MutantStack<int, std::list<int> >::iterator it = mlist.begin();
		MutantStack<int, std::list<int> >::iterator ite = mlist.end();

		++it;
		--it;

		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int, std::list<int> > s(mlist);

		while (!s.empty()){
			std::cout << s.top() << std::endl;
			s.pop();
		}
	}
	{
		std::cout << "\n" << std::endl;
		std::cout << "List Test" <<std::endl;
		std::list<int> mlist;

		mlist.push_back(5);
		mlist.push_back(17);
		std::cout << mlist.back() << std::endl;
		mlist.pop_back();
		std::cout << mlist.size() << "\n" << std::endl;

		mlist.push_back(3);
		mlist.push_back(5);
		mlist.push_back(737);
		//[...]
		mlist.push_back(0);

		std::list<int>::iterator it = mlist.begin();
		std::list<int>::iterator ite = mlist.end();

		++it;
		--it;

		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int, std::list<int> > s(mlist);

		while (!s.empty()){
			std::cout << s.top() << std::endl;
			s.pop();
		}
	}
}
