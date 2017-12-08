#include <string>
#include <utility>
#include <vector>
using namespace std;

using Regist = vector<string>;

class CNode {
public:
  Regist data;
  CNode *childs[2];

  CNode() {
    data = Regist(0);
    childs[0] = childs[1] = nullptr;
  }

  CNode(const Regist &data) {
    this->data = data;
    childs[0] = childs[1] = nullptr;
  }
  
  ~CNode(){};
};
