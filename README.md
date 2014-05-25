EasySDL
=======

An easy interface for drawing on the screen using SDL.

Download development libraries:
    http://www.libsdl.org/download-2.0.php
    https://www.libsdl.org/projects/SDL_image/
    
Update project settings to include the include directories and lib directories of SDL and SDL_image

Add all DLLs to Windows\System32 or Windows\SysWOW64

Set Code-Generation -> Runtime Library to Multi-threaded DLL

Add
    SDL2.lib
    SDL2main.lib
    SDL2_image.lib
to Linker -> Input -> Additional Dependencies
