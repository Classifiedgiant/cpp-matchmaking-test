# cpp-matchmaking-test

Testing repo for matchmaking servers

## Prerequisites

* Install Visual Studio (for Windows MSVC) or GCC on Linux
* Install CMake on your machine (Add to PATH)
* Install Python for Conan

## Setup Conan for building
* `conan install . -pr .\.conan\window_msvc_debug --build=missing` -- Pull deps from conan
   * `-pr .\.conan\window_msvc_debug` - Select profile to use for building
   * `--build=missing` - build missing
`cmake --preset --conan-default`
`cmake --preset conan-release` -- mac
`cmake --build --preset --conan-debug`


## Packing steps (Release only)
### Window
* conan install (as above with release profile)
* `cmake --preset conan-default`
   * Can be appended with `-DCMAKE_CONFIGURATION_TYPES=Debug` for Windows VS debug builds
* `cmake --build --preset conan-release`
* `cpack --config .\build\CPackConfig.cmake`
