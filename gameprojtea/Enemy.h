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
	CircleShape enemy;
	int HP;
	int HPMAX;
	int DAMAGE;
	int POINT;
	float speedenemy;

	void setenemy();
	void intvariables();
};

void Enemy::setenemy() {
	enemy.setRadius(rand() % 20 + 20);
	enemy.setPointCount(rand() % 100 + 3);
	enemy.setFillColor(Color(rand() % 200 + 1, rand() % 255 + 2, rand() % 255 + 3, 255));
}

void Enemy::intvariables() {
	HP = rand() % 50 + 100;
	HPMAX = 100;
	DAMAGE = rand() % 5 + 20;
	POINT = 1;
	speedenemy = 10.f;
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