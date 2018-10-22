/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file Button.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/10/15 2018
 * @brief Button member definition
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#include "pch.h"
#include "Button.h"

void
Button::onClick() {
  std::string p = m_text.getString();
  std::cout << "clicked" << p << std::endl;
}
