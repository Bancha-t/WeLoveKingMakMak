#include "Enemy.h"
void Enemy::setenemy() {
	if (!enemytexture.loadFromFile("C:/Users/User/Desktop/gamenaja/main/png/remo.png")) {
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

int Enemy::getDamage() const {
	return DAMAGE;
}

void Enemy::update(const Vector2f& playerPosition) {
	const float distanceThreshold = 500.0f;

	int randomDirection = rand() % 4;

	switch (randomDirection) {
	case 0:
		enemy.move(0.f, -speedenemy);
		break;
	case 1:
		enemy.move(0.f, speedenemy);
		break;
	case 2:
		enemy.move(-speedenemy, 0.f);
		break;
	case 3:
		enemy.move(speedenemy, 0.f);
		break;
	}

	if (rand() % 2 == 0) {
		randomDirection = rand() % 4;
		switch (randomDirection) {
		case 0:
			enemy.move(0.f, -speedenemy);
			break;
		case 1:
			enemy.move(0.f, speedenemy);
			break;
		case 2:
			enemy.move(-speedenemy, 0.f);
			break;
		case 3:
			enemy.move(speedenemy, 0.f);
			break;
		}
	}

	Vector2f direction = playerPosition - enemy.getPosition();
	float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

	if (distance < distanceThreshold) {
		direction /= distance;
		enemy.move(direction * speedenemy);
	}
}


void Enemy::render(RenderTarget& target) const {
	target.draw(enemy);
}

Vector2f Enemy::getPosition() const {
	return enemy.getPosition();
}