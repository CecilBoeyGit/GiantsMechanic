//======================================================================================================
// Copyright 2020, NaturalPoint Inc.
//====================================================================================================== 
#include "LiveLinkNatNetSettings.h"

#define LOCTEXT_NAMESPACE "LiveLinkNatNetSettings"


// static
FString FOptitrackLiveLinkSettings::ConnectionTypeToString( EOptitrackLiveLinkConnectionType ConnType )
{
	return (ConnType == EOptitrackLiveLinkConnectionType::Unicast)
		? "Unicast"
		: "Multicast";
}


//static
FOptitrackLiveLinkSettings FOptitrackLiveLinkSettings::FromString( const FString& SettingsStr )
{
	FOptitrackLiveLinkSettings ParsedSettings;

	FParse::Bool( *SettingsStr, TEXT("ConnectAutomatically="), ParsedSettings.ConnectAutomatically );
	FParse::Value( *SettingsStr, TEXT("ServerIpAddress="), ParsedSettings.ServerIpAddress );
	FParse::Value( *SettingsStr, TEXT("ClientIpAddress="), ParsedSettings.ClientIpAddress );

	FString TempConnType;
	if ( FParse::Value( *SettingsStr, TEXT("ConnectionType="), TempConnType ) )
	{
		if ( TempConnType.Equals( "Unicast", ESearchCase::IgnoreCase ) )
		{
			ParsedSettings.ConnectionType = EOptitrackLiveLinkConnectionType::Unicast;
		}
		else 
		{
			ParsedSettings.ConnectionType = EOptitrackLiveLinkConnectionType::Multicast;
		}
	}

	return ParsedSettings;
}

FString FOptitrackLiveLinkSettings::ToString() const
{
	return FString::Printf(
		TEXT( "ConnectAutomatically=\"%s\" "
		      "ServerIpAddress=\"%s\" "
		      "ClientIpAddress=\"%s\" "
		      "ConnectionType=\"%s\"" ),
		ConnectAutomatically ? TEXT("true") : TEXT("false"),
		*ServerIpAddress,
		*ClientIpAddress,
		*ConnectionTypeToString( ConnectionType )
	);
}

void UOptitrackLiveLinkSourceSettings::PostEditChangeProperty( FPropertyChangedEvent& PropertyChangedEvent )
{
	// Get the name of the property which changed
	const FName PropertyName = ( PropertyChangedEvent.Property != nullptr ) ? PropertyChangedEvent.Property->GetFName() : NAME_None;

	// Here we check if the camera checkbox has changed, and let LiveLinkNatNetSource know
	// Also we update the checkbox if the subject changes
	if( PropertyName == GET_MEMBER_NAME_CHECKED( UOptitrackLiveLinkSourceSettings, LiveLinkSubject ) )
	{
		if( !CameraSubjects.Contains( LiveLinkSubject ) )
		{
			CameraSubjects.Add( LiveLinkSubject );
			CameraSubjects[ LiveLinkSubject ] = false;
		}
		SubjectIsCamera = CameraSubjects[ LiveLinkSubject ];
	}
	else if( PropertyName == GET_MEMBER_NAME_CHECKED( UOptitrackLiveLinkSourceSettings, SubjectIsCamera ) )
	{
		if( !CameraSubjects.Contains( LiveLinkSubject ) )
		{
			CameraSubjects.Add( LiveLinkSubject );
		}
		CameraSubjects[ LiveLinkSubject ] = SubjectIsCamera;
	}
}

#undef LOCTEXT_NAMESPACE
