#pragma once
#define TYPE 5
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;


class Golem
{
    public:
        Golem(float posx,float posy);
        virtual ~Golem();
        void update(const Vector2f& playerPosition);
        void render(RenderTarget& target) const;
        Vector2f getPosition() const;
        void intvariables();
        int getheal() const;
        float spawntimerMax;
    private:
        CircleShape Gloem;
        int HP;
        int HPMAX;
        int Heal;
        int POINT;
        float spawntimer;
        float speedGolem;

    void setGolem();
};

void Golem::setGolem() {
    int type = rand() % 5;
    if (type == 0) {
        HPMAX = 10;
        Heal = rand() % 1 + 5;
    }
    else if (type == 1) {
        HPMAX = 20;
        Heal = rand() % 5 + 10;
    }
    Golem.setRadius(static_cast<float>(rand() % 20 + 20)); งงว่าคืออะไรกำลังทำอยู่
    Golem.setPointCount(rand() % 100 + 3);
    Golem.setFillColor(Color(rand() % 200 + 1, rand() % 255 + 2, rand() % 255 + 3, 255)); 
    
}


void Golem::intvariables() {

    POINT = 3;
    speedGolem = 4.f;
}

Enemy::Golem(float posx, float posy)
{
    setGolem();
    intvariables();
    Golem.setPosition(posx, posy);
}

int Golem::getHeal() const {
    return Heal;
}

Golem::~Golem()
{
}

void Golem::update(const Vector2f& playerPosition) {
    Vector2f direction = playerPosition - Golem.getPosition();
    float length = sqrt(direction.x * direction.x + direction.y * direction.y);
    direction /= length;
    Golem.move(direction * speedGolem);
}

void Golem::render(RenderTarget& target) const {
    target.draw(Golem);
}

Vector2f Golem::getPosition() const {
    return Golem.getPosition();
}