// @Daniel Janák
// Virtuos Labs Prague

#include "AnimatableRetainerBox.h"

void UAnimatableRetainerBox::SynchronizeProperties()
{
	SetEffectMaterial(Cast<UMaterialInterface>(Brush.GetResourceObject()));
	Super::SynchronizeProperties();
}
