/*
   File:        GameFactory.cpp
   Objective:	Designm�nster DT063G - Abstract Factory
   Last change: feb 2014 / Orjan Sterner
*/

#include "GameFactory.h"
#include "Obstacle.h"
#include "Action.h"

#include <vector>
#include <string>

using std::string;
using std::vector;

NastyGameFactory *NastyGameFactory::instance = nullptr;
NiceGameFactory *NiceGameFactory::instance = nullptr;

/* Implementationer av konkreta factoryklasser */

vector<Obstacle *> NiceGameFactory::makeObstacles()
{
    //     I ett 'Nice Game' ing�r f�ljande hinder:
    //     Wizard, Wall, Elephant, DPexam
    vector<Obstacle *> obstacles{
        new Wizard(),
        new Wall(),
        new Elephant(),
        new DPexam(),
    };

    return obstacles;
}

vector<Action *> NiceGameFactory::makeActions()
{
    //     BowAndShakeHandsAction, RunAndHideAction, BargainAndBuyAction,
    //     ChainsawAction, ClimbAction, CastAspellAction, SurrenderActio
    vector<Action *> actions = {
        new BowAndShakeHandsAction(),
        new RunAndHideAction(),
        new BargainAndBuyAction(),
        new ChainsawAction(),
        new ClimbAction(),
        new CastAspellAction(),
        new SurrenderAction()};

    return actions;
}

Player *NiceGameFactory::makePlayer()
{
    return new OrdinaryPlayer();
}
string NiceGameFactory::setGameTitle()
{
    return "Nice game";
}

vector<Obstacle *> NastyGameFactory::makeObstacles()
{
    //    I ett 'Nasty Game' ing�r f�ljande hinder:Dragon, Bomb, Samuray, SumoWrestler, Gangster
    vector<Obstacle *> obstacles{
        new Dragon(),
        new Bomb(),
        new Samuray(),
        new SumoWrestler(),
        new Gangster()};

    return obstacles;
}

vector<Action *> NastyGameFactory::makeActions()
{
    // BowAndShakeHandsAction, RunAndHideAction, SwordAction, RifleAction, OfferFoodAction, ChainsawAction, CastAspellAction, BargainAndBuyAction, SurrenderAction

    vector<Action *> actions = {
        new BowAndShakeHandsAction(),
        new RunAndHideAction(),
        new SwordAction(),
        new RifleAction(),
        new OfferFoodAction(),
        new ChainsawAction(),
        new CastAspellAction(),
        new BargainAndBuyAction(),
        new SurrenderAction()};

    return actions;
}

Player *NastyGameFactory::makePlayer()
{
    return new HeroPlayer();
}
string NastyGameFactory::setGameTitle()
{
    return "Nasty Game";
}