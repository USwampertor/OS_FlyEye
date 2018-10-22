/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file TextBox.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/10/15 2018
 * @brief TextBox member definition
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#include "pch.h"
#include "Textbox.h"

TextBox
TextBox::operator = (const TextBox& other) const {
  return TextBox(other);
}

void
TextBox::setData(std::string userData) {
  m_text.setString(userData);
}

void
TextBox::setPosition(float x, float y) {
  m_text.setPosition(x, y + m_box.getSize().y / 3.0f);
  m_box.setPosition(x, y);
}

void
TextBox::setSize(float x, float y) {
  m_box.setSize(sf::Vector2f(x, y));
}

void
TextBox::setBoxColor(sf::Color color) {
  m_box.setFillColor(color);
}