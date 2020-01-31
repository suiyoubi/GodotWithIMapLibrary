## Godot with InfluenceMap Library Integration

This repo contains the source code of godot engine and the influencemap library.
All the IMap-related codes are located in `modules/imap`, and all the other files
are kept update with the master branch of Godot.

## Usage
To use the InfluenceMap library, either clone this repo, which grants you the ability
to compile the source code into executable. What you can also do is to only download the
`modules/imap` folder, clone the source code of godot from the official website, and place
the folder into the same place. 

1. Clone the repo:
`git clone https://github.com/suiyoubi/GodotWithIMapLibrary.git`
2. Install Scons:
	- This is the build tool that godot is using for building the engine. You can read
	more about this from their official documentation [here](https://docs.godotengine.org/en/3.2/development/compiling/introduction_to_the_buildsystem.html)
	- if you are using mac, I recommend you using [brew](https://brew.sh/) to install it:
	`brew install scons`
3. Build the engine:
	- Make sure you are in the root folder of the repo
	- For mac user: `user@host:~/godot$ scons platform=osx --jobs=$(sysctl -n hw.logicalcpu)`
	- Please refer to their documentation for other specific platform usage (since I have not
	tested) [here](https://docs.godotengine.org/en/3.2/development/compiling/index.html)
4. Run the engine:
	- For mac user, you can simply execute the executable in the `bin` folder, the executable
	should be named similar to `godot.osx.tools.64`: `user@host:~/godot$ bin/godot.osx.tools.64`
5. Use the library:
	- In the Godot script, you can simply instantiate a influence instance by
	```
		var imap = IMap.new()
	```
	- It is important to call `imap.initialize_default_map()` after creating the new instance,
	the default map has size 40x30. If you want to customize the size, use `imap.create_imap()`
	- For now, there are three basic operation provided for godot: add/move/get influence source:
		- `void add_influence_source(int id, float x, float y, float influence_value);`
		- `void move_influence_source(int id, float x, float y);`
		- `float float get_influence_value_at(float x, float y);`
	- You should be able to call this three method directly from the GDScript
	- There will be more operations supported, you can read the implementation of the "wrapper" class
	[IMap.cpp](modules/imap/IMap.cpp)






[![Godot Engine logo](/logo.png)](https://godotengine.org)

## Godot Engine

Homepage: https://godotengine.org

#### 2D and 3D cross-platform game engine

Godot Engine is a feature-packed, cross-platform game engine to create 2D and
3D games from a unified interface. It provides a comprehensive set of common
tools, so that users can focus on making games without having to reinvent the
wheel. Games can be exported in one click to a number of platforms, including
the major desktop platforms (Linux, Mac OSX, Windows) as well as mobile
(Android, iOS) and web-based (HTML5) platforms.

#### Free, open source and community-driven

Godot is completely free and open source under the very permissive MIT license.
No strings attached, no royalties, nothing. The users' games are theirs, down
to the last line of engine code. Godot's development is fully independent and
community-driven, empowering users to help shape their engine to match their
expectations. It is supported by the Software Freedom Conservancy
not-for-profit.

Before being open sourced in February 2014, Godot had been developed by Juan
Linietsky and Ariel Manzur (both still maintaining the project) for several
years as an in-house engine, used to publish several work-for-hire titles.

![Screenshot of a 3D scene in Godot Engine](https://raw.githubusercontent.com/godotengine/godot-design/master/screenshots/editor_tps_demo_1920x1080.jpg)

### Getting the engine

#### Binary downloads

Official binaries for the Godot editor and the export templates can be found
[on the homepage](https://godotengine.org/download).

#### Compiling from source

[See the official docs](https://docs.godotengine.org/en/latest/development/compiling/)
for compilation instructions for every supported platform.

### Community and contributing

Godot is not only an engine but an ever-growing community of users and engine
developers. The main community channels are listed [on the homepage](https://godotengine.org/community).

To get in touch with the developers, the best way is to join the
[#godotengine IRC channel](https://webchat.freenode.net/?channels=godotengine)
on Freenode.

To get started contributing to the project, see the [contributing guide](CONTRIBUTING.md).

### Documentation and demos

The official documentation is hosted on [ReadTheDocs](https://docs.godotengine.org).
It is maintained by the Godot community in its own [GitHub repository](https://github.com/godotengine/godot-docs).

The [class reference](https://docs.godotengine.org/en/latest/classes/)
is also accessible from within the engine.

The official demos are maintained in their own [GitHub repository](https://github.com/godotengine/godot-demo-projects)
as well.

There are also a number of other learning resources provided by the community,
such as text and video tutorials, demos, etc. Consult the [community channels](https://godotengine.org/community)
for more info.

[![Travis Build Status](https://travis-ci.org/godotengine/godot.svg?branch=master)](https://travis-ci.org/godotengine/godot)
[![AppVeyor Build Status](https://ci.appveyor.com/api/projects/status/bfiihqq6byxsjxxh/branch/master?svg=true)](https://ci.appveyor.com/project/akien-mga/godot)
[![Code Triagers Badge](https://www.codetriage.com/godotengine/godot/badges/users.svg)](https://www.codetriage.com/godotengine/godot)
[![Translate on Weblate](https://hosted.weblate.org/widgets/godot-engine/-/godot/svg-badge.svg)](https://hosted.weblate.org/engage/godot-engine/?utm_source=widget)
