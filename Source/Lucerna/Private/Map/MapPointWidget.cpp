// @Daniel Janák
// Virtuos Labs Prague

#include "MapPointWidget.h"

#include "Components/CanvasPanelSlot.h"
#include "Components/GridSlot.h"

void UMapPointWidget::InitializePoint(UPARAM(ref) FMapPoint& Data)
{
	OnSetBackground(Data.Background);
	OnSetIcon(Data.Icon);

	if(UGridSlot* GridSlot = Cast<UGridSlot>(Slot))
	{
		GridSlot->SetColumn(Data.Column);
		GridSlot->SetRow(Data.Row);
		GridSlot->SetColumnSpan(Data.ColumnSpan);
		GridSlot->SetRowSpan(Data.RowSpan);
		GridSlot->SetHorizontalAlignment(EHorizontalAlignment::HAlign_Fill);
		GridSlot->SetVerticalAlignment(EVerticalAlignment::VAlign_Fill);
	}
	else if (UCanvasPanelSlot* CanvasSlot = Cast<UCanvasPanelSlot>(Slot))
	{
		CanvasSlot->SetPosition(Data.Position);
		CanvasSlot->SetAlignment(FVector2D(0.5, 0.5));
		CanvasSlot->SetSize(Data.Size);
	}

	OnSetSize(Data.Size);
}
