/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file App.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/15 2018
 * @brief Application object to initiate everything
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
#pragma once

#include "Button.h"
#include "Textbox.h"
#include "Utilities.h"



/**
 * Line
 * Description:
 * 	a capsuled vertex to access to its shit
 * Sample usage:
 * 	drawLine
 */
class line 
{
public:
  /**
   * Constructor with a set of vectors that define starting point A and ending point B
   */
  line(sf::Vector2f a, sf::Vector2f b) {
    m_p[0].position = a;
    m_p[0].color = sf::Color::White;
    m_p[1].position = b;
    m_p[1].color = sf::Color::Blue;
  }
  
 public:
  sf::Vertex m_p[2];
};

 /**
  * lineSet
  * Description:
  * 	vector of lines but with mutex for handling
  * Sample usage:
  * 	
  */
class lineSet 
{
 public:


 public:

  std::vector<line> m_lineSet;

  std::mutex m_mutex;
};

/**
 * PointSet
 * Description:
 * 	a group of lines that will render per point
 * Sample usage:
 *
 */
class pointSet 
{
 public:

  /**
   * the amount of lines per point to draw
   */
  std::vector<line> m_linesPerPoint;

  /**
   * Tells to the thread or to the while that all the lines have been drawn;
   */
  bool m_finished;
};

/**
 * lineDrawer
 * Description:
 * 	thread handler that draws the lines with threads
 * Sample usage:
 *
 */
class lineDrawer
{
 public:
  void
  drawThreads(int amount, 
              int offset, 
              int linesPerSet, 
              lineSet& setLines, 
              std::vector<pointSet> points ) {

    for (int start = offset, i = 0; i < amount; ++i) {

      for (int j = 0; j < linesPerSet; ++j) {
        std::unique_lock<std::mutex> lock(setLines.m_mutex, std::try_to_lock);
        if (lock.owns_lock()) {
          //m_lineSet.m_mutex.lock();
          //lock.lock();
          setLines.m_lineSet.push_back(points[start + i].m_linesPerPoint[j]);
          //m_lineSet.m_mutex.unlock();
          lock.unlock();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
      }
      std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
  }
};

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
  initialize();

  /**
   * Rendering of objects inside
   */
  void
  onRender();

  /**
   * Updates the objects and polls for inputs
   */
  void
  onUpdate();

  /**
   * Checks everytime the user clicks
   */
  void
  onClick();

  /**
   * @brief Prepares the canvas to draw the fly eye 
   * @param 
   * @return 
   *
   */
  bool
  startCalculation();

  /**
   * @brief Sets the coordinates for all the lines to draw
   * @param 
   * @return 
   *
   */
  void
  setCoordinates();

  /**
   * @brief Sets all the lines before drawing them and sorts them so each point
   *  draws the same amount of lines
   * @param 
   * @return 
   *
   */
  void
  setLines();

  /**
   * @brief Draw with threads, sets how much each thread will draw
   * @param 
   * @return 
   *
   */
  void
  drawThreads(int amount, int offset);

  /**
   * @brief inserts the thread in a list with all the lines to render
   * @param the amount of threads to use (1 if not using threads)
   * @return
   *
   */
  void
  drawLines();

  /**
   * @brief sets the thread pool
   * @param 
   * @return 
   *
   */
  void
  startThreads();
  /**
   * Member declaration
   */
 public:

  /**
   * Window component to render stuff
   */
  sf::RenderWindow m_window;

  /**
   * Button for initialization of fly eye drawing with threads
   */
  Button m_threadStart;

  /**
   * Button for initialization of drawing
   */
  Button m_normalStart;

  /**
   * TextBox to say how many threads use
   */
  TextBox m_threadCount;

  /**
   * TextBox to tell how many lines in the Fly Eye
   */
  TextBox m_pointCount;

  /**
   * Circle as the Eye
   */
  sf::CircleShape m_circle;

  /**
   * Pointer to the selected textbox;
   */
  TextBox* m_currentTextBox;

  /**
   * Default font
   */
  sf::Font m_defaultFont;

  /**
   * Catches all number inputs
   */
  std::string m_catcher;

  /**
   * Center of the circle
   */
  sf::Vector2f m_center;

  /**
   * How many points are gonna be in the circle
   */
  int m_totalPoints;

  /**
   * list of all points to render
   */
  std::vector<sf::Vector2f> m_pointList;

  /**
   * list of all point sets
   */
  std::vector<pointSet> m_totalSets;

  /**
   * amount of threads to draw with
   */
  int m_totalThreads;

  /**
   * lines per set
   */
  int m_linesPerSet;

  /**
   * The lines to draw constantly
   */
  lineSet m_lineSet;

  int running = 0;
  int setRunning = 0;
};

