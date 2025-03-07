/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:09:42 by jianwong          #+#    #+#             */
/*   Updated: 2025/03/08 00:58:49 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"


int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ){
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}

Account::~Account(){
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}

void	Account::displayAccountsInfos( void ){
	_displayTimestamp();
	std::cout << "account:" << _nbAccounts << ";total:" << _totalAmount << ";deposit:" << \
		_totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << "\n";
}

void	Account::makeDeposit( int deposit ){
	_displayTimestamp();
	_totalNbDeposits++;
	_nbDeposits++;
	_totalAmount += deposit;
	_amount += deposit;
	std::cout << "index:" << _accountIndex << ";p_amount:" <<	_amount - deposit << ";deposit:" \
		<< deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << "\n";
}

bool	Account::makeWithdrawal( int withdrawal ){
	_displayTimestamp();
	if (withdrawal > _amount)
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused\n";
	else
	{
		_totalAmount -=withdrawal;
		_amount -= withdrawal;
		_totalNbWithdrawals++;
		_nbWithdrawals++;
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount + withdrawal << ";withdrawal:" \
			<< withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << "\n";
		return (true);
	}
	return (false);
}

int		Account::checkAmount( void ) const{
	return (_amount);
}

void	Account::displayStatus( void ) const{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" <<	_amount << ";deposit:" << _nbDeposits << \
		";withdrawals:" << _nbWithdrawals << "\n";
}

void	Account::_displayTimestamp( void ){
	time_t now = time(0);
	tm *ltm = localtime(&now);
	char buffer[100];

	strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", ltm);
	std::cout << "[" << buffer << "] "; }
