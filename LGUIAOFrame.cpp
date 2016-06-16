#include "ISXAO.h"
#include "LGUIAOFrame.h"

LGUIFactory<LGUIAOFrame> AOFrameFactory("aoframe");

LGUIAOFrame::LGUIAOFrame(const char *p_Factory, LGUIElement *p_pParent, const char *p_Name):LGUIFrame(p_Factory,p_pParent,p_Name)
{
	pText=0;
	Count=0;
}
LGUIAOFrame::~LGUIAOFrame(void)
{
}
bool LGUIAOFrame::IsTypeOf(char *TestFactory)
{
	return (!_stricmp(TestFactory,"aoframe")) || LGUIFrame::IsTypeOf(TestFactory);
}
bool LGUIAOFrame::FromXML(class XMLNode *pXML, class XMLNode *pTemplate)
{
	if (!pTemplate)
		pTemplate=g_UIManager.FindTemplate(XMLHelper::GetStringAttribute(pXML,"Template"));
	if (!pTemplate)
		pTemplate=g_UIManager.FindTemplate("aoframe");
	if (!LGUIFrame::FromXML(pXML,pTemplate))
		return false;

	// custom xml properties
	return true;
}

void LGUIAOFrame::OnCreate()
{
	// All children of this element are guaranteed to have been created now.
	pText = (LGUIText*)FindUsableChild("Output","text");
}

void LGUIAOFrame::Render()
{
	Count++;
	if (pText)
	{
		char Temp[256];
		sprintf_s(Temp,"This frame has been rendered %d times.",Count);
		pText->SetText(Temp);
	}

	LGUIFrame::Render();
}


