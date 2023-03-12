//
// Created by xspir0w on 09/03/23.
//

#include "renderer.hpp"

Renderer::Renderer(int width, int height, const std::string& title) : _window(sf::VideoMode(width, height), title, sf::Style::Close) {
    _frames.emplace_back(width, height);
    _window.setFramerateLimit(144);
    _penSize = 5;
    _alpha = 255;
    _smooth = false;
    _penColor = sf::Color::White;
}

std::vector<sf::Uint8> Renderer::createUpdateFrame() const {
    std::vector<sf::Uint8> pixels;

    for (int i = 0; i < _penSize; i++) {
        for (int j = 0; j < _penSize; j++) {
            pixels.push_back(_penColor.r);
            pixels.push_back(_penColor.g);
            pixels.push_back(_penColor.b);
            pixels.push_back(_alpha);
        }
    }
    return pixels;
}

void Renderer::eventHandler(Frame &currentFrame) {
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed)
            _window.close();
        if (_event.type == sf::Event::MouseButtonPressed && _event.mouseButton.button == sf::Mouse::Left)
            currentFrame.updatePixels(createUpdateFrame(), _event.mouseButton.x, _event.mouseButton.y, _penSize);
        else if (_event.type == sf::Event::MouseMoved && sf::Mouse::isButtonPressed(sf::Mouse::Left))
            currentFrame.updatePixels(createUpdateFrame(), _event.mouseMove.x, _event.mouseMove.y, _penSize);
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