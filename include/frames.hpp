//
// Created by xspir0w on 09/03/23.
//

#ifndef PAINT_FRAMES_HPP
#define PAINT_FRAMES_HPP

#include "core.hpp"

class Frame {
    public:
        Frame(int width, int height);
        sf::Sprite getFrameSprite() const;
        void updatePixels(std::vector<sf::Uint8> pixels, int x, int y, short size);
        virtual ~Frame() = default;

    private:
        sf::Sprite _frameSprite;
        sf::Texture _frameTexture;
};

#endif //PAINT_FRAMES_HPP
