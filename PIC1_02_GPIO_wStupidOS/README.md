
# PIC16F877A_Dev_OS

## Git contents

Commit the source and project configuration:

- `maincode/`
- `.vscode/PIC16F877A_Dev_OS.mplab.json`
- `.vscode/launch.json`
- `.vscode/settings.json`
- `.vscode/c_cpp_properties.json`
- `README.md`

Do not commit `_build/`, `out/`, or generated `cmake/` files. They contain build
cache, generated artifacts, and machine-specific paths. The local MPLAB file
`.vscode/PIC16F877A_Dev_OS.mplab-local.json` is also excluded because it stores
the programmer/debugger serial number.

## Requirements

- VS Code with the Microchip MPLAB extension for VS Code
- Microchip XC8 compiler `v3.10`
- Device Family Pack `PIC16Fxxx_DFP` version `1.8.167`
- A PICkit 4 is needed only for programming or hardware debugging

The MPLAB extension supplies/manages the generated build tools. A separate
CMake or Ninja installation is not required.

## Build after cloning

1. Open this project folder in VS Code.
2. Open `.vscode/PIC16F877A_Dev_OS.mplab.json` through the MPLAB extension.
3. Select the `default` configuration.
4. Run the MPLAB task `PIC16F877A_Dev_OS: default - Build`.
5. Use `PIC16F877A_Dev_OS: default - Build (Production)` for the production image.

## Structure

| Path                                 | Purpose                                                                                                                             |
|--------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------|
| _build                               | The [CMake build tree](https://cmake.org/cmake/help/latest/manual/cmake.1.html#introduction-to-cmake-buildsystems), can be deleted. |
| cmake                                | Generated [CMake](https://cmake.org/) files. May be deleted if user.cmake has not been added                                        |
| .vscode                              | See [VSCode](https://code.visualstudio.com/docs/getstarted/settings)                                                                |
| .vscode\settings.json                | Workspace specific settings                                                                                                         |
| .vscode\PIC16F877A_Dev_OS.mplab.json | The MPLAB project file, should not be deleted                                                                                       |
| out                                  | Final build artifacts                                                                                                               |
