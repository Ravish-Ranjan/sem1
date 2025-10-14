#ifndef PYTHAGORIAN_H
#define PYTHAGORIAN_H

#include <vector>
#include <cstddef>

/**
 * Checks if a given number is a perfect square.
 * @param {size_t} num The number to check.
 * @return {bool} True if the number is a perfect square, false otherwise.
 */
bool isPerfectSqaure(size_t num){
  for(size_t i = 1; i*i <= num; i++){
    if(i*i == num){
      return true;
    }
  }
  return false;
}

/**
 * Calculates the integer square root of a perfect square.
 * @param {size_t} num The perfect square number.
 * @return {size_t} The integer square root, or 0 if not a perfect square.
 */
size_t sqrt(size_t num){
  for(size_t i = 1; i*i <= num; i++){
    if(i*i == num){
      return i;
    }
  }
  return 0;
}

/**
 * Calculates the square of a number.
 * @param {size_t} num The number to square.
 * @return {size_t} The square of the number.
 */
size_t sq(size_t num){
  return num*num;
}

/**
 * Finds the next Pythagorean triple (a, b, c) where c is greater than the given c.
 * It searches for a triple where the new c is incremented from the given c.
 * @param {size_t} a The first element of the current triple.
 * @param {size_t} b The second element of the current triple.
 * @param {size_t} c The third element of the current triple.
 * @return {std::vector<size_t>} A vector containing the next Pythagorean triple {a, b, c}, or {0, 0, 0} if none is found within the search range.
 */
std::vector<size_t> nextPythagorian(size_t a, size_t b, size_t c){
  for(size_t i = 1; i < 10; i++){
    size_t cand = sq(c+i);
    size_t low = 1,high = c+i-1;
    while(low <= high){
      size_t sum = sq(low) + sq(high);
      if ( sum == cand ){
        return {low,high,c+i};
      } else if (sum > cand){
        high--;
      } else {
        low++;
      }
    }
  }
  return {0,0,0};
}

#endif
