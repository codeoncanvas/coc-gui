#pragma once

#include "cinder/app/App.h"
#include "cinder/Utilities.h"


namespace coc {
    
    /*
     Edits imgui.ini file to move GUI to different display on restart
     Assumes displays are same width in single row
     Requires that all windows have already saved coords to file
     */

    static void moveGuiToDisplay( int _id, int _width )
    {
        
        static string path = ( getAssetPath( "" ) / "imgui.ini" ).string();
        std::ifstream fileIn(path.c_str());
        std::string line;
        std::string newFile = "";
        
        while (std::getline(fileIn, line))
        {
            if (line.substr(0,4) == "Pos=") {
                std::vector<string> splits = split(line,',');
                int i = ci::fromString<int>(splits[0].substr(4,splits[0].size()-1));
                int offsetX = _id * _width;
                i = i%_width + offsetX;
                std::string newLine = "Pos=" + toString(i) + "," + splits[1] + '\n';
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
