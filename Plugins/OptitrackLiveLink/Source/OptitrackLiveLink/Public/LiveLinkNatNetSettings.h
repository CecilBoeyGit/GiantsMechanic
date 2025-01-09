//======================================================================================================
// Copyright 2020, NaturalPoint Inc.
//====================================================================================================== 
#pragma once

#include <LiveLinkSourceSettings.h>

#include "LiveLinkNatNetSettings.generated.h"


UENUM( BlueprintType )
enum class EOptitrackLiveLinkConnectionType : uint8
{
	Multicast = 0     UMETA(DisplayName = "Multicast"),
	Unicast			  UMETA(DisplayName = "Unicast"),
};


struct OPTITRACKLIVELINK_API FOptitrackLiveLinkSettings
{
public:
	static FString ConnectionTypeToString( EOptitrackLiveLinkConnectionType ConnType );

	static FOptitrackLiveLinkSettings FromString( const FString& SettingsStr );

public:
	FString ToString() const;

	bool ConnectAutomatically = true;
	FString ServerIpAddress = "127.0.0.1";
	FString ClientIpAddress = "127.0.0.1";
	EOptitrackLiveLinkConnectionType ConnectionType = EOptitrackLiveLinkConnectionType::Multicast;
};


/** Live link streaming settings */
UCLASS( hidecategories = ( Settings ) )
class OPTITRACKLIVELINK_API UOptitrackLiveLinkSourceSettings : public ULiveLinkSourceSettings
{
public:
	GENERATED_BODY()

	// Triggered after changes to any properties
	void PostEditChangeProperty( FPropertyChangedEvent& PropertyChangedEvent );

	/** Origin of streamed data. */
	UPROPERTY(EditAnywhere, Category = "StreamedDataOffset", DisplayName = "Location")
	FVector Location = FVector::ZeroVector;

	/** Orientation of streamed data. */
	UPROPERTY(EditAnywhere, Category = "StreamedDataOffset", DisplayName = "Orientation")
	FRotator Orientation = FRotator::ZeroRotator;

	/** Scale of streamed data. */
	UPROPERTY(EditAnywhere, Category = "StreamedDataOffset", DisplayName = "Scale")
	float Scale = 1;

	/** Whether to create LiveLink subjects for labeled markers */
	UPROPERTY(EditAnywhere, Category = "Markers", DisplayName = "Create Labeled Markers")
	bool CreateLabeledMarkerSubjects = false;

	/** Whether to create LiveLink subjects for unlabeled markers */
	UPROPERTY(EditAnywhere, Category = "Markers", DisplayName = "Create Unlabeled Markers")
	bool CreateUnlabeledMarkerSubjects = false;

	/** Drop down of subjects */
	UPROPERTY(EditAnywhere, Category = "Live Link Roles", DisplayName = "Live Link Subject")
	FLiveLinkSubjectKey LiveLinkSubject;

	/** Checkbox to assign camera role for rigid bodies */
	UPROPERTY(EditAnywhere, Category = "Live Link Roles", DisplayName = "Stream As Camera (Rigid Bodies Only)")
	bool SubjectIsCamera;

	/** Set LiveLink as timecode provider */
	UPROPERTY(EditAnywhere, Category = "TimecodeProvider", DisplayName = "Timecode Provider")
	bool TimecodeProvider = false;

	/** Timecode provider subject name */
	UPROPERTY(EditAnywhere, Category = "TimecodeProvider", DisplayName = "Subject Name")
	FName SubjectName;

	// Keep track of which subjects are supposed to be cameras
	TMap<FLiveLinkSubjectKey, bool> CameraSubjects;

};
