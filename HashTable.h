//Programmer Name: Thomas Molnar-Brock, Josh, Justin Goodman, Kyle
//Programmer ID: 1744869
//Assignment Name: Final Project
#ifndef HashTable_h
#define HashTable_h
#include <queue>
#include <list>

template <typename K, typename V, int CAP>
class HashTable{
  struct Node{
    K key;
    V value;
  };
  std::list<Node> data[CAP]; //chaining
  int(*hashCode)(const K&); //ptr to hashCode function
  int siz;
  int n_siz;
  
public:
  HashTable(int(*)(const K&));
  ~HashTable(); //Destructor
  double loadFactor() const {return double(siz)/CAP;}
  double node_loadFactor() const { return double(n_siz)/CAP;}
  V operator[] (const K&) const; // square-bracket getter
  V& operator[] (const K&); //square-bracket setter
  bool containsKey(const K&) const; //getter
  void deleteKey(const K&); //setter
  std::queue<K> keys() const;
  int size() const {return siz;}
  int n_size() const {return n_siz;}
  void clear();
  double average();
  void sort();
};

template <typename K, typename V, int CAP> //constructor
HashTable<K,V,CAP>::HashTable(int(*hashCode)(const K& key)){
  siz = 0;
  n_siz = 0;
  this->hashCode = hashCode;
}
template <typename K, typename V, int CAP> //destructor
HashTable<K,V,CAP>::~HashTable(){
  typename std::list<Node>::iterator it;
  for(int i = 0; i < CAP; i++){
    data[i].clear();
  }
  n_siz = 0;
  siz = 0;
}
template <typename K, typename V, int CAP> // square-bracket getter
V HashTable<K,V,CAP>::operator[](const K& key) const{
  int index = hashCode(key) % CAP;
  typename std::list<Node>::const_iterator it;
  for(it = data[index].begin(); it != data[index].end(); it++){
    if(it->key == key){
      return it->value; //found at it
    }
  }
  return V(); //not found
}
template <typename K, typename V, int CAP> //square-bracket setter
V& HashTable<K,V,CAP>::operator[](const K& key){
  int index = hashCode(key) % CAP;
  typename std::list<Node>::iterator it;
  for(it = data[index].begin(); it != data[index].end(); it++){
    if(it->key == key){
      return it->value;
    }
  }
  if(data[index].size() == 0){
    siz++;
  }
  n_siz++;
  data[index].push_back(Node{key,V()});
  return data[index].back().value;
}
template <typename K, typename V, int CAP> //getter
bool HashTable<K,V,CAP>::containsKey(const K& key)const{
  int index = hashCode(key) % CAP;
  typename std::list<Node>::const_iterator it;
  for(it = data[index].begin(); it != data[index].end(); it++){
    if(it->key == key){
      return true;
    }
  }
  return false;
}
template <typename K, typename V, int CAP> //setter
void HashTable<K,V,CAP>::deleteKey(const K& key){
  int index = hashCode(key) % CAP;
  typename std::list<Node>::iterator it;
  for(it = data[index].begin(); it != data[index].end(); it++){
    if(it->key == key){
      if(data[index].size() == 0){
        siz--;
      }
      n_siz--;
      delete it;
    }
  }
}
template <typename K, typename V, int CAP> // keys
std::queue<K> HashTable<K,V,CAP>::keys() const {
  std::queue<K> temp;
  typename std::list<Node>::const_iterator it;
  for(int i = 0; i < CAP; i++){
    for(it = data[i].begin(); it != data[i].end(); it++){
      temp.push(it->key);
    }
  }
  return temp;
}
template <typename K, typename V, int CAP> //clear
void HashTable<K,V,CAP>::clear() {
  for(int i = 0; i < CAP; i++){
    data[i].clear();
  }
  n_siz = 0;
  siz = 0;
}
//Additional functions for our application
template<typename K, typename V, int CAP>
double HashTable<K, V, CAP>::average() {
  double sum = 0;
  double count = 0;
  typename std::list<Node>::const_iterator it;
  for (int a = 0; a < CAP; a++) {
    for (it = data[a].begin(); it != data[a].end(); it++, count++) {
      sum += it->key;
    }
  }
  return (sum / count);
}
template<typename K, typename V, int CAP>
void HashTable<K, V, CAP>::sort() {
  for (int i = 0; i < CAP; i++) {
    if (!data[i].empty()) {
      data[i].sort();
    }
  }
}
#endif


