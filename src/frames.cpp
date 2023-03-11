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
    _frameTexture.update(pixels.data(), size, size, x - size, y - size);
}