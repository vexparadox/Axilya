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
 * This class describes a Colour class, it carries RGBA values from 0-255.
 */
#ifndef Colour_h
#define Colour_h
#include <SDL2/SDL.h>
namespace AXGraphics{
    class Colour{
        //#todo add static presets
        float r, g, b, a;
    public:
        /*!
        * The constructor for this Colour
        *
        * Note that values will be clamped to 0-255
        * @param r the red value of this Colour (0-255)
        * @param g the green value of this Colour (0-255)
        * @param b the blue value of this Colour (0-255)
        * @param a the alpha value of this Colour (0-255)
        */ 

        Colour(float r, float g, float b, float a) {
            colourAssign(this->r, r);
            colourAssign(this->g, g);
            colourAssign(this->b, b);
            colourAssign(this->a, a);
        }
        /*!
        * The constructor for this Colour
        *
        * The r, g, b, a values will be set to 0 by default
        */ 
        Colour(){
            r = 0;
            g = 0;
            b = 0;
            a = 0;
        }
        /*!
        * A method to set this Colour's values
        *
        * Note that values will be clamped to 0-255
        * @param r the red value to set this Colour (0-255)
        * @param g the green value to set this Colour (0-255)
        * @param b the blue value to set this Colour (0-255)
        * @param a the alpha value to set this Colour (0-255)
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
        * @return The red value of this Colour
        */ 
        float getR() const{
            return r;
        }
        /*!
        * A method to get the green value
        *
        * @return The green value of this Colour
        */ 
        float getG() const{
            return g;
        }
        /*!
        * A method to get the blue value
        *
        * @return The blue value of this Colour
        */ 
        float getB() const{
            return b;
        }
        /*!
        * A method to get the alpha value
        *
        * @return The alpha value of this Colour
        */ 
        float getA() const{
            return a;
        }
        /*!
        * A method to get an SDL_Color from this Colour
        *
        * @return a SDL_Color
        */
        SDL_Color toSDL(){
            SDL_Color color = {(Uint8)r, (Uint8)g, (Uint8)b, (Uint8)a};
            return color;
        }
        inline Colour& operator- (const Colour& c){
            colourAssign(this->r, (this->r - c.r));
            colourAssign(this->g, (this->g - c.g));
            colourAssign(this->b, (this->b - c.b));
            colourAssign(this->a, (this->a - c.a));
            return *this;
        }
        
        friend inline void operator-= (Colour& c1, const Colour& c2){
            c1 = c1-c2;
            return;
        }
        
        inline Colour& operator+ (const Colour& c){
            colourAssign(this->r, (this->r + c.r));
            colourAssign(this->g, (this->g + c.g));
            colourAssign(this->b, (this->b + c.b));
            colourAssign(this->a, (this->a + c.a));
            return *this;
        }
        
        friend inline void operator+= (Colour& c1, const Colour& c2){
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
}

#endif /* Colour_h */
