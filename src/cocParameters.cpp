#include "cocParameters.h"


namespace coc {

Parameters::Parameters(){}
Parameters* Parameters::pInst = nullptr;
Parameters* Parameters::instance()
{
	if(pInst == nullptr) {
		pInst = new Parameters();
	}
	return pInst;
}


void Parameters::saveParameters( std::string _filename )
{

	ci::XmlTree xml("parameters","");
	for (int i=0; i<params.size(); i++) {

		ci::XmlTree p( "parameter", "" );
		p.setAttribute( "name", params[i].name );
		p.setAttribute( "type", (int) params[i].type );

		switch (params[i].type) {
			case PARAM_FLOAT:
				p.setAttribute( "val", *(float*) params[i].val );
				break;
			case PARAM_INT:
				p.setAttribute( "val", *(int*) params[i].val );
				break;
			case PARAM_BOOL:
				p.setAttribute( "val", (int) *(bool*) params[i].val );
				break;
			case PARAM_VEC2:
				p.setAttribute( "x", (*(glm::vec2*) params[i].val).x );
				p.setAttribute( "y", (*(glm::vec2*) params[i].val).y );
				break;
		}

		xml.push_back( p );
	}

	xml.write( ci::writeFile( ci::app::getAssetPath( _filename ) ) );

	CI_LOG_I( "Saved GUI: " <<  params.size() << " parameters");

}

void Parameters::loadParameters( std::string _filename )
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

		for (int i=0; i<params.size(); i++) {

			if ( name == params[i].name ) {

				if (type != params[i].type) CI_LOG_E( name << " types do not match!");

				switch ( type ) {
					case PARAM_FLOAT:
						*(float *) params[i].val = parameter->getAttributeValue<float>( "val", 0.0f );
						break;
					case PARAM_INT:
						*(int *) params[i].val = parameter->getAttributeValue<int>( "val", 0.0f );
						break;
					case PARAM_BOOL:
						*(bool *) params[i].val = (bool) parameter->getAttributeValue<int>( "val", 0 );
						break;
					case PARAM_VEC2:
						(*(glm::vec2 *) params[i].val).x = parameter->getAttributeValue<float>( "x", 0 );
						(*(glm::vec2 *) params[i].val).y = parameter->getAttributeValue<float>( "y", 0 );
						break;
				}

			}
		}
	}

	CI_LOG_I( "Loaded GUI: " <<  params.size() << " parameters");

}

}//namespace coc