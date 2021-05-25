#pragma once
#include "Block.h"

class Cryptocurrency
{
public:
	Cryptocurrency();
	void addBlock(Block *toAdd);
	void printChain();
	bool isChainValid();

private:
	//vector of pointers to actual blocks
	std::vector<Block*> chain;
};

