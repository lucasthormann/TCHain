#include "Blockchain.h"

Blockchain::Blockchain() { // Blockchain constructor
  _vChain.emplace_back(Block(0, "Genisis Block")); // emplace genisis block onto vector chain
  _nDifficulty = 6; // default network difficulty
}

void Blockchain::AddBlock(Block bNew) {
  bNew.sPrevHash = _GetLastBlock().getHash(); // set previous hash variable for new block to hash of last block
  bNew.MineBlock(_nDifficulty); // block is mined
  _vChain.push_back(bNew); // block is added to vector chain
}

Block Blockchain::_GetLastBlock() const {
  return _vChain.back(); // return last block in VChain vector using the vector::back method
}
