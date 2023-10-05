#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <cstdio>

using std::cout;

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

void	Account::_displayTimestamp( void )
{
    std::time_t rawtime;
    std::tm* timeinfo;
    char buffer [20];

    std::time(&rawtime);
    timeinfo = std::localtime(&rawtime);

    std::strftime(buffer,80,"%Y%m%d_%H%M%S",timeinfo);
    cout << "[" << buffer << "] ";
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	cout << "accounts:"; << _nbAccounts;
	cout << ";total:" << _totalAmount;
	cout << ";deposits:" << _totalNbDeposits;
	cout << ";withdrawals:" << _totalNbWithdrawals;
	cout << std::endl;
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	cout << "index:" << _accountIndex;
	cout << ";amount:" << _amount;
	cout << ";created";
	cout << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	cout << "index:" << _accountIndex;
	cout << ";amount:" << _amount;
	cout << ";closed";
	cout << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	cout << "index:" << _accountIndex;
	cout << ";p_amount:" << _amount;
	cout << ";deposit:" << deposit;
	
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	
	cout << ";amount:" << _amount;
	cout << ";nb_deposits:" << _nbDeposits;
	cout << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	cout << "index:" << _accountIndex;
	cout << ";p_amount:" << _amount;
	cout << ";withdrawal:";
	if (withdrawal > _amount)
	{
		cout << "refused" << std::endl;
		return (false);
	}
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	
	cout << withdrawal;
	cout << ";amount:" << _amount;
	cout << ";nb_withdrawals:" << _nbWithdrawals;
	cout << std::endl;
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	coit << "index:" << _accountIndex;
	cout << ";amount:" << _amount;
	cout << ";deposits:" << _nbDeposits;
	cout << ";withdrawals:" << _nbWithdrawals;
	cout << std::endl;
}
