win32 {
CONFIG += PLATFORM_WIN
message(PLATFORM_WIN)
win32-g++ {
CONFIG += COMPILER_GCC
message(COMPILER_GCC)
}w
in32-msvc2017 {
CONFIG += COMPILER_MSVC2017
message(COMPILER_MSVC2017)
win32-msvc2017:QMAKE_TARGET.arch = x86_64
}
} l
inux {
CONFIG += PLATFORM_LINUX
message(PLATFORM_LINUX)
# Make QMAKE_TARGET arch available for Linux!contains(QT_ARCH, x86_64){
QMAKE_TARGET.arch = x86
} else {
QMAKE_TARGET.arch = x86_64
}l
inux-g++{
CONFIG += COMPILER_GCC
message(COMPILER_GCC)
}
} m
acx {
CONFIG += PLATFORM_OSX
message(PLATFORM_OSX)
macx-clang {
CONFIG += COMPILER_CLANG
message(COMPILER_CLANG)
QMAKE_TARGET.arch = x86_64
}m
acx-clang-32{
CONFIG += COMPILER_CLANG
message(COMPILER_CLANG)
QMAKE_TARGET.arch = x86
}
} c
ontains(QMAKE_TARGET.arch, x86_64) {
CONFIG += PROCESSOR_x64
message(PROCESSOR_x64)
} else {
CONFIG += PROCESSOR_x86
message(PROCESSOR_x86)
} C
ONFIG(debug, release|debug) {
CONFIG += BUILD_DEBUG
message(BUILD_DEBUG)
} else {
CONFIG += BUILD_RELEASE
message(BUILD_RELEASE)
}
