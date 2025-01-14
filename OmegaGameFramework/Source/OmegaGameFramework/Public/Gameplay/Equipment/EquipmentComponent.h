﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "EquipmentComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnItemEquipped, UPrimaryDataAsset*, Item, FString, Slot);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnItemUnequipped, UPrimaryDataAsset*, Item, FString, Slot);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class OMEGAGAMEFRAMEWORK_API UEquipmentComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UEquipmentComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY()
	TMap<FString, UPrimaryDataAsset*> EquippedItems;

	UFUNCTION(BlueprintPure, Category="Equipment", meta=(CompactNodeTitle="Equipment"))
	TMap<FString, UPrimaryDataAsset*> GetEquipment();

	UFUNCTION(BlueprintCallable, Category="Equipment")
	void SetEquipment(TMap<FString, UPrimaryDataAsset*> Equipment);
	
	//Determines what assets can be accepted. Blank will accept all.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Equipment")
	FGameplayTagContainer AcceptedItemTags;

	//Determines what assets can be accepted. Blank will reject none.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Equipment")
	FGameplayTagContainer RejectedItemTags;
	
	bool IsItemAccepted(UPrimaryDataAsset* Item);
	bool IsItemRejected(UPrimaryDataAsset* Item);
	
	UFUNCTION(BlueprintCallable, Category="Equipment")
	bool EquipItem(UPrimaryDataAsset* Item, FString Slot);

	UFUNCTION(BlueprintCallable, Category="Equipment")
	bool UnequipSlot(FString Slot);
	
	UFUNCTION(BlueprintPure, Category="Equipment")
	UPrimaryDataAsset* GetEquipmentInSlot(FString Slot, bool& bValidItem);

	UPROPERTY(BlueprintAssignable)
	FOnItemEquipped OnItemEquipped;

	UPROPERTY(BlueprintAssignable)
	FOnItemUnequipped OnItemUnequipped;
};
