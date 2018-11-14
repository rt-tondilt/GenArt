# GenArt

Gallery of shader effects and generated art.

Project for Computer Graphics course (MTAT.03.015).

## Compilation instructions for Windows with Code Blocks

1. Download the source code.
2. Download GLM from https://glm.g-truc.net/ >> Downloads.
3. Copy everything inside `glm/glm` to `GenArt/include/glm`.
4. Download Windows binaries from https://www.glfw.org/download.html. Choose ones that correspond to your MinGW installation (32 or 64 bit).
5. Copy all files from `glfw-x.x.x.bin.WINxx\lib-mingw` to `GenArt/lib`.
6. Copy `GLFW` folder from `glfw-x.x.x.bin.WINxx\include` to `GenArt/include`.
7. Download Windows binaries from http://glew.sourceforge.net.
8. Copy everything from `glew-x.x.x\lib\Release\Win32` or `glew-x.x.x\lib\Release\x64` (depending on MinGW installation) to `GenArt/lib`.
9. Copy everything from `glew-x.x.x/include/GL` to `GenArt/include/GLEW`.
10. And enjoy linker errors.
