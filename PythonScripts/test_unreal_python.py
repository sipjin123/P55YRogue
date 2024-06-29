import unreal
import random

UBase = unreal.GlobalEditorUtilityBase.get_default_object()
EAS = unreal.get_editor_subsystem(unreal.EditorActorSubsystem)
selectedActors = EAS.get_selected_level_actors()

# TO STUDY
#SelectedActors = unreal.EditorFilterLibrary.by_class(actorSub.get_selected_level_actors(), unreal.StaticMeshActor)

   #unreal.get_editor_subsystem(unreal.StaticMeshEditorSubsystem).

   # join_static_mesh_actors(list_of_actors, my_options)

    #actorLabel = actor.get_actor_label()
    #actorPos = actor.get_actor_location()
#unreal.Interface.call_method(actor, “YourFunctionNameAsInCpp”, FunctionArgumentsIfAny)
newConsoleCommands = ['r.ScreenPercentage 0.1', 'r.Color.Max 6', 'stat fps', 'stat unit']


#region Get Actors
def getAllActorsOfClass(use_selection=False, actor_class=None,actor_tag=None):
  if use_selection:
    unreal.log("SELECTION")

    # Selection Filter
    selected_actors = selectedActors
    # Class Filter
    class_actors = [x for x in selected_actors if cast(x, actor_class)]
    # Tag Filter
    tag_actors = class_actors
    if(actor_tag):
      tag_actors = [x for x in selected_actors if x.actor_has_tag(actor_tag)]
      
    return [x for x in tag_actors]
  elif actor_class:
    unreal.log("CLASS FILTER")

    world = unreal.get_editor_subsystem(unreal.UnrealEditorSubsystem).get_editor_world()
    actors = unreal.GameplayStatics.get_all_actors_of_class(world, actor_class)
    tag_actors = actors
    if (actor_tag):
      tag_actors = [x for x in actors if x.actor_has_tag(actor_tag)]

    for q in tag_actors:
        print (q.get_name())
    return [x for x in tag_actors]
  elif actor_tag:
    unreal.log("TAG FILTER")

    world = unreal.get_editor_subsystem(unreal.UnrealEditorSubsystem).get_editor_world()
    tag_actors = unreal.GameplayStatics.get_all_actors_with_tag(world, actor_tag)
    
    return [x for x in tag_actors]
  else:
    world = unreal.get_editor_subsystem(unreal.UnrealEditorSubsystem).get_editor_world()
    actors = unreal.GameplayStatics.get_all_actors_of_class(world, unreal.Actor)
    unreal.log("DEFAULT")
    return [x for x in actors]
  
def cast(object_to_cast, object_class):
  try:
    return object_class.cast(object_to_cast)
  except:
    return None

#endregion
def getSelected_actors():
   #return unreal.UnrealEditorSubsystem.get_selected_level_actors()
   return selectedActors

   # DEPRECATED return unreal.EditorLevelLibrary.get_selected_level_actors()

def setSelected_actors(actors_to_select=[]):
   return unreal.EditorLevelLibrary.set_selected_level_actors(actors_to_select)

def getSelectedActors_TEST():
   for x in getSelected_actors():
    print (x.get_name())

def runVectorTest():
    v1 = unreal.Vector()
    v1.x = 10
    v2 = unreal.Vector(10, 20, 30)
    v3 = (v1 + v2) * 2
    print(v3)

def focusViewportOnActor(active_viewport_only=True, actor=None):
   command = 'CAMERA ALIGN'
   if (active_viewport_only):
      command += ' ACTIVEVIEWPORTONLY'
   if actor:
      command += ' NAME=' + actor.get_name()
   # Custom C++ Script [NOT WORKING YET][CustomPythonLinker]
   #unreal.CustomPythonLinker.ExecuteConsoleCommand(command)

   #unreal.SystemLibrary.execute_console_command(None, "CAMERA ALIGN ACTIVEVIEWPORTONLY")
   unreal.SystemLibrary.execute_console_command(None, command)

def checkDir():
   # Unfiltered Classes to see if custom class is compiled and recognized in python
   for x in sorted(dir(unreal)):
    print (x)

def getFuncsFromPythonLinker():
  # Get functions from custom c++, NOTE: Function names are different in python, log here to check
  for c in sorted(dir(unreal.CustomPythonLinker)): #unreal.CustomPythonLinker / unreal.BCustomUtility
    print (c)
    
def focusViewportOnRandomActor_Test(shouldRandom = False):
   world = unreal.get_editor_subsystem(unreal.UnrealEditorSubsystem).get_editor_world()
   # DEPRECATED world = unreal.EditorLevelLibrary.get_editor_world()
   actors = unreal.GameplayStatics.get_all_actors_of_class(world, unreal.Actor)
   if (shouldRandom):
    randomActorInWorld = actors[random.randrange(len(actors))]
    focusViewportOnActor(False, randomActorInWorld)
   else:
    lenNew = len(getSelected_actors())-1
    focusViewportOnActor(False, getSelected_actors()[lenNew])

def spawnActor():
  asset_path = "/Game/Blueprints/AI/EnemyAI/Actors/MeleeEnemyBP"
  bp_class = unreal.EditorAssetLibrary.load_blueprint_class(asset_path)

  newVec = unreal.BCustomUtility.get_viewport_cam_loc()
  newRot = unreal.BCustomUtility.get_viewport_cam_rot()
  newForwardVec = unreal.BCustomUtility.get_viewport_forward_vector(newRot)

  newVec = newVec + (newForwardVec * 1000)
  newActor = unreal.EditorLevelLibrary.spawn_actor_from_class(bp_class, newVec)
  newActorArray = [newActor]
  unreal.EditorLevelLibrary.set_selected_level_actors(newActorArray)
  print(newActor.get_name())

def TestLogs():
    unreal.log("wat")
    unreal.log_warning("aw")
    unreal.log_error("tw")
    print("tyeseter")

#getSelected_actors()

print("--------------------")
#getSelectedActors_TEST()
#focusViewportOnRandomActor_Test(False)
#print(UBase.get_selected_assets())

#getAllActorsOfClass(False, None, "")
#getAllActorsOfClass(False, unreal.Character, "")
#print(getAllActorsOfClass(False, unreal.Actor, ""))

#setSelected_actors(getAllActorsOfClass(False, unreal.Character, ""))

#unreal.Character / unreal.Actor

#unreal.CustomPythonLinker.called_from_python("wa")
#print (unreal.CustomPythonLinker.call_my_test())
       

spawnActor()