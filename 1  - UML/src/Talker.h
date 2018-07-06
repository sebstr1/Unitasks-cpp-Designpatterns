/* 2018-03-14
* Namn: Sebastian Strindlund
*/

#ifndef TalkerH
#define TalkerH

using namespace std;

class Talker {
public:
	Talker() {}
	virtual ~Talker() {}
	virtual void saySomething() const = 0;
};
#endif