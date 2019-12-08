//Justin Goodman
//1638752

#include <iostream>

using namespace std;

template <typename T>
auto minmax_copy(const T& a, const T& b)
{
    return (b < a) ? pair<const T, const T>(b, a) : pair<const T, const T>(a, b);
}

int main()
{
    int a = 2;
    int b = 1;
    tie(a, b) = minmax_copy(a, b);
    cout << "Min is " << a << endl;
    cout << "Max is " << b << endl;
    
    return 0;
}

//template <typename K, typename V, int CAP>
//K HashTable<K, V, CAP>::min(){
//    typename std::list<Node>::const_iterator it;
//    K min = K();
//    bool isFirst = true;
//
//    for(int i = 0; i < CAP; i++){
//        for(it = data[i].begin(); it != data[i].end(); it++){
//            if(isFirst){
//                min = it->value;
//                isFirst = false;
//            }
//            if(it->value < min)
//                min = it->value;
//        }
//    }
//    return min;
//}

//template <typename K, typename V, int CAP>
//K HashTable<K, V, CAP>::max(){
//    typename std::list<Node>::const_iterator it;
//    K max = K();
//    bool isFirst = true;
//
//    for(int i = 0; i < CAP; i++){
//        for(it = data[i].begin(); it != data[i].end(); it++){
//            if(isFirst){
//                min = it->value;
//                isFirst = false;
//            }
//            if(it->value < min)
//                min = it->value;
//        }
//    }
//    return min;
//}

