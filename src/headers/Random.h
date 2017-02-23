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
 * An unfinished random class that will return random numbers.
 */
#ifndef Random_h
#define Random_h

namespace Math {
    class random {
        int seed;
    public:
        random(unsigned seed = 0x9bac7615) : seed(seed) {
        }
        
        void set_seed(unsigned seed) {
            this->seed = seed;
        }
        
        // get a floating point value
        float get(float min, float max) {
            // todo: test for period
            seed = ( ( seed >> 31 ) & 0xa67b9c35 ) ^ ( seed << 1 );
            seed = ( ( seed >> 31 ) & 0xcb73194c ) ^ ( seed << 1 );
            return min + ( ( seed >> 8 ) & 0xffff ) * ( ( max - min ) / 0xffff );
        }
        
        // get an int value in a small range
        int get(int min, int max) {
            assert(max - min <= 0x7fff);
            seed = ( ( seed >> 31 ) & 0xa67b9c35 ) ^ ( seed << 1 );
            return min + ( ( seed >> 8 ) & 0xffff ) * ( max - min ) / 0xffff;
        }
        
        // get an value between 0 and 0xffff
        unsigned get0xffff() {
            seed = ( ( seed >> 31 ) & 0xa67b9c35 ) ^ ( seed << 1 );
            return ( ( seed >> 8 ) & 0xffff );
        }
    };
} }


#endif /* Random_h */
