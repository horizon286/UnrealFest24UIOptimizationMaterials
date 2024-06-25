// @Daniel Janák
// Virtuos Labs Prague

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "GridDefinition.h"
#include "MapWidget.generated.h"

class UGridPanel;
class UMapPointWidget;

UCLASS()
class LUCERNA_API UMapWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UGridDefinition> GridData;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UMapPointWidget> MapPointClass;
	
public:

	UFUNCTION(BlueprintCallable)
	void InitializeGrid(UGridPanel* InPanel);
	
	UFUNCTION(BlueprintCallable)
	void InitializeEntry(UPARAM(ref) FMapPoint& InEntry, UPanelWidget* InPanel) const;

	UFUNCTION(BlueprintCallable)
	void CreateEntries(UPanelWidget* InPanel);

	UFUNCTION(BlueprintCallable)
	void ExecuteBack();
	
};
