#pragma once
#define TYPEENEMY 5
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace sf;

class Enemy
{
private:
    CircleShape enemy[TYPEENEMY];
    int HP[TYPEENEMY];
    int damage[TYPEENEMY];
    int point[TYPEENEMY];
    Vector2f playerPosition;

    void MoveEnemy(Vector2f playerPosition);
    void RendEnemy();

public:
    Enemy(Vector2f playerPosition);
    virtual ~Enemy();

    void CreateEnemy(Vector2f playerPosition);
    void update();
    void render(RenderTarget& target);
};

void Enemy::CreateEnemy(Vector2f playerPosition)
{
    for (int i = 0; i < TYPEENEMY; i++)
    {
        RendEnemy();

        enemy[i].setPosition(playerPosition.x + i * 50.f, playerPosition.y);
    }
}

void Enemy::RendEnemy()
{
    int type = rand() % TYPEENEMY;
    if (type == 0)
    {
        enemy[0].setFillColor(Color::Red);
        HP[0] = 50;
    }
    else if (type == 1)
    {
        enemy[1].setFillColor(Color::Yellow);
        HP[1] = 60;
    }
    else if (type == 2)
    {
        enemy[2].setFillColor(Color::Blue);
        HP[2] = 70;
    }
    else if (type == 3)
    {
        enemy[3].setFillColor(Color::Cyan);
        HP[3] = 80;
    }
    else if (type == 4)
    {
        enemy[4].setFillColor(Color::Green);
        HP[4] = 100;
    }
}

Enemy::Enemy(Vector2f playerPosition)
{
    this->playerPosition = playerPosition;
    CreateEnemy(playerPosition);
}

Enemy::~Enemy()
{
}

void Enemy::MoveEnemy(Vector2f playerPosition)
{
    for (int i = 0; i < TYPEENEMY; ++i)
    {
        Vector2f direction = playerPosition - enemy[i].getPosition();
        float magnitude = std::sqrt(direction.x * direction.x + direction.y * direction.y);
        if (magnitude > 1e-5)
        {
            direction /= magnitude;
            enemy[i].move(direction * 0.3f);
        }
    }
}

void Enemy::update()
{
    MoveEnemy(playerPosition);
}

void Enemy::render(RenderTarget& target)
{
    for (int i = 0; i < TYPEENEMY; ++i)
    {
        target.draw(enemy[i]);
    }
}
