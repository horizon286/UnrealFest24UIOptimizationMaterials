// @Daniel Janák
// Virtuos Labs Prague

#include "Hud/LayoutWidget.h"
#include "CommonActivatableWidget.h"
#include "Widgets/CommonActivatableWidgetContainer.h"

void ULayoutWidget::ShowScreen(TSubclassOf<UCommonActivatableWidget> WidgetClass)
{
	ScreenStack->AddWidget(WidgetClass);
}

void ULayoutWidget::GoBack()
{
	if (UCommonActivatableWidget* ToRemove = ScreenStack->GetActiveWidget())
	{
		ScreenStack->RemoveWidget(*ToRemove);
	}
}
