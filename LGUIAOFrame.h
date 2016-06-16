#pragma once

class LGUIAOFrame :
	public LGUIFrame
{
public:
	LGUIAOFrame(const char *p_Factory, LGUIElement *p_pParent, const char *p_Name);
	~LGUIAOFrame(void);
	bool IsTypeOf(char *TestFactory);
	bool FromXML(class XMLNode *pXML, class XMLNode *pTemplate=0);
	void OnCreate();
	void Render();

	LGUIText *pText;
	unsigned int Count;
};

extern LGUIFactory<LGUIAOFrame> AOFrameFactory;

