set(CMAKE_C_COMPILER "/apps/all/AOCC/3.2.0-GCCcore-11.2.0/bin/clang")
set(CMAKE_C_COMPILER_ARG1 "")
set(CMAKE_C_COMPILER_ID "Clang")
set(CMAKE_C_COMPILER_VERSION "13.0.0")
set(CMAKE_C_COMPILER_VERSION_INTERNAL "")
set(CMAKE_C_COMPILER_WRAPPER "")
set(CMAKE_C_STANDARD_COMPUTED_DEFAULT "17")
set(CMAKE_C_EXTENSIONS_COMPUTED_DEFAULT "ON")
set(CMAKE_C_COMPILE_FEATURES "c_std_90;c_function_prototypes;c_std_99;c_restrict;c_variadic_macros;c_std_11;c_static_assert;c_std_17;c_std_23")
set(CMAKE_C90_COMPILE_FEATURES "c_std_90;c_function_prototypes")
set(CMAKE_C99_COMPILE_FEATURES "c_std_99;c_restrict;c_variadic_macros")
set(CMAKE_C11_COMPILE_FEATURES "c_std_11;c_static_assert")
set(CMAKE_C17_COMPILE_FEATURES "c_std_17")
set(CMAKE_C23_COMPILE_FEATURES "c_std_23")

set(CMAKE_C_PLATFORM_ID "Linux")
set(CMAKE_C_SIMULATE_ID "")
set(CMAKE_C_COMPILER_FRONTEND_VARIANT "GNU")
set(CMAKE_C_SIMULATE_VERSION "")




set(CMAKE_AR "/apps/all/AOCC/3.2.0-GCCcore-11.2.0/bin/llvm-ar")
set(CMAKE_C_COMPILER_AR "/apps/all/AOCC/3.2.0-GCCcore-11.2.0/bin/llvm-ar")
set(CMAKE_RANLIB "/apps/all/AOCC/3.2.0-GCCcore-11.2.0/bin/llvm-ranlib")
set(CMAKE_C_COMPILER_RANLIB "/apps/all/AOCC/3.2.0-GCCcore-11.2.0/bin/llvm-ranlib")
set(CMAKE_LINKER "/apps/all/AOCC/3.2.0-GCCcore-11.2.0/bin/ld.lld")
set(CMAKE_MT "")
set(CMAKE_COMPILER_IS_GNUCC )
set(CMAKE_C_COMPILER_LOADED 1)
set(CMAKE_C_COMPILER_WORKS TRUE)
set(CMAKE_C_ABI_COMPILED TRUE)

set(CMAKE_C_COMPILER_ENV_VAR "CC")

set(CMAKE_C_COMPILER_ID_RUN 1)
set(CMAKE_C_SOURCE_FILE_EXTENSIONS c;m)
set(CMAKE_C_IGNORE_EXTENSIONS h;H;o;O;obj;OBJ;def;DEF;rc;RC)
set(CMAKE_C_LINKER_PREFERENCE 10)

# Save compiler ABI information.
set(CMAKE_C_SIZEOF_DATA_PTR "8")
set(CMAKE_C_COMPILER_ABI "ELF")
set(CMAKE_C_BYTE_ORDER "LITTLE_ENDIAN")
set(CMAKE_C_LIBRARY_ARCHITECTURE "")

if(CMAKE_C_SIZEOF_DATA_PTR)
  set(CMAKE_SIZEOF_VOID_P "${CMAKE_C_SIZEOF_DATA_PTR}")
endif()

if(CMAKE_C_COMPILER_ABI)
  set(CMAKE_INTERNAL_PLATFORM_ABI "${CMAKE_C_COMPILER_ABI}")
endif()

if(CMAKE_C_LIBRARY_ARCHITECTURE)
  set(CMAKE_LIBRARY_ARCHITECTURE "")
endif()

set(CMAKE_C_CL_SHOWINCLUDES_PREFIX "")
if(CMAKE_C_CL_SHOWINCLUDES_PREFIX)
  set(CMAKE_CL_SHOWINCLUDES_PREFIX "${CMAKE_C_CL_SHOWINCLUDES_PREFIX}")
endif()





set(CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES "/apps/all/binutils/2.38-GCCcore-12.1.0/include;/apps/all/zlib/1.2.12-GCCcore-12.1.0/include;/apps/all/libarchive/3.6.1-GCCcore-12.2.0/include;/apps/all/XZ/5.2.7-GCCcore-12.2.0/include;/apps/all/cURL/7.86.0-GCCcore-12.2.0/include;/apps/all/OpenSSL/1.1/include;/apps/all/bzip2/1.0.8-GCCcore-12.2.0/include;/apps/all/ncurses/6.3-GCCcore-12.2.0/include;/apps/all/libxml2/2.9.10-GCCcore-11.2.0/include/libxml2;/apps/all/libxml2/2.9.10-GCCcore-11.2.0/include;/apps/all/imkl/2022.0.1/mkl/2022.0.1/include/fftw;/apps/all/imkl/2022.0.1/mkl/2022.0.1/include;/apps/all/impi/2021.5.0-intel-compilers-2022.0.1/mpi/2021.5.0/include;/apps/all/UCX/1.11.2-GCCcore-11.2.0/include;/apps/all/numactl/2.0.14-GCCcore-11.2.0/include;/apps/all/intel-compilers/2022.0.1/tbb/2021.5.0/include;/apps/all/AOCC/3.2.0-GCCcore-11.2.0/include;/apps/all/AOCC/3.2.0-GCCcore-11.2.0/lib/clang/13.0.0/include;/usr/local/include;/usr/include")
set(CMAKE_C_IMPLICIT_LINK_LIBRARIES "gcc;gcc_s;c;gcc;gcc_s")
set(CMAKE_C_IMPLICIT_LINK_DIRECTORIES "/apps/all/GCCcore/12.1.0/lib/gcc/x86_64-pc-linux-gnu/12.1.0;/apps/all/GCCcore/12.1.0/lib64;/lib64;/usr/lib64;/apps/all/AOCC/3.2.0-GCCcore-11.2.0/lib;/lib;/usr/lib;/apps/all/binutils/2.38-GCCcore-12.1.0/lib;/apps/all/zlib/1.2.12-GCCcore-12.1.0/lib;/apps/all/libarchive/3.6.1-GCCcore-12.2.0/lib;/apps/all/XZ/5.2.7-GCCcore-12.2.0/lib;/apps/all/cURL/7.86.0-GCCcore-12.2.0/lib;/apps/all/OpenSSL/1.1/lib;/apps/all/bzip2/1.0.8-GCCcore-12.2.0/lib;/apps/all/ncurses/6.3-GCCcore-12.2.0/lib;/apps/all/AOCC/3.2.0-GCCcore-11.2.0/lib32;/apps/all/libxml2/2.9.10-GCCcore-11.2.0/lib;/apps/all/imkl-FFTW/2022.0.1-iimpi-2022.00/lib;/apps/all/imkl/2022.0.1/mkl/2022.0.1/lib/intel64;/apps/all/imkl/2022.0.1/compiler/2022.0.1/linux/compiler/lib/intel64_lin;/apps/all/impi/2021.5.0-intel-compilers-2022.0.1/mpi/2021.5.0/libfabric/lib;/apps/all/impi/2021.5.0-intel-compilers-2022.0.1/mpi/2021.5.0/lib/release;/apps/all/impi/2021.5.0-intel-compilers-2022.0.1/mpi/2021.5.0/lib;/apps/all/UCX/1.11.2-GCCcore-11.2.0/lib;/apps/all/numactl/2.0.14-GCCcore-11.2.0/lib;/apps/all/intel-compilers/2022.0.1/tbb/2021.5.0/lib/intel64/gcc4.8;/apps/all/intel-compilers/2022.0.1/compiler/2022.0.1/linux/compiler/lib/intel64_lin;/apps/all/intel-compilers/2022.0.1/compiler/2022.0.1/linux/lib/x64;/apps/all/intel-compilers/2022.0.1/compiler/2022.0.1/linux/lib")
set(CMAKE_C_IMPLICIT_LINK_FRAMEWORK_DIRECTORIES "")
