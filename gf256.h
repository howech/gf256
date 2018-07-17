#ifndef GF256_H
#define GF256_H

#include <inttypes.h>

class gf256 {
  public:
  uint8_t n;

  gf256()           {n=0;}
  gf256(uint8_t m)  {n=m;}
  gf256(int m)      {n=m;}
  gf256(uint16_t m) {n=m;}
  gf256(const gf256 &g) {n=g.n;}
  
  gf256 operator +(const gf256 &b) const { return n ^ b.n; }
  gf256 operator -(const gf256 &b) const { return n ^ b.n; }
  gf256 operator *(const gf256 &b) const;
  gf256 operator /(const gf256 &b) const;
  gf256 operator ~() const;
  gf256 power(int n) const;

  bool operator==(const gf256 &o) const {return n == o.n;}

  uint16_t log() const;
  gf256 alog(uint16_t n) const;
  
};

#endif
