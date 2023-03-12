//
// Created by xspir0w on 09/03/23.
//

#include "frames.hpp"

Frame::Frame(int width, int height) {
    _frameTexture.create(width, height);
    _frameSprite.setTexture(_frameTexture);
}

sf::Sprite Frame::getFrameSprite() const {
    return _frameSprite;
}

void Frame::updatePixels(std::vector<sf::Uint8> pixels, int x, int y, short size) {
    (x > 1920) ? x = 1920 : x;
    (y > 1080) ? y = 1080 : y;
    (x - size < 0) ? x = size : x;
    (y - size < 0) ? y = size : y;
    _frameTexture.update(pixels.data(), size, size, x - size, y - size);
}