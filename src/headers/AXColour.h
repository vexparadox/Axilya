/**
 * @file
 * @author William Meaton <will.meaton@gmail.com>
 *
 * @section LICENSE
 *
 * The MIT License
 * 
 * Copyright (c) 2017 WillMeaton http://willmeaton.com
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * @section DESCRIPTION
 *
 * This class describes a AXColour class, it carries RGBA values from 0-255.
 */
#ifndef AXColour_h
#define AXColour_h
#include <SDL2/SDL.h>
class AXColour{
    //#todo add static presets
    float r, g, b, a;
public:
    /*!
    * The constructor for this AXColour
    *
    * Note that values will be clamped to 0-255
    * @param r the red value of this AXColour (0-255)
    * @param g the green value of this AXColour (0-255)
    * @param b the blue value of this AXColour (0-255)
    * @param a the alpha value of this AXColour (0-255)
    */ 

    AXColour(float r, float g, float b, float a) {
        colourAssign(this->r, r);
        colourAssign(this->g, g);
        colourAssign(this->b, b);
        colourAssign(this->a, a);
    }

    /*!
    * The constructor for this AXColour
    *
    * Note that values will be clamped to 0-255
    * @param r the red value of this AXColour (0-255)
    * @param g the green value of this AXColour (0-255)
    * @param b the blue value of this AXColour (0-255)
    * The alpha value is set to 255
    */ 

    AXColour(float r, float g, float b) {
        colourAssign(this->r, r);
        colourAssign(this->g, g);
        colourAssign(this->b, b);
        colourAssign(this->a, 255);
    }

    /*!
    * The constructor for this AXColour
    *
    * Note that values will be clamped to 0-255
    * @param gr is the greyscale value of this AXColour (0-255)
    * The alpha value is set to 255
    */ 

    AXColour(float gr) {
        colourAssign(this->r, gr);
        colourAssign(this->g, gr);
        colourAssign(this->b, gr);
        colourAssign(this->a, 255);
    }

    /*!
    * The constructor for this AXColour
    *
    * Note that values will be clamped to 0-255
    * @param gr is the greyscale value of this AXColour (0-255)
    * @param a the alpha value of this AXColour (0-255)
    */ 

    AXColour(float gr, float a) {
        colourAssign(this->r, gr);
        colourAssign(this->g, gr);
        colourAssign(this->b, gr);
        colourAssign(this->a, a);
    }
    /*!
    * The constructor for this AXColour
    *
    * The r, g, b values will be set to 0 by default
    * The a value will be set to 255
    */ 
    AXColour(){
        r = 0;
        g = 0;
        b = 0;
        a = 255;
    }
    /*!
    * A method to set this AXColour's values
    *
    * Note that values will be clamped to 0-255
    * @param r the red value to set this AXColour (0-255)
    * @param g the green value to set this AXColour (0-255)
    * @param b the blue value to set this AXColour (0-255)
    * @param a the alpha value to set this AXColour (0-255)
    */ 
    void set(float r, float g, float b, float a){
        colourAssign(this->r, r);
        colourAssign(this->g, g);
        colourAssign(this->b, b);
        colourAssign(this->a, a);
    }
    /*!
    * A method to get the red value
    *
    * @return The red value of this AXColour
    */ 
    float getR() const{
        return r;
    }
    /*!
    * A method to get the green value
    *
    * @return The green value of this AXColour
    */ 
    float getG() const{
        return g;
    }
    /*!
    * A method to get the blue value
    *
    * @return The blue value of this AXColour
    */ 
    float getB() const{
        return b;
    }
    /*!
    * A method to get the alpha value
    *
    * @return The alpha value of this AXColour
    */ 
    float getA() const{
        return a;
    }
    /*!
    * A method to get an SDL_Color from this AXColour
    *
    * @return a SDL_Color
    */
    SDL_Color toSDL(){
        SDL_Color color = {(Uint8)r, (Uint8)g, (Uint8)b, (Uint8)a};
        return color;
    }
    inline AXColour& operator- (const AXColour& c){
        colourAssign(this->r, (this->r - c.r));
        colourAssign(this->g, (this->g - c.g));
        colourAssign(this->b, (this->b - c.b));
        colourAssign(this->a, (this->a - c.a));
        return *this;
    }
    
    friend inline void operator-= (AXColour& c1, const AXColour& c2){
        c1 = c1-c2;
        return;
    }
    
    inline AXColour& operator+ (const AXColour& c){
        colourAssign(this->r, (this->r + c.r));
        colourAssign(this->g, (this->g + c.g));
        colourAssign(this->b, (this->b + c.b));
        colourAssign(this->a, (this->a + c.a));
        return *this;
    }
    
    friend inline void operator+= (AXColour& c1, const AXColour& c2){
        c1 = c1+c2;
        return;
    }
private:
    inline void colourAssign(float &c, float input){
        if(input >= 255){
            c = 255;
            return;
        }
        if(input <= 0){
            c = 0;
            return;
        }
        c = input;
    }
};
#endif /* Colour_h */
