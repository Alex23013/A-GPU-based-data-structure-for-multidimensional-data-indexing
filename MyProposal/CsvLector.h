#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

using Regist = vector<string>;

inline vector<string> splitStr(const string &str, const char delim) {
  // Splits a string, using delim as the delimiter and return
  // a vector with the result.
  vector<string> res;
  size_t fnd = str.find_first_of(delim);
  size_t pos = 0;
  while (fnd != string::npos) {
    res.emplace_back(str, pos, fnd - pos);
    pos = fnd + 1;
    fnd = str.find_first_of(delim, fnd + 1);
  }
  res.emplace_back(str, pos, fnd - pos);
  return res;
}

inline vector<string> splitStr(const string &str, const char delim,
                               const size_t itemsQtty) {
  // Same as splitStr, but extract a certain number of items
  // or all the items if you know their quantity.
  // More efficient than splitStr if you know the item quantity.
  vector<string> res(itemsQtty);
  size_t fnd = str.find_first_of(delim);
  size_t pos = 0;
  size_t i = 0;
  while (fnd != string::npos and i < itemsQtty) {
    res[i] = string(str, pos, fnd - pos);
    pos = fnd + 1;
    fnd = str.find_first_of(delim, fnd + 1);
    i++;
  }
  res[i] = string(str, pos, fnd - pos);
  return res;
}
inline size_t countSplits(const string &str, const char delim) {
  // Count the items(splits) in a string.
  size_t cnt = count(str.begin(), str.end(), delim);
  if (!str.empty())
    cnt++;
  return cnt;
}

inline size_t countFileLines(istream &file) {
  size_t cnt = count(istreambuf_iterator<char>(file), {}, '\n');
  file.seekg(ios_base::beg);
  return cnt;
}


inline vector<Regist> readCSV(istream &file, const bool hasHeader) {
  char delim = ',';
  string line;
  size_t numLines = countFileLines(file);
  cout<<"numLines "<< numLines<<endl;
  size_t numSplits;
  size_t i;
  vector<Regist> registers;
  getline(file, line);
  Regist tmp = splitStr(line, delim);
  numSplits = tmp.size();
  registers = vector<Regist>(numLines, Regist());
  registers[0] = move(tmp);
  i = 1;
  
  for (; i < numLines; i++) {
    getline(file, line);
    registers[i] = splitStr(line, delim, numSplits);
  }
  return registers;
}

inline int comparePoints(const Regist &a, const Regist &b, const size_t dim) {
    //If a < b -> returns negative, if a >b returns positive, else returns 0.
    std::string::size_type sz; 
    float ad = std::stof (a[dim],&sz);
    float bd = std::stof (b[dim],&sz);
    //cout<<endl<<ad<<" - "<<bd<<endl;
    if(ad < bd){
        return -1;
    }else if(ad > bd){
        return 1;
    }else{
        return 0;
    }
}

