// @Daniel Janák
// Virtuos Labs Prague

#include "Hud/MainHUD.h"

#include "Blueprint/UserWidget.h"
#include "CommonActivatableWidget.h"
#include "LayoutWidget.h"

void AMainHUD::ShowScreen(TSubclassOf<UCommonActivatableWidget> WidgetClass)
{
	LayoutWidget->ShowScreen(WidgetClass);
}

void AMainHUD::GoBack()
{
	LayoutWidget->GoBack();
}

void AMainHUD::BeginPlay()
{
	Super::BeginPlay();
	
	LayoutWidget = CreateWidget<ULayoutWidget>(GetOwningPlayerController(), LayoutWidgetClass);
	LayoutWidget->AddToViewport();

	OnLayoutCreated();
}
