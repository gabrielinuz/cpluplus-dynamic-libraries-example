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
#include "include/DynamicLinkLibraryLoader.h"

using namespace std;

int main()
{
    //THE LOADER:
    ILibraryLoader* loader = DynamicLinkLibraryLoader::getInstance();

    //LOAD
    void* load = loader->loadLibrary("./lib/libgreeter");

    if(load)
    {
        typedef bool (*test_type) (string);
        test_type isInstanceOf = (test_type) loader->getMethod("instanceOf");
        //TEST TYPE
        if(!isInstanceOf("IGreeter"))
        {
            cout << "The object is not instance of IGreeter!" << endl;
        }
        else
        {
            //CREATE GREETER
            typedef IGreeter* (*create_greeter_type) ();
            create_greeter_type createGreeter = (create_greeter_type) loader->getMethod("create");
            IGreeter* greeter = createGreeter();

            greeter->greet("Hello World!");

            //DELETE GREETER
            delete greeter;
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
