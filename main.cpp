//Programmer Name: Thomas Molnar-Brock, Josh, Justin Goodman, Kyle
//Programmer ID: 1744869
//Assignment Name: Final Project

#include <iostream>
#include <cmath>
#include "HashTable.h"
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

void parseInFileToHashTable(const string filename, const string desiredIndVar, HashTable<int, double, 1000> &table){
  ifstream fin;
  fin.open(filename);
  if(!fin.good()){
    cout << "I/O Error\n";
  }
  char* token;
  char buf[1000];
  string line;
  int lineCount = 0;
  const char* delimiter = "\" , \"";
  
  while(fin.good()){
    //Parses File
    getline(fin, line);
    strcpy(buf, line.c_str());
    
    if(buf[0] == 0){ //skip blank lines
      continue;
    }
    if(lineCount == 0){
      lineCount++;
      continue;
    }
    const string timestamp(token = strtok(buf, ","));
    const string hrsSleep((token = strtok(0, delimiter)) ? token : "" );
    const string hrsStudied((token = strtok(0, delimiter)) ? token : "");
    const string mealsAte((token = strtok(0, delimiter)) ? token : "");
    const string GPA((token = strtok(0, delimiter)) ? token : "");
    double doubleGPA = stof(GPA);
    if(desiredIndVar == "hrsSleep"){
      table[stoi(hrsSleep)] = doubleGPA;
    }else if(desiredIndVar == "hrsStudied"){
      table[stoi(hrsStudied)] = doubleGPA;
    }else if(desiredIndVar == "mealsAte"){
      table[stoi(mealsAte)] = doubleGPA;
    }else{
      cout << "input error!";
    }
  }
  fin.close();
  
}

double findOptimalHrsToStudy(const HashTable<int, double, 1000> &dataTable){
  struct Point{
    int x;
    double y;
  };
  queue<int> keys = dataTable.keys();
  int SIZE = int(keys.size());
  Point points[SIZE];
  while(SIZE > 0){
    points[SIZE - 1] = Point{keys.front(), dataTable[keys.front()]};
    keys.pop();
    SIZE--;
  }
  SIZE = dataTable.n_size();
  double sumOfConstants = 0;
  double constantMultiplier;
  double x = 0;

  for(int i = 0; i < SIZE; i++){
    sumOfConstants += points[i].y / log(points[i].x + 1);
  }
  constantMultiplier = sumOfConstants / SIZE;
  //cout << "The function of best fit is: " << constantMultiplier << "ln(x + 1)\n";
  x = exp(4.0/constantMultiplier) - 1;
  if(x >= 20){
    x = constantMultiplier/0.1;
  }
  //cout << "The optimal number of hours to study is: " << x << endl;
  return x;
}
int hashCode( const int &key) {
  int x = key;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x;
}

double findOptimalMealsToEat(const HashTable<int, double, 1000> &dataTable){
  double result = 0;
  int count = 0;
  queue<int> keys = dataTable.keys();
  int size = int(keys.size());
  for(int i = 0; i < size; i++){
    if(dataTable[keys.front()] >= 3){
      result += keys.front();
      count++;
    }
  }
  return result / double(count);
}
double findOptimalHoursToSleep(const HashTable<int, double, 1000> &dataTable){
  double result = 0;
  int count = 0;
  queue<int> keys = dataTable.keys();
  int size = int(keys.size());
  for(int i = 0; i < size; i++){
    if(dataTable[keys.front()] >= 3){
      result += keys.front();
      count++;
    }
  }
  return result / double(count);
}

int main(){
  HashTable<int, double, 1000> hrsStudiedToGPA(hashCode); //stores the hrs studied as key and gpa as value
  HashTable<int, double, 1000> mealsToGPA(hashCode);
  HashTable<int, double, 1000> sleepToGPA(hashCode);
  
  parseInFileToHashTable("Habits Survey.csv", "hrsStudied", hrsStudiedToGPA);
  parseInFileToHashTable("Habits Survey.csv", "mealsAte", mealsToGPA);
  parseInFileToHashTable("Habits Survey.csv", "hrsSleep", sleepToGPA);
  
  //Statistical Analysis
  cout <<"\nHours studied: \n";
  cout << "**************\n";
  
  cout << "The optimal number of hours to study per day is: " << findOptimalHrsToStudy(hrsStudiedToGPA) << endl;
  cout << "The average numeber of hours studied by partcipants was: " << hrsStudiedToGPA.average() << endl;
  cout << "Here are the hours studied and their respective GPA:\n";
  queue<int> keys = hrsStudiedToGPA.keys();
  while(keys.size()){
    cout << "key: " << keys.front();
    cout << " value: " << hrsStudiedToGPA[keys.front()] << endl;
    keys.pop();
  }
  cout <<"\nMeals Eaten: \n";
  cout << "**************\n";
  
  cout << "The optimal number of meals to eat per day is: " << findOptimalMealsToEat(mealsToGPA) << endl;
  cout << "The average numeber of hours eaten by partcipants was: " << hrsStudiedToGPA.average() << endl;
  cout << "Here are the number of meals eaten and their respective GPA:\n";
  keys = mealsToGPA.keys();
  while(keys.size()){
    cout << "key: " << keys.front();
    cout << " value: " << mealsToGPA[keys.front()] << endl;
    keys.pop();
  }
  cout <<"\nHours Slept: \n";
  cout << "**************\n";
  
  cout << "The optimal number of hours to sleep per day is: " << findOptimalHoursToSleep(sleepToGPA) << endl;
  cout << "The average numeber of hours to slept by partcipants was: " << sleepToGPA.average() << endl;
  cout << "Here are the number of hours slept and their respective GPA:\n";
  keys = sleepToGPA.keys();
  while(keys.size()){
    cout << "key: " << keys.front();
    cout << " value: " << sleepToGPA[keys.front()] << endl;
    keys.pop();
  }
  
}
