/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file Textbox.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/15 2018
 * @brief Text box for user inputs
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/

#pragma once
#include "Utilities.h"

/**
* TextBox
* Description:
*   A simple textBox for user string input
* Sample usage:
* 	TextBox.insert() gives the textbox the text the user inserted
*/
class TextBox
{
 public:
  
  /**
   * Default constructor
   */
  TextBox() = default;

  /**
   * Default destructor
   */
  ~TextBox() = default;
   
  /**
   * @brief Inserts the user input into the text box
   * @param user data: the string to insert
   * @return --
   * 
   */
  void 
  insertData(std::string userData);

  /**
   * Member declaration
   */
 public:

  /**
   * SFML text output to show user input
   */
   sf::Text m_text;

  /**
   * SFML text box as boundary for the text
   */
   sf::RectangleShape m_box;
};
