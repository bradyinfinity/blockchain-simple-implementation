#pragma once
#include <string>
#include <iostream>

class Entity
{
public:
	Entity(std::string u, float b) : username(u), balance(b) {}

	float getBalance() { return balance; }
	std::string getUsername() { return username; }
	void setBalance(float amount) {
		balance += amount;
	};
	void printBalance() { std::cout << username << "'s balance is: " << balance << std::endl; };

private:
	std::string username;
	float balance;
};
