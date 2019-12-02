#include <iostream>
#include "HashTable.h"

using namespace std;

int hashCode(const string&);

int main(){
  HashTable<string, long long, 100> phoneBook(hashCode);
}
int hashCode(const string& key){
  return 10;
}
