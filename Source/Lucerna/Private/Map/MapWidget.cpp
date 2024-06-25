// @Daniel Janák
// Virtuos Labs Prague

#include "MapWidget.h"

#include "MainHUD.h"
#include "MapPointWidget.h"
#include "Components/GridPanel.h"
#include "Components/PanelWidget.h"

void UMapWidget::InitializeGrid(UGridPanel* InPanel)
{
	GridData->RegenerateGridDefinitions();
	
	InPanel->ColumnFill = GridData->ColumnDefinitions;
	InPanel->RowFill = GridData->RowDefinitions;
	InPanel->SynchronizeProperties();
}

void UMapWidget::InitializeEntry(FMapPoint& InEntry, UPanelWidget* InPanel) const
{
	UMapPointWidget* MapPoint = CreateWidget<UMapPointWidget>(GetOwningPlayer(), MapPointClass);
	InPanel->AddChild(MapPoint);
	MapPoint->InitializePoint(InEntry);
}

void UMapWidget::CreateEntries(UPanelWidget* InPanel)
{
	InPanel->ClearChildren();

	for (FMapPoint& Entry : GridData->Entries)
	{
		InitializeEntry(Entry, InPanel);
	}
}

void UMapWidget::ExecuteBack()
{
	AMainHUD* MainHUD = Cast<AMainHUD>(GetOwningPlayer()->GetHUD());
	MainHUD->GoBack();
}
