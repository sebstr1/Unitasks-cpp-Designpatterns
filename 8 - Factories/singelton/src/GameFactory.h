/*
   File:        GameFactory.h
   Objective:	Designm�nster DT063G - Abstract Factory
   Last change: feb 2014 / Orjan Sterner
*/

#ifndef GameFactoryH
#define GameFactoryH

#include <vector>
#include <string>

using std::string;
using std::vector;

class Player;
class Obstacle;
class Action;

// GameFactory �r en abstrakt klass som definierar ett interface f�r
// deriverade konkreta klasser

class GameFactory
{
  protected:
    GameFactory() {}

  public:
    virtual ~GameFactory() = default;
    // Lämpliga operationer: se klassen Game.
    virtual vector<Obstacle *> makeObstacles() = 0;
    virtual vector<Action *> makeActions() = 0;
    virtual Player *makePlayer() = 0;
    virtual string setGameTitle() = 0;
};

class NiceGameFactory : public GameFactory
{
  private:
    static NiceGameFactory *instance;
    NiceGameFactory() {}

  public:
    virtual vector<Obstacle *> makeObstacles();
    virtual vector<Action *> makeActions();
    virtual Player *makePlayer();
    virtual string setGameTitle();
    static NiceGameFactory *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new NiceGameFactory;
        }
        return instance;
    }
    void destroy()
    {
        delete instance;
        instance = nullptr;
    }
};

class NastyGameFactory : public GameFactory
{
  private:
    static NastyGameFactory *instance;
    NastyGameFactory() {}

  public:
    virtual vector<Obstacle *> makeObstacles();
    virtual vector<Action *> makeActions();
    virtual Player *makePlayer();
    virtual string setGameTitle();
    static NastyGameFactory *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new NastyGameFactory;
        }
        return instance;
    }
    void destroy()
    {
        delete instance;
        instance = nullptr;
    }
};

#endif
