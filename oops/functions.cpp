#include <cstddef>

/**
* @brief Returns the successor of a given number.
*
* Adds one to the given number.
*
* @param num non-positive integer.
* @return size_t The successor of num.
*/
size_t succ(size_t num){
    // method : add one to the given number
    return num+1;
}

/**
 * @brief Returns the predecessor of a given number.
 *
 * Recursively increments candidate until its successor equals the number.
 *
 * @param num positive integer.
 * @param cand The candidate value (default is 0).
 * @return size_t The predecessor of num.
 */
size_t pred(size_t num,size_t cand = 0){
    // method : recursively increment candidate until its successor equals the number
    if(succ(cand) == num) return cand;
    return pred(num,succ(cand));
}

/**
 * @brief Adds two numbers recursively.
 *
 * Recursively increments the first number and decrements the second until the second is zero.
 *
 * @param num1 The first non-negative integer.
 * @param num2 The second non-negative integer.
 * @return size_t The sum of num1 and num2.
 */
size_t add(size_t num1,size_t num2){
    // method : recursively increment first number and decrement second until second is zero
    if(num2 <= 0) return num1;
    return add(succ(num1),pred(num2));
}

/**
 * @brief Subtracts one number from another recursively.
 *
 * Recursively decrements both numbers until the second is zero.
 *
 * @param num1 The minuend. Atleast one more than num2.
 * @param num2 The subtrahend. Atmost one less than num1.
 * @return size_t The result of num1 - num2.
 */
size_t sub(size_t num1,size_t num2){
    // method : recursively decrement both numbers until second is zero
    if(num2 <= 0) return num1;
    return sub(pred(num1),pred(num2));
}

/**
 * @brief Multiplies two numbers recursively.
 *
 * Recursively adds the first number to an accumulator and decrements the second until zero.
 *
 * @param num1 The first non-negative integer.
 * @param num2 The second non-negative integer.
 * @param temp The accumulator (default is 0).
 * @return size_t The product of num1 and num2.
 */
size_t mul(size_t num1,size_t num2,size_t temp = 0){
    // method : recursively add first number to accumulator, decrement second until zero
    if(num2 <= 0 || num1 <=0) return temp;
    return mul(num1,pred(num2),add(temp,num1));
}

/**
 * @brief Recursively divides num1 by num2 using subtraction.
 *
 * This function calculates the integer quotient of num1 divided by num2
 * by repeatedly subtracting num2 from num1 and incrementing the quotient
 * until num1 is less than num2.
 *
 * @param num1 The non-negative dividend.
 * @param num2 The non-negative divisor.
 * @param quo The current quotient (default is 0).
 * @return size_t The integer quotient of num1 divided by num2.
 */
size_t divi(size_t num1,size_t num2,size_t quo = 0){
    // method : recursively subtract second from first, increment quotient until first < second
    if(num1 < num2) return quo;
    return divi(sub(num1,num2),num2,succ(quo));
}

/**
 * @brief Calculates the modulus of num1 by num2 recursively.
 *
 * Recursively subtracts num2 from num1 until num1 is less than num2.
 *
 * @param num1 The non-negative dividend.
 * @param num2 The non-negative divisor.
 * @return size_t The remainder of num1 divided by num2.
 */
size_t mod(size_t num1,size_t num2){
    // method : recursively subtract second from first until first < second
    if(num1 < num2) return num1;
    return mod(sub(num1,num2),num2);
}