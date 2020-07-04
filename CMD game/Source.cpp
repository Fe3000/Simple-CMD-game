#include <iostream>
using namespace std;

#include "olcConsoleGameEngine.h"

class Game : public olcConsoleGameEngine
{
public:
	Game() {}
protected:
	virtual bool OnUserCreate()
	{
		return true;
	}
	virtual bool OnUserUpdate(float fElapsedTime)
	{
		if (m_keys[VK_LEFT].bHeld)
			m_fPlayerX -= 20 * fElapsedTime;
		if (m_keys[VK_RIGHT].bHeld)
			m_fPlayerX += 20 * fElapsedTime;

		Fill(0, 0, m_nScreenWidth, m_nScreenHeight, L' ', 0);
		Fill((int)m_fPlayerX, (int)m_fPlayerY, m_fPlayerX + 5, m_fPlayerY + 7);

		return true;
	}	
private:
	float m_fPlayerX;
	float m_fPlayerY=50;
};

int main()
{
	Game game;
	game.ConstructConsole(160, 100, 10, 10);
	game.Start();


	return 0;
}