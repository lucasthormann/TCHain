#include <cstdint>
#include <iostream>

using namespace std;

class Block {
  public:
    string sPrevHash; //Each block is linked to the previous block
    
    Block(uint32_t nIndexIn, const string &sDataIn); // Const keyword and reference modifier used so that parameters are passed by reference but cannot be changed (improves efficiency and saves mem)

    string getHash();

    void MineBlock(uint32_t nDifficulty);

  private:
    uint32_t _nIndex;
    int64_t _nNonce;
    string sData;
    string _sHash;
    time_t _tTime;


    string _CalculateHash() const; // const ensures the method cannot change any of the variables in the Block class
};
