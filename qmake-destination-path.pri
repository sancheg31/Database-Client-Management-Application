platform_path = unknown-platform
compiler_path = unknown-compiler
processor_path = unknown-processor
build_path = unknown-build
PLATFORM_WIN {
platform_path = windows
}P
LATFORM_OSX {platform_path = osx
}P
LATFORM_LINUX {
platform_path = linux
} C
OMPILER_GCC {
compiler_path = gcc
}C
OMPILER_MSVC2017 {
compiler_path = msvc2017
}C
OMPILER_CLANG {
compiler_path = clang
} P
ROCESSOR_x64 {
processor_path = x64
}P
ROCESSOR_x86 {
processor_path = x86
} B
UILD_DEBUG {
build_path = debug
} else {
build_path = release
} D
ESTINATION_PATH = $$platform_path/$$compiler_path/$$processor_path/$$build_path
message(Dest path: $${DESTINATION_PATH})
