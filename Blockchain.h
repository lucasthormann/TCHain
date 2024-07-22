#define TESTCHAIN_BLOCKCHAIN_H

#include <cstdint>
#include <vector>
#include "Block.h"

using namespace std; // shortcut to the standard namespace in C++

class Blockchain {
public:
  Blockchain();

  void AddBlock(Block bNew);

private:
  uint32_t _nDifficulty;
  vector<Block> _vChain; // vector of Block objs

  Block _GetLastBlock() const; // const ensures output of method cannot be changed
};

#endif
