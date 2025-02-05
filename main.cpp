#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

pair<int, int> parsePair(const string &s){

  int commaPos = s.find(',');
  int child = stoi(s.substr(1, commaPos - 1));
  int parent = stoi(s.substr(commaPos + 1, s.size() - commaPos - 2));

  return {child, parent};
}
string TreeConstructor(string strArr[], int arrLength) {
  
  unordered_map<int, int> child_count;
  unordered_map<int, int> parent_count;

  for(int i = 0; i < arrLength; i++){
    auto [child, parent] = parsePair(strArr[i]);

    child_count[child]++;
    if(child_count[child] > 1){
      return "false";
    }

    parent_count[parent]++;
    
    if(parent_count[parent] > 2){
      return "false";
    }

    if(child_count.find(parent) == child_count.end()){
      child_count[parent] = 0;
    }

    if(child_count.find(child) == parent_count.end()){
      parent_count[child] = 0;
    }
  }

  int root_count = 0;
  for (auto &entry : child_count){
    if(entry.second == 0){
      root_count++;

      if(root_count > 1){
        return "false";
      }
    }
  }

  if(root_count == 0){
    return "false";
  }

  return "true";
}

// keep this function call here
int main(void) { 
   
  string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << TreeConstructor(A, arrLength);
  return 0;
    
}
