#include "Cryptocurrency.h"

Cryptocurrency::Cryptocurrency()
{
}

void Cryptocurrency::addBlock(Block *toAdd)
{	
	if (toAdd->isValid) {

		//add pointer to vector
		chain.push_back(toAdd);

		//Set previous hash "NULL" for genesis block
		if (chain.size() == 1) {
			chain[0]->setPreviousHash("NULL");
		}
		//Set Previous Hash of all other blocks
		else {
			chain[chain.size() - 1]->setPreviousHash(chain[chain.size() - 2]->getHash());
		}
		//Set Hash of current block
		chain[chain.size() - 1]->setHash();
	}
	else
		std::cout << "block could not be added because it is invalid" << std::endl << std::endl;

}

void Cryptocurrency::printChain()
{
	for (size_t i = 0; i < chain.size(); i++) {
		std::cout << "Block: "; std::cout << i << std::endl;;
		std::cout << "Hash: " << chain[i]->getHash() << std::endl;
		std::cout << "Previous Hash: " << chain[i]->getPreviousHash() << std::endl << std::endl;
	}
}

bool Cryptocurrency::isChainValid()
{
	for (size_t i = 1; i < chain.size(); i++) {
		Block currentBlock = *chain[i];
		Block previousBlock = *chain[i - 1];

		//checks if generated hash is same as stored hash
		if (currentBlock.generateHash() != currentBlock.getHash()) {
			return false;
		}
		//checks if previous hash is same as previous hash stored in current block
		if (currentBlock.getPreviousHash() != previousBlock.generateHash())
			return false;
	}
	return true;
}
