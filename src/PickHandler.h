#ifndef PickHandler_H
#define PickHandler_H

#include <osgViewer/Viewer>
#include <osgViewer/CompositeViewer>
#include <osg/Material>
#include <osg/Geode>
#include <osg/BlendFunc>
#include <osg/Depth>
#include <osg/Projection>
#include <osg/MatrixTransform>
#include <osg/Camera>
#include <osg/io_utils>
#include <osg/ShapeDrawable>

#include <osgText/Text>
#include <osgText/TextBase>

#include <sstream>

#include "InitViewerTypes.h"

namespace Fissure
{

	// class to handle events with a pick
	class PickHandler : public osgGA::GUIEventHandler {
	public: 
		
		PickHandler(osgText::Text* updateText, SomaMap& somaMap, int& selectedSomaId, SynapseMap& synapseMap, int& selectedSynapseId):
		_updateText(updateText)
		,_somaMap(somaMap)
		,_selectedSomaId(selectedSomaId)
		,_synapseMap(synapseMap)
		,_selectedSynapseId(selectedSynapseId)
		{
		}
		
		~PickHandler() {}
		
		bool handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa);
		
		virtual void pick(osgViewer::View* view, const osgGA::GUIEventAdapter& ea);
		
		void setLabel(const std::string& name)
		{
			if (_updateText.get()) _updateText->setText(name);
		}
		
	protected:
		SomaMap &_somaMap;
		int &_selectedSomaId;
		SynapseMap &_synapseMap;
		int &_selectedSynapseId;
		osg::ref_ptr<osgText::Text>  _updateText;
	};

} //namespace fissure
#endif