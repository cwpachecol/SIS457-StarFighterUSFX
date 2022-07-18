// Fill out your copyright notice in the Description page of Project Settings.


#include "PaS_TypeOfWeapon.h"


void APaS_TypeOfWeapon::AlterShoot(AActor* MyChanceWeapon)
{
	ChangeWeapon = Cast<IPaS_ChangeWeapon>(MyChanceWeapon);

	if (!ChangeWeapon)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, TEXT("Cast invalido! Consulte Registro de salida para obtener m�s detalles."));
		UE_LOG(LogTemp, Error, TEXT("AlterShoot(): �El actor no es una estrategia de ChangeWeapon! �Est�s seguro de que el actor implementa esa interfaz? "));
	}
}

void APaS_TypeOfWeapon::Change(FVector _LocationPlayer)
{
	if (!ChangeWeapon)
	{
		UE_LOG(LogTemp, Error, TEXT("Change(): ChangeWeapon es NULL, aseg�rese de que est� inicializado."));
		return;
	}
	ChangeWeapon->ShootWeapon(_LocationPlayer);
}

