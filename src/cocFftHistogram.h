#pragma once

#include "cinder/audio/audio.h"

namespace coc {

struct FftData {
	int size;
	std::vector<float> data;
	std::vector<float> dataNorm;
	std::vector<float> dataMax;
	std::vector<float> dataPeak;
	std::vector<int> dataCut;
	float maxDecay;
	float peakValue;
	float peakDecay;
	float peakAverage;
	float cutThreshold;
	float linearEQIntercept;
	float linearEQSlope;
};


class FftHistogram {

public:

	void setup( std::string _label, int _fftSize );

	void connectNode( ci::audio::GainNodeRef _ref );
	void connectNode( ci::audio::BufferPlayerNodeRef _ref );

	void update();


	void updateUI();

	// GETTERS / SETTERS

	void setThreshold(float value);

	float getThreshold();

	float getAveragePeak();

	void setPeakDecay(float value);

	float getPeakDecay();

	void setMaxDecay(float value);

	float getMaxDecay();

	int getSize();

	const std::vector<float> & getFftRawData();

	const std::vector<float> & getFftNormData();

	const std::vector<float> & getFftPeakData();

	const std::vector<int> & getGlitchData();

	bool setUseNormVals( bool _use );


private:

	ci::audio::MonitorNodeRef			monitorNode;
	ci::audio::MonitorSpectralNodeRef	monitorSpectralNode;
	std::vector<float>					magSpectrum;
	std::string 						label;

	FftData								fftData;
	bool 								useNormVals = false;

};//class FftHistogram


}//namespace coc