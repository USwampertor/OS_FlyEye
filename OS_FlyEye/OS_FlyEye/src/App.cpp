/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file App.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/10/15 2018
 * @brief Application member definition
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#include "pch.h"
#include "App.h"

void
App::initiate() {
  m_window.create(sf::VideoMode(800, 600),"FLY EYE");
}

void
App::onUpdate() {
  while (m_window.isOpen())
  {
    sf::Event event;
    while (m_window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        m_window.close();
    }

    m_window.clear();
    //m_window.draw(shape);
    m_window.display();
  }
}

void
App::onRender() {

}
