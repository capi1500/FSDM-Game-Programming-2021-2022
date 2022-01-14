#pragma once

#include "platformer/scene.hpp"
#include "box2d/b2_world.h"

class Play : public Scene{
    private:
        b2World b2World;
    public:
        void onNotify(const sf::Event &event) override;

    void update(const sf::Time &time) override;

    Play(StateMachine &stateMachine);
};

