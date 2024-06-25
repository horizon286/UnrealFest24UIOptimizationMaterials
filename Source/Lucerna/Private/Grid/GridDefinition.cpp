// @Daniel Janák
// Virtuos Labs Prague

#include "GridDefinition.h"

void UGridDefinition::RegenerateGridDefinitions()
{
	ColumnDefinitions.Empty();
	RowDefinitions.Empty();
	
	// Generate grid layout
	TArray<int32> horizontalEdges, verticalEdges;

	// Calculate and extract edges
	for (FMapPoint& entry : Entries)
	{
		const int32 halfX = entry.Size.X * 0.5f;
		const int32 halfY = entry.Size.Y * 0.5f;

		entry.StartEdgeX = entry.Position.X - halfX;
		entry.EndEdgeX = entry.Position.X + halfX;
		entry.StartEdgeY = entry.Position.Y - halfY;
		entry.EndEdgeY = entry.Position.Y + halfY;
		
		horizontalEdges.AddUnique(entry.StartEdgeX);
		horizontalEdges.AddUnique(entry.EndEdgeX);

		verticalEdges.AddUnique(entry.StartEdgeY);
		verticalEdges.AddUnique(entry.EndEdgeY);
	}

	// Sort edges from smallest to biggest
	horizontalEdges.Sort([](const int32& e1, const int32& e2) {
				return  e1 < e2;
			});
	verticalEdges.Sort([](const int32& e1, const int32& e2) {
				return  e1 < e2;
			});
	
	for (FMapPoint& entry : Entries)
	{
		// Get indexes from sorted arrays
		const int32 startIndexX = horizontalEdges.IndexOfByKey(entry.StartEdgeX);
		const int32 endIndexX = horizontalEdges.IndexOfByKey(entry.EndEdgeX);
		const int32 startIndexY = verticalEdges.IndexOfByKey(entry.StartEdgeY);
		const int32 endIndexY = verticalEdges.IndexOfByKey(entry.EndEdgeY);

		// Calculate Grid Slot properties
		entry.Column = startIndexX + 1;
		entry.ColumnSpan = endIndexX - startIndexX;
		entry.Row = startIndexY + 1;
		entry.RowSpan = endIndexY - startIndexY;
	}

	// Generate row and column definitions
	int32 prevValue = 0;
	for (int32& horizontal : horizontalEdges)
	{
		ColumnDefinitions.Emplace((horizontal - prevValue) / static_cast<float>(Size.X));
		prevValue = horizontal;
	}
	ColumnDefinitions.Emplace((Size.X - prevValue) / static_cast<float>(Size.X));

	prevValue = 0;
	for (int32& vertical : verticalEdges)
	{
		RowDefinitions.Emplace((vertical - prevValue) / static_cast<float>(Size.Y));
		prevValue = vertical;
	}
	RowDefinitions.Emplace((Size.Y - prevValue) / static_cast<float>(Size.Y));
}