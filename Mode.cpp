//Justin Goodman
//1638752

//#include <iostream>
//#include <map>
//#include <vector>
//#include <algorithm>
//#include <string>
//#include <stdexcept>
//
//using namespace std;
//
//template<typename T>
//T findMode(const vector<T>& vec ){
//    
//    if(vec.size() == 0){
//        throw domain_error("No mode for empty vector");
//    }
//    else if(vec.size() == 1)
//        return vec[0];
//    
//    // copy the original, don´t alter the input
//    vector<T> v(vec);
//    
//    // Order just to group same elements
//    // T MUST implement '>' operator. Which is trivial
//    // for primitive types.
//    sort(v.begin(), v.end());
//    
//    typename vector<T>::iterator it ;
//    
//    it = v.begin();
//    
//    size_t largest_count = 0;
//    T mode;
//    bool flag = false; // this flag indicates when we found 2 equal modes
//    while(it != v.end())
//    {
//        
//        T m = *it;
//        size_t count = 1;
//        
//        while( it != v.end() && *++it == m ){
//            count++;
//        }
//        
//        if(count > largest_count){
//            largest_count = count;
//            mode = m;
//            flag = false;
//        }
//        else if(count == largest_count){
//            flag = true;
//        }
//    }
//    
//    if(flag){
//        // if we found a count as large as the largest,
//        // we have no mode, so, throw exception
//        throw domain_error("No mode for vector");
//    }
//    
//    return mode;
//}
//
//template<typename T>
//bool test(const vector<T> v, const T& expected_mode)
//{
//    T mode;
//    try
//    {
//        return findMode<T>(v) == expected_mode;
//    }
//    catch(const domain_error& de)
//    {
//        return false;
//    }
//}
//
//int main()
//{
//    const vector<int> vec_int = {1};
//    cout << [&](){ return test<int>(vec_int, 1) == true ? "OK" : "NOK"; }() << " for {1}"
//    << endl;
//    
//    // This test is OK, if returns false, there is no mode
//    const vector<int> vec_int2 = {1,1,2,2};
//    cout << [&](){ return test<int>(vec_int2, 1) == false ? "OK" : "NOK"; }()
//    << " for {1,1,2,2}" << endl;
//    
//    // This test is OK, if returns false, there is no mode
//    const vector<int> vec_int3 = {1,1,1,1};
//    cout << [&](){ return test<int>(vec_int3, 1) == true ? "OK" : "NOK"; }()
//    << " for {1,1,1,1}" << endl;
//    
//    // This test is OK, if returns false, there is no mode
//    const vector<double> vec_double = {6.25, 1.1, 1.1, 2.2, 2.3, 2.5, 6.25, 6.25, 6.25, 6};
//    cout << [&](){ return test<double>(vec_double, 6.25) == true ? "OK" : "NOK"; }()
//    << " for {6.25, 1.1, 1.1, 2.2, 2.3, 2.5, 6.25, 6.25, 6.25, 6}" << endl;
//    
//    
//    // This test is OK, if returns false, there is no mode
//    const vector<char> vec_char ={'0', 'X', 'D', 'E', 'A', 'D', 'B', 'E', 'E', 'F'};
//    cout << [&](){ return test<char>(vec_char, 'E') == true ? "OK" : "NOK"; }()
//    << " for {'0', 'X', 'D', 'E', 'A', 'D', 'B', 'E', 'E', 'F'}" << endl;
//    
//    return 0;
//}
