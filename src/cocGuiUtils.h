#pragma once

#include "cinder/Cinder.h"

#include "cinder/app/App.h"
#include "cinder/gl/gl.h"
#include "cinder/Utilities.h"
#include <iostream>


namespace coc {
    
    /*
     Edits imgui.ini file to move GUI to different display on restart
     Assumes displays are same width in single row
     Requires that all windows have already saved coords to file

     e.g. in app Setup():
     XmlTree xml(loadAsset("config/GuiDisplay.xml"));
     int d = xml.getChild("config/display").getValue<int>();
     int w = xml.getChild("config/width").getValue<int>();
     coc::moveGuiToDisplay(d, w);
     */

    static void moveGuiToDisplay( int _id, int _width )
    {
        
        std::string path = ( ci::app::getAssetPath( "" ) / "imgui.ini" ).string();
        std::ifstream fileIn(path.c_str());
        std::string line;
        std::string newFile = "";
        
        while (std::getline(fileIn, line))
        {
            if (line.substr(0,4) == "Pos=") {
                std::vector<std::string> splits = ci::split(line,',');
                int i = ci::fromString<int>(splits[0].substr(4,splits[0].size()-1));
                int offsetX = _id * _width;
                i = i%_width + offsetX;
                std::string newLine = "Pos=" + ci::toString(i) + "," + splits[1] + '\n';
                newFile += newLine;
            } else {
                newFile += line + '\n';
            }
        }
        fileIn.close();
        
        std::ofstream fileOut(path.c_str());
        fileOut << newFile;
        fileOut.close();
        
    }
    
}//namespace coc
