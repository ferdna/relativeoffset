
// to compile:
// g++ get_relative_offset.cpp -o get_relative_offset -std=c++11
//
// To enable C++11 support with g++ or clang, you need to pass the
// option -std=c++0x. You can also use -std=c++11 on the newer versions
// of those compilers.
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm> 

template <typename T,unsigned S>
inline unsigned arraysize(const T (&v)[S]) { return S; }

template <typename T>
void remove_duplicates(std::vector<T>& vec)
{
  std::sort(vec.begin(), vec.end());
  vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
}

//Standard namespace declaration
using namespace std;

int main(int argc, char* argv[])
{
  string VERSION = "0.99";
  string offsetOrig = "0x00000000"; // offset Origin.
  string offsetDest = "0xFFFFFFFF"; // offset Destination.
  string hexPrefix = "0x";
  string hexActual = offsetOrig.erase(0,2);
  //bool returnBool = false;

  for (int i = 0; i < argc; i++)
  {
    //cout << "index: " << i << " argc: " << argc << ".\n";
    string tmpStr = argv[i];
    if (!(tmpStr == "-?" || tmpStr == "-h" || tmpStr == "-v" || tmpStr == "--help" || tmpStr == "--usage") && argc <= 2)
    {
      cout << "Relative Offset Calculator version: " << VERSION << endl << "==============\n" 
           << "Default Prefix " << hexPrefix << endl << "==============\n" 
           << " -o offset Origin. ex. 0x00400eb3 \n"
           << " -d Destination.\n"
           << " -hex HEX prefix. default: 0x\n";
           //returnBool = false;
	   return 0;
    }
    
    if (tmpStr == "-o")
    {
      //cout << "origin: " << argv[i + 1] << ".\n";
      offsetOrig = argv[i + 1];
      hexActual = offsetOrig; //offsetOrig.erase(0,2);
    }
    if (tmpStr == "-d")
    {
      //cout << "dest: " << argv[i + 1] << ".\n";
      offsetDest = argv[i + 1];
    }
    if (tmpStr == "-hex")
    {
      //cout << "prefix: " << argv[i + 1] << ".\n";
      hexPrefix = argv[i + 1];
    }
  }

  const int hexNum1[10] = {0,1,2,3,4,5,6,7,8,9};
  const char hexLet1[6] = {'a','b','c','d','e','f'};
  
  vector<string> strPossibilities;
  
  for (int n = 0; n < arraysize(hexNum1); n++)
  {
    for (int l = 0; l < arraysize(hexLet1); l++)
      //cout << hexPrefix << hexNum1[n] << hexLet1[l] << "\n";
      strPossibilities.push_back(hexPrefix + to_string(hexNum1[n]) + hexLet1[l]);
  }
  
  for (int l = 0; l < arraysize(hexLet1); l++)
  {
    for (int n = 0; n < arraysize(hexNum1); n++)
      //cout << hexPrefix << hexLet1[l] << hexNum1[n] << "\n";
      strPossibilities.push_back(hexPrefix + hexLet1[l] + to_string(hexNum1[n]));
  }
  
  for (int l = 0; l < arraysize(hexLet1); l++)
  {
      //cout << hexPrefix << hexLet1[l] << hexLet1[l] << "\n";
      strPossibilities.push_back(hexPrefix + hexLet1[l] + hexLet1[l]);
  }
  
  for (int n = 0; n < arraysize(hexNum1); n++)
  {
      //cout << hexPrefix << hexNum1[n] << hexNum1[n] << "\n";
      strPossibilities.push_back(hexPrefix + to_string(hexNum1[n]) + to_string(hexNum1[n]));
  }
  
  for (int l1 = 0; l1 < arraysize(hexLet1); l1++)
  {
    for (int l2 = 0; l2 < arraysize(hexLet1); l2++)
      //cout << hexPrefix << hexLet1[l1] << hexLet1[l2] << "\n";
      strPossibilities.push_back(hexPrefix + hexLet1[l1] + hexLet1[l2]);
  }
  for (int l1 = 0; l1 < arraysize(hexLet1); l1++)
  {
    for (int l2 = 0; l2 < arraysize(hexLet1); l2++)
      //cout << hexPrefix << hexLet1[l2] << hexLet1[l1] << "\n";
      strPossibilities.push_back(hexPrefix + hexLet1[l2] + hexLet1[l1]);
  }
  
  for (int n1 = 0; n1 < arraysize(hexNum1); n1++)
  {
    for (int n2 = 0; n2 < arraysize(hexNum1); n2++)
      //cout << hexPrefix << hexNum1[n1] << hexNum1[n2] << "\n";
      strPossibilities.push_back(hexPrefix + to_string(hexNum1[n1]) + to_string(hexNum1[n2]));
  }
  
  for (int n1 = 0; n1 < arraysize(hexNum1); n1++)
  {
    for (int n2 = 0; n2 < arraysize(hexNum1); n2++)
      //cout << hexPrefix << hexNum1[n2] << hexNum1[n1] << "\n";
      strPossibilities.push_back(hexPrefix + to_string(hexNum1[n2]) + to_string(hexNum1[n1]));
  }
  
  remove_duplicates(strPossibilities);
  
  // TODO
  // 
  // 
 
  return 0;
}