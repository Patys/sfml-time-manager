#pragma once

#include <SFML/Graphics.hpp>
#include <functional>

class Time {
public:
  Time()
  {
    time = 100;
    deltaTime = sf::milliseconds(time);
    paused = false;
  }

  void update(std::function<void ()> func)
  {
    if (paused) return;

    elapsedTime += clock.restart();
    if(elapsedTime >= deltaTime) {
      // run sth
      func();
      // run sth ^
      elapsedTime -= deltaTime;
      ticks++;
    }
  }

  void setSpeedFactor(float factor)
  {
    resume();
    deltaTime = sf::milliseconds(time / factor);
  }

  void pause()
  {
    paused = true;
  }

  void resume()
  {
    paused = false;
    deltaTime = sf::milliseconds(time);
    elapsedTime = sf::milliseconds(0);
    clock.restart();
  }

  void togglePause()
  {
    if (paused) resume();
    else pause();
  }

  sf::Time getDelta()
  {
    return deltaClock.restart();
  }

  std::string getGameDate()
  {
    int day = ticks % 30 + 1;
    int month = ticks / 30 % 12 + 1;
    int year = ticks / 30 / 12 + 1;

    std::string dayString = day > 9 ? std::to_string(day) : "0" + std::to_string(day);
    std::string monthString = month > 9 ? std::to_string(month) : "0" + std::to_string(month);
    std::string yearString =
      year < 10 ? "000" + std::to_string(year) :
      year > 10 && year < 100 ? "00" + std::to_string(year) :
      year > 100 && year < 1000 ? "0" + std::to_string(year) : std::to_string(year);

    return dayString + "." + monthString + "." + yearString;
  }
private:
  sf::Time elapsedTime;
  sf::Clock clock;
  sf::Time deltaTime;
  sf::Clock deltaClock;

  bool paused;
  float time;
  int ticks;
  std::string gameDate;
};
