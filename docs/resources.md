# Other Resources
Reverse engineering _Explorers of Sky_ requires multiple skills in varying degrees. Here are some of them, with some links to help you get started:
- How to read assembly, and enough low-level knowledge of computers to understand that assembly.
    - For EoS, there are technically _two_ forms of assembly you need to know, ARM and THUMB, although they're extremely similar, and for the most part you only need to know ARM. If you're just getting started, [this guide](https://forums.therockmanexezone.com/intro-to-asm-modding-hooking-t5374.html) is a great introduction to the concepts needed to read assembly, and [this guide](https://www.coranac.com/tonc/text/asm.htm) is a fantastic reference and introduction to the finer details of ARM assembly.
- Other systems-level knowledge of the Nintendo DS.
    - Working with the EoS binaries requires you to have some specialized knowledge (but it depends on what you're doing). One of the biggest things to know about is probably the [overlay system](overlays.md). If you're working with anything graphical, there are additional concepts you'll need to know, such as the OAM ([this series of posts](https://macabeus.medium.com/reverse-engineering-a-gameboy-advance-game-introduction-ec185bd8e02) is a great introduction to these concepts for the Game Boy Advance, most of which are also relevant to the NDS).
- What reverse engineering tools are available, and how to use them properly.
    - See [General reverse engineering](#general-reverse-engineering) for some suggestions.
    - With EoS, one of the biggest obstacles when starting out is figuring out how to even [set up a project properly](ghidra-setup.md), because it's unfortunately not as simple as importing the whole ROM with one button.

## Specific to _Pokémon Mystery Dungeon: Explorers of Sky_
This is a nonexhaustive list, and only contains subjectively "large" collections of information. Note that some information from the following docs have also been added into `pmdsky-debug`.

- [Project Pokémon technical docs.](https://projectpokemon.org/docs/mystery-dungeon-nds/)
- [SkyTemple](https://skytemple.org/) and the associated [Discord server](https://discord.gg/skytemple) (the `#tech-docs` channel has some links not listed here). Also see [this directory in skytemple-files](https://github.com/SkyTemple/skytemple-files/tree/master/skytemple_files/_resources/ppmdu_config), which has XML files with various collections of useful data, and [this other directory](https://github.com/SkyTemple/skytemple-files/tree/master/skytemple_files/graphics) with various graphics file format docs.
- Other (older) tools for EoS include [Sky Editor](https://projectpokemon.org/home/files/file/4003-sky-editor-rom-editor/) and [PPMDU](https://github.com/PsyCommando/ppmdu).
- End45's [dungeon data doc](https://docs.google.com/document/d/1UfiFz4xAPtGd-1X2JNE0Jy2z-BLkze1PE4Fo9u-QeYo) and [map generation doc](https://docs.google.com/document/d/1HuJIEOtTYCtSHK6R-sp4LC2gk1RDL_mfoFL6Qn_wdkE).
- UsernameFodder's [EoS RAM notes](https://docs.google.com/document/d/1_Q_7BGmNx5wJtJ9iJEwlK1WITjiCcEQxE9C82RECJbg).
- UsernameFodder's [enum collection](https://drive.google.com/drive/folders/1-jQNhtZ-Ao-QrwoaG5LY1iVh5gUoMxlH). Most have been ported to the C headers in `pmdsky-debug`, but this still has some obscure additional info.
- ShinxHijinx's [PMD Info Spreadsheet](https://docs.google.com/spreadsheets/d/18utO_lCpWQ7iXY9wpbtxXpgmzebEI2IRjADp6IrUKZ0/edit).
- SkyTemple's [dungeon-eos](https://github.com/SkyTemple/dungeon-eos) repository is a reproduction of EoS's dungeon generation algorithm written in Python.
- [psy_commando's tools and research notes](https://projectpokemon.org/home/forums/topic/31407-pokemon-mystery-dungeon-2-psy_commandos-tools-and-research-notes/). Also see [this Dropbox folder](https://www.dropbox.com/sh/8on92uax2mf79gv/AADCmlKOD9oC_NhHnRXVdmMSa), which has some more up-to-date information.
- Some (not really organized) dumps of various bits of data from EoS on GameFAQs: [Various in-game data](https://gamefaqs.gamespot.com/boards/955859-pokemon-mystery-dungeon-explorers-of-sky/51698562), [Explorers of Darkness Dungeon FAQ 0.5](https://gamefaqs.gamespot.com/boards/938930-pokemon-mystery-dungeon-explorers-of-darkness/50597686).

## General reverse engineering
The above list is, of course, tailored to reverse engineering EoS. If you want to learn about general reverse engineering, you can Google around for various resources. If you want some concrete links, check out [wtsxDev/reverse-engineering](https://github.com/wtsxDev/reverse-engineering) and [r/ReverseEngineering](https://www.reddit.com/r/ReverseEngineering/).

Project Pokémon has a [list of reverse engineering tools](https://projectpokemon.org/home/forums/topic/39011-rom-hacking-tool-and-resource-collection/?tab=comments#comment-204182) specifically geared towards NDS ROM hacking. GBATEK also has a [full technical reference dump](https://problemkaputt.de/gbatek.htm#ndsreference), which can be useful in very specific circumstances.

## A personal list of research tools
This is a list of tools that I (UsernameFodder) use for EoS research that might prove helpful to some people. Keep in mind that I usually only do a specific subset of things when it comes to reverse engineering, so this list won't be suited for all use cases.

- [Ghidra](https://ghidra-sre.org/) (cross-platform) for the majority of asm research, since it's free and has one of the best decompilers out there. It has [built-in tutorials](https://github.com/NationalSecurityAgency/ghidra/tree/master/GhidraDocs/GhidraClass) ([HTML preview of the beginner class](https://htmlpreview.github.io/?https://github.com/NationalSecurityAgency/ghidra/blob/stable/GhidraDocs/GhidraClass/Beginner/Introduction_to_Ghidra_Student_Guide.html)). The other well known binary analysis tool is IDA, which you need to pay for (for ARM binaries). If you're a licensed IDA user, you probably don't need to be reading these docs anyway.
- [DeSmuME](https://desmume.org/) on Windows for watching memory at runtime (unfortunately only the Windows version has these tools at the time of writing). I find its memory viewer/editor (Tools > View Memory) and RAM Search (Tools > RAM Search...) tools particularly useful.
- [No$GBA](https://www.nogba.com/) (Windows only) for interactive debugging. However, I've found this emulator to be relatively unstable, and I try to avoid using it unless there's no other option.
- [DSLazy](https://projectpokemon.org/home/files/file/2118-dslazy/) (Windows only) for unpacking NDS ROMs, since it's the simplest thing with a GUI that works. It's a wrapper around [`ndstool`](https://github.com/devkitPro/ndstool), which is cross-platform. See the [Ghidra setup doc](ghidra-setup.md#unpack-the-rom) for detailed instructions.
- [SkyTemple](https://skytemple.org/) (cross-platform), primarily for getting up to speed on things the community has already figured out.
- [Hex Fiend](https://hexfiend.com/) (macOS only) and [HxD](https://mh-nexus.de/en/hxd/) (Windows only) on the rare occasion I need to do raw hex editing, but honestly any hex editor works.

## I don't know any of this and I'm feeling overwhelmed!
There's a lot to learn if you're just starting out, especially if you don't already have a background in computer science. If you want just _one_ thing to sink your teeth into initially, I recommend installing [Ghidra](https://ghidra-sre.org/) and going through the [Ghidra setup tutorial](ghidra-setup.md). The program is free, it's cross-platform and will work on any operating system, and it'll let you jump right into exploring the EoS code. The tutorial won't teach you how to read assembly, but it'll get you set up so that you can focus _just_ on learning assembly without needing to sweat the other details.
