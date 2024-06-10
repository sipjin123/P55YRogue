// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponDisplayWidget.h"
#include "P5YY/Data/WeaponData.h"

void UWeaponDisplayWidget::NativeConstruct()
{
	//const auto WeaponData = Weapon.DataTable->FindRow<FWeaponData>("Pistol","");

	/*
	TArray<FWeaponData*> Weapons;
	Weapon.DataTable->GetAllRows<FWeaponData>("",Weapons);
	for (const auto OtherWeapon:Weapons)
	{
		if (OtherWeapon)
		{
			// ...
		}
	}*/
		
	const auto WeaponData = Weapon.GetRow<FWeaponData>("");
	if(WeaponData)
	{
		// ...
	}
}
 