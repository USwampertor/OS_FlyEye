// OS_FlyEye.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include "App.h"
int main()
{
  App mainApp;
  mainApp.initiate();
  mainApp.onUpdate();
  std::cout << "Hello World!\n"; 
}
