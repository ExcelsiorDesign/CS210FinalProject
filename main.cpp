#include <iostream>
#include <cmath>

using namespace std;

struct Point{
  int x;
  int y;
};

int main(){
  const int SIZE = 5;
  Point points[SIZE] = { Point{1,2}, Point{2,4}, Point{3,9}, Point{4,16}, Point{5,25}};
  double sumOfConstants = 0;
  double constantMultiplier;
  double x;
  
  for(int i = 0; i < SIZE; i++){
    sumOfConstants += double(points[i].y) / log(points[i].x + 1);
  }
  constantMultiplier = sumOfConstants / SIZE;
  cout << "The function of best fit is: " << constantMultiplier << "ln(x + 1)\n";
  x = exp(4.0/constantMultiplier) - 1;
  if(x >= 20){
    x = constantMultiplier/0.1;
  }
  cout << "The optimal number of hours to study is: " << x << endl;
  
}
