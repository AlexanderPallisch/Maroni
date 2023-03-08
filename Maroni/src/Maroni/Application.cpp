#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Maroni {

	Application::Application()
	{
	};

	Application::~Application()
	{
	};

	void Application::Run()
	{
		WindowResizeEvent e(1900, 1280);
		if (e.IsInCategory(EventCategoryApplication))
		{
			MR_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			MR_TRACE(e);
		}

		while (true);
	};
}