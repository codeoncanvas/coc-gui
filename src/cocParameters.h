#pragma once

#include "cinder/Xml.h"
#include "cinder/Log.h"

#include <fstream>

namespace coc {

enum parameterType {
	PARAM_FLOAT = 0,
	PARAM_INT = 1,
	PARAM_BOOL = 2,
	PARAM_VEC2 = 10
};

struct Parameter {

	std::string 	name;
	parameterType 	type;
	void*			val;

};

static std::vector<Parameter> parameters;

template<typename T>
void registerParameter( std::string _name, T *_val )
{
	parameters.push_back(Parameter());
	parameters.back().name = _name;
	parameters.back().val = _val;
	if (std::is_same<T, float>::value) parameters.back().type = PARAM_FLOAT;
	else if (std::is_same<T, int>::value) parameters.back().type = PARAM_INT;
	else if (std::is_same<T, bool>::value) parameters.back().type = PARAM_BOOL;
	else if (std::is_same<T, glm::vec2>::value) parameters.back().type = PARAM_VEC2;

}

static void saveParameters( std::string _filename = "config_params.xml" )
{

	ci::XmlTree xml("parameters","");
	for (int i=0; i<parameters.size(); i++) {

		ci::XmlTree p( "parameter", "" );
		p.setAttribute( "name", parameters[i].name );
		p.setAttribute( "type", (int) parameters[i].type );

		switch (parameters[i].type) {
			case PARAM_FLOAT:
				p.setAttribute( "val", *(float*) parameters[i].val );
				break;
			case PARAM_INT:
				p.setAttribute( "val", *(int*) parameters[i].val );
				break;
			case PARAM_BOOL:
				p.setAttribute( "val", (int) *(bool*) parameters[i].val );
				break;
			case PARAM_VEC2:
				p.setAttribute( "x", (*(glm::vec2*) parameters[i].val).x );
				p.setAttribute( "y", (*(glm::vec2*) parameters[i].val).y );
				break;
		}

		xml.push_back( p );
	}

	xml.write( ci::writeFile( ci::app::getAssetPath( _filename ) ) );

	CI_LOG_I( "Saved GUI" );

}

static void loadParameters( std::string _filename = "config_params.xml" )
{

	ci::XmlTree xml;
	try {
		xml = ci::XmlTree( ci::app::loadAsset( _filename ) );
	}
	catch( ci::Exception exc ){
		CI_LOG_EXCEPTION( "Loading XML failed, creating file", exc )
		std::ofstream file( (ci::app::getAssetPath("") / _filename).string() );
		file.close();
	}


	for( auto parameter = xml.begin( "parameters/parameter" ); parameter != xml.end(); parameter ++ ) {

		std::string 	name = parameter->getAttributeValue<std::string>("name","");
		parameterType 	type = (parameterType) parameter->getAttributeValue<int>( "type", 0 );

		for (int i=0; i<parameters.size(); i++) {

			if ( name == parameters[i].name ) {

				if (type != parameters[i].type) CI_LOG_E( name << " types do not match!");

				switch ( type ) {
					case PARAM_FLOAT:
						*(float *) parameters[i].val = parameter->getAttributeValue<float>( "val", 0.0f );
						break;
					case PARAM_INT:
						*(int *) parameters[i].val = parameter->getAttributeValue<int>( "val", 0.0f );
						break;
					case PARAM_BOOL:
						*(bool *) parameters[i].val = (bool) parameter->getAttributeValue<int>( "val", 0 );
						break;
					case PARAM_VEC2:
						(*(glm::vec2 *) parameters[i].val).x = parameter->getAttributeValue<float>( "x", 0 );
						(*(glm::vec2 *) parameters[i].val).y = parameter->getAttributeValue<float>( "y", 0 );
						break;
				}

			}
		}
	}

}

}//namespace coc