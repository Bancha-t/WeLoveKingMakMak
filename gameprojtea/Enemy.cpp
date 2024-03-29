#include "Enemy.h"
void Enemy::setenemy() {
	if (!enemytexture.loadFromFile("C:/Users/User/Desktop/gameprojtea/photo/1ZA.png")) {
		std::cout << "Error loading texture: 1ZA.png" << std::endl;
	}
	else {
		std::cout << "Texture loaded successfully" << std::endl;
	}

	enemy.setTexture(enemytexture);
	enemy.setOrigin(0.f, 0.f);
	enemy.setScale(0.1f, 0.1f);

}
void Enemy::intvariables() {
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

int Enemy::getDamage() const
{
	return DAMAGE;
}

int Enemy::getHealth() const
{
	return health;
}

sf::FloatRect Enemy::getGlobalBounds() const {
	return enemy.getGlobalBounds();
}

void Enemy::reduceHealth(int amount) {
	health -= amount;
}

void Enemy::update(const Vector2f& playerPosition) {
	const float distanceThreshold = 400.0f;

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
	FloatRect enemyBounds = enemy.getGlobalBounds();
	RectangleShape borderRect(Vector2f(enemyBounds.width, enemyBounds.height));
	borderRect.setPosition(enemyBounds.left, enemyBounds.top);
	borderRect.setFillColor(Color::Transparent);
	borderRect.setOutlineColor(Color::Green);
	borderRect.setOutlineThickness(2.0f);
	target.draw(borderRect);
}

Vector2f Enemy::getPosition() const {
	return enemy.getPosition();
}
