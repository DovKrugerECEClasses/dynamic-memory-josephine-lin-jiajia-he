#include "Account.hh"
#include <iostream>

int main() {
	Account a1;
	a1.deposit(500);
	a1.withdraw(200);
	std::cout << a1.getBalance() << '\n';
}
