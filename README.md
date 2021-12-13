# Starlight — SMO Base Project

This repo contains a base project that can be used to create code modifications for Super Mario Odyssey v1.0.0. It's main purpose is to give people a project that contains headers that can be used to more easily create mods that does more to the game than what can normally be done through romfs editing alone. it also contains example code to show how to do certain things within the starlight environment.

## Prerequisites

- [devkitPro](https://devkitpro.org/) 
- Python 3
- The [Keystone-Engine](https://www.keystone-engine.org/) Python Module

## Configuration and Setup

Before Building, you should make sure that the default things for the project is properly setup. 

For the TCP Logger, you can define `GLOBALDEBUGIP` to set the IP address used for connecting the socket to a server hosted on your local machine. (Note: the port can be easily changed in logger.cpp, its default value is 3080.)

In the makefile, you can set `IP`, `USER`, and `PASS` to their respective values in order to automatically send builds to an FTP server hosted on a modded switch. Then, whenever you run `make send` you'll build the project and immediately send to the switch.

Creating a custom actor is straight forward thankfully, and there is an example actor in this repository if you wish to start from one already proven working. To add more custom actors, firs you'll need to create the custom actors header and c++ files in their respective folders. Then, create a class that extends `al::LiveActor` and implement the virtual functions used in the example actor. You can then define nerves by using the `NERVE_IMPL` and `NERVE_HEADER` macros used in the [OdysseyDecomp](https://github.com/MonsterDruide1/OdysseyDecomp) project, which I included here for easy nerve defines. Then, after creating your actor, navigate to `al/factory/ActorFactoryEntries100.h` and add in the name of your class, as well as its creation function (do this by simply using al::createActorFunction<(class type)> in the second parameter for factory entries) to the static table of actor creators. 

Once you've handled most of the code for the custom actor, you can either copy an existing object archive from SMO and edit it to your liking, or create an entirely new archive, so long as the archive contains the minimum Init bymls required for an actor (most of the time its InitModel.byml, InitPose.byml, InitClipping.byml, InitExecutor.byml, and InitMaterialLight.byml), and a BFRES model if your actor needs it. Once done, save the archive, and add your custom actor to a stage you wish to have the actor in. From there everything should work and you'll have a custom actor working in Odyssey!

## Prerequisites

- [devkitPro](https://devkitpro.org/) 
- Python 3
- The [Keystone-Engine](https://www.keystone-engine.org/) Python Module

## Building

Build has only been tested on WSL2 running Ubuntu 20.04.1.

Just run:
```
DEVKITPRO={path_to_devkitpro} make
```

On Ubuntu (and other Debian-based systems), devkitPro will be installed to `/opt/devkitpro` by default:

```
DEVKITPRO=/opt/devkitpro/ make
```

## Installing (Atmosphère)

After a successful build, simply transfer the `atmosphere` folder located inside `starlight_patch_100` to the root of your switch's SD card.

---

# Credits
- [OdysseyDecomp](https://github.com/MonsterDruide1/OdysseyDecomp) nerve utility macros
- [OdysseyReversed](https://github.com/shibbo/OdysseyReversed) original decomp repo
- [open-ead](https://github.com/open-ead/sead) sead Headers
- [Bryce](https://github.com/brycewithfiveunderscores/Starlight-SMO-Example/) Original Starlight fork for SMO

# Starlight (Original README)
An enviroment for linking to Splatoon 2 executable and implementing hooks.

# Starlight Contributors
- [3096](https://github.com/3096)
- [khang06](https://github.com/khang06)
- [OatmealDome](https://github.com/OatmealDome)
- [Random0666](https://github.com/random0666)
- [shadowninja108](https://github.com/shadowninja108)
- [shibbo](https://github.com/shibbo) - Repo based on their work on OdysseyReversed
- [Thog](https://github.com/Thog) - Expertise in how rtld is implemented

# Starlight Credits
- devkitA64
- libnx - switch build rules
