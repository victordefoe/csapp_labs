/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  int p = x & y; // bit=1 for both x and y
  int q = (~x) & (~y); // bits=0 for both x and y
  return (~p)&(~q); // find the zero bits for both p and q
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  
  return 1<<31; //compiler feels constant 0x80000000 illegal
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
// 11111 & 0
int isTmax(int x) {
   //feat 1: use the feature of x+1 is totally oppsite with x (overflow)
  int Plus_1_test = !(~(x^(x+1)));
  // feat 2: however both 0xFFFFFFFF(-1) and 0x7FFFFFFF(Tmax) fit the feat 1,
  // so try to get rid of 0xFFFFFFFF answer
  int NotAllOne = !(!(~(x|0)));
  // combine feat 1 and 2, right answer needs to fit both
  return (Plus_1_test & NotAllOne);
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int oddd = 0xAA;
  oddd = (oddd<<8)+0xAA;
  oddd = (oddd<<8)+0xAA;
  oddd = (oddd<<8)+0xAA;
  return !((x&oddd)^oddd); 
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x+1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  int prefix=(!(x&(~0x3F))); // make sure first two bytes must be zero
  int midium=(!((x&0x30)^0x30)); //  make sure the third byte must be one
  int suffix=(!(((x&0xF)+0x6)&0xF0)); // make sure the last byte no greater than 9
  return prefix&midium&suffix; // combine all conditions
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
   // if x true(choose y), s=0x0; if x false(choose z), s=0xFFFFFFFF;
  int s = (~(!x))+1;
  return ((s^y)&y)+(s&z); // use s to control select which part
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  // make a (y-x) expression and see if it's negative or positive
  // if y-x < 0 (x>y) then return 0 else return 1
  // when x, y are in opposite sign, there may be an overflow need to be avoid
  int Tmin=(1<<31);
  int SameSign = !((x&Tmin) ^ (y&Tmin)); // x and y have same sign situation
  int MinusPos = !( (y+((~(x))+1)) & Tmin); // y-x>0 situation
  int Ypos_Xneg = (!SameSign) & (!(y&Tmin)); // y positive and x negative situation
  return Ypos_Xneg | (SameSign & MinusPos);
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  //use "lowbit" method to get lowest bit
  // example: lowbit(0b00110110)=0b00000010
  int lowbit = x&((~x)+1); 
  // for non-zero number, lowbit's two's complement has form like 0b11111110 (highest bit is 1),
  // but if lowbit=0, it's 2's complement is 0 (highest bit is 0)
  int neg_lowbit = (~lowbit)+1;
  // take the differece of highest bit as a classification feature
  int sign = neg_lowbit & (1<<31);
  // notice it's an arithmetic right shift
  return  (sign>>31)+1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  int b16,b8,b4,b2,b1,b0;
  int sign=x>>31;
  //Unchanged if x is positive. Otherwise, invert the bitwise (this also removes the sign bit)
  x = (sign&~x)|(~sign&x);

// Keep narrowing the range
  b16 = !!(x>>16)<<4;//Is there a 1 in the high sixteenth bit
  x = x>>b16;//If there is (at least 16 bits are required), the original number is right-shifted by 16 bits
  b8 = !!(x>>8)<<3;//Is there a 1 in the remaining 8 high bits
  x = x>>b8;//If there is (requires at least 16+8=24 bits), then shift right by 8 bits
  b4 = !!(x>>4)<<2;//in the same way
  x = x>>b4;
  b2 = !!(x>>2)<<1;
  x = x>>b2;
  b1 = !!(x>>1);
  x = x>>b1;
  b0 = x;
  return b16+b8+b4+b2+b1+b0+1;//+1 means add sign bit

  return 0;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  int tmin=1<<31;
  int scale=(1<<23);
  int sign=uf&tmin;
  
  if( (!( (uf&(~tmin))|0 )) ) // if uf is +/- 0
    return uf;
  if(!(uf&(0xFF<<23))) // else if exp field is all zero
    return (uf<<1)+sign;
  if(!((uf&(0xFF<<23))^(0xFF<<23))) // if exp field is all one, return NaN
    return uf;
  
  return (uf+scale)&(~tmin)+sign;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  int tmin=1<<31;
  int sign=uf&tmin;
  int frac=uf&0x007fffff;
  int Bias=127;
  int shift=((uf&(0xFF<<23))>>23)-Bias;
  int res1=(frac+(1<<23))>>(23-shift);

  if( (!( (uf&(~tmin))|0 )) ) // if uf is +/- 0
    return 0;

  if(shift<0) // if exp<0  then uf<1
    return 0;

  if(shift < 23) // frac right shift needed
    if(!sign) // if uf is positive
      return res1; 
    else
      return (~(res1))+1; 
  if(shift>31)
    return tmin;

  return ((frac+(1<<23))<<(shift-23))+sign;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
  int inf=(0xFF)<<23;
  if(x>127)
    return inf;
  if(x>-127)
    return (x+127)<<23; //float: exp range from -126 to 127
  return 0;
}
