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


void GuiQuad::setup( ci::ivec2 _size )
{
	size = _size;
	fbo.setup( size );

	int w = 10;
	for ( Rectf &r : rects) r = Rectf(0,0,w,w);
	rects[0].offsetCenterTo( vec2(0,0) );//UL
	rects[1].offsetCenterTo( vec2(size.x,0) );//UR
	rects[2].offsetCenterTo( vec2(size.x,size.y) );//LR
	rects[3].offsetCenterTo( vec2(0,size.y) );//LL
}

ci::vec2 GuiQuad::getCorner( int _i )
{
	return rects[_i].getCenter();
}

void GuiQuad::updateGui( gl::TextureRef _tex)
{
	fbo.bind();
	gl::color(Color(1,1,1));
	gl::draw( _tex, fbo.getTextureRef()->getBounds() );

	for (int i=0; i<4; i++) {
		gl::drawSolidRect( rects[i] );
		if (i==3) {
			gl::drawLine( rects[i].getCenter(), rects[0].getCenter());
		}
		else {
			gl::drawLine( rects[i].getCenter(), rects[i+1].getCenter());
		}

	}

	fbo.unbind();

	ImVec2 cursorScreenPos = ImGui::GetCursorScreenPos();

	ui::ImageButton(fbo.getTextureRef(), size, ImVec2(0,1), ImVec2(1,0), 0);

	if(ui::IsItemHovered()) {

		ImVec2 cursorLocalPos = ImVec2(ui::GetIO().MousePos.x - cursorScreenPos.x, ui::GetIO().MousePos.y - cursorScreenPos.y);

		if(ui::GetIO().MouseClicked[0]) {

			CI_LOG_V("mouse down");
			isMouseDown = true;
		}
		else if(ui::GetIO().MouseReleased[0]) {
			CI_LOG_V("mouse up");
			isMouseDown = false;
		}
		else if (isMouseDown){ //dragging
			CI_LOG_V("mouse drag");
		}


	}
	else {
		isSelected = false;
		isMouseDown = false;
	}



//	ImVec2 cursorScreenPos = ImGui::GetCursorScreenPos();
//
//	ui::ImageButton(timelineFbo.getTextureRef(), timelineFbo.getFboRef()->getSize(), ImVec2(0,1), ImVec2(1,0), 0);
//
//	bTimelineOver = ui::IsItemHovered();
//	bTimelineOver.update();
//
//	if(bTimelineOver == true) {
//
//		ImVec2 cursorTimelinePos = ImVec2(ui::GetIO().MousePos.x - cursorScreenPos.x, ui::GetIO().MousePos.y - cursorScreenPos.y);
//		// TODO: the padding around ui::ImageButton is added to the cursor position.
//		// TODO: need to remove padding around ui::ImageButton for cursor positions to be 100% correct.
//
//		//------------------------------------------------------ mouse down.
//		if(ui::GetIO().MouseClicked[0]) {
//
//			TimelineButton * buttonHit = NULL;
//			for(int i=0; i<appButtons.size(); i++) {
//				TimelineButton * button = &appButtons[i];
//				bool bHit = button->rect.isInside(cursorTimelinePos.x, cursorTimelinePos.y);
//				if(bHit == true) {
//					buttonHit = button;
//					break;
//				}
//			}
//
//			for(int i=0; i<appButtons.size(); i++) {
//				TimelineButton * button = &appButtons[i];
//				if(buttonHit == button) {
//					button->bSelected = !button->bSelected;
//					if(button->bSelected == true) {
//						appIndexSelected = i;
//					} else {
//						appIndexSelected = -1;
//					}
//				} else {
//					if(buttonHit != NULL) {
//						button->bSelected = false;
//					}
//				}
//			}
//
//			bSeeking = scrubberRect.isInside(cursorTimelinePos.x, cursorTimelinePos.y);
//		}
//
//		//------------------------------------------------------ mouse up.
//		if(ui::GetIO().MouseReleased[0]) {
//
//			bSeeking = false;
//		}
//
//		if(bSeeking ==  true) {
//			timeSeek = coc::map(cursorTimelinePos.x, scrubberRect.x1, scrubberRect.x2, 0.0, appTimeTotal, true);
//		}
//	}
//
//	bool bTimelineOut = true;
//	bTimelineOut = bTimelineOut && (bTimelineOver == false);
//	bTimelineOut = bTimelineOut && (bTimelineOver.hasChanged());
//	if(bTimelineOut == true) {
//		bSeeking = false;
//	}
}

}