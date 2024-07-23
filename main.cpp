#include "Blockchain.h"

int main() {
  Blockchain bChain = Blockchain(); // creates a new blockchain

  cout << "Mining block 1..." << endl;
  bChain.AddBlock(Block(1, "Block 1 Data")); // Creates new block and adds it to the chain

  cout << "Mining block 2..." << endl;
  bChain.AddBlock(Block(2, "Block 2 Data"));

  cout << "Mining block 3..." << endl;
  bChain.AddBlock(Block(3, "Block 3 Data"));

  return 0;
}
