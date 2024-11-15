#include "BCustomUtility.h"
#if WITH_EDITOR
#include "Editor.h"
#include "EditorViewportClient.h"
#endif

#include "Kismet/KismetMathLibrary.h"


void UBCustomUtility::Test(int a, int b)
{
	
}

FVector UBCustomUtility::GetViewportCamLoc()
{
	FVector viewPos;
#if WITH_EDITOR// || !WITH_EDITOR
	//FViewport* Viewport = GEditor->GetActiveViewport();
	//FIntPoint mousePos;
	//GEditor->GetActiveViewport()->GetMousePos(mousePos, true);
	FViewport* activeViewport = GEditor->GetActiveViewport();
	FEditorViewportClient* editorViewClient = (FEditorViewportClient*)activeViewport->GetClient();
	if( editorViewClient )
	{
		viewPos = editorViewClient->GetViewLocation();
	}
	return viewPos;
#endif
	//return FVector(0.0f, 0.0f, 0.0f);
	return viewPos;
}

FRotator UBCustomUtility::GetViewportCamRot()
{
	FRotator viewRot;
#if WITH_EDITOR// || !WITH_EDITOR
	FViewport* activeViewport = GEditor->GetActiveViewport();
	FEditorViewportClient* editorViewClient = (FEditorViewportClient*)activeViewport->GetClient();
	if( editorViewClient )
	{
		viewRot = editorViewClient->GetViewRotation();
	}
	return viewRot;
#endif
	return viewRot;
}

FVector UBCustomUtility::GetViewportForwardVector(FRotator NewRotator)
{
	return UKismetMathLibrary::GetForwardVector(NewRotator);
}
