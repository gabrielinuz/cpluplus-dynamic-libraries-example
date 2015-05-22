#ifndef LIBRARYLOADER_H
#define LIBRARYLOADER_H

#ifdef __unix__
    #define RTLD_LAZY   1
    #define RTLD_NOW    2
    #define RTLD_GLOBAL 4
    #include "dlfcn.h"

#elif defined(_WIN32) || defined(WIN32)
    #include <windows.h>
#endif // defined

#include "ILibraryLoader.h"
#include <string>
#include <iostream>

class LibraryLoader : public ILibraryLoader
{
    public:
        virtual ~LibraryLoader();
        static LibraryLoader* getInstance();

        void* loadLibrary(string name);
        void* getMethod(string name);
        bool freeLibrary();

    protected:
        LibraryLoader();

    private:
        static LibraryLoader* m_instance;
        void* m_library;
        void* m_method;
        bool m_freedom;
};

#endif // LIBRARYLOADER_H

