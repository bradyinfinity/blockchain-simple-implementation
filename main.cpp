/*
	This code was created to demonstrate the basic infrastructure of blockchain technology
*/
#include "Cryptocurrency.h"

int main() //demo run
{
	//cryptos
	Cryptocurrency fakeCoin;

	//create genesis block
	Entity Genesis("genesis", 0.0f);
	Block genesisBlock(0, Genesis, Genesis, 0);
	fakeCoin.addBlock(&genesisBlock);

	//entities
	Entity Martin("martin", 12.5f);
	Entity Clara("clara", 85.03f);
	Entity Albert("albert", 2.7f);

	//blocks
	Block block1(1, Martin, Clara, 0.5f);
	fakeCoin.addBlock(&block1);
	Block block2(2, Clara, Albert, 11.5f);
	fakeCoin.addBlock(&block2);
	Block block3(3, Martin, Albert, 1.2f);
	fakeCoin.addBlock(&block3);
	Block block4(4, Clara, Martin, 100.1f);
	fakeCoin.addBlock(&block4);

	//for demo purposes only, this is obviously not a good idea for actual crypto
	fakeCoin.printChain();

	//check validity of chain
	if (fakeCoin.isChainValid())
		std::cout << "Chain is valid!" << std::endl;
	else
		std::cout << "Chain is invalid!" << std::endl;

	//tamper with blockchain and check validity again
	block3.setPreviousHash("take this!");
	if (fakeCoin.isChainValid())
		std::cout << "Chain is valid!" << std::endl;
	else
		std::cout << "Chain is invalid!" << std::endl << std::endl;

	//check balance of entities
	Martin.printBalance();
	Clara.printBalance();
	Albert.printBalance();

	return 0;
}