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

namespace coc {

class GuiQuad {

public:

	void setup( ci::ivec2 _size );

	void updateGui( ci::gl::TextureRef _tex );

	ci::vec2 getCorner( int _i );

protected:

	ci::Rectf	rects[4];

	coc::FboWrapper	fbo;

	bool isMouseDown = false;
	bool isSelected = false;

	ci::ivec2 size = ci::vec2(0,0);

};//class cocGuiQuad

}