#ifndef _MaxMatrix_H_
#define _MaxMatrix_H_

#include "Arduino.h"
//the opcodes for the MAX7219
#define OP_NOOP   0
#define OP_DIGIT0 1
#define OP_DIGIT1 2
#define OP_DIGIT2 3
#define OP_DIGIT3 4
#define OP_DIGIT4 5
#define OP_DIGIT5 6
#define OP_DIGIT6 7
#define OP_DIGIT7 8
#define OP_DECODEMODE  9
#define OP_INTENSITY   10
#define OP_SCANLIMIT   11
#define OP_SHUTDOWN    12
#define OP_DISPLAYTEST 15

class MaxMatrix
{
private:
  byte data;
  byte cs;
  byte clock;

public:
  MaxMatrix(byte data, byte cs, byte clock);

  void init();
  void clear();
  void setCommand(byte command, byte value);
  void setIntensity(byte intensity);
  void setColumn(byte col, byte value);
  void setColumnAll(byte col, byte value);
  void writeSprite(const byte* sprite);
};

#endif

