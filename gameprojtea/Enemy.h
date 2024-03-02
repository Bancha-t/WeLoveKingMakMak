#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class Enemy
{
public:
	Enemy(float posx, float posy);
	virtual ~Enemy();
	void update(const Vector2f& playerPosition);
	void render(RenderTarget& target) const;
	Vector2f getPosition() const;

private:
	int HP;
	int HPMAX;
	int DAMAGE;
	int POINT;
	float speedenemy;
	Texture enemytexture;
	Sprite enemy;

	void setenemy();
	void intvariables();
};

void Enemy::setenemy() {


	if (!enemytexture.loadFromFile("C:/Users/User/Desktop/gamenaja/main/png/player_2.png")) {
		std::cout << "Error loading texture: player_2.png" << std::endl;
	}
	enemy.setTexture(enemytexture);
}

void Enemy::intvariables() {
	HP = rand() % 50 + 100;
	HPMAX = 100;
	DAMAGE = rand() % 5 + 20;
	POINT = 1;
	speedenemy = 2.f;
}

Enemy::Enemy(float posx, float posy)
{
	setenemy();
	intvariables();
	enemy.setPosition(posx, posy);
}

Enemy::~Enemy()
{
}

void Enemy::update(const Vector2f& playerPosition) {

	Vector2f direction = playerPosition - enemy.getPosition();

	float length = sqrt(direction.x * direction.x + direction.y * direction.y);
	direction /= length;

	enemy.move(direction * speedenemy);
}

void Enemy::render(RenderTarget& target) const {
	target.draw(enemy);
}

Vector2f Enemy::getPosition() const {
	return enemy.getPosition();
}