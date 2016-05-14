//
//  Random.h
//  Project2
//
//  Created by William Meaton on 05/02/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

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
