/*
   File: 		Obstacle.cpp
   Objective:	Designmönster DT063G - Abstract Factory
   Last change: feb 2014 / Orjan Sterner
*/

#include <cstdlib>
#include <ctime>
#include "Obstacle.h"

using std::cerr;
using std::endl;

void delay(int n); // Delay execution n seconds

bool Wall::tryToPass(Player *player, Action *pAct, ostream &os) {

     if(!pAct->doIt(player,os)) return false;
     os << "--> ";
     delay(ACTIONDELAY);

     if ((*pAct)() == "CastAspellAction") {
        os << "You cannot cast a spell on a wall.\n";
        return false;
     }
     if ((*pAct)() == "RunAndHideAction") {
        os << "No use hiding from a wall.\n";
        return false;
     }
     if ((*pAct)() == "BargainAndBuyAction") {
        os << "You cannot bargain with a wall.\n";
        return false;
     }
     if ((*pAct)() == "ClimbAction") {
        os << "Sorry, the wall is too high.\n";
        return false;
     }
     if ((*pAct)() == "BowAndShakeHandsAction") {
        os << "How do you shake hands with a wall?.\n";
        return false;
     }
     if ((*pAct)() == "ChainsawAction") {
        os << "Yes, the chainsaw gets you through!.\n";
        return true;
     }
     cerr << "Unknown action for Wall. Terminating.\n";
     exit(1);
     return false;
}

void Wall::show(ostream &os) {
     os << "\n>> Now you are standing in front of a huge wall.\n";
}


bool Elephant::tryToPass(Player *player, Action *pAct, ostream &os) {

     if(!pAct->doIt(player,os)) return false;
     os << "--> ";
     delay(ACTIONDELAY);

     if ((*pAct)() == "CastAspellAction") {
        os << "You cannot cast a spell on an an elephant.\n";
        return false;
     }
     if ((*pAct)() == "RunAndHideAction") {
        os << "Pure optimism, you can't outrun an elephant.\n";
        return false;
     }
     if ((*pAct)() == "BargainAndBuyAction") {
        os << "Elephants don't talk, do they?\n";
        return false;
     }
     if ((*pAct)() == "ChainsawAction") {
        os << "Oh no! That's too cruel!.\n";
        return false;
     }
     if ((*pAct)() == "BowAndShakeHandsAction") {
        os << "Shake foots you mean? No, this is ridiculous!\n";
        return false;
     }
     if ((*pAct)() == "ClimbAction") {
        os << "Congratulations, you are riding the elephant!\n";
        return true;
     }
     cerr << "Unknown action for Elephant. Terminating.";
     exit(1);
     return false;
}

void Elephant::show(ostream &os) {
     os << "\n>> You are now facing an enormous indian elephant.\n";
}

bool Wizard::tryToPass(Player *player, Action *pAct, ostream &os) {

     if(!pAct->doIt(player,os)) return false;
     os << "--> ";
     delay(ACTIONDELAY);

     if ((*pAct)() == "CastAspellAction") {
        os << "No way! Casting a spell on a wizard? Ha Ha!.\n";
        return false;
     }
     if ((*pAct)() == "RunAndHideAction") {
        os << "No use running. He will track you down.\n";
        return false;
     }
     if ((*pAct)() == "BargainAndBuyAction") {
        os << "Money is of no interest for a wizard.\n";
        return false;
     }
     if ((*pAct)() == "ClimbAction") {
        os << "No. He is too old and will probably die.\n";
        return false;
     }
     if ((*pAct)() == "ChainsawAction") {
        os << "No! You cannot be that blood thirsty!.\n";
        return false;
     }
     if ((*pAct)() == "BowAndShakeHandsAction") {
        os << "The wizard says 'Have a nice day young man'.\n";
        return true;
     }
     cerr << "Unknown action for Wall. Terminating.";
     exit(1);
     return false;
}

void Wizard::show(ostream &os) {
     os << "\n>> You meet with an old but mighty wizard.\n";
}


bool DPexam::tryToPass(Player *player, Action *pAct, ostream &os)
{

     if(!pAct->doIt(player,os)) return false;
     os << "--> ";
     delay(ACTIONDELAY);


     if ((*pAct)() == "RunAndHideAction") {
        os << "This will not help you pass.\n";
        return false;
     }
     if ((*pAct)() == "ChainsawAction") {
        os << "Brutal beast! Shame on you.\n";
        return false;
     }
     if ((*pAct)() == "CastAspellAction") {
        os << "Mambo-Jambo doesn't help you.\n";
        return false;
     }
     if ((*pAct)() == "BowAndShakeHandsAction") {
        os << "Very nice, but not enough.\n";
        player->decHealth();
        return false;
     }
     if ((*pAct)() == "ClimbAction") {
        os << "Hopeless.\n";
        return false;
     }
     if ((*pAct)() == "BargainAndBuyAction") {
        os << "Works every time...\n";
        return true;
     }

     cerr << "Unknown action for Exam. Terminating.";
     exit(1);
     return false;
}

void DPexam::show(ostream &os)
{
  os << "\n>> You have to pass an exam in Design patterns... \n";
}




bool Dragon::tryToPass(Player *player, Action *pAct, ostream &os) {

     if(!pAct->doIt(player,os)) return false;
     os << "--> ";
     delay(ACTIONDELAY);

     if ((*pAct)() == "SwordAction") {
        os << "The dragon blows a fire storm on you... You are badly hurt.\n";
        player->decHealth();
        return false;
     }
     if ((*pAct)() == "RifleAction") {
        os << "That doesn't affect the armoured dragon much.\n";
        return false;
     }
     if ((*pAct)() == "RunAndHideAction") {
        os << "Running will only buy you some time.\n";
        return false;
     }
     if ((*pAct)() == "ChainsawAction") {
        os << "Fatal. The dragon swallows both the chainsaw and you.\n";
        player->kill();
        return false;
     }
     if ((*pAct)() == "BowAndShakeHandsAction") {
        os << "He sure is not impressed.\n";
        return false;
     }
     if ((*pAct)() == "OfferFoodAction") {
        os << "You can only feed a dragon with yourself.\n";
        return false;
     }
     if ((*pAct)() == "BargainAndBuyAction") {
        os << "Dragons don't use money.\n";
        return false;
     }
     if ((*pAct)() == "CastAspellAction") {
        os << "You are lucky! The dragon was instantly turned into a frog!\n";
        return true;
     }
     cerr << "Unknown action for Dragon. Terminating.";
     exit(1);
     return false;
}

void Dragon::show(ostream &os) {
     os << "\n>> You encounter a red-eyed dragon with 10-inch teeth and smoking nostrils.\n";
}



bool Bomb::tryToPass(Player *player, Action *pAct, ostream &os) {

     if(!pAct->doIt(player,os)) return false;
     os << "--> ";
     delay(ACTIONDELAY);

     if ((*pAct)() == "SwordAction") {
        os << "BOOM!\n";
        player->kill();
        return false;
     }
     if ((*pAct)() == "RifleAction") {
        os << "KABOOM!\n";
        player->kill();
        return false;
     }
     if ((*pAct)() == "ChainsawAction") {
        os << "BAAAM!\n";
        player->kill();
        return false;
     }
     if ((*pAct)() == "BowAndShakeHandsAction") {
        os << "With a bomb? BOOM!\n";
        player->kill();
        return false;
     }
     if ((*pAct)() == "CastAspellAction") {
        os << "That doesn't help with a bomb.\n";
        return false;
     }
     if ((*pAct)() == "OfferFoodAction") {
        os << "Bombs don't eat, do they?\n";
        return false;
     }
     if ((*pAct)() == "BargainAndBuyAction") {
        os << "With a BOMB??\n";
        return false;
     }
     if ((*pAct)() == "RunAndHideAction") {
        os << "You got away with some injuries. You can continue.\n";
        player->decHealth();
        return true;
     }
     cerr << "Unknown action for Bomb. Terminating.";
     exit(1);
     return false;
}

void Bomb::show(ostream &os) {
     os << "\n>> You stumble over a smoking package labled 'TNT-Explosives'.\n";
}


bool Samuray::tryToPass(Player *player, Action *pAct, ostream &os) {

     if(!pAct->doIt(player,os)) return false;
     os << "--> ";
     delay(ACTIONDELAY);

     if ((*pAct)() == "SwordAction") {
        os << "That was a big mistake. You are very dead.\n";
        player->kill();
        return false;
     }
     if ((*pAct)() == "RifleAction") {
        os << "Before you have triggered you are missing your hand...\n";
        player->decHealth();
        return false;
     }
     if ((*pAct)() == "RunAndHideAction") {
        os << "Running will not save you.\n";
        return false;
     }
     if ((*pAct)() == "ChainsawAction") {
        os << "You shouldn't have. You are utmost dead.\n";
        player->kill();
        return false;
     }
     if ((*pAct)() == "CastAspellAction") {
        os << "Such Mambo-Jambo doesn't work with a samuray!\n";
        return false;
     }
     if ((*pAct)() == "OfferFoodAction") {
        os << "Sorry, he has just eaten a big portion of Sushi.\n";
        return false;
     }
     if ((*pAct)() == "BargainAndBuyAction") {
        os << "Money is of no interest for a real Samuray.\n";
        return false;
     }
     if ((*pAct)() == "BowAndShakeHandsAction") {
        os << "He bows, take your hands and show you the way.\n";
        return true;
     }
     cerr << "Unknown action for Samuray. Terminating.";
     exit(1);
     return false;
}

void Samuray::show(ostream &os) {
     os << "\n>> You encounter a Samuray swinging his sword...\n";
}

bool SumoWrestler::tryToPass(Player *player, Action *pAct, ostream &os) {

     if(!pAct->doIt(player,os)) return false;
     os << "--> ";
     delay(ACTIONDELAY);

     if ((*pAct)() == "SwordAction") {
        os << "A slice of pork falls to the ground. Thats all.\n";
        return false;
     }
     if ((*pAct)() == "RifleAction") {
        os << "The bullet is burried in a thick layer of pork. Thats all.\n";
        return false;
     }
     if ((*pAct)() == "RunAndHideAction") {
        os << "This will not help you pass.\n";
        return false;
     }
     if ((*pAct)() == "ChainsawAction") {
        os << "Your chainsaw is not powerful enough.\n";
        return false;
     }
     if ((*pAct)() == "CastAspellAction") {
        os << "Such Mambo-Jambo doesn't work with a real Sumo!\n";
        return false;
     }
     if ((*pAct)() == "BowAndShakeHandsAction") {
        os << "He bows... AND ATTACK YOU. You are flat and hurt.\n";
        player->decHealth();
        return false;
     }
     if ((*pAct)() == "BargainAndBuyAction") {
        os << "Money is of no interest for a real SUMO.\n";
        return false;
     }
     if ((*pAct)() == "OfferFoodAction") {
        os << "You pass silently while the Sumo concentrates on eating.\n";
        return true;
     }

     cerr << "Unknown action for SumoWrestler. Terminating.";
     exit(1);
     return false;
}

void SumoWrestler::show(ostream &os) {
     os << "\n>> You encounter a 256.7-kg Sumo wrestler...\n";
}


bool Gangster::tryToPass(Player *player, Action *pAct, ostream &os) {

     if(!pAct->doIt(player,os)) return false;
     os << "--> ";
     delay(ACTIONDELAY);

     if ((*pAct)() == "SwordAction") {
        os << "That was a big mistake. You are very dead.\n";
        player->kill();
        return false;
     }

     if ((*pAct)() == "RifleAction") {
        os << "He was twice as fast as you... Sorry , you are dead.\n";
        player->kill();
        return false;
     }

     if ((*pAct)() == "CastAspellAction") {
        os << "That doesn't impress the gun...\n";
        return false;
     }
     if ((*pAct)() == "RunAndHideAction") {
        os << "BAM! He shot you in your back.\n";
        player->decHealth();
        return false;
     }

     if ((*pAct)() == "OfferFoodAction") {
        os << "He is desperate, not hungry\n";
        return false;
     }
     if ((*pAct)() == "ChainsawAction") {
        os << "Very unwise. He shot you right in your heart.\n";
        player->kill();
        return false;
     }
     if ((*pAct)() == "BowAndShakeHandsAction") {
        os << "He is not impressed.\n";
        return false;
     }
     if ((*pAct)() == "BargainAndBuyAction") {
        os << "Very clever. You bought yourself a passage.\n";
        return true;
     }
     cerr << "Unknown action for Gangster. Terminating.";
     exit(1);
     return false;
}

void Gangster::show(ostream &os) {
     os << "\n>> You encounter a clean-cut gangster in a smart suit with a gun in his hand.\n";
}


void delay(int n) {
  long t = time(NULL);
  while(time(NULL) < (t+n)); // busy wait
}
