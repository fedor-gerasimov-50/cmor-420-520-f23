#include <iostream>
#include <chrono>
#include <random>

double mysum(int n, double * x){
  double val = 0.0;
  for (int i = 0; i < n; ++i){
    if (i % 2 == 0){
      val += x[i];
    }else{
      val -= x[i];
    }
  }
  return val;
}

int main(void){

  // Seed the random number generator
  std::random_device rd;
  std::mt19937 gen(rd()); // mt is a "mersenne twister" with 19937 bits
  std::normal_distribution<double> distribution(0.0, 1.0);

  int n = 1000000;
  double * x = new double [n];
  for (int i = 0; i < n; ++i){
    x[i] = distribution(gen);
  }

  int num_samples = 100;
  double val;
  
  auto start = std::chrono::high_resolution_clock::now();  

  for (int i = 0; i < num_samples; ++i){
    val = mysum(n, x);
  }
  
  // Record end time
  auto end = std::chrono::high_resolution_clock::now();

  // Calculate the duration
  std::chrono::microseconds duration =
    std::chrono::duration_cast<std::chrono::microseconds>(end - start) / num_samples;

  std::cout << "Last value of val = " << val << std::endl;
  
  // Print the duration in microseconds
  std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;
    
  return 0;
}
