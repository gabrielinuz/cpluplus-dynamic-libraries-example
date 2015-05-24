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

#include "../../include/IGreeter.h"

#include <iostream>
#include <gtk/gtk.h>
#include <string>

using namespace std;

class GtkGreeter : public IGreeter
{
    public:
        void greet(string message)
        {
            GtkWidget *window;
            GtkWidget *button;

            gtk_init (NULL, 0);

            window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

            gtk_signal_connect (GTK_OBJECT (window), "destroy",
                                    GTK_SIGNAL_FUNC (gtk_main_quit), NULL);

            gtk_container_border_width (GTK_CONTAINER (window), 10);

            string greeting;
            greeting = "I am the gtk greeter and the message is: "+message;
            button = gtk_button_new_with_label (greeting.c_str());

            gtk_container_add (GTK_CONTAINER (window), button);
            gtk_widget_show (button);

            gtk_widget_show (window);

            gtk_main ();
        }
};

extern "C"
{
    bool implements(string type)
    {
        return type == "IGreeter" ? true : false;
    }

    IGreeter* create()
    {
        return new GtkGreeter();
    }
}
