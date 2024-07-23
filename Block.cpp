#include "Block.h"
#include "sha256.h"

Block::Block(uint32_t nIndexIn, const string &sDataIn) : _nIndex(nIndexIn), sData(sDataIn) { // block constructor copies parameter value into variables 
  _nNonce = -1;
  _tTime = time(nullptr); // set to current time
}

string Block::getHash() { // accessor for the blocks hash
  return _sHash;
}

void Block::MineBlock(uint32_t nDifficulty) { // pass difficulty determined by the network
  char cstr[nDifficulty + 1]; // create array of characters with a length one greater than the value of the difficulty specified by the network
  for (uint32_t i = 0; i < nDifficulty; ++i) { // fill array with zeros 
    cstr[i] = '0';
  }
  cstr[nDifficulty] = '\0'; // final array given the string terminator character

  string str(cstr); // character array converted to standard string

  do {
    _nNonce++; // if the hash is not valid increment nonce
    _sHash =_CalculateHash(); // calculate hash using sha256 algo
    cout << "PoW: " << _nNonce << endl << endl;
  } while (_sHash.substr(0, nDifficulty) != str); // compare leading zeros of hash to string of zeros

  cout << "Block mined: " << _sHash << endl; // message sent to output buffer to say block mined

}

inline string Block::_CalculateHash() const { /* inline keyword makes code more efficient as the compiler places 
                                                 the method's instructions inline wherever the method is called 
                                                 (cuts down on seperate method call stringstream ss; */
  stringstream ss;
  ss << _nIndex << _tTime << sData << _nNonce << sPrevHash; // create string stream and append values

  return sha256(ss.str()); // return output of sha256 method using the string output from the string stream

}
