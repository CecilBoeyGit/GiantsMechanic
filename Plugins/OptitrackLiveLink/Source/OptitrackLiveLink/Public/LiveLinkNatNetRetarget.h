//======================================================================================================
// Copyright 2020, NaturalPoint Inc.
//====================================================================================================== 
#pragma once

#include <LiveLinkRetargetAsset.h>
#include <LiveLinkRemapAsset.h>

#include "CoreMinimal.h"
#include "BoneIndices.h"
#include "RetargetSkeleton.h"
#include "LiveLinkNatNetRetarget.generated.h"

UCLASS( Blueprintable )
class OPTITRACKLIVELINK_API UOptiTrackLiveLinkRetarget : public ULiveLinkRetargetAsset
{
    GENERATED_UCLASS_BODY()

    //~ Begin ULiveLinkRetargetAsset interface
    virtual void BuildPoseFromAnimationData( float DeltaTime, const FLiveLinkSkeletonStaticData* InSkeletonData, const FLiveLinkAnimationFrameData* InFrameData, FCompactPose& OutPose );
    //~ End ULiveLinkRetargetAsset interface

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Root Bone Name")
    FString RootBoneName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Hip Bone Name")
    FString HipBoneName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Ab Bone Name")
    FString AbBoneName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Chest Bone Name")
    FString ChestBoneName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Neck Bone Name")
    FString NeckBoneName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Head Bone Name")
    FString HeadBoneName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Shoulder Bone Name")
    FString LShoulderBoneName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Upper Arm Bone Name")
    FString LUArmBoneName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Forearm Bone Name")
    FString LFArmBoneName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Hand Bone Name")
    FString LHandBoneName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Shoulder Bone Name")
    FString RShoulderBoneName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Upper Arm Bone Name")
    FString RUArmBoneName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Forearm Bone Name")
    FString RFArmBoneName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Hand Bone Name")
    FString RHandBoneName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Thigh Bone Name")
    FString LThighBoneName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Shin Bone Name")
    FString LShinBoneName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Foot Bone Name")
    FString LFootBoneName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Toe Bone Name")
    FString LToeBoneName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Thigh Bone Name")
    FString RThighBoneName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Shin Bone Name")
    FString RShinBoneName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Foot Bone Name")
    FString RFootBoneName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Toe Bone Name")
    FString RToeBoneName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Thumb1 Bone Name")
    FString LThumb1BoneName;  

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Thumb2 Bone Name")
    FString LThumb2BoneName;  

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Thumb3 Bone Name")
    FString LThumb3BoneName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Index1 Bone Name")
    FString LIndex1BoneName;  

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Index2 Bone Name")
    FString LIndex2BoneName;  

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Index3 Bone Name")
    FString LIndex3BoneName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Middle1 Bone Name")
    FString LMiddle1BoneName; 

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Middle2 Bone Name")
    FString LMiddle2BoneName; 

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Middle3 Bone Name")
    FString LMiddle3BoneName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Ring1 Bone Name")
    FString LRing1BoneName;   

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Ring2 Bone Name")
    FString LRing2BoneName;   

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Ring3 Bone Name")
    FString LRing3BoneName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Pinky1 Bone Name")
    FString LPinky1BoneName;  

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Pinky2 Bone Name")
    FString LPinky2BoneName;  

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Left Pinky3 Bone Name")
    FString LPinky3BoneName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Thumb1 Bone Name")
    FString RThumb1BoneName;  

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Thumb2 Bone Name")
    FString RThumb2BoneName;  

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Thumb3 Bone Name")
    FString RThumb3BoneName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Index1 Bone Name")
    FString RIndex1BoneName;  

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Index2 Bone Name")
    FString RIndex2BoneName;  

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Index3 Bone Name")
    FString RIndex3BoneName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Middle1 Bone Name")
    FString RMiddle1BoneName; 

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Middle2 Bone Name")
    FString RMiddle2BoneName; 

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Middle3 Bone Name")
    FString RMiddle3BoneName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Ring1 Bone Name")
    FString RRing1BoneName;   

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Ring2 Bone Name")
    FString RRing2BoneName;   

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Ring3 Bone Name")
    FString RRing3BoneName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Pinky1 Bone Name")
    FString RPinky1BoneName;  

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Pinky2 Bone Name")
    FString RPinky2BoneName;  

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Retargeting", DisplayName = "Right Pinky3 Bone Name")
    FString RPinky3BoneName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings", DisplayName = "Scale Bones")
    bool mScaleBones;

    UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Settings", DisplayName = "Left Thumb1 Rotation Offset" )
    FRotator mLThumb1Rotation;

    UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Settings", DisplayName = "Left Thumb2 Rotation Offset" )
    FRotator mLThumb2Rotation;

    UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Settings", DisplayName = "Left Thumb3 Rotation Offset" )
    FRotator mLThumb3Rotation;

    UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Settings", DisplayName = "Right Thumb1 Rotation Offset" )
    FRotator mRThumb1Rotation;

    UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Settings", DisplayName = "Right Thumb2 Rotation Offset" )
    FRotator mRThumb2Rotation;

    UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Settings", DisplayName = "Right Thumb3 Rotation Offset" )
    FRotator mRThumb3Rotation;

private:
    cRetargetSkeleton mSourceSkeleton;
    cRetargetSkeleton mTargetSkeleton;

    bool mDrawSourceSkeleton;
    bool mDrawTargetSkeleton;
    bool mDrawOutputPose;

    FString FBXBoneName( OptiTrackBoneID ID ) const;
    FString UEBoneName( OptiTrackBoneID ID ) const;
    OptiTrackBoneID FBXBoneNameToID( const FString& boneName ) const;
    OptiTrackBoneID UEBoneNameToID( const FString& boneName ) const;
    bool IsFBXBoneNamingConvention( const TArray<FName>& boneNames ) const;
    bool IsUEBoneNamingConvention( const TArray<FName>& boneNames ) const;

    void DrawAxis( UWorld* world, const FTransform& tr, float size ) const;
    void DrawSkeleton( UWorld* world, const cRetargetSkeleton& skeleton, bool drawAxis, const FColor& color ) const;
    void DrawSkeleton( UWorld* world, const FLiveLinkSkeletonStaticData* skeletonData, const FLiveLinkAnimationFrameData* frameData, bool drawLines, bool drawJoints, bool drawAxis, const FColor& color ) const;
    void DrawPose( UWorld* world, const FCompactPose& pose, bool drawLines, bool drawJoints, bool drawAxis, const FColor& color ) const;
};
