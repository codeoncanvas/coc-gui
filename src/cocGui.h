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

/*
 * TODO:
 * - update to use TextBrowser object for wiki
 * - update save params code
 */

namespace coc {


class Gui {
public:

	bool isGuiVisible = false;
	void setIsGuiVisible( bool _b ) { isGuiVisible = _b; }
	bool getIsGuiVisible() { return isGuiVisible; }

	bool isWikiVisible = false;
	void setIsWikiVisible( bool _b ) { isWikiVisible = _b; }
	bool getIsWikiVisible() { return isWikiVisible; }

	bool isUsingParams = false;
	void setIsUsingParams( bool _b ) { isUsingParams = _b; }
	bool getIsUsingParams() { return isUsingParams; }

	void setup() {

		//load wiki
		std::vector<std::string> filenames = listDirectory("wiki",false);
		for (int i=0; i<filenames.size(); i++) {
			std::string content = ci::loadString( ci::app::loadAsset( "wiki/" + filenames[i] ) );
			pages.push_back( WikiPage() );
			pages.back().name = filenames[i];
			pages.back().content = content;
		}

		//todo: register key events
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



	void keyDown( ci::app::KeyEvent event ) {

		char ch = event.getChar();

		if( event.isControlDown() || event.isMetaDown()) {

			switch (ch) {
				case 'g':
				case 'G':
					isGuiVisible = !isGuiVisible;
					break;
				case 's':
				case 'S':
//					if (isUsingParams) ::coc::saveParameters();
					break;
			}

		}

	}

	void update() {
		if (isGuiVisible) {
			updateMenuBar();
			updateWiki();
		}
	}

	void updateMenuBar() {
		// menu bar
		{
			ui::ScopedMainMenuBar menuBar;

			if ( ui::BeginMenu( "File" ) ) {
				ui::MenuItem( "Save", getKeyShortcutString( "S" ).c_str() );
				ui::EndMenu();
			}
			if ( ui::BeginMenu( "View" ) ) {
				if (ui::MenuItem( "Hide", getKeyShortcutString( "G" ).c_str() ) ) {
					setIsGuiVisible( false );
				}
				ui::EndMenu();
			}
			if ( ui::BeginMenu( "Help" ) ) {
				if (ui::MenuItem( "Wiki" )) {
					setIsWikiVisible( true );
				}
				ui::EndMenu();
			}
		}

	}


	void updateWiki( ) {

		if ( isWikiVisible ) {

			if (ImGui::Begin("Wiki", &isWikiVisible))
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

			for ( boost::filesystem::directory_iterator it( p ); it != boost::filesystem::directory_iterator(); ++it )
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
};//class Gui

static Gui gui;//global


}//namespace coc
