//
//  Text.hpp
//  Project2
//
//  Created by William Meaton on 17/03/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#ifndef Text_hpp
#define Text_hpp

#include <stdio.h>
#include "dT/drawtext.h"
#include <iostream>
#include "GLFW/glfw3.h"
#include "Vector2D.h"
namespace Graphics{
    class Text{
        struct dtx_font *font;
        float size = 24;
        bool loaded = false;
    public:
        Text();
        /*!
        * Creates a new Text object
        * @param size string to be drawn
        * @param load whether the glyphmap will be loaded or not
        */
        Text(float size, bool load);
        /*!
        * Will draw the given string at x, y
        * @param str string to be drawn
        * @param x the x position of the string
        * @param y the y position of the string
        * @see Text::draw(const std::string &str, const Math::Vector2D &v)
        */
        void draw(const std::string &str, float x, float y);
        void draw(const std::string &str, const Math::Vector2D &v);
        /*!
        * Loads the glyphmap for Text
        * Can be called by the Text constructor
        * Required before drawing
        * @param size the scaled size the glyphmap will be loaded at
        */
        void loadGlyphmap(float size);
          /*!
        * Changes the set size of the Text
        * @param size sets the size of the Text being drawn
        */
        void setSize(int size);
    };
}
#endif /* Text_hpp */
