//======================================================================================================
// Copyright 2020, NaturalPoint Inc.
//====================================================================================================== 

#include "LiveLinkNatNetRetarget.h"

#include <BoneIndices.h>
#include <BonePose.h>
#include <Roles/LiveLinkAnimationTypes.h>
#include "DrawDebugHelpers.h"

UOptiTrackLiveLinkRetarget::UOptiTrackLiveLinkRetarget( const FObjectInitializer& ObjectInitializer )
    : Super( ObjectInitializer )
{
    RootBoneName = UEBoneName( OptiTrackBoneID::Root );
    HipBoneName = UEBoneName( OptiTrackBoneID::Hips );
    AbBoneName = UEBoneName( OptiTrackBoneID::Spine );
    ChestBoneName = UEBoneName( OptiTrackBoneID::Spine1 );
    NeckBoneName = UEBoneName( OptiTrackBoneID::Neck );
    HeadBoneName = UEBoneName( OptiTrackBoneID::Head );

    LShoulderBoneName = UEBoneName( OptiTrackBoneID::LeftShoulder );
    LUArmBoneName = UEBoneName( OptiTrackBoneID::LeftArm );
    LFArmBoneName = UEBoneName( OptiTrackBoneID::LeftForeArm );
    LHandBoneName = UEBoneName( OptiTrackBoneID::LeftHand );

    RShoulderBoneName = UEBoneName( OptiTrackBoneID::RightShoulder );
    RUArmBoneName = UEBoneName( OptiTrackBoneID::RightArm );
    RFArmBoneName = UEBoneName( OptiTrackBoneID::RightForeArm );
    RHandBoneName = UEBoneName( OptiTrackBoneID::RightHand );

    LThighBoneName = UEBoneName( OptiTrackBoneID::LeftUpLeg );
    LShinBoneName = UEBoneName( OptiTrackBoneID::LeftLeg );
    LFootBoneName = UEBoneName( OptiTrackBoneID::LeftFoot );
    LToeBoneName = UEBoneName( OptiTrackBoneID::LeftToeBase );

    RThighBoneName = UEBoneName( OptiTrackBoneID::RightUpLeg );
    RShinBoneName = UEBoneName( OptiTrackBoneID::RightLeg );
    RFootBoneName = UEBoneName( OptiTrackBoneID::RightFoot );
    RToeBoneName = UEBoneName( OptiTrackBoneID::RightToeBase );

    LThumb1BoneName = UEBoneName( OptiTrackBoneID::LeftHandThumb1 );
    LThumb2BoneName = UEBoneName( OptiTrackBoneID::LeftHandThumb2 );
    LThumb3BoneName = UEBoneName( OptiTrackBoneID::LeftHandThumb3 );
    LIndex1BoneName = UEBoneName( OptiTrackBoneID::LeftHandIndex1 );
    LIndex2BoneName = UEBoneName( OptiTrackBoneID::LeftHandIndex2 );
    LIndex3BoneName = UEBoneName( OptiTrackBoneID::LeftHandIndex3 );
    LMiddle1BoneName = UEBoneName( OptiTrackBoneID::LeftHandMiddle1 );
    LMiddle2BoneName = UEBoneName( OptiTrackBoneID::LeftHandMiddle2 );
    LMiddle3BoneName = UEBoneName( OptiTrackBoneID::LeftHandMiddle3 );
    LRing1BoneName = UEBoneName( OptiTrackBoneID::LeftHandRing1 );
    LRing2BoneName = UEBoneName( OptiTrackBoneID::LeftHandRing2 );
    LRing3BoneName = UEBoneName( OptiTrackBoneID::LeftHandRing3 );
    LPinky1BoneName = UEBoneName( OptiTrackBoneID::LeftHandPinky1 );
    LPinky2BoneName = UEBoneName( OptiTrackBoneID::LeftHandPinky2 );
    LPinky3BoneName = UEBoneName( OptiTrackBoneID::LeftHandPinky3 );

    RThumb1BoneName = UEBoneName( OptiTrackBoneID::RightHandThumb1 );
    RThumb2BoneName = UEBoneName( OptiTrackBoneID::RightHandThumb2 );
    RThumb3BoneName = UEBoneName( OptiTrackBoneID::RightHandThumb3 );
    RIndex1BoneName = UEBoneName( OptiTrackBoneID::RightHandIndex1 );
    RIndex2BoneName = UEBoneName( OptiTrackBoneID::RightHandIndex2 );
    RIndex3BoneName = UEBoneName( OptiTrackBoneID::RightHandIndex3 );
    RMiddle1BoneName = UEBoneName( OptiTrackBoneID::RightHandMiddle1 );
    RMiddle2BoneName = UEBoneName( OptiTrackBoneID::RightHandMiddle2 );
    RMiddle3BoneName = UEBoneName( OptiTrackBoneID::RightHandMiddle3 );
    RRing1BoneName = UEBoneName( OptiTrackBoneID::RightHandRing1 );
    RRing2BoneName = UEBoneName( OptiTrackBoneID::RightHandRing2 );
    RRing3BoneName = UEBoneName( OptiTrackBoneID::RightHandRing3 );
    RPinky1BoneName = UEBoneName( OptiTrackBoneID::RightHandPinky1 );
    RPinky2BoneName = UEBoneName( OptiTrackBoneID::RightHandPinky2 );
    RPinky3BoneName = UEBoneName( OptiTrackBoneID::RightHandPinky3 );

	mScaleBones = false;

	mLThumb1Rotation = FRotator::MakeFromEuler( FVector( 0, 0, 0 ) );
	mLThumb2Rotation = FRotator::MakeFromEuler( FVector( 0, 0, 0 ) );
	mLThumb3Rotation = FRotator::ZeroRotator;
	mRThumb1Rotation = FRotator::MakeFromEuler( FVector( 0, 0, 0 ) );
	mRThumb2Rotation = FRotator::MakeFromEuler( FVector( 0, 0, 0 ) );
	mRThumb3Rotation = FRotator::ZeroRotator;

	mDrawSourceSkeleton = false;
	mDrawTargetSkeleton = false;
	mDrawOutputPose = false;
}

void UOptiTrackLiveLinkRetarget::BuildPoseFromAnimationData( float DeltaTime, const FLiveLinkSkeletonStaticData* InSkeletonData, const FLiveLinkAnimationFrameData* InFrameData, FCompactPose& OutPose )
{
	OutPose.ResetToRefPose();

	if( mSourceSkeleton.Bones().Num() == 0 )
	{
        TMap<FString, OptiTrackBoneID> boneNameMap;

        if( IsFBXBoneNamingConvention( InSkeletonData->GetBoneNames() ) )
        {
            for( int id = (int)OptiTrackBoneID::FirstBone; id <= (int)OptiTrackBoneID::LastBone; id++ )
                boneNameMap.Add( FBXBoneName( (OptiTrackBoneID)id ), (OptiTrackBoneID)id );
        }
        else if( IsUEBoneNamingConvention( InSkeletonData->GetBoneNames() ) )
        {
            for( int id = (int)OptiTrackBoneID::FirstBone; id <= (int)OptiTrackBoneID::LastBone; id++ )
                boneNameMap.Add( UEBoneName( (OptiTrackBoneID)id ), (OptiTrackBoneID)id );
        }

		mSourceSkeleton.Create( *InSkeletonData, *InFrameData, boneNameMap );
	}

    // FBX Bone naming convention.
    if( mTargetSkeleton.Bones().Num() == 0 )
    {
		TMap<FString, OptiTrackBoneID> boneNameMap;
        {
            boneNameMap.Add( RootBoneName, OptiTrackBoneID::Root );
            boneNameMap.Add( HipBoneName, OptiTrackBoneID::Hips );
            boneNameMap.Add( AbBoneName, OptiTrackBoneID::Spine );
            boneNameMap.Add( ChestBoneName, OptiTrackBoneID::Spine1 );
            boneNameMap.Add( NeckBoneName, OptiTrackBoneID::Neck );
            boneNameMap.Add( HeadBoneName, OptiTrackBoneID::Head );

            boneNameMap.Add( LShoulderBoneName, OptiTrackBoneID::LeftShoulder );
            boneNameMap.Add( LUArmBoneName, OptiTrackBoneID::LeftArm );
            boneNameMap.Add( LFArmBoneName, OptiTrackBoneID::LeftForeArm );
            boneNameMap.Add( LHandBoneName, OptiTrackBoneID::LeftHand );

            boneNameMap.Add( RShoulderBoneName, OptiTrackBoneID::RightShoulder );
            boneNameMap.Add( RUArmBoneName, OptiTrackBoneID::RightArm );
            boneNameMap.Add( RFArmBoneName, OptiTrackBoneID::RightForeArm );
            boneNameMap.Add( RHandBoneName, OptiTrackBoneID::RightHand );

            boneNameMap.Add( LThighBoneName, OptiTrackBoneID::LeftUpLeg );
            boneNameMap.Add( LShinBoneName, OptiTrackBoneID::LeftLeg );
            boneNameMap.Add( LFootBoneName, OptiTrackBoneID::LeftFoot );
            boneNameMap.Add( LToeBoneName, OptiTrackBoneID::LeftToeBase );

            boneNameMap.Add( RThighBoneName, OptiTrackBoneID::RightUpLeg );
            boneNameMap.Add( RShinBoneName, OptiTrackBoneID::RightLeg );
            boneNameMap.Add( RFootBoneName, OptiTrackBoneID::RightFoot );
            boneNameMap.Add( RToeBoneName, OptiTrackBoneID::RightToeBase );

            boneNameMap.Add( LThumb1BoneName, OptiTrackBoneID::LeftHandThumb1 );
            boneNameMap.Add( LThumb2BoneName, OptiTrackBoneID::LeftHandThumb2 );
            boneNameMap.Add( LThumb3BoneName, OptiTrackBoneID::LeftHandThumb3 );
            boneNameMap.Add( LIndex1BoneName, OptiTrackBoneID::LeftHandIndex1 );
            boneNameMap.Add( LIndex2BoneName, OptiTrackBoneID::LeftHandIndex2 );
            boneNameMap.Add( LIndex3BoneName, OptiTrackBoneID::LeftHandIndex3 );
            boneNameMap.Add( LMiddle1BoneName, OptiTrackBoneID::LeftHandMiddle1 );
            boneNameMap.Add( LMiddle2BoneName, OptiTrackBoneID::LeftHandMiddle2 );
            boneNameMap.Add( LMiddle3BoneName, OptiTrackBoneID::LeftHandMiddle3 );
            boneNameMap.Add( LRing1BoneName, OptiTrackBoneID::LeftHandRing1 );
            boneNameMap.Add( LRing2BoneName, OptiTrackBoneID::LeftHandRing2 );
            boneNameMap.Add( LRing3BoneName, OptiTrackBoneID::LeftHandRing3 );
            boneNameMap.Add( LPinky1BoneName, OptiTrackBoneID::LeftHandPinky1 );
            boneNameMap.Add( LPinky2BoneName, OptiTrackBoneID::LeftHandPinky2 );
            boneNameMap.Add( LPinky3BoneName, OptiTrackBoneID::LeftHandPinky3 );

            boneNameMap.Add( RThumb1BoneName, OptiTrackBoneID::RightHandThumb1 );
            boneNameMap.Add( RThumb2BoneName, OptiTrackBoneID::RightHandThumb2 );
            boneNameMap.Add( RThumb3BoneName, OptiTrackBoneID::RightHandThumb3 );
            boneNameMap.Add( RIndex1BoneName, OptiTrackBoneID::RightHandIndex1 );
            boneNameMap.Add( RIndex2BoneName, OptiTrackBoneID::RightHandIndex2 );
            boneNameMap.Add( RIndex3BoneName, OptiTrackBoneID::RightHandIndex3 );
            boneNameMap.Add( RMiddle1BoneName, OptiTrackBoneID::RightHandMiddle1 );
            boneNameMap.Add( RMiddle2BoneName, OptiTrackBoneID::RightHandMiddle2 );
            boneNameMap.Add( RMiddle3BoneName, OptiTrackBoneID::RightHandMiddle3 );
            boneNameMap.Add( RRing1BoneName, OptiTrackBoneID::RightHandRing1 );
            boneNameMap.Add( RRing2BoneName, OptiTrackBoneID::RightHandRing2 );
            boneNameMap.Add( RRing3BoneName, OptiTrackBoneID::RightHandRing3 );
            boneNameMap.Add( RPinky1BoneName, OptiTrackBoneID::RightHandPinky1 );
            boneNameMap.Add( RPinky2BoneName, OptiTrackBoneID::RightHandPinky2 );
            boneNameMap.Add( RPinky3BoneName, OptiTrackBoneID::RightHandPinky3 );

            for( int id = (int)OptiTrackBoneID::FirstBone; id <= (int)OptiTrackBoneID::LastBone; id++ )
                boneNameMap.FindOrAdd( FBXBoneName( (OptiTrackBoneID)id ), (OptiTrackBoneID)id );

            for( int id = (int)OptiTrackBoneID::FirstBone; id <= (int)OptiTrackBoneID::LastBone; id++ )
                boneNameMap.FindOrAdd( UEBoneName( (OptiTrackBoneID)id ), (OptiTrackBoneID)id );
        }

		mTargetSkeleton.Create( OutPose.GetBoneContainer().GetReferenceSkeleton(), boneNameMap );
		mTargetSkeleton.SetTPose( mSourceSkeleton );
	}

	if( mTargetSkeleton.HasFingers() )
	{
		mTargetSkeleton.SetBoneRotationOffset( OptiTrackBoneID::LeftHandThumb1, mLThumb1Rotation.Quaternion() );
		mTargetSkeleton.SetBoneRotationOffset( OptiTrackBoneID::LeftHandThumb2, mLThumb2Rotation.Quaternion() );
		mTargetSkeleton.SetBoneRotationOffset( OptiTrackBoneID::LeftHandThumb3, mLThumb3Rotation.Quaternion() );

		mTargetSkeleton.SetBoneRotationOffset( OptiTrackBoneID::RightHandThumb1, mRThumb1Rotation.Quaternion() );
		mTargetSkeleton.SetBoneRotationOffset( OptiTrackBoneID::RightHandThumb2, mRThumb2Rotation.Quaternion() );
		mTargetSkeleton.SetBoneRotationOffset( OptiTrackBoneID::RightHandThumb3, mRThumb3Rotation.Quaternion() );
	}

	mSourceSkeleton.Update( *InFrameData );
	mTargetSkeleton.Retarget( mSourceSkeleton, mScaleBones );
	mTargetSkeleton.GetPose( OutPose );

	if( mDrawSourceSkeleton )
	{
		//DrawSkeleton( GetWorld(), InSkeletonData, InFrameData, true, true, true, FColor::Green );
		DrawSkeleton( GetWorld(), mSourceSkeleton, true, FColor::Red );
	}

	if( mDrawTargetSkeleton )
	{
		DrawSkeleton( GetWorld(), mTargetSkeleton, true, FColor::Cyan );

		// Draw T pose
		for( cRetargetBone& bone : mTargetSkeleton.Bones() )
			bone.mFinalTransform.SetRotation( bone.mCoordinate );
		DrawSkeleton( GetWorld(), mTargetSkeleton, true, FColor::Yellow );
	}

	if( mDrawOutputPose )
		DrawPose( GetWorld(), OutPose, true, true, true, FColor::Orange );
}

FString UOptiTrackLiveLinkRetarget::FBXBoneName( OptiTrackBoneID ID ) const
{
    switch( ID )
    {
    case OptiTrackBoneID::Origin: return L"Origin";
    case OptiTrackBoneID::Root: return L"Root";
    case OptiTrackBoneID::Hips: return L"Hips";
    case OptiTrackBoneID::Spine: return L"Spine";
    case OptiTrackBoneID::Spine1: return L"Spine1";
    case OptiTrackBoneID::Neck: return L"Neck";
    case OptiTrackBoneID::Head: return L"Head";

    case OptiTrackBoneID::LeftShoulder: return L"LeftShoulder";
    case OptiTrackBoneID::LeftArm: return L"LeftArm";
    case OptiTrackBoneID::LeftForeArm: return L"LeftForeArm";
    case OptiTrackBoneID::LeftHand: return L"LeftHand";

    case OptiTrackBoneID::RightShoulder: return L"RightShoulder";
    case OptiTrackBoneID::RightArm: return L"RightArm";
    case OptiTrackBoneID::RightForeArm: return L"RightForeArm";
    case OptiTrackBoneID::RightHand: return L"RightHand";

    case OptiTrackBoneID::LeftUpLeg: return L"LeftUpLeg";
    case OptiTrackBoneID::LeftLeg: return L"LeftLeg";
    case OptiTrackBoneID::LeftFoot: return L"LeftFoot";
    case OptiTrackBoneID::LeftToeBase: return L"LeftToeBase";

    case OptiTrackBoneID::RightUpLeg: return L"RightUpLeg";
    case OptiTrackBoneID::RightLeg: return L"RightLeg";
    case OptiTrackBoneID::RightFoot: return L"RightFoot";
    case OptiTrackBoneID::RightToeBase: return L"RightToeBase";

    case OptiTrackBoneID::LeftHandThumb1: return L"LeftHandThumb1";
    case OptiTrackBoneID::LeftHandThumb2: return L"LeftHandThumb2";
    case OptiTrackBoneID::LeftHandThumb3: return L"LeftHandThumb3";
    case OptiTrackBoneID::LeftHandIndex1: return L"LeftHandIndex1";
    case OptiTrackBoneID::LeftHandIndex2: return L"LeftHandIndex2";
    case OptiTrackBoneID::LeftHandIndex3: return L"LeftHandIndex3";
    case OptiTrackBoneID::LeftHandMiddle1: return L"LeftHandMiddle1";
    case OptiTrackBoneID::LeftHandMiddle2: return L"LeftHandMiddle2";
    case OptiTrackBoneID::LeftHandMiddle3: return L"LeftHandMiddle3";
    case OptiTrackBoneID::LeftHandRing1: return L"LeftHandRing1";
    case OptiTrackBoneID::LeftHandRing2: return L"LeftHandRing2";
    case OptiTrackBoneID::LeftHandRing3: return L"LeftHandRing3";
    case OptiTrackBoneID::LeftHandPinky1: return L"LeftHandPinky1";
    case OptiTrackBoneID::LeftHandPinky2: return L"LeftHandPinky2";
    case OptiTrackBoneID::LeftHandPinky3: return L"LeftHandPinky3";

    case OptiTrackBoneID::RightHandThumb1: return L"RightHandThumb1";
    case OptiTrackBoneID::RightHandThumb2: return L"RightHandThumb2";
    case OptiTrackBoneID::RightHandThumb3: return L"RightHandThumb3";
    case OptiTrackBoneID::RightHandIndex1: return L"RightHandIndex1";
    case OptiTrackBoneID::RightHandIndex2: return L"RightHandIndex2";
    case OptiTrackBoneID::RightHandIndex3: return L"RightHandIndex3";
    case OptiTrackBoneID::RightHandMiddle1: return L"RightHandMiddle1";
    case OptiTrackBoneID::RightHandMiddle2: return L"RightHandMiddle2";
    case OptiTrackBoneID::RightHandMiddle3: return L"RightHandMiddle3";
    case OptiTrackBoneID::RightHandRing1: return L"RightHandRing1";
    case OptiTrackBoneID::RightHandRing2: return L"RightHandRing2";
    case OptiTrackBoneID::RightHandRing3: return L"RightHandRing3";
    case OptiTrackBoneID::RightHandPinky1: return L"RightHandPinky1";
    case OptiTrackBoneID::RightHandPinky2: return L"RightHandPinky2";
    case OptiTrackBoneID::RightHandPinky3: return L"RightHandPinky3";

    default: return L"UndefinedBone";
    }
}

FString UOptiTrackLiveLinkRetarget::UEBoneName( OptiTrackBoneID ID ) const
{
    switch( ID )
    {
    case OptiTrackBoneID::Origin: return L"origin";
    case OptiTrackBoneID::Root: return L"root";
    case OptiTrackBoneID::Hips: return L"pelvis";
    case OptiTrackBoneID::Spine: return L"spine_01";
    case OptiTrackBoneID::Spine1: return L"spine_02";
    case OptiTrackBoneID::Neck: return L"neck_01";
    case OptiTrackBoneID::Head: return L"head";

    case OptiTrackBoneID::LeftShoulder: return L"clavicle_l";
    case OptiTrackBoneID::LeftArm: return L"upperarm_l";
    case OptiTrackBoneID::LeftForeArm: return L"lowerarm_l";
    case OptiTrackBoneID::LeftHand: return L"hand_l";

    case OptiTrackBoneID::RightShoulder: return L"clavicle_r";
    case OptiTrackBoneID::RightArm: return L"upperarm_r";
    case OptiTrackBoneID::RightForeArm: return L"lowerarm_r";
    case OptiTrackBoneID::RightHand: return L"hand_r";

    case OptiTrackBoneID::LeftUpLeg: return L"thigh_l";
    case OptiTrackBoneID::LeftLeg: return L"calf_l";
    case OptiTrackBoneID::LeftFoot: return L"foot_l";
    case OptiTrackBoneID::LeftToeBase: return L"ball_l";

    case OptiTrackBoneID::RightUpLeg: return L"thigh_r";
    case OptiTrackBoneID::RightLeg: return L"calf_r";
    case OptiTrackBoneID::RightFoot: return L"foot_r";
    case OptiTrackBoneID::RightToeBase: return L"ball_r";

    case OptiTrackBoneID::LeftHandThumb1: return L"thumb_01_l";
    case OptiTrackBoneID::LeftHandThumb2: return L"thumb_02_l";
    case OptiTrackBoneID::LeftHandThumb3: return L"thumb_03_l";
    case OptiTrackBoneID::LeftHandIndex1: return L"index_01_l";
    case OptiTrackBoneID::LeftHandIndex2: return L"index_02_l";
    case OptiTrackBoneID::LeftHandIndex3: return L"index_03_l";
    case OptiTrackBoneID::LeftHandMiddle1: return L"middle_01_l";
    case OptiTrackBoneID::LeftHandMiddle2: return L"middle_02_l";
    case OptiTrackBoneID::LeftHandMiddle3: return L"middle_03_l";
    case OptiTrackBoneID::LeftHandRing1: return L"ring_01_l";
    case OptiTrackBoneID::LeftHandRing2: return L"ring_02_l";
    case OptiTrackBoneID::LeftHandRing3: return L"ring_03_l";
    case OptiTrackBoneID::LeftHandPinky1: return L"pinky_01_l";
    case OptiTrackBoneID::LeftHandPinky2: return L"pinky_02_l";
    case OptiTrackBoneID::LeftHandPinky3: return L"pinky_03_l";

    case OptiTrackBoneID::RightHandThumb1: return L"thumb_01_r";
    case OptiTrackBoneID::RightHandThumb2: return L"thumb_02_r";
    case OptiTrackBoneID::RightHandThumb3: return L"thumb_03_r";
    case OptiTrackBoneID::RightHandIndex1: return L"index_01_r";
    case OptiTrackBoneID::RightHandIndex2: return L"index_02_r";
    case OptiTrackBoneID::RightHandIndex3: return L"index_03_r";
    case OptiTrackBoneID::RightHandMiddle1: return L"middle_01_r";
    case OptiTrackBoneID::RightHandMiddle2: return L"middle_02_r";
    case OptiTrackBoneID::RightHandMiddle3: return L"middle_03_r";
    case OptiTrackBoneID::RightHandRing1: return L"ring_01_r";
    case OptiTrackBoneID::RightHandRing2: return L"ring_02_r";
    case OptiTrackBoneID::RightHandRing3: return L"ring_03_r";
    case OptiTrackBoneID::RightHandPinky1: return L"pinky_01_r";
    case OptiTrackBoneID::RightHandPinky2: return L"pinky_02_r";
    case OptiTrackBoneID::RightHandPinky3: return L"pinky_03_r";

    default: return L"UndefinedBone";
    }
}

OptiTrackBoneID UOptiTrackLiveLinkRetarget::FBXBoneNameToID( const FString& boneName ) const
{
    for( int id = (int)OptiTrackBoneID::FirstBone; id <= (int)OptiTrackBoneID::LastBone; id++ )
    {
        if( FBXBoneName( (OptiTrackBoneID)id ).Compare( boneName, ESearchCase::IgnoreCase ) == 0 )
            return (OptiTrackBoneID)id;
    }
    return OptiTrackBoneID::UndefinedBone;
}

OptiTrackBoneID UOptiTrackLiveLinkRetarget::UEBoneNameToID( const FString& boneName ) const
{
    for( int id = (int)OptiTrackBoneID::FirstBone; id <= (int)OptiTrackBoneID::LastBone; id++ )
    {
        if( UEBoneName( (OptiTrackBoneID)id ).Compare( boneName, ESearchCase::IgnoreCase ) == 0 )
            return (OptiTrackBoneID)id;
    }
    return OptiTrackBoneID::UndefinedBone;
}

bool UOptiTrackLiveLinkRetarget::IsFBXBoneNamingConvention( const TArray<FName>& boneNames ) const
{
    for( const FName& boneName : boneNames )
    {
        if( FBXBoneNameToID( boneName.ToString() ) == OptiTrackBoneID::UndefinedBone )
            return false;
    }
    return true;
}

bool UOptiTrackLiveLinkRetarget::IsUEBoneNamingConvention( const TArray<FName>& boneNames ) const
{
    for( const FName& boneName : boneNames )
    {
        if( UEBoneNameToID( boneName.ToString() ) == OptiTrackBoneID::UndefinedBone )
            return false;
    }
    return true;
}

void UOptiTrackLiveLinkRetarget::DrawAxis( UWorld* world, const FTransform& tr, float size ) const
{
	DrawDebugLine( world, tr.GetTranslation(), tr.TransformPositionNoScale( FVector( size, 0, 0 ) ), FColor::Red, false, -1, SDPG_MAX, 0.5f );
	DrawDebugLine( world, tr.GetTranslation(), tr.TransformPositionNoScale( FVector( 0, size, 0 ) ), FColor::Green, false, -1, SDPG_MAX, 0.5f );
	DrawDebugLine( world, tr.GetTranslation(), tr.TransformPositionNoScale( FVector( 0, 0, size ) ), FColor::Blue, false, -1, SDPG_MAX, 0.5f );
}

void UOptiTrackLiveLinkRetarget::DrawSkeleton( UWorld* world, const cRetargetSkeleton& skeleton, bool drawAxis, const FColor& color ) const
{
	for( const cRetargetBone& bone : skeleton.Bones() )
	{
		if( bone.mParent )
			DrawDebugLine( world, bone.mFinalTransform.GetTranslation(), bone.mParent->mFinalTransform.GetTranslation(), color, false, -1, SDPG_MAX, 1 );

		DrawDebugSphere( world, bone.mFinalTransform.GetTranslation(), 1, 6, color, false, -1, SDPG_MAX, 0.5f );

		if( drawAxis )
			DrawAxis( world, bone.mFinalTransform, 10 );
	}
}

void UOptiTrackLiveLinkRetarget::DrawSkeleton( UWorld* world, const FLiveLinkSkeletonStaticData* skeletonData, const FLiveLinkAnimationFrameData* frameData, bool drawLines, bool drawJoints, bool drawAxis, const FColor& color ) const
{
    bool fbxNames = IsFBXBoneNamingConvention( skeletonData->GetBoneNames() );
	TMap<OptiTrackBoneID, FTransform> boneTransforms;
	for( int i = 0; i < skeletonData->GetBoneNames().Num(); i++ )
	{
        FString boneName = skeletonData->GetBoneNames()[i].ToString();
		OptiTrackBoneID boneID = fbxNames ? FBXBoneNameToID( boneName ) : UEBoneNameToID( boneName );
		if( boneID == OptiTrackBoneID::UndefinedBone )
			continue;

		boneTransforms.FindOrAdd( boneID ) = frameData->Transforms[i];

		int parentIndex = skeletonData->GetBoneParents()[i];
		if( parentIndex >= 0 )
		{
            FString parentName = skeletonData->GetBoneNames()[parentIndex].ToString();
			OptiTrackBoneID parentID = fbxNames ? FBXBoneNameToID( parentName ) : UEBoneNameToID( parentName );
			if( parentID != OptiTrackBoneID::UndefinedBone )
				boneTransforms[boneID] *= boneTransforms[parentID];

			if( drawLines )
				DrawDebugLine( world, boneTransforms[parentID].GetTranslation(), boneTransforms[boneID].GetTranslation(), color, false, -1, SDPG_MAX, 1 );
		}

		if( drawJoints )
			DrawDebugSphere( world, boneTransforms[boneID].GetTranslation(), 1, 6, color, false, -1, SDPG_MAX, 0.5f );

		if( drawAxis )
			DrawAxis( world, boneTransforms[boneID], 10 );
	}
}

void UOptiTrackLiveLinkRetarget::DrawPose( UWorld* world, const FCompactPose& pose, bool drawLines, bool drawJoints, bool drawAxis, const FColor& color ) const
{
	TMap<int, FTransform> boneTransforms;

	for( const FCompactPoseBoneIndex& poseIndex : pose.ForEachBoneIndex() )
	{
		boneTransforms.FindOrAdd( poseIndex.GetInt() ) = pose[poseIndex];

		int parentIndex = pose.GetBoneContainer().GetReferenceSkeleton().GetRawParentIndex(poseIndex.GetInt());
		if( parentIndex >= 0 )
			boneTransforms[poseIndex.GetInt()] *= boneTransforms[parentIndex];

		if( drawLines && parentIndex >= 0 )
			DrawDebugLine( world, boneTransforms[parentIndex].GetTranslation(), boneTransforms[poseIndex.GetInt()].GetTranslation(), color, false, -1, SDPG_MAX, 1 );

		if( drawJoints )
			DrawDebugSphere( world, boneTransforms[poseIndex.GetInt()].GetTranslation(), 1, 6, color, false, -1, SDPG_MAX, 0.5f );

		if( drawAxis )
			DrawAxis( world, boneTransforms[poseIndex.GetInt()], 10 );
	}
}