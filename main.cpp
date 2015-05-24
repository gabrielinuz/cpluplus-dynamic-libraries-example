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

#include <iostream>
#include <string>

#include "include/IGreeter.h"
#include "include/ILibraryLoader.h"
#include "include/LibraryLoader.h"

using namespace std;

int main()
{
    //THE LOADER:
    ILibraryLoader* loader = LibraryLoader::getInstance();

    //LOAD
    void* load = loader->loadLibrary("./lib/libgreeter");

    if(load)
    {
        typedef bool (*test_type) (string);
        test_type implements = (test_type) loader->getExternalFunction("implements");
        //TEST TYPE
        if(implements("IGreeter"))
        {
            //CREATE GREETER
            typedef IGreeter* (*create_type) ();
            create_type createGreeter = (create_type) loader->getExternalFunction("create");
            IGreeter* greeter = createGreeter();

            greeter->greet("Hello World!");

            //DELETE GREETER
            delete greeter;
        }
        else
        {
            cout << "The object is not instance of IGreeter!" << endl;
        }
        //FREE LIBRARY
        loader->freeLibrary();
    }
    else
    {
        cout << "Failed to load the library" << endl;
    }

    return 0;
}
