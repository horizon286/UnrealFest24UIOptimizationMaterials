// @Daniel Janák
// Virtuos Labs Prague

#pragma once

#include "CoreMinimal.h"
#include "Components/RetainerBox.h"
#include "AnimatableRetainerBox.generated.h"

UCLASS()
class LUCERNA_API UAnimatableRetainerBox : public URetainerBox
{
	GENERATED_BODY()

public:

	virtual void SynchronizeProperties() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Appearance")
	FSlateBrush Brush;

};
