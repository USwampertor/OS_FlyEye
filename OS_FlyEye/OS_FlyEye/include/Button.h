/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file Button.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/15 2018
 * @brief button Object for interface use
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#pragma once
#include "Utilities.h"
#include "Textbox.h"
/**
* Button
* Description:
*   A simple User friendly Button
* Sample usage:
* 	Button.onClick registers a click and does something
*/
class Button : public TextBox
{
 public:
  
  /**
   * Default constructor
   */
  Button() = default;


  /**
   * Default destructor
   */
  ~Button() = default;
  
  
  /**
   * The function to initialize the drawing of the fly Eye
   */
  void
  onClick();

 public:

  bool m_clicked;

};
