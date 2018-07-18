# gf256

This is a fairly small and fast immplementation of the GF256 finite field used in AES encryption.

Addition and subtraction are implemented as bitwise xor over the underlying 8 bit data structures.

Multiplications, additions and exponents are impemented with the aid of static log and exponential
tables stored in program space static arrays. Trivial operations are implemented as inline methods.

The gf256 class will automatically cast to an uint8_t when needed.

## Example

```c++
#include <gf256.h>

void setup() {
  Serial.begin(9600);

  gf256 a = 2;
  gf256 b = 3;

  gf256 y = ~b;
  gf256 z = ~a;

  Serial.print("\n     a = "); Serial.print(a, HEX);
  Serial.print("\n     b = "); Serial.print(b, HEX);
  Serial.print("\n   a*b = "); Serial.print(a*b, HEX);
  Serial.print("\n   b*a = "); Serial.print(b*a, HEX);
  Serial.print("\n   a+b = "); Serial.print(a+b, HEX);
  Serial.print("\n   b+a = "); Serial.print(b+a, HEX);
  Serial.print("\n  a*~a = "); Serial.print(a*~a, HEX);
  Serial.print("\n  ~a*a = "); Serial.print(~a*a, HEX);
  Serial.print("\n   a/b = "); Serial.print(a/b, HEX);   
  Serial.print("\n   b/a = "); Serial.print(b/a, HEX);
  Serial.print("\n~(b/a) = "); Serial.print(~(b/a), HEX);
}

void loop() {  
}
```


```
     a = 2
     b = 3
   a*b = 6
   b*a = 6
   a+b = 1
   b+a = 1
  a*~a = 1
  ~a*a = 1
   a/b = F7
   b/a = 8C
~(b/a) = F7
```