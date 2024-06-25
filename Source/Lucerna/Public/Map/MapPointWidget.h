// @Daniel Janák
// Virtuos Labs Prague

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "GridDefinition.h"
#include "MapPointWidget.generated.h"


UCLASS()
class LUCERNA_API UMapPointWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetBackground(UTexture2D* BackgroundTexture);
	
	UFUNCTION(BlueprintImplementableEvent)
	void OnSetIcon(UTexture2D* IconTexture);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetSize(const FIntPoint& Size);

	UFUNCTION(BlueprintCallable)
	void InitializePoint(UPARAM(ref) FMapPoint& Data);
};
