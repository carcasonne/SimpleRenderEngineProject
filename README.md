# SimpleRenderEngine Projects



<img align="left" src="./media/gp24.png" alt="gp24" width=48/>

## ITU GameProgramming24


This is a fork of Morten Nobel-Jørgensen's SimpleRenderEngineProject, composed of a simple OpenGL renderer and a set of common dependencies for game development. This repo aim to introduce
- [x] support for x64 architectures
- [x] more streamlined dependency system
- [ ] restructure project to get rid of git submodules
- [ ] more modern and clear examples

For more informations about SimpleRenderEngine, see
https://github.com/Chris-Carvelli/SimpleRenderEngine


## Setup
- clone this repo
- initialize submodules `git submodule update --init --recursive`
- open the fodler in VisualStudio
- select `Manage Configurations` in the configuration list
![cmake_settings](media/cmake_settings.png)
- check that the current architecture matches your current system. **NB: only x64 supported at this time!**
![target_architecture](media/target_architecture.png)
- set the `SRE_LIBS_PATH` variable to the path containing the project's dependencies, then **RESTART VisualStudio**
![srep_libs](media/srep_libs.png)

## Current Known Limitations
- only Windows x64 supported at the time
- Bullet physics not integrated yet
- openVR not integrated yet
- Cmake neews a complete overhaul, in the interest of both compile performance AND being easy to understand (this is a didactical engine first and foremost)

## Credits
- https://github.com/mortennobel/SimpleRenderEngine
- https://github.com/mortennobel/SimpleRenderEngineProject
