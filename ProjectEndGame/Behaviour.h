#pragma once

class Behaviour {
public:
	virtual ~Behaviour(void) { }
	virtual void update(float dt) = 0;

protected:
	Behaviour(void) { }
};