/**********************************************************************
*          Copyright (c) 2013, Hogeschool voor de Kunsten Utrecht
*                      Hilversum, the Netherlands
*                          All rights reserved
***********************************************************************
*  This program is free software: you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation, either version 3 of the License, or
*  (at your option) any later version.
*
*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with this program.
*  If not, see <http://www.gnu.org/licenses/>.
***********************************************************************
*
*  File name     : osc_server.h
*  System name   : osc++ : Open Sound Control
* 
*  Description   : Demo class using C++ wrapper for liblo
*
*
*  Author        : Marc_G
*  E-mail        : marcg@dinkum.nl
*
**********************************************************************/

#include <osc.h>

// subclass OSC into a local class so we can provide our own callback
class LocalOSC : public OSC {
    public:
  LocalOSC(float& parameterRef) : parameterReference(parameterRef){} 
    private:
  int realcallback (const char* path,
                    const char* types,
                    lo_arg** argv,
                    int argc) {
    string msgpath = path;

    cout << "path: " << msgpath << endl;
    if (! msgpath.compare ("/parameter")) {
        parameterReference = (float)argv[0]->f;
        cout << "Updated parameter to: " << parameterReference << endl;
    }
    return 0;
  }  // realcallback()
     
    float& parameterReference;   

};
