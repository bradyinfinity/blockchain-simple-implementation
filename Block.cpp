#include "Block.h"

Block::Block(int i, Entity &s, Entity &r, float a) :
	index(i), amount(a), senderUsername(s.getUsername()), receiverUsername(r.getUsername())
{
	timestamp = time(nullptr);
	//check if transaction is valid before adjusting balance & hashing
	if ((s.getBalance() - a) >= 0) {
		isValid = true;
		s.setBalance(-a);
		r.setBalance(a);
		Hash = generateHash();
	}
	else {
		std::cout << "transaction is invalid" << std::endl;
		isValid = false;
	}
}

std::string Block::generateHash()
{
	//string of index, sender, receiver, amount, timestamp, previous hash
	std::string toHash = std::to_string(index) + senderUsername + receiverUsername + std::to_string(amount)
		+ std::to_string(timestamp) + previousHash;

	//picosha2 library to generate sha256 hash (link: https://github.com/okdshin/PicoSHA2)
	return picosha2::hash256_hex_string(toHash);
}