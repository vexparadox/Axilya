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
 * The AXPrefabManager allows users to store AXEntities in a template-style format and recall them later by name.
 */
#ifndef AXPrefabManager_hpp
#define AXPrefabManager_hpp

#include <unordered_map>
#include <iostream>
class AXEntity;
class AXPrefabManager final{
    AXPrefabManager(){};
    ~AXPrefabManager();
    AXPrefabManager(const AXPrefabManager& p) = delete;
    AXPrefabManager(const AXPrefabManager&& p) = delete;
    AXPrefabManager& operator= (const AXPrefabManager& o) = delete;
    static AXPrefabManager* instance;
    std::unordered_map<std::string, AXEntity*> entityMap;
public:
	static AXPrefabManager* getInstance();
	bool addPrefab(AXEntity* e);
	AXEntity* getPrefab(const std::string& name);
	bool doesPrefabExist(const std::string& name);
};

#endif