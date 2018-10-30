/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file Utilities.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/15 2018
 * @brief Utilities are defined here, are headers that everyone use
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>
#include <chrono>

#include <SFML/Graphics.hpp>

#define _VARIADIC_MAX 10
/**
 * @brief converts degrees to rads
 * @param angle to convert
 * @return 
 *
 */
static const double 
degToRad(double angle) {
  //Multiply and divide by 1000 to not lose precision
  double tofloor = std::floor(angle * (3.1415926 / 180) * 1000);
  return tofloor / 1000;
}
/**
 * @brief converts rads to degrees
 * @param rads to convert
 * @return 
 *
 */
static const double 
radToDeg(double angle) {
  //Multiply and divide by 1000 to not lose precision
  double tofloor = std::floor(angle * (180 / 3.1415926) * 1000);
  return tofloor / 1000;
}
