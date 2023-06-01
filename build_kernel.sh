#/bin/bash
set -e

[ ! -e "toolchain" ] && echo "Make toolchain avaliable at $(pwd)/toolchain" && exit

export KBUILD_BUILD_USER=Royna
export KBUILD_BUILD_HOST=GrassLand

git submodule update --init

PATH=$PWD/toolchain/bin:$PATH
COMMON_FLAGS="O=out ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- CC=clang AS=llvm-as LD=ld.lld AR=llvm-ar NM=llvm-nm STRIP=llvm-strip OBJCOPY=llvm-objcopy OBJDUMP=llvm-objdump"
rm -rf out

make O=out $COMMON_FLAGS -j$(nproc) r3q_defconfig
cp out/.config arch/arm64/configs/r3q_defconfig
make O=out $COMMON_FLAGS -j$(nproc)
