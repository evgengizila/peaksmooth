#include <iostream>
#include <cstdlib>
  using namespace std;

void smoothPeaks (double array[], int length, int platform);
void inRandomArray (double array[], int length);
void outArray (double array[], int length);

int main () {
  const int L = 500;	
  double a[L];
  inRandomArray (a, L);
  outArray (a, L);
  cout << endl;
  for (int i = 0; i < 10; ++i){
    smoothPeaks (a, L, 3);
    outArray (a, L);
    cout << endl;
  } 
  return 0;
}

void smoothPeaks (double array[], int length, int platform){
  for (int i = 0; i < (length - platform + 1); ++i){
    double sum = 0;
    for (int j = 0; j < platform; ++j){
      sum += array [i+j];
    }
    sum /= platform;
    for (int j = 0; j < platform; ++j){
      array[i+j] = sum;
    }
  }
}

void inRandomArray (double array[], int length){
  for (int i = 0; i < length; ++i) 
    array[i] = rand() % 100;
}

void outArray (double array[], int length){
  for (int i = 0; i < length; ++i)
    cout << array[i] <<" ";
}
