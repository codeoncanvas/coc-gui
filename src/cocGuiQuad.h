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
#include "cocFboWrapper.h"
#include "cocParameters.h"

namespace coc {


struct corner {
	ci::Rectf rect;
	bool isSelected = false;
};

class GuiQuad {

public:

	GuiQuad();

	void setup( ci::ivec2 _size );

	void registerParams( coc::Parameters *_params, std::string _saveName );

	void updateGui( ci::gl::TextureRef _tex );

	ci::vec2 getCorner( int _i );

	ci::vec2 getCornerNormalised( int _i );

	ci::vec2 getLastCursorLocalPos();

protected:

	corner	corners[4];

	coc::FboWrapper	fbo;

	bool isMouseDown = false;
	int selected = -1;

	ci::ivec2 size = ci::vec2(0,0);
	ci::ivec2 cursorLocalPos = ci::vec2(0,0);

	ci::Color	colOutline;

};//class cocGuiQuad

}