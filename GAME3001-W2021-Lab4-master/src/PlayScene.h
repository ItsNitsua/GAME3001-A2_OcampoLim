#pragma once
#ifndef __PLAY_SCENE__
#define __PLAY_SCENE__

#include "Scene.h"
#include "Button.h"
#include "Heuristic.h"
#include "Label.h"
#include "Obstacle.h"
#include "ship.h"
#include "SpaceShip.h"
#include "Target.h"
#include "Tile.h"

class PlayScene : public Scene
{
public:
	PlayScene();
	~PlayScene();

	// Scene LifeCycle Functions
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;

private:
	// IMGUI Function
	void GUI_Function();
	std::string m_guiTitle;
	glm::vec2 m_mousePosition;

	Target* m_pTarget;
	Ship* m_pShip;
	Label* m_pInstructionLabel;
	Label* m_pInstructionLabel2;
	Label* m_pInstructionLabel3;
	Label* m_pInstructionLabel4;
	Label* m_pInstructionLabel5;


	bool m_isGridEnabled;

	Obstacle* m_obstacle;
	
	// Pathfinding functions and objects
	void m_buildGrid();
	void m_computeTileCosts();
	void m_findShortestPath();
	void m_displayPathList();
	void m_setGridEnabled(bool state);
	bool m_getGridEnabled() const;
	std::vector<Tile*> m_pGrid;
	
	// convenience functions
	SDL_Rect m_pRect;
	Tile* m_getTile(int col, int row);
	Tile* m_getTile(glm::vec2 grid_postion);
	//heruristic
	Heuristic currentHeuristic;

	//open close and path list
	std::vector<Tile*> m_pOpenList;
	std::vector<Tile*> m_pClosedList;
	std::vector<Tile*> m_pPathList;

	void m_moveShip();
	int moveCounter = 0;
	bool m_shipIsMoving = false;
};

#endif /* defined (__PLAY_SCENE__) */
