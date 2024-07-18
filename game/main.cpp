// OOP Game Project
// Dragon Game

#include <SFML/Graphics.hpp>
#include <time.h>
#include <cmath>
#include <iostream>
#include <random>
#include <string>
using namespace std;

class Dragon {
 private:
  sf::RectangleShape* body;
  int speed;
  int depth;

 public:
  Dragon(int x, int y, int depth) {
    body = new sf::RectangleShape(sf::Vector2f(depth, depth));
    body->setFillColor(sf::Color::White);
    body->setOrigin(depth / 2, depth / 2);
    body->setPosition(x, y);
  }

  void draw(sf::RenderWindow* win) { win->draw(*body); }

  int get_x() { return body->getPosition().x; }
  int get_y() { return body->getPosition().y; }
  int get_depth() { return depth; }

  void move_up(int speed) { body->move(0, -speed); }
  void move_right(int speed) { body->move(speed, 0); }
  void move_left(int speed) { body->move(-speed, 0); }
  void move_down(int speed) { body->move(0, speed); }
};

// The eggs class is an abstract function that has functions that will need to
// behave differently in all 4 coloured egg classes
class Eggs {
 public:
  virtual void spawn_egg(int x, int y) = 0;
  virtual void die() = 0;
};

class Dragon_egg : public Eggs {
 protected:
  sf::CircleShape* body;
  int egg_depth;

 public:
  Dragon_egg() {
    egg_depth = 30;
    body = new sf::CircleShape();
    body->setRadius(25);
    body->setOrigin(egg_depth / 2, egg_depth / 2);
    body->setPosition(-1, -1);
    srand(time(0));
  }
};

class Green_egg : public Dragon_egg {
 private:
  bool alive;

 public:
  Green_egg() {
  body->setFillColor(sf::Color(sf::Color::Green));
  alive=false;
   }

  int get_GE_X() { return body->getPosition().x; }
  int get_GE_Y() { return body->getPosition().y; }
  int get_egg_depth() { return egg_depth; }

  bool GE_eaten() { return alive; }

  void die() { alive = false; }

  bool isTouched(int x, int y, int depth) {
    bool Touched = false;
    int GE_X = get_GE_X();
    int GE_Y = get_GE_Y();
    float d = sqrt((x - GE_X) * (x - GE_X) + (y - GE_Y) * (y - GE_Y));
    if (d < (depth + egg_depth)) {
      Touched = true;
    }
    return Touched;
  }

  void spawn_egg(int GE_X, int GE_Y) {
    int rand_GY = rand() % GE_Y + 2;
    int rand_GX = rand() % GE_X + 2;
    body->setPosition(rand_GX, rand_GY);
    this->alive = true;
  }

  void draw(sf::RenderWindow* win) {
    if (this->alive) {
      win->draw(*body);
      if (body->getPosition().x < 0) {
        this->spawn_egg(win->getSize().x, win->getSize().y);
      }
    }
  }
};

/*
class Blue_egg : public Dragon_egg {
 private:
  bool alive;

 public:
  Blue_egg() { body->setFillColor(Color(Color::Blue)); }

  int get_BE_X() { return body->getPosition().x; }
  int get_BE_Y() { return body->getPosition().y; }
  int get_egg_depth() { return egg_depth; }

  bool BE_eaten() { return alive; }

  void die() { alive = false; }

  bool isTouched(int x, int y, int depth) {
    bool Touched = false;
    int BE_X = get_BE_X();
    int BE_Y = get_BE_Y();
    float d = sqrt((x - BE_X) * (x - BE_X) + (y - BE_Y) * (y - BE_Y));
    if (d < (depth + egg_depth)) {
      Touched = true;
    }
    return Touched;
  }

  void spawn_egg(int BE_X, int BE_Y) {
    int rand_BY = rand() % BE_Y + 2;
    int rand_BX = rand() % BE_X + 2;
    body->setPosition(rand_BX, rand_BY);
    this->alive = true;
  }

  void draw(RenderWindow* win) {
    if (this->alive) {
      win->draw(*body);
      if (body->getPosition().x < 0) {
        this->spawn_egg(win->getSize().x, win->getSize().y);
      }
    }
  }
};
*/


class Game {
 private:
  sf::RenderWindow* win;
  Green_egg* G_egg;
  Dragon* dragon;
  // Blue_egg* B_egg;
  int speed;
  int score;

 public:
  Game(int size) {
    win = new sf::RenderWindow(sf::VideoMode(size, size), "Game");
    G_egg = new Green_egg();
    // B_egg = new Blue_egg();
    dragon = new Dragon(10, 50, 50);
    speed = 11;
    score = 0;
  }

  void check_score() {
    if (G_egg->GE_eaten()) {
      if (G_egg->isTouched(dragon->get_x(), dragon->get_y(), dragon->get_depth())) {
        score++;
        G_egg->die();
        G_egg->spawn_egg(win->getSize().x - 100, win->getSize().y - 100);
        if (5 < speed && speed < 17) {
          speed--;
        }
      }
    }
    /*
    if (B_egg->isTouched(dragon->get_x(), dragon->get_y(),
                         dragon->get_depth())) {
      score = score + 2;
      B_egg->die();
      B_egg->spawn_egg(win->getSize().x - 100, win->getSize().y - 100);
    }
    */

  }

  void run() {
    while (win->isOpen()) {
      sf::Event e;
      while (win->pollEvent(e)) {
        if (e.type == sf::Event::Closed) {
          win->close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
          dragon->move_up(speed);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
          dragon->move_left(speed);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
          dragon->move_right(speed);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
          dragon->move_down(speed);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
          G_egg->spawn_egg(win->getSize().x - 100, win->getSize().y - 100);
        //  B_egg->spawn_egg(win->getSize().x - 100, win->getSize().y - 100);
        }
        win->clear();
        check_score();
        if (score < 0) {
          break;
        }
        G_egg->draw(win);
       // B_egg->draw(win);
        dragon->draw(win);
        win->display();
      }
    }
  }
  ~Game() {
    delete G_egg;
   // delete B_egg;
    delete dragon;
  }
};

int main() {
  Game g(1000);
  g.run();

  return 0;
}
