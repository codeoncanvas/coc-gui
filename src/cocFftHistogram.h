#pragma once

#include "CinderImGui.h"
#include "cinder/audio/audio.h"

namespace coc {


class FftHistogram {

public:

	void setup( string _label, int _fftSize ) {

		label = _label;
		auto ctx = ci::audio::Context::master();

		// By providing an FFT size double that of the window size, we 'zero-pad' the analysis data, which gives
		// an increase in resolution of the resulting spectrum data.
		auto monitorFormat = ci::audio::MonitorSpectralNode::Format().fftSize( _fftSize ).windowSize( _fftSize/2 );
		monitorSpectralNode = ctx->makeNode( new audio::MonitorSpectralNode( monitorFormat ) );

	}


	void update( audio::BufferPlayerNodeRef _ref) {
		_ref >> monitorSpectralNode;
		magSpectrum = monitorSpectralNode->getMagSpectrum();
	}


	void updateUI() {
		ui::PlotHistogram(label.c_str(), &magSpectrum[0], magSpectrum.size(), 0, NULL, 0.0f, 1.0f, glm::ivec2(0,100) );

	}

	int getSize() { return magSpectrum.size(); }
	float getValueAtIndex( int _i ) { return magSpectrum[_i]; }


private:

	ci::audio::MonitorSpectralNodeRef	monitorSpectralNode;
	std::vector<float>					magSpectrum;
	std::string 						label;

};//class FftHistogram


}//namespace coc