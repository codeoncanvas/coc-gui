/**
 *
 *      ┌─┐╔═╗┌┬┐┌─┐
 *      │  ║ ║ ││├┤
 *      └─┘╚═╝─┴┘└─┘
 *   ┌─┐┌─┐╔╗╔┬  ┬┌─┐┌─┐
 *   │  ├─┤║║║└┐┌┘├─┤└─┐
 *   └─┘┴ ┴╝╚╝ └┘ ┴ ┴└─┘
 *
 * Copyright (c) 2016 Code on Canvas Pty Ltd, http://CodeOnCanvas.cc
 *
 * This software is distributed under the MIT license
 * https://tldrlegal.com/license/mit-license
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code
 *
 **/

#pragma once

#include "cinder/app/App.h"
#include "CinderImGui.h"
#include "cocParameters.h"

namespace coc {


class TextBrowser {
public:

	std::string	title;

	void setup( std::string _title, std::string folderName) {

		title = _title;

		//load wiki
		std::vector<std::string> filenames = listDirectory(folderName,false);
		for (int i=0; i<filenames.size(); i++) {
			std::string content = ci::loadString( ci::app::loadAsset( folderName + "/" + filenames[i] ) );
			pages.push_back( WikiPage() );
			pages.back().name = filenames[i];
			pages.back().content = content;
		}
	}

	std::string getKeyShortcutString( std::string _key )
	{
#if defined CINDER_MSW
		return "Ctrl+"+_key;
#elif defined CINDER_COCOA
		return "Cmd+"+_key;
#else
		return "";
#endif
	}


	void updateUI( bool *isWikiVisible ) {

		if (ImGui::Begin(title.c_str(), isWikiVisible))
		{
			static int selected = 0;
			ImGui::BeginChild("page list", ImVec2(150, 0), false);
			for (int i = 0; i < pages.size(); i++)
			{
				char label[128];
				if (ImGui::Selectable(pages[i].name.c_str(), selected == i))
					selected = i;
			}
			ImGui::EndChild();
			ImGui::SameLine();

			ImGui::BeginChild("page view");
			ImGui::TextWrapped( pages[selected].content.c_str() );
			ImGui::EndChild();
		}
		ImGui::End();
	}

private:

	struct WikiPage {
		std::string name;
		std::string content;
	};
	std::vector<WikiPage> pages;

	std::vector<std::string> listDirectory( std::string _path, bool _verbose = false ) {

		std::vector<std::string> files;
		ci::fs::path p( ci::app::getAssetPath( _path ) );

		if (_verbose) ci::app::console()<< "About to list " << ci::app::getAssetPath( _path ) << ":\n";

		if (p.generic_string() != "") {

			for ( ci::fs::directory_iterator it( p ); it != ci::fs::directory_iterator(); ++it )
			{
				if ( ci::fs::is_regular_file( *it ) )
				{
					std::string fileName = it->path().filename().string();

					if( !( fileName.compare( ".DS_Store" ) == 0 ) )
					{
						files.push_back( fileName );
						if (_verbose) ci::app::console() << "\t" << fileName << std::endl;
					}
				}
			}
		}

		return files;
	}
};//class TextBrowser


}//namespace coc
