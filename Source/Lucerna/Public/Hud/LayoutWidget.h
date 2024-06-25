// @Daniel Janák
// Virtuos Labs Prague

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "LayoutWidget.generated.h"

class UCommonActivatableWidgetContainerBase;
class UCommonActivatableWidget;

UCLASS()
class LUCERNA_API ULayoutWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UCommonActivatableWidgetContainerBase* ScreenStack;
	
public:

	UFUNCTION(BlueprintCallable)
	void ShowScreen(TSubclassOf<UCommonActivatableWidget> WidgetClass);

	UFUNCTION(BlueprintCallable)
	void GoBack();
};
