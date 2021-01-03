//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.0
//    DATE: 2020-12-03
// PURPOSE: unit tests for the PCF8575 I2C port expander
//          https://github.com/RobTillaart/PCF8575
//          https://github.com/Arduino-CI/arduino_ci/blob/master/REFERENCE.md
//

// supported assertions
// ----------------------------
// assertEqual(expected, actual);               // a == b
// assertNotEqual(unwanted, actual);            // a != b
// assertComparativeEquivalent(expected, actual);    // abs(a - b) == 0 or (!(a > b) && !(a < b))
// assertComparativeNotEquivalent(unwanted, actual); // abs(a - b) > 0  or ((a > b) || (a < b))
// assertLess(upperBound, actual);              // a < b
// assertMore(lowerBound, actual);              // a > b
// assertLessOrEqual(upperBound, actual);       // a <= b
// assertMoreOrEqual(lowerBound, actual);       // a >= b
// assertTrue(actual);
// assertFalse(actual);
// assertNull(actual);

// // special cases for floats
// assertEqualFloat(expected, actual, epsilon);    // fabs(a - b) <= epsilon
// assertNotEqualFloat(unwanted, actual, epsilon); // fabs(a - b) >= epsilon
// assertInfinity(actual);                         // isinf(a)
// assertNotInfinity(actual);                      // !isinf(a)
// assertNAN(arg);                                 // isnan(a)
// assertNotNAN(arg);                              // !isnan(a)

#include <ArduinoUnitTests.h>

#define assertEqualFloat(arg1, arg2, arg3)  assertOp("assertEqualFloat", "expected", fabs(arg1 - arg2), compareLessOrEqual, "<=", "actual", arg3)
// #define assertEqualINF(arg)  assertOp("assertEqualINF", "expected", INFINITY, compareEqual, "==", "actual", arg)
// #define assertEqualNAN(arg)  assertOp("assertEqualNAN", "expected", true, compareEqual, "==", "actual", isnan(arg))


#include "Arduino.h"
#include "PCF8575.h"

PCF8575 PCF(0x38);


unittest_setup()
{
}

unittest_teardown()
{
}

unittest(test_begin)
{
  fprintf(stderr, "VERSION: %s\n", PCF8574_LIB_VERSION);

  PCF8575 PCF(0x38);

  PCF.begin();

  int readValue = PCF.read8();
  assertEqual(0, readValue);

  int expect = PCF8575_I2C_ERROR;
  assertEqual(expect, PCF.lastError());
}


unittest(test_read)
{
  PCF8575 PCF(0x38);
  int readValue;

  PCF.begin();
  for (int i = 0; i < 8; i++)
  {
    fprintf(stderr, "line %d\t", i);
    readValue = PCF.read(i);
    assertEqual(0, readValue);

    int expect = PCF8575_I2C_ERROR;
    assertEqual(expect, PCF.lastError());
  }
  printf("test");
  readValue = PCF.read(8);
  assertEqual(0, readValue);
  int expect = PCF8575_PIN_ERROR;
  assertEqual(expect, PCF.lastError());
}


unittest_main()

// --------
