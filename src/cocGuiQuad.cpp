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

#include "cinder/Log.h"
#include "cocGuiQuad.h"

namespace coc {

using namespace ci;
using namespace ci::app;
using namespace std;


GuiQuad::GuiQuad()
{

}

void GuiQuad::setup( ci::ivec2 _size )
{
	size = _size;
	fbo.setup( size );

	int w = 20;
	for ( corner &c : corners) c.rect = Rectf(0,0,w,w);
	corners[0].rect.offsetCenterTo( vec2(0,0) );//UL
	corners[1].rect.offsetCenterTo( vec2(size.x,0) );//UR
	corners[2].rect.offsetCenterTo( vec2(size.x,size.y) );//LR
	corners[3].rect.offsetCenterTo( vec2(0,size.y) );//LL

}

void GuiQuad::registerParams( coc::Parameters *_params, std::string _saveName )
{
	_params->setVerbose(true);
	for (int i=0; i<4; i++) {
		_params->registerParam(_saveName + toString(i), &corners[i].rect );
	}
}

ci::vec2 GuiQuad::getCorner( int _i )
{
	return corners[_i].rect.getCenter();
}

ci::vec2 GuiQuad::getCornerNormalised( int _i )
{
	return corners[_i].rect.getCenter() / (vec2) size;
}

void GuiQuad::updateGui( gl::TextureRef _tex)
{
	fbo.bind();
	gl::color(Color(1,1,1));
	gl::draw( _tex, fbo.getTextureRef()->getBounds() );

	for (int i=0; i<4; i++) {
		gl::drawSolidRect( corners[i].rect );
		if (i==3) {
			gl::drawLine( corners[i].rect.getCenter(), corners[0].rect.getCenter());
		}
		else {
			gl::drawLine( corners[i].rect.getCenter(), corners[i+1].rect.getCenter());
		}

	}

	fbo.unbind();

	ImVec2 cursorScreenPos = ImGui::GetCursorScreenPos();

	ui::ImageButton(fbo.getTextureRef(), size, ImVec2(0,1), ImVec2(1,0), 0);

	if(ui::IsItemHovered()) {

		ImVec2 cursorLocalPos = ImVec2(ui::GetIO().MousePos.x - cursorScreenPos.x, ui::GetIO().MousePos.y - cursorScreenPos.y);

		if(ui::GetIO().MouseClicked[0]) {

			isMouseDown = true;

			for (int i=0; i<4; i++) {
				if (corners[i].rect.contains(cursorLocalPos)) {
					corners[i].isSelected = true;
					selected = i;
					break;
				}
			}
		}
		else if(ui::GetIO().MouseReleased[0]) {
			selected = -1;
			for ( corner &c : corners) c.isSelected = false;
			isMouseDown = false;
		}
		else if (isMouseDown){ //dragging
			corners[selected].rect.offsetCenterTo(cursorLocalPos);
		}

	}
	else {
		selected = -1;
		for ( corner &c : corners) c.isSelected = false;
		isMouseDown = false;
	}

}

}