/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file App.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/15 2018
 * @brief Application object to initiate everything
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "Button.h"
#include "Textbox.h"
#include "Utilities.h"

/**
* App
* Description:
*   Is the main class in which everything runs
* Sample usage:
* 	App.Run will start the whole thing
*/
class App 
{
 public:

  /**
   * Default Constructor
   */
  App() = default;

  /**
   * Default Destructor
   */
  ~App() = default;

  /**
   * Initializes the window from SFML
   */
  void
  initiate();

  /**
   * Rendering of objects inside
   */
  void
  onRender();

  /**
   * Member declaration
   */
 public:

  /**
   * Window component to render stuff
   */
  sf::RenderWindow m_window;

  /**
   * Button for initialization of fly eye drawing
   */


};