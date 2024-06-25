// @Daniel Janák
// Virtuos Labs Prague

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MainHUD.generated.h"

class UCommonActivatableWidget;
class ULayoutWidget;

UCLASS()
class LUCERNA_API AMainHUD : public AHUD
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ULayoutWidget> LayoutWidgetClass;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<ULayoutWidget> LayoutWidget;

public:

	UFUNCTION(BlueprintImplementableEvent)
	void OnLayoutCreated();

	UFUNCTION(BlueprintCallable)
	void ShowScreen(TSubclassOf<UCommonActivatableWidget> WidgetClass);

	UFUNCTION(BlueprintCallable)
	void GoBack();
	
protected:

	virtual void BeginPlay() override;
	
};
