#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
//#include "Player.h"
using namespace sf;

class Enemy
{
public:
	Enemy(float posx, float posy);
	//void returnenemydamage(int);
	//void returnenemyHP(int);
	Enemy():health(100){}//constructor to initialie heath to 100
	virtual ~Enemy();
	int getDamage() const;
	void takeDamage(int damage);
		health -= damage;
		if(health<=0){
			std::count<<"Enemy defeated!"<<std::endl;
			delete this;//Delete the enemy if health is zero
		}
	}
	int getHealth() const{
		return health;
	}
	void update(const Vector2f& playerPosition);
	void render(RenderTarget& target) const;
	Vector2f getPosition() const;
private:
	int HP;//Enemy's health points
	int HPMAX;
	int DAMAGE;
	int POINT;
	int NewHp;
	int health;
	float speedenemy;
	Texture enemytexture;
	Sprite enemy;

	void setenemy();
	void intvariables();
};
#endif // ENEMY_H

