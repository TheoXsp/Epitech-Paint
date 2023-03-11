//
// Created by xspir0w on 09/03/23.
//

#ifndef PAINT_RENDERER_HPP
#define PAINT_RENDERER_HPP

#include "core.hpp"
#include "frames.hpp"

class Renderer {
    public:
        Renderer(int width, int height, const std::string& title);
        void eventHandler(Frame &currentFrame);
        void run();
        virtual ~Renderer() = default;

    private:
        sf::RenderWindow _window;
        sf::Event _event;
        std::vector<Frame> _frames;
};

#endif //PAINT_RENDERER_HPP
