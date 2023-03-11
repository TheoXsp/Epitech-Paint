//
// Created by xspir0w on 09/03/23.
//

#include "frames.hpp"

FrameBuffer::FrameBuffer(int width, int height, sf::Color defaultColor) : _width(width), _height(height) {
    _frameBuffer.resize(width * height * 4);
    for (int i = 0; i < width * height * 4; i += 4) {
        _frameBuffer[i] = defaultColor.r;
        _frameBuffer[i + 1] = defaultColor.g;
        _frameBuffer[i + 2] = defaultColor.b;
        _frameBuffer[i + 3] = defaultColor.a;
    }
}

void FrameBuffer::setPixel(int x, int y, sf::Color color) {
    int index = (x + y * _width) * 4;

    _frameBuffer[index] = color.r;
    _frameBuffer[index + 1] = color.g;
    _frameBuffer[index + 2] = color.b;
    _frameBuffer[index + 3] = color.a;
}

std::vector<sf::Uint8>& FrameBuffer::getFrameBuffer() {
    return _frameBuffer;
}

int FrameBuffer::getWidth() const {
    return _width;
}

int FrameBuffer::getHeight() const {
    return _height;
}

// -----------------------------

Frame::Frame(FrameBuffer frameBuffer) : _frameBuffer(frameBuffer) {
    _frameTexture.create(_frameBuffer.getWidth(), _frameBuffer.getHeight());
    _frameTexture.update(_frameBuffer.getFrameBuffer().data());
    _frameSprite.setTexture(_frameTexture);
}

sf::Sprite Frame::getFrameSprite() const {
    return _frameSprite;
}

void Frame::updatePixels(int x, int y, sf::Color color) {
    _frameBuffer.setPixel(x, y, color);
    _frameTexture.update(_frameBuffer.getFrameBuffer().data());
}