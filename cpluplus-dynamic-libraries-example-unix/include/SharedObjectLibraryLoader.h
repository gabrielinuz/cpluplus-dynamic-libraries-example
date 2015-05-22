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

#ifndef SHAREDOBJECTLIBRARYLOADER_H
#define SHAREDOBJECTLIBRARYLOADER_H

#define RTLD_LAZY   1
#define RTLD_NOW    2
#define RTLD_GLOBAL 4

#include "ILibraryLoader.h"
#include <string>
#include <iostream>
#include "dlfcn.h"

class SharedObjectLibraryLoader : public ILibraryLoader
{
    public:
        virtual ~SharedObjectLibraryLoader();
        static SharedObjectLibraryLoader* getInstance();

        void* loadLibrary(string name);
        void* getMethod(string name);
        bool freeLibrary();

    protected:
        SharedObjectLibraryLoader();

    private:
        static SharedObjectLibraryLoader* m_instance;
        void* m_library;
        void* m_method;
};

#endif // SHAREDOBJECTLIBRARYLOADER_H
