// @Daniel Janák
// Virtuos Labs Prague

#pragma once

#include "CoreMinimal.h"
#include "GridDefinition.generated.h"

USTRUCT(BlueprintType)
struct LUCERNA_API FMapPoint
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D* Background;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D* Icon;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FIntPoint Position;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FIntPoint Size = FIntPoint(64, 64);

	UPROPERTY(BlueprintReadOnly)
	int32 Column;
	
	UPROPERTY(BlueprintReadOnly)
	int32 Row;
	
	UPROPERTY(BlueprintReadOnly)
	int32 ColumnSpan;
	
	UPROPERTY(BlueprintReadOnly)
	int32 RowSpan;
	
	int32 StartEdgeX;
	int32 EndEdgeX;
	int32 StartEdgeY;
	int32 EndEdgeY;
};

UCLASS(BlueprintType)
class LUCERNA_API UGridDefinition : public UDataAsset
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FMapPoint> Entries;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FIntPoint Size = FIntPoint(1920, 1080);
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<float> ColumnDefinitions;
	 
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<float> RowDefinitions;

public:

	UFUNCTION(BlueprintCallable)
	void RegenerateGridDefinitions();
};