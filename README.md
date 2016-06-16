# ISXAO
### An [Inner Space](http://www.lavishsoft.com/) extension for [Anarchy Online](http://www.anarchy-online.com/).
## Commands

### **Activate** 

#### Syntax:  
`activate <Slot Name>`  

#### Description:  
Activates an item that is equipped or in the general inventory.  

##### Equipment slot names:  
###### Weapon Slots:
`WS_HUD1`
`WS_HUD2`
`WS_HUD3`
`WS_UTIL1`
`WS_UTIL2`
`WS_UTIL3`
`WS_RHAND`
`WS_BELT`
`WS_LHAND`
`WS_NCU1`
`WS_NCU2`
`WS_NCU3`
`WS_NCU4`
`WS_NCU5`
`WS_NCU6`
###### Armor Slots:
`AS_NECK`
`AS_HEAD`
`AS_BACK`
`AS_RSHOULDER`
`AS_CHEST`
`AS_LSHOULDER`
`AS_RARM`
`AS_HANDS`
`AS_LARM`
`AS_RWRIST`
`AS_LEGS`
`AS_LWRIST`
`AS_RFINGER`
`AS_FEET`
`AS_LFINGER`
###### Implant Slots:
`IS_EYES`
`IS_HEAD`
`IS_EARS`
`IS_RARM`
`IS_CHEST`
`IS_LARM`
`IS_RWRIST`
`IS_WAIST`
`IS_LWRIST`
`IS_RHAND`
`IS_LEGS`
`IS_LHAND`
`IS_FEET`
###### General Inventory:
`GI_64`
`GI_65`
`GI_66`
`GI_67`
`GI_68`
`GI_69`
`GI_70`
`GI_71`
`GI_72`
`GI_73`
`GI_74`
`GI_75`
`GI_76`
`GI_77`
`GI_78`
`GI_79`
`GI_80`
`GI_81`
`GI_82`
`GI_83`
`GI_84`
`GI_85`
`GI_86`
`GI_87`
`GI_88`
`GI_89`
`GI_90`
`GI_91`
`GI_92`
`GI_93`
`GI_94`

#### Examples:  
`activate GI_74`  
`activate WS_BELT`
	
### **AOEcho**

#### Syntax:  
`AOEcho [options] [output]`  

#### Description:  
The command echoes text directly to your chat window(s).

#### Options:
`-chattype <type>`   
By supplying a chattype, you are indicating to your client the color of the message only. All text echoed to the client is echoed as the "System" channel.  

##### Chat types:	
`Black`
`Green`
`Silver`
`Lime`
`Gray`
`Olive`
`White`
`Yellow`
`Maroon`
`Navy`
`Red`
`Blue`
`Purple`
`Teal`
`Fuchsia`
`Aqua`			
`Error`
`System`
`CmdFeedback`
`OTell`
`ITell`
`Admin`
`Clan`
`Emote`
`GM`
`Misc`
`Newbie`
`News`
`PGroup`
`SeekingTeam`
`Shout`
`Team`
`Raid`
`Tell`
`Vicinity`
`Whisper`
`Tower`
`MyPet`
`OtherPet`
`Research`			
`None`
`Comm`
`MeHitByNano`
`OtherHitByNano`
`MonsterHitMe`
`PlayerHitMe`
`MeHitOther`
`OtherHitOther`
`OtherHitOtherMyPet`
`MeHealed`
`MeGotXp`
`MeCastNano`
`Skill`
`ShowFullName`
`Link`
`ToolTip`
`Cash`
`InfoHeadline`
`InfoHeader`
`InfoText`
`InfoTextBold`
`Text`
`Header`
`NPCChat`
`NPCOOC`
`NPCEmote`
`NPCSystem`
`NPCQuestion`
`NPCDescription`
`NPCTrade`
`ItemUnknown`
`ItemTrash`
`ItemNormal`
`ItemExotic`
`ItemQuest`
`ItemSocial`
Defaults: The default "chat type" is `System`.  

#### Examples: 
`AOEcho ${Me.Name}`  
`AOEcho -chattype red ${Target.Name}`
	
### **AOExecute**

#### Syntax: 
`AOExecute <Chat Command>`  

#### Description:  
This command executes in-game AO commands. It is primarily used for executing AO commands within scripts or the InnerSpace console window.  

#### Example: 
`AOExecute /follow`

### **Face**

#### Syntax: 
`face [options]`  

#### Parameters:
* `face`
  * If used alone, the face command will face your current target.  
* `face <heading>`  
  * This command, if used with a float value, will face the given heading. A valid heading would be any float value between 0.00 and 360.00.
* `face <x> <z>`
  * This command, if used with two float values, will face the location given (on the X and Z planes).
* `face <x> <y> <z>`
  * This command, if used with three float values, will face the location given (on the X and Z planes). The Y parameter is ignored.
* `face <name>`
  * If the command is used with any character string, it will assume that you are searching for a specific entity that is either a partial or exacy match for the 'name' given.
#### Examples: 
`face Boobies`  
`face 300.15 -234.32`  
`face 46.5`  

### **Target**

#### Syntax: 
`target [parameter]`

#### Parameters:
* `target <type>`
  * Target used with a type alone, will target the nearest entity of the type given. "Type" names are:
			`me`
			`pc`
			`npc`
			`pet`
* `target <ID>`
  * Will target the entity with the provided 64-bit ID.
* `target <name>`
  * If used with any string which is not one of the "types" listed above, it will assum that you are searching for a specific after and will target the nearest actor that is either a partial or exact match for the actor name given.

#### Examples: 
`target Boobies`  
`target me`  
`target pc`  

## Datatypes

### **AO**
This datatype include miscellaneous data that is available to ISXAO that pertain to the Anarchy Online gameworld.  

#### Members:  
* `bool CheckCollision[to_X, to_Y, to_Z, from_X, from_Y, from_Z]` 
  * TRUE if the there is line of sight between the provided positions. 
    * Note: When determining whether or not the client has line of sight to an object for purposes of casting or attacking, it adds 1.6 units to the Y axis of the player and object to account for height. This member does not account for this offset. If you wanted to see if a dynel had line of sight to another for the purposes of casting or attacking, you would need to add 1.6 units the the y-axis value provided.
* `uint GetActors[index:actor]`
  * This member fills the provided index with an array of actors visible to the client at the point of creation, sorted by distance. The returned value is the number of actors in the index.
* `float HeadingTo[to_X, to_Y, to_Z, from_X, from_Y, from_Z]`
  * Returns the heading you would need to face from the from point to to reach the to point.
* `int Zoning`
  * Return values are: -1 = unsure, 0 = not zoning, 1 = zoning

### **ActionLock**
This datatype has data pertaining a specific locked skill or action.  

#### Members:
* `uint LockoutTimeLeft`
  * The number of seconds of lockout time remaining.
* `uint LockoutTimeTotal`
  * The number of seconds that the skill or action was locked after use.
* `string ToString`
  * The number of seconds of lockout time remaining.
	
### **Actor** (inherits from **Dynel**)
Actor represents NPCs on the playfield that the character can affect.  

#### Members:

##### General:
* `string Breed`
  * The actor's breed.
* `uint Casting`
  * Returns the nano id of the spell currently being cast be the dynel. `0` if the actor is not casting.  
* `int CurrentHealth`
  * The current health of the actor.
* `uint CurrentNCU`
  * The current NCU of the actor.	
* `string Gender`
  * The actor's gender.
* `uint GetPets[index:actor]`
  * Populates the supplied index of type actor with the pets of the actor. Returns the size of the index. For the client's pets, you will need to use .ToPet in order to issue commands.
* `uint Level`
  * The actor's level. For players, this is their profession level and Shadowlands levels.
* `variable Pet[n] or Pet[name]`
  * Retrieves the nth pet of the actor or the first pet that matches the name or partial name provided. The return type is Pet for pets belonging to the Character and Actor for all other pets.
* `uint PetCount`
  * The number of pets controlled by the actor.	
* `variable Master`
  * If the actor is a pet, this is their master. The return type will be the type of the master (actor, player, or character).	
* `uint MaxHealth`
  * The maximum health of the actor. This number seems to always be a little off. Using CurrentHealth and PctHealth to determine the MaxHealth may be more reliable.
* `uint PctHealth`
  * The percent health of the actor.  (0 to 100)	
* `string Profession`
  * The profession of the actor;
* `int RunSpeed`
  * The runspeed skill of the actor.
* `float Speed`
  * The speed of the actor in units/s.
* `string ToString`
  * The identity of the actor.
* `point3f Velocity`
  * The actor's velocity in 3-dimensions.	

##### Location:
* `float CharRadius`
  * The radius of the actor for collision purposes.
* `float DistancePredict`
  * The estimated distance to the actor accounting for the actor's speed and heading in the XZ-plane.	

##### Boolean:
* `bool GM`
  * TRUE if the actor has a GM level greater than zero. Do not trust this for any reason.
* `bool HasPets`
  * TRUE if the actor has a pet on the playfield.
* `bool IsBackingUp`
  * TRUE if actor is backing up.
* `bool IsCasting`
  * TRUE if the actor is casting.
* `bool IsFighting` 
  * TRUE if the actor is fighting.
* `bool IsFightingMe` 
  * TRUE if the actor is fighting and the character is the actor's target.
* `bool IsIdle` 
  * TRUE if the actor is not moving forward/backward and not strafing left/right.
* `bool IsInvis` 
  * TRUE if the actor is not visible.
* `bool IsMovingForward` 
  * TRUE if the actor is moving forward.
* `bool IsStealthed` 
  * same as IsInvis.
* `bool IsStrafingLeft` 
  * TRUE if the actor is strafing left.
* `bool IsStrafingRight` 
  * TRUE if the actor is strafing right.			

###### Mutually Exclusive:
* `bool IsCrawling` 
  * TRUE if the actor is crawling.
* `bool IsFlying` 
  * TRUE if the actor is flying.
* `bool IsRooted` 
  * TRUE if the actor is rooted.
* `bool IsRunning` 
  * TRUE if the actor's movement mode is set to run.	
* `bool IsSneaking` 
  * TRUE if the actor is sneaking. This refers only to movement speed. Use IsInvis or IsStealthed to see if you are invisible to others.	
* `bool IsSwimming` 
  * TRUE if the actor is swimming.
* `bool IsWalking` 
  * TRUE if the actor's movement mode is set to walk.	

##### Effects:
* `uint GetNCU[index:nanotemplate]`
  * Populates the supplied index of type nanotemplate with the nanotemplates in the actor's NCU.	
* `nanotemplate NCU[n] or NCU[name]`
  * Retrieves the *nth* nanoprogram (from `1 to NCUCount`) running in the actor's NCU or the first nanoprogram in the actor's NCU that matches the name or partial name provided.
* `uint NCUCount`
  * The number of nanoprograms running in the actor's NCU.
	
#### Methods:
* `DoFace`
  * The character will rotate to face the actor.
* `DoTarget`
  * The character will target the actor.	
	
### **Dynel**
Dynel represents a game object on the playfield. This includes players, monsters, doors, mission kiosks, corpses, and even some player carried weapons and containers. The main purpose of this datatype is to allow you to collect enough information to determine the correct type and then cast it to the type. There is very limited information available about these objects.  

#### Members:

##### General:
* `identity Identity`
  * The globally unique type and identifier for the dynel.
* `uint Id` 
  * The unique identifier of the dynel.
* `string Name` 
  * The name of the dynel.
* `variable NearestDynel[(optional)n]`
  * Returns the *nth* closest dynel to this dynel. The return type will correspond to the dynel's actual type (`actor`, `player`, `character`, etc.).	
* `string ToString` 
  * The dynel's identity.
* `string Type` 
  * The dynel type (corpse, actor, player, etc.).

##### Location:
* `float Distance` 
  * The distance to the dynel on the XYZ-plane.
* `float Distance2D` 
  * The distance to the dynel on the XZ-plane.		
* `float X` 
  * The x-coordinate of the dynel position. (East-West)
* `float Y` 
  * The y-coordinate of the dynel position. (North-South)
* `float Z` 
  * The z-coordinate of the dynel position. (Up-Down)
* `point3f Loc `
  * The position of the dynel in point3f format.	
* `float Heading` 
  * The compass heading the dynel is facing.
* `float HeadingTo` 
  * The compass heading for the player to face this dynel.
* `float HeadingToLoc[x,z]` 
  * The compass heading to a location specified by a two argument offset (x, z) from the dynel's position. HeadingToLoc[0,-1] determines the heading to a location 1m south of the dynel.
* `bool CheckCollision` 
  * TRUE if the player has line of sight to the dynel for purposes of attacking or casting.
* `bool CheckCollision[point3f]` 
  * TRUE if the dynel has line of sight to the provided position. 
    * Note: When determining whether or not the client has line of sight to an object for purposes of casting or attacking, it adds 1.6 units to the y-axis of the player and object to account for height. This member does not account for this offset. If you wanted to see if this dynel had line of sight to another for the purposes of casting, you would need to add 1.6 units the the y-axis of the point3f provided.
* `bool CheckCollision[to_x, to_y, to_z]` 
  * TRUE if the dynel has line of sight to the provided position.
    * Note: When determining whether or not the client has line of sight to an object for purposes of casting or attacking, it adds 1.6 units to the y-axis of the player and object to account for height. This member does not account for this offset. If you wanted to see if this dynel had line of sight to another for the purposes of casting, you would need to add 1.6 units the the y-axis value provided.	

##### Type Casting:
* `actor ToActor`
  * Casts the `dynel` type to an `actor` type.
* `pet ToPet`
  * Casts the `dynel` type to a `pet` type. The `pet` type is for the client character's pets only. All other pets should use `ToActor`.
* `player ToPlayer`
  * Casts the Dynel to a Player.
* `teammember ToTeamMember`
  * Casts the Dynel to a TeamMember.	

##### Booleans:
* `bool IsActor` 
  * TRUE if the dynel is an actor.
* `bool IsAPet` 
  * TRUE if the dynel is a pet.	
* `bool IsCharacter` 
  * TRUE if the dynel is the client character.
* `bool IsMyPet` 
  * TRUE if the dynel is the character's pet.
* `bool IsPlayer` 
  * TRUE if the dynel is a player.
* `bool IsTeamMember` 
  * TRUE if the dynel is in the character's team.	

#### Methods:
* `Interact`
  * Has the effect of right clicking on the dynel. (e.g. start trade with a player, open a mission kiosk, etc.)
	
### **Identity**
The identity serves as a globally unique identifier for all in-game objects. The HIDWORD is the object type and the LODWORD is the unique identifier.  

### Members:
* `uint Type` 
  * The object type (nano, weapon, container, corpse, door, player, mission, etc.).
* `uint Id` 
  * The unique identifier assigned to the object.
* `string ToString` 
  * The identity.	
	
### **InventoryItem**
This datatype includes data available to ISXAO related to items.  

#### Members:

##### General:
* `string Description` 
  * The description of the item.
* `string Name` 
  * The name of the item.
* `string ToString` 
  * The item's name.	

##### Booleans:
* `bool CanApplyOnFriendly` 
  * TRUE if the item can be used on friendly players.
* `bool CanApplyOnHostile` 
  * TRUE if the item can be used on hostile players or NPCs.
* `bool CanApplyOnFightingTarget` 
  * TRUE if the item can be used on the player's fighting target only.
* `bool CanApplyOnSelf` 
  * TRUE if the item can be used on the player only.
* `bool CanBeSplit` 
  * TRUE if the item can be split.
* `bool CanUse` 
  * TRUE if the item can be used.
* `bool IsArmor` 
  * TRUE if the item is an armor item.
* `bool IsConsumable` 
  * TRUE if the item is a consumable.
* `bool IsImplant` 
  * TRUE if the item is an implant.
* `bool IsMisc` 
  * TRUE if the item is a miscellaneous item.
* `bool IsNPC` 
  * TRUE if the item is an NPC.
* `bool IsSpirit` 
  * TRUE if the item is a spirit.
* `bool IsStackable` 
  * TRUE of the item is stackable.
* `bool IsTower` 
  * TRUE if the item is a tower.
* `bool IsWeapon` 
  * TRUE if the item is a weapon.
* `bool IsUtility` 
  * TRUE if the item is a utility item.
* `bool MustSit` 
  * TRUE if the target of the item must be sitting in order to apply the item.
	
### **InventorySlot**
This datatype includes data available to ISXAO related to the inventory slots in which inventory items reside.  

#### Members:
* `string Name` 
  * The name of the item in the inventory slot.
* `inventoryitem Item` 
  * The item in the inventory slot.
* `identity Slot` 
  * The identity of the inventory item slot.
* `string ToString` 
  * The name of the slot.
#### Methods:
* `Use` 
  * This will attempt to use the item in the inventory slot.
	
### **ISXAO**
This datatype interacts with the extension itself.  

#### Members:
* `bool IsReady`
  *  TRUE once the extension has been intialized and is ready to go. Your scripts should always check to make sure this is TRUE before continuing.
* `string Version`
  *  Returns the ISXAO version.
	
### **NanoSpell**
This datatype includes all of the data available to ISXAO related to a nanoprogram.  

#### Members:
* `float CastingTime` 
  * The time required to cast the nanoprogram, in seconds.
* `float FormulaProgress` 
  * The time spent casting this nanoprogram, in seconds.
* `uint FormulaRadius` 
  * The radius of the nanoprogram, in units. If greater than 0, this is an area-effect nanoprogram.
* `string Name` 
  * The name of the nanoprogram.
* `string NanoSchool` 
  * The school of the nanoprogram: Combat, Medical, Protection, Psi, and Space.
* `uint NanoStrain` 
  * The strain of the nanoprogram.
* `uint NCUCost` 
  * The NCU cost of the nanoprogram.
* `uint Range` 
  * The range of the nanoprogram.
* `float RechargeDelay` 
  * The recharge delay of the nanoprogram, in seconds.
* `string ToString` 
  * The nano id of the nanoprogram.

#### Methods:
* `Cast` 
  * Will attempt to cast the nanoprogram.

### **NanoTemplate**
This datatype includes all of the data available to ISXAO related to a nanoprogram running in an NCU.  

#### Members:
* `identity CasterId` 
  * The identity of the caster that applied the nanoprogram. This information does not persist through zoning or logging in or out.
* `uint NanoId` 
  * The id of the applied nanoprogram effect. This id is used in conjuntion with NanoSpell TLO to obtain information about the effect.
* `uint TimeCast` 
  * The number of seconds after the client character entered the gameworld that the nanoprgram was applied.
* `uint TotalDuration` 
  * The total number of seconds that the nanoprogram will remain in the NCU.
* `float TimeRemaining` 
  * The remaining duration of the nanoprogram, in seconds.
* `string ToString` 
  * The nano id of the nanotemplate.

#### Methods:
* `Remove` 
  * Will attempt to remove the nanoprogram effect from the NCU. This will only work for things the client character could normally cancel on their own.
	
### **Pet** (inherits from **Actor**)
Pet represents a pet owned by the client character.  

#### Members:
* `uint Type` 
  * The type of the pet.
* `string ToString` 
  * The identity of the pet.

#### Methods:
* `Attack` 
  * Issues the attack command to the pet.
* `Behind` 
  * Issues the behind command to the pet.
* `Follow` 
  * Issues the follow command to the pet.
* `Guard` 
  * Issues the guard command to the pet.
* `Heal` 
  * Issues the heal command to the pet.
* `Report` 
  * Issues the report command to the pet.
* `Terminate` 
  * Issues the terminate command to the pet.
* `Wait` 
  * Issues the wait command to the pet.
		
### **Player** (inherits from **Actor**)
Player represents player characters on the playfield that the character can affect.  

#### Members:

##### General:
* `uint ProfessionLevel` 
  * The profession level of the player.
* `string VisualProfession` 
  * The visual profession of the player.
* `string ToString` 
  * The identity of the player.

##### Boolean:
* `bool IsInMyTeam` 
  * TRUE if the player is in the client character's team/raid.
* `bool IsInTeam` 
  * TRUE if the player is in a team/raid.	

#### Methods:
* `Invite` 
  * Attempts to invites the player to a team.

### **Playfield**
This datatype includes the data available to the ISXAO about the current playfield (zone).  

#### Members:
* `string Name` 
  * The name of the playfield.
* `uint ID` 
  * The ID of the playfield.
* `string ToString` 
  * The name of the playfield.
	
### **SpecialAction**
This datatype includes the data available to ISXAO about special actions available to the character. (i.e. sit/stand, brawl, perks, fling shot, etc.) 

#### Members:
* `identity Identity` 
  * The identity of the special action.
* `string Name` 
  * The name of the special action.
* `bool IsLocked` 
  * TRUE if the action is locked. This is only TRUE if this specific action is locked.
* `actionlock LockInfo` 
  * If the action is locked, LockInfo will return the ActionLock info for the action.
* `string ToString` 
  * The identity of the action.

#### Methods:
* `Use`
  * Attempts to use the action.
	
### **TeamEntry**
This datatype includes the data available to ISXAO about a team/raid member entry.

#### Members:
* `string Name` 
  * The name of the team/raid member.
* `string Identity` 
  * The identity of the team/raid/member.
* `teammember ToTeamMember` 
  * Casts the TeamEntry to the TeamMember datatype. This will only work if the team/raid member is in range.
* `string ToString` 
  * The identity of the team/raid member.

#### Methods:
* `Kick` 
  * Attempts to kick the team/raid member from the team.
* `MakeLeader` 
  * Attempts to make the team/raid member the leader of the team.

### **TeamMember** (inherits from **Player**)
This datatype includes the data available to ISXAO about a team/raid member player.  

#### Members:

##### General:
* `uint CurrentNano` 
  * The current nano energy of the team member.
* `uint MaxNano` 
  * The current maximum nano energy of the team member.
* `uint PctNano` 
  * The percent nano energy of the team member. (0 to 100).	

##### Boolean:
* `bool IsInMyRaidTeam` 
  * TRUE if the team member is in the Character's group.	

#### Methods:
* `Kick` 
  * Removes the player from the team if you are the leader.
* `MakeLeader` 
  * Makes the team member the team leader if the Character is the leader.
	
### **TeamRaid**
This datatype contains the data available to ISXAO about the character's team/raid.

#### Members:
* `uint GetTeam[index:teamentry]` 
  * Populates the supplied index with the character's team member entries. Returns the size of the returned index.
* `uint GetRaid[index:teamentry]` 
  * Populates the supplied index with the character's raid member entries. Returns the size of the returned index.
* `teamentry Leader` 
  * The leader of the team.
* `teamentry Team[n] or Team[name]` 
  * Retrieves the team member at the specified index (from 1 to TeamCount) or the first team meber that matches the partial name provided.
* `uint TeamCount` 
  * The number of members in the team.
* `TeamEntry Raid[n] or Raid[name]` 
  * Retrieves the raid member at the specified index (from 1 to RaidCount) or the first raid member that matches the partial name provided.
* `uint RaidCount` 
  * The number of members in the raid.

	
## Top-Level Objects

### **AO**

Description:
	Retrieves information about AO.
Form:
	ao AO
Example:
	echo ${AO.Zoning}

Actor
Description:
	Retrieves an actor from the gameworld.
Form:
	actor Actor[(optional)nth, <parameter>, ...]
	Parameters
		me - Returns the client character.
		nth - Identifies which actor in the collection of actors to return (e.g. 2nd, 3rd, etc.). If left out, it will always return the nearest.
		pc - Returns the nth nearest pc.
		npc - Returns the nth nearest npc.
		pet - Returns the nearest pet that is not the character's pet.
		mypet - Returns your nth nearest pet.
		nopet - Removes any pets from the search.
		range, #, # - Returns the nth nearest actor with a level between the two values provided.
		loc, #, # - Returns the nth nearest actor to the x and z coordinates provided.
		radius, # - Provides the maximum search radius for the location provided by loc, #, #.
		id, # - Returns the actor that matches the identity provided.
		yradius, # - Provides a y-axis filter for searches.
		notid, # - Returns the nth nearest actor that does not match the provided identity.
		nopcnear[, #] - Returns the nth nearest actor for which there is no pc within the given radius from it. If no argument is given, then it defaults to a range of 200.
		# - Returns the nth nearest actor with a level that matches the number provided. This argument must be preceded by an nth parameter if it is the first parameter.
		"string" - Returns the nth nearest actor whose name matches or partial matches the string provided.
Examples:
	${Actor[npc]}
	${Actor[npc, nopet]}
	${Actor[2, npc]}
	${Actor[me]}
	${Actor[mypet]}
	${Actor[2, mypet]}
	${Actor[npc, range, 100, 118]}
	${Actor[Boobies]}
	${Actor[nopcnear, 15, range, 15, 20]}		
		
ActorCount
Description:
	Retrieves the number of actors in the gameworld that match the provided search parameters.
Form:
	uint ActorCount[<parameter>, ...]
	Parameters:
		same as TLO Actor
Example:
	${ActorCount[nopcnear, 30, range, 15, 20]}
		
ISXAO
Description:
	Retrieves information about ISXAO.
Form:
	isxao ISXAO
Examples:
	echo ${ISXAO.Version}
	
Me:
Description:
	Retrieves information about the client character.
Form:
	character Me
Example:
	echo ${Me.Name}
	
NanoSpell
Description:
	Retrieves information about nanoprograms.
Forms:
	nanospell NanoSpell[#]
		Retrieves the nanospell object for the provided NanoId. This will work for any valid NanoId, not just NanoIds for nanoprograms known by the client.
	nanospell NanoSpell[name]
		Retrieves the first nanospell object that matches or partially matches the provided name. This is only valid for nanoprograms that are "known" by the client at the time. Nanoprograms are "known" to the client if they have been cast by the client or another in the client's vicinity, or the nanoprogram is active in the NCU of the client or another in the client's vicinity. All nanoprograms memorized by the client character are "known" to the client after the Nanoprogram window is opened.
Example:
	${NanoSpell[${Me.NCU[3]}].Name}

Playfield:
Description:
	Retrieves information about the current playfield (zone).
Form:
	playfield Playfield
Examples:
	${Playfield.Name}

Target
Description:
	Retrieves information about the client's selection target.
Form:
	variable Target (the return type will be the type of the target: actor, player, etc.)
Example:
	${Target.CurrentHealth}
	
TeamRaid
Description:
	Retrieves information about the client's team/raid.
Form:
	teamraid TeamRaid
Example:
	echo ${TeamRaid.Leader.Name}
		
WeaponTarget
Description:
	Retrieves information about the client's weapon target. This is the target of the client's weapon when auto-attack is on. It may or may not be the client's selection target.
Form:
	variable WeaponTarget  (the return type will be the type of the weapon target: actor, player, etc.)
Example:
	${WeaponTarget.CurrentHealth}
	
Events

AO_onAddPet
Triggers when a pet is added to the client.
Arguments:
int PetId

AO_onAttack
Triggers when the client attacks a target.
Arguments:
int TargetId

AO_onCastNanoSpell
Triggers whenever a nano is cast by the client or anyone in the vicinity of the client.
Arguments:
int NanoId, int TargetId, int CasterId
Child Events:
	AO_onCastNanoSpell_TargetSelf/AO_onCastNanoSpell_TargetOther
	AO_onCastNanoSpell_CasterSelf/AO_onCastNanoSpell_CasterOther
	
AO_onFinishedCastingNano
Triggers when a nano cast by the client has completed.
Arguments:
int NanoId

AO_onFollowTarget
Triggers when you begin autofollowing your target.
Arguments:
int TargetId

AO_onIncomingSystemText
Triggers when text is output to the client that is not a Vicinity, Tell, or Group Message.
Arguments:
string ChatType
	Chat Types:
	YOUR_PETS
	OTHER_PETS
	ME_HIT_BY_ENVIRONMENT
	ME_HIT_BY_OYHER
	YOUR_PET_HIT_BY_NANO
	OTHER_HIT_BY_NANO
	YOU_HIT_OTHER_WITH_NANO
	ME_HIT_BY_MONSTER
	ME_HIT_BY_PLAYER
	YOU_HIT_OTHER
	YOUR_PET_HIT_BY_OTHER
	OTHER_HIT_BY_OTHER
	ME_GOT_XP
	ME_GOT_SK
	YOUR_PET_HIT_BY_MONSTER
	YOUR_MISSES
	OTHER_MISSES
	YOU_GAVE_HEALTH
	ME_GOT_HEALTH
	ME_GOT_NANO
	YOU_GAVE_NANO
	ME_CAST_NANO
	TEAM_LOOT_MESSAGES
	VICINITY_LOOT_MESSAGES
	RESEARCH
	0 - All text that does not fall into the above categories has a chat type of '0.' (zero)
string Text

AO_onGroupMessageReceived
Triggers when the client receives a message on a channel (i.e. org, Clan OOC, etc...).
Arguments:
string SenderName
string ChannelName
string Message
int64 SenderId

AO_onNanoApplied
Triggers when a nano effect is applied to the client or anyone in the vicinity of the client.
Arguments:
int NanoId, int CasterId, int Duration
	
AO_onStand
Triggered when the client stands.
Arguments:
none

AO_onTellReceived
Triggered when the client receives a message from another player.
Arguments:
string SenderName
string Message
int64 SenderId
	
AO_onVicinityMessageReceived
Triggered when there is a vicinity message in the vicinity of the client (i.e. whisper, shout, yell).
Arguments:
string SenderName
string Message
int64 SenderId
	
AO_onZoneBegin
Triggered when zoning begins.
Arguments:
none

AO_onZoneEnd
Triggered when zoning is complete.
Arguments:
none