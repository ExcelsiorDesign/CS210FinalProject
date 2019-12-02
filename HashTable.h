//Programmer Name: Thomas Molnar-Brock
//Programmer ID: 1744869
//Assignment Name: HashTable Lab (Chaining Implementation)

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
  V operator[] (const K&) const; //getter
  V& operator[] (const K&); //setter
  bool containsKey(const K&) const; //getter
  void deleteKey(const K&); //setter
  std::queue<K> keys() const;
  int size() const {return siz;}
  void clear();
};

template <typename K, typename V, int CAP>
HashTable<K,V,CAP>::HashTable(int(*hashCode)(const K& key)){
  siz = 0;
  n_siz = 0;
  this->hashCode = hashCode;
}
template <typename K, typename V, int CAP> //getter
#endif
