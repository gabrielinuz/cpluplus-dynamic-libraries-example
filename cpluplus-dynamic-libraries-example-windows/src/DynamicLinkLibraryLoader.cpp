/**
 *  Copyright 2015 Gabriel Nicolás González Ferreira <gabrielinuz@gmail.com>
 *
 *  Permission is hereby granted, free of charge, to any person obtaining
 *  a copy of this software and associated documentation files (the
 *  "Software"), to deal in the Software without restriction, including
 *  without limitation the rights to use, copy, modify, merge, publish,
 *  distribute, sublicense, and/or sell copies of the Software, and to
 *  permit persons to whom the Software is furnished to do so, subject to
 *  the following conditions:
 *
 *  The above copyright notice and this permission notice shall be
 *  included in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 *  LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 *  OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 *  WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
**/

#include "../include/DynamicLinkLibraryLoader.h"

DynamicLinkLibraryLoader* DynamicLinkLibraryLoader::m_instance = 0;

DynamicLinkLibraryLoader::DynamicLinkLibraryLoader()
{
    //ctor
}

DynamicLinkLibraryLoader::~DynamicLinkLibraryLoader()
{
    //dtor
}

DynamicLinkLibraryLoader* DynamicLinkLibraryLoader::getInstance()
{
    if(m_instance == 0)
    {
        m_instance = new DynamicLinkLibraryLoader();
    }
    return m_instance;
}

void* DynamicLinkLibraryLoader::loadLibrary(string name)
{
    name += ".dll";
    return m_library = (void*) LoadLibrary(name.c_str());
}

void* DynamicLinkLibraryLoader::getMethod(string name)
{
    return m_method = (void*) GetProcAddress((HINSTANCE)m_library, name.c_str());
}

bool DynamicLinkLibraryLoader::freeLibrary()
{
    return FreeLibrary((HINSTANCE)m_library);
}
