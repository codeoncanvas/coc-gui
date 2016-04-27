#include "cocFftHistogram.h"

#include "cinder/Log.h"
#include "CinderImGui.h"
#include "cocMath.h"

namespace coc {

using namespace std;
using namespace ci;
using namespace ci::app;

void FftHistogram::setup( string _label, int _fftSize )
{

	setMaxDecay( 0.995 );
	setPeakDecay( 0.96 );
	setThreshold( 0.0 );

	label = _label;
	auto ctx = ci::audio::Context::master();

	// By providing an FFT size double that of the window size, we 'zero-pad' the analysis data, which gives
	// an increase in resolution of the resulting spectrum data.
	auto monitorFormat = ci::audio::MonitorSpectralNode::Format().fftSize( _fftSize ).windowSize( _fftSize / 2 );
	monitorSpectralNode = ctx->makeNode( new audio::MonitorSpectralNode( monitorFormat ) );

	// INIT AUDIO DATA

	fftData.size = _fftSize / 2;

	fftData.data.resize( fftData.size, 0 );
	fftData.dataNorm.resize( fftData.size, 0 );
	fftData.dataMax.resize( fftData.size, 0 );
	fftData.dataPeak.resize( fftData.size, 0 );
	fftData.dataCut.resize( fftData.size, 0 );

	fftData.linearEQIntercept = 1.0;
	fftData.linearEQSlope = 0.0;


}

void FftHistogram::connectNode( audio::GainNodeRef _ref )
{ _ref >> monitorSpectralNode; }

void FftHistogram::connectNode( audio::BufferPlayerNodeRef _ref )
{ _ref >> monitorSpectralNode; }

void FftHistogram::update()
{
	fftData.data = monitorSpectralNode->getMagSpectrum();

	fftData.peakValue = 0;
	fftData.peakAverage = 0;

	for ( int i = 0; i < fftData.size; i ++ ) {

		//normalise data:
		fftData.data[i] = audio::linearToDecibel( fftData.data[i] ) / 100;

		if ( fftData.peakValue < fftData.data[i] ) {
			fftData.peakValue = fftData.data[i];
		}
	}

	for ( int i = 0; i < fftData.size; i ++ ) {

		float p = i / (float) (fftData.size - 1);

		float dataVal;
		dataVal = fftData.data[i]; // use magnitude for fft data.
		dataVal *= fftData.linearEQIntercept + p * fftData.linearEQSlope; // scale value.

		if ( isinf( dataVal ) ) {
			CI_LOG_E( "Audio data value is infinity." );
			fftData.peakValue = 0;
			return;
		}

		float dataPeakRatio;
		dataPeakRatio = dataVal / fftData.peakValue;

		float dataMaxVal;
		dataMaxVal = fftData.dataMax[i];

		if ( dataMaxVal < dataVal ) {
			dataMaxVal = dataVal;
		}

		float dataNormVal;
		dataNormVal = 0;
		if ( dataMaxVal > 0 ) {
			dataNormVal = dataVal / dataMaxVal; // normalise data between 0 and 1.
		}

		if ( dataVal < 0.1 ) {
			dataNormVal = 0;
		}

		dataMaxVal *= fftData.maxDecay; // decay the max value.

		fftData.dataNorm[i] = dataNormVal;

		fftData.dataMax[i] = dataMaxVal;

		float dataPeakVal;
		dataPeakVal = fftData.dataPeak[i];
		dataPeakVal *= fftData.peakDecay; // decay peak value.

		if ( useNormVals ) {
			if ( dataPeakVal < dataNormVal ) { // check if new peak.
				dataPeakVal = dataNormVal;
			}
		}
		else {
			if ( dataPeakVal < fftData.data[i] ) { // check if new peak.
				dataPeakVal = fftData.data[i];
			}
		}

		fftData.dataPeak[i] = dataPeakVal;

		fftData.peakAverage += dataPeakVal; // sum of all peaks.

		int dataCutVal; // switch data (on/off).
		if ( dataPeakVal < fftData.cutThreshold ) {
			dataCutVal = 1;
		}
		else {
			dataCutVal = 0;
		}

		fftData.dataCut[i] = dataCutVal;
	}

	fftData.peakAverage /= fftData.size;

}


void FftHistogram::updateUI()
{

	if ( fftData.data.size() ) {

		ImVec2 p = ui::GetCursorScreenPos();
		if (useNormVals) {
			ui::PlotHistogram( label.c_str(), &fftData.dataNorm[0], fftData.size, 0, NULL, 0.0f, 1.0f, glm::ivec2( 0, 100 ) );
		}
		else {
			ui::PlotHistogram( label.c_str(), &fftData.data[0], fftData.size, 0, NULL, 0.0f, 1.0f, glm::ivec2( 0, 100 ) );
		}

		ui::SameLine();
		static int labelW = 28;
		static int padding = 4;
		p.x += padding;
		float w = (ui::GetCursorScreenPos().x - p.x - labelW - padding) / fftData.size;
		ImDrawList *draw_list = ui::GetWindowDrawList();
		static ImVec4 col = ImVec4( 0.92f, 0.18f, 0.29f, 0.86f );
		const ImU32 col32 = ImColor( col );

		//draw peak
		for ( int i = 0; i < fftData.size; i ++ ) {
			ImVec2 newP;
			newP.x = p.x + i * w;
			newP.y = p.y + lmap<float>( getFftPeakData()[i], 0, 1, 100, 0 );
			draw_list->AddLine( ImVec2( newP.x, newP.y ), ImVec2( newP.x + w -1, newP.y ), col32 );
		}

		ui::Text( "\n" );
	}

}

// GETTERS / SETTERS

void FftHistogram::setThreshold( float value )
{
//		value = ofClamp(value, 0, 1);
	fftData.cutThreshold = value;
}

float FftHistogram::getThreshold()
{
	return fftData.cutThreshold;
}

float FftHistogram::getAveragePeak()
{
	return fftData.peakAverage;
}

void FftHistogram::setPeakDecay( float value )
{
	value = coc::clamp( value, 0, 1 );
	fftData.peakDecay = value;
}

float FftHistogram::getPeakDecay()
{
	return fftData.peakDecay;
}

void FftHistogram::setMaxDecay( float value )
{
	value = coc::clamp( value, 0, 1 );
	fftData.maxDecay = value;
}

float FftHistogram::getMaxDecay()
{
	return fftData.maxDecay;
}

int FftHistogram::getSize()
{ return fftData.data.size(); }

const vector<float> &FftHistogram::getFftRawData()
{
	return fftData.data;
}

const vector<float> &FftHistogram::getFftNormData()
{
	return fftData.dataNorm;
}

const vector<float> &FftHistogram::getFftPeakData()
{
	return fftData.dataPeak;
}

const vector<int> &FftHistogram::getGlitchData()
{
	return fftData.dataCut;
}

bool FftHistogram::setUseNormVals( bool _use )
{ useNormVals = _use; };

}//namespace coc