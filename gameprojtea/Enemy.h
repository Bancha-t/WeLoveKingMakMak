#pragma once
#define TYPE 5
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
    void intvariables();
    int getDamage() const;
    float spawntimerMax;

private:
    CircleShape enemy;
    int HP;
    int HPMAX;
    int DAMAGE;
    int POINT;
    float spawntimer;

    float speedenemy;

    void setenemy();
};


void Enemy::setenemy() {
    //int type = rand() % 5;
    //if (type == 0) {
    //    HP = rand() % 5 + 10;
    //    HPMAX = 10;
    //    DAMAGE = rand() % 2 + 5;
    //}
    //else if (type == 1) {
    //    HP = rand() % 10 + 20;
    //    HPMAX = 20;
    //    DAMAGE = rand() % 5 + 10;
    //}
    //else if (type == 2) {
    //    HP = rand() % 15 + 30;
    //    HPMAX = 30;
    //    DAMAGE = rand() % 20 + 30;
    //}
    //else if (type == 3) {
    //    HP = rand() % 25 + 40;
    //    HPMAX = 40;
    //    DAMAGE = rand() % 5 + 20;
    //}
    //else if (type == 4) {
    //    HP = rand() % 80 + 100;
    //    HPMAX = 100;
    //    DAMAGE = rand() % 10 + 30;
    //}

    enemy.setRadius(static_cast<float>(rand() % 20 + 20));
    enemy.setPointCount(rand() % 100 + 3);
    enemy.setFillColor(Color(rand() % 200 + 1, rand() % 255 + 2, rand() % 255 + 3, 255));
}


void Enemy::intvariables() {

    POINT = 1;
    speedenemy = 2.f;
}

Enemy::Enemy(float posx, float posy)
{
    setenemy();
    intvariables();
    enemy.setPosition(posx, posy);
}

int Enemy::getDamage() const {
    return DAMAGE;
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

