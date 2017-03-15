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
 * This class describes a AXTriangle shape.
 */

#ifndef AXTriangle_h
#define AXTriangle_h
#include "AXVector2D.h"
class AXTriangle{
    AXVector2D v1, v2, v3;
public:
    AXTriangle(const AXVector2D &v1, const AXVector2D &v2, const AXVector2D &v3){
        this->v1=v1;
        this->v2=v2;
        this->v3=v3;
    }
    AXTriangle(float x1, float y1, float x2, float y2, float x3, float y3){
        this->v1 = AXVector2D(x1, y1);
        this->v2 = AXVector2D(x2, y2);
        this->v3 = AXVector2D(x3, y3);
    }
    
    void set(const AXVector2D &v1, const AXVector2D &v2, const AXVector2D &v3){
        this->v1=v1;
        this->v2=v2;
        this->v3=v3;
    }
    
    void set(float x1, float y1, float x2, float y2, float x3, float y3){
        this->set(AXVector2D(x1, y1), AXVector2D(x2, y2), AXVector2D(x3, y3));
    }
    
    const AXVector2D& getV1() const {
        return v1;
    }
    
    const AXVector2D& getV2() const{
        return v2;
    }
    
    const AXVector2D& getV3() const{
        return v3;
    }
};
#endif /* Triangle_h */
