/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file TextBox.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/10/15 2018
 * @brief TextBox member definition
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
#include "pch.h"
#include "Textbox.h"

void
TextBox::insertData(std::string userData) {
  m_text.setString(userData);
}