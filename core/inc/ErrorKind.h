/// @file ErrorKind.h
/// @brief Enum of possible error and is_ok function implementation.
#pragma once

/// @brief All possible error in the project
enum class ErrorKind {
  SPI,
  I2C,
  UART,
  PWM,
  TIMER,
  DIV0,
  DUTY_NOT_IN_RANGE,
};

/// @brief Tests if return value is ok.
/// @param return value of majority of functions in this project. class Val_or_Ok is in most cases Ok_t.
/// @return true or false
template <class Val_or_Ok>
bool
is_ok(std::expected<Val_or_Ok, ErrorKind> ret)
{
    return ret.has_value() ? true : false;
}
