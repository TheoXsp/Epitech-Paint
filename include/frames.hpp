//
// Created by xspir0w on 09/03/23.
//

#ifndef PAINT_FRAMES_HPP
#define PAINT_FRAMES_HPP

#include "core.hpp"

class FrameBuffer {
    public:
        FrameBuffer(int width, int height, sf::Color defaultColor);
        std::vector<sf::Uint8>& getFrameBuffer();
        void setPixel(int x, int y, sf::Color color);
        int getWidth() const;
        int getHeight() const;
        virtual ~FrameBuffer() = default;

    private:
        std::vector<sf::Uint8> _frameBuffer;
        int _width;
        int _height;
};

class Frame {
    public:
        Frame(FrameBuffer frameBuffer);
        sf::Sprite getFrameSprite() const;
        void updatePixels(int x, int y, sf::Color color);
        virtual ~Frame() = default;

    private:
        sf::Sprite _frameSprite;
        sf::Texture _frameTexture;
        FrameBuffer _frameBuffer;
};

#endif //PAINT_FRAMES_HPP
