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
App::initialize() {

  if (!m_defaultFont.loadFromFile("resources/PGB.ttf")) {
    std::cout << "Failed to create default font from file...\n";
    return;
  }

  m_window.create(sf::VideoMode(1000, 800), "FLY EYE");
  m_center.x = 500;
  m_center.y = 400;
  m_circle.setRadius(200.0f);
  m_circle.setPosition(300.0f, 200.0f);
  m_circle.setFillColor(sf::Color::Black);
  m_circle.setOutlineColor(sf::Color::White);
  m_circle.setOutlineThickness(2.0f);

  m_threadCount.setSize(100, 50);
  m_threadCount.setPosition(50, 101);
  m_threadCount.setBoxColor(sf::Color::White);
  m_threadCount.m_text.setFont(m_defaultFont);
  m_threadCount.m_text.setScale(0.5f, 0.5f);
  m_threadCount.m_text.setFillColor(sf::Color::Blue);

  m_pointCount.setSize(100, 50);
  m_pointCount.setPosition(50, 50);
  m_pointCount.setBoxColor(sf::Color::White);
  m_pointCount.m_text.setFont(m_defaultFont);
  m_pointCount.m_text.setScale(0.5f, 0.5f);
  m_pointCount.m_text.setFillColor(sf::Color::Blue);

  m_threadStart.setSize(300, 50);
  m_threadStart.setPosition(151, 50);
  m_threadStart.setBoxColor(sf::Color::Green);
  m_threadStart.m_text.setFont(m_defaultFont);
  m_threadStart.m_text.setScale(0.5f, 0.5f);
  m_threadStart.m_text.setFillColor(sf::Color::Magenta);
  m_threadStart.setData("Start w/ threads");


  m_normalStart.setSize(300, 50);
  m_normalStart.setPosition(151, 101);
  m_normalStart.setBoxColor(sf::Color::Blue);
  m_normalStart.m_text.setFont(m_defaultFont);
  m_normalStart.m_text.setScale(0.5f, 0.5f);
  m_normalStart.m_text.setFillColor(sf::Color::Magenta);
  m_normalStart.setData("Start w/o threads");

  m_currentTextBox = nullptr;
  m_catcher = "";
}

void
App::onUpdate() {

  sf::Event event;
  while (m_window.isOpen())
  {
    while (m_window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed) { m_window.close(); }
        

      if (event.type == sf::Event::MouseButtonPressed && 
          event.mouseButton.button == sf::Mouse::Left) { onClick(); }

      if (event.type == sf::Event::TextEntered && m_currentTextBox != nullptr ) {

        if (event.text.unicode == 13) {
          m_currentTextBox->m_text.setString(m_catcher);
          m_catcher.clear();
        }

        else if (event.text.unicode > 47 && event.text.unicode < 58) {
          m_catcher += static_cast<char>(event.text.unicode);
          m_currentTextBox->m_text.setString(m_catcher);
          std::cout << m_catcher << std::endl;
        }
      }
    }

    m_window.clear();
    onRender();
    m_window.display();
  }
}

void
App::onRender() {
  m_window.draw(m_pointCount.m_box);
  m_window.draw(m_threadCount.m_box);
  m_window.draw(m_threadStart.m_box);
  m_window.draw(m_normalStart.m_box);
  
  m_window.draw(m_pointCount.m_text);
  m_window.draw(m_threadCount.m_text);
  m_window.draw(m_threadStart.m_text);
  m_window.draw(m_normalStart.m_text);

  m_window.draw(m_circle);

  drawLines();

}

void
App::onClick() {

  sf::Vector2f mousePos = m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));

  std::cout << mousePos.x << " " << mousePos.y << std::endl;

  if (mousePos.x > m_pointCount.m_box.getPosition().x &&
      mousePos.x < m_pointCount.m_box.getPosition().x + m_pointCount.m_box.getSize().x &&
      mousePos.y > m_pointCount.m_box.getPosition().y &&
      mousePos.y < m_pointCount.m_box.getPosition().y + m_pointCount.m_box.getSize().y) {

    std::cout << "selected eye count" << std::endl;
    if (m_currentTextBox != nullptr) { m_currentTextBox->m_text.setString(m_catcher); }
    m_catcher.clear();
    m_currentTextBox = &m_pointCount;
  }

  else if (mousePos.x > m_threadCount.m_box.getPosition().x &&
           mousePos.x < m_threadCount.m_box.getPosition().x + m_threadCount.m_box.getSize().x &&
           mousePos.y > m_threadCount.m_box.getPosition().y &&
           mousePos.y < m_threadCount.m_box.getPosition().y + m_threadCount.m_box.getSize().y) {

    std::cout << "selected thread count" << std::endl;
    if (m_currentTextBox != nullptr) { m_currentTextBox->m_text.setString(m_catcher); }
    m_catcher.clear();
    m_currentTextBox = &m_threadCount;
  }

  else if (mousePos.x > m_threadStart.m_box.getPosition().x &&
           mousePos.x < m_threadStart.m_box.getPosition().x + m_threadStart.m_box.getSize().x &&
           mousePos.y > m_threadStart.m_box.getPosition().y &&
           mousePos.y < m_threadStart.m_box.getPosition().y + m_threadStart.m_box.getSize().y) {

    std::cout << "selected thread start" << std::endl;
    m_threadStart.onClick();
  }

  else if (mousePos.x > m_normalStart.m_box.getPosition().x &&
           mousePos.x < m_normalStart.m_box.getPosition().x + m_normalStart.m_box.getSize().x &&
           mousePos.y > m_normalStart.m_box.getPosition().y &&
           mousePos.y < m_normalStart.m_box.getPosition().y + m_normalStart.m_box.getSize().y) {
    
    std::cout << "selected normal start" << std::endl;
    m_normalStart.onClick();
    if (startCalculation()) { drawLines(); }
  }

}

bool
App::startCalculation() {
  

  std::string points = m_pointCount.m_text.getString();
  std::string thrds = m_threadCount.m_text.getString();
  m_totalPoints = atoi(points.c_str());
  m_totalThreads = atoi(thrds.c_str());

  std::cout << "total points: " << m_totalPoints << std::endl;
  std::cout << "total threads: " << m_totalThreads << std::endl;

  if (m_totalPoints < 3) { 
    std::cout << "Too little points to generate a fly eye" << std::endl;
    return false;
  }

  m_totalSets.clear();
  m_pointList.clear();
  
  if (m_threadStart.m_clicked && m_totalThreads < 2) {
    std::cout << "Too little threads to draw in parallel" << std::endl;
    return false;
  }

  setCoordinates();
  setLines();
  return true;
}

void
App::setCoordinates() {
  int thetta = 360;

  for (int i = 0; i < m_totalPoints; ++i) {
    int alfa = thetta * i / m_totalPoints;
    double b = degToRad(alfa);

    float x = std::round(m_circle.getRadius()*std::sin(b));
    float y = std::round(m_circle.getRadius()*std::cos(b));

    sf::Vector2f a(x + m_center.x, y + m_center.y);
    m_pointList.push_back(a);
  }
}

void
App::setLines() {
  m_linesPerSet = m_totalPoints / 2;

  if (m_totalPoints % 2 == 0) {
    --m_linesPerSet;
  }

  for (int i = 0; i < m_totalPoints; ++i) {

    int rounder = 0;
    pointSet ps;
    ps.m_finished = false;

    for (int j = i + 1, v = 0; v < m_linesPerSet; ++v, ++j) {
      //this checks if it got to the end of the list of points and makes it start from the beginning
      if (j > m_totalPoints - 1) {
        j = rounder;
        ++rounder;
      }

      line p(m_pointList[i], m_pointList[j]);
      ps.m_linesPerPoint.push_back(p);

    }
    m_totalSets.push_back(ps);
  }
}

void
App::drawThreads() {

}

void
App::drawLines(int amount) {
  //sets how many sets each thread will draw in case of using threads,so no one
  //steps on another thread
  int times = m_totalSets.size() / amount;
  

  for (int i = 0; i < times; ++i) {

    for (int j = 0; j < m_linesPerSet; ++j) {
      m_window.draw(m_totalSets[i].m_linesPerPoint[j].m_p, 2, sf::Lines);
    }
  }
}