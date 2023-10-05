#include "Account.hpp"
void	Account::_displayTimestamp( void )
{
	std::
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	std::cout << "index:" << _accountIndex << ";amount" << initial_deposit << "created" << std::endl;
	_nbAccounts++;
	makeDeposit(inital_deposit);
}

Account::~Account(void)
{
	
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	this->_nbDeposits++;
	this->_totalNbDeposists++;
	std::cout << "index:" << _accountIndex << ";p_amount" << _amount << ";deposit:" << deposit;
	_amount += deposit;
	std::cout << ";amount:" << _amount << ";nb_deposits" << _nbDeposits << std::endl;
	_totalAmount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	if (withdrawl > _amount)
	{
		std::cout << "refused";
		return (false);
	}
	this->_nbWithdrawals++;
	this->_totalNbWithdrawals++;
	_amount -= withdrawal;
	std::cout << withdrawal << ";amount" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
}

int		checkAmount( void ) const;
void	displayStatus( void ) const;

