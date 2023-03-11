//
// Created by xspir0w on 09/03/23.
//

#include "renderer.hpp"

Renderer::Renderer(int width, int height, const std::string& title) : _window(sf::VideoMode(width, height), title) {
    _frames.emplace_back(FrameBuffer(width, height, sf::Color::Black));
}

void Renderer::eventHandler(Frame &currentFrame) {
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed)
            _window.close();
        if (_event.type == sf::Event::MouseButtonReleased)
            currentFrame.updatePixels(_event.mouseButton.x, _event.mouseButton.y, sf::Color::White);
    }
}

void Renderer::run() {
    Frame &currentFrame = _frames.back();

    while (_window.isOpen()) {
        eventHandler(currentFrame);
        _window.clear();
        for (auto &i : _frames) {
            _window.draw(i.getFrameSprite());
        }
        _window.display();
    }
}