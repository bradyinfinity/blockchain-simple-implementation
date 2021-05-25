#pragma once
#include <ctime>
#include "picosha2.h"
#include "Entity.h"

class Block
{
public:
	Block(int i, Entity &s, Entity &r, float a);

	std::string generateHash();
	std::string getHash() const { return Hash; };
	std::string getPreviousHash() const { return previousHash; };
	void setPreviousHash(std::string previous) { previousHash = previous; };
	void setHash() { Hash = generateHash(); };
	bool isValid;

private:
	//all sorts of private variables
	int index;
	float amount;
	std::string senderUsername;
	std::string receiverUsername;
	std::time_t timestamp;
	std::string Hash;
	std::string previousHash;
};
