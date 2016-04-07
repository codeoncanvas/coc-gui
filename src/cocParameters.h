/*
 *
 * 	USAGE:
 *
 * 	coc::parameters()->registerParam("variableName",&variable);
 * 	coc::parameters()->load();
 * 	...
 * 	coc::parameters()->save();
 *
 */

#pragma once

#include "cinder/app/App.h"
#include "cinder/Xml.h"
#include "cinder/Log.h"
#include <fstream>

namespace coc {

enum parameterType {
	PARAM_FLOAT = 0,
	PARAM_INT = 1,
	PARAM_BOOL = 2,
	PARAM_STR = 3,
	PARAM_VEC2 = 10
};

struct Parameter {

	std::string 	name;
	parameterType 	type;
	void*			val;

};

class Parameters {
public:

    Parameters();

	template<typename T>
	void registerParam( std::string _name, T *_val )
	{
		params.push_back(Parameter());
		params.back().name = _name;
		params.back().val = _val;
		if (std::is_same<T, float>::value) params.back().type = PARAM_FLOAT;
		else if (std::is_same<T, int>::value) params.back().type = PARAM_INT;
		else if (std::is_same<T, bool>::value) params.back().type = PARAM_BOOL;
		else if (std::is_same<T, std::string>::value) params.back().type = PARAM_STR;
		else if (std::is_same<T, glm::vec2>::value) params.back().type = PARAM_VEC2;
	}

	void save( std::string _filename = "config_params.xml" );
	void load( std::string _filename = "config_params.xml" );


	static Parameters* instance();

private:

	static Parameters* pInst;

	std::vector<coc::Parameter> params;
};

static Parameters* parameters() { return Parameters::instance(); }


}//namespace coc

